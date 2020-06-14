#include "PyVar.hxx"

namespace types{
PyVar::PyVar(PyObject *_data) {
    data = _data;
    Py_INCREF(data);
}

PyVar::PyVar(InternalType *_data) {
    if (_data -> isBool() && _data -> getAs<Bool>() -> getSize() == 1) {
        int *val = _data -> getAs<Bool>() -> get();
        data = PyBool_FromLong(*val);
    } else if ((_data -> isDouble() || _data -> isFloat() || _data -> isInt()) && _data -> getAs<Double>() -> getSize() == 1) {
        double *val = _data -> getAs<Double>() -> get();
        if (int(*val) == *val) {
            data = PyLong_FromDouble(*val);
        } else {
            data = PyFloat_FromDouble(*val);
        }
    } else if (_data -> isString() && _data -> getAs<String>() -> getSize() == 1) {
        wchar_t **val = _data -> getAs<String>() -> get();
        data = PyUnicode_FromWideChar(*val, wcslen(*val));
    } else if (_data -> getTypeStr() == L"Python Variable") {
        data = _data -> getAs<PyVar>() -> get();
    } else {
        throw ast::InternalError("Incompatible type");
    }
}

PyVar::~PyVar() {
    Py_DECREF(data);
}

std::wstring PyVar::getTypeStr() const {
    return L"Python Variable";
}

std::wstring PyVar::getShortTypeStr() const {
    return L"py";
}

PyVar* PyVar::clone() {
    PyVar *newVar = new PyVar(data);
    return newVar;
}

bool PyVar::hasToString() {
    return true;
}

bool PyVar::toString(std::wostringstream& ostr) {
    PyObject *str_rep = PyObject_Repr(data);
    ostr << PyUnicode_AsUTF8(str_rep);
    Py_DECREF(str_rep);
    return true;
}

PyObject* PyVar::get() {
    return data;
}

bool PyVar::extract(const std::wstring& name, InternalType *& out) {
    const wchar_t *winput = name.c_str();
    char *input = new char[wcslen(winput) + 1];
    sprintf(input, "%ws", winput);
    if (!PyObject_HasAttrString(data, input)) {
        std::string err = "Python variable has no attribute '";
        err.append(input);
        delete input;
        PyErr_Clear();
        throw ast::InternalError(err + "'");
    }
    out = new PyVar(PyObject_GetAttrString(data, input));
    delete input;
    return true;
}

bool PyVar::isInvokable() const {
    return true;//(PyCallable_Check(data) || PyDict_Check(data) || PySequence_Check(data));
}

bool PyVar::invoke(types::typed_list & in, types::optional_list & opt, int _iRetCount, types::typed_list & out, const ast::Exp & e) {
    if (PySequence_Check(data)) {
        if (in.size() > 2 || in.size() < 1) {
            throw ast::InternalError("Wrong number of arguements, 1 or 2 expected");
            return true;
        }
        if (in[0] -> isDouble() || in[0] -> isFloat() || in[0] -> isInt()) {
            double *val = in[0] -> getAs<Double>() -> get();
            if (int(*val) != *val) {
                throw ast::InternalError("Incompatible type float, integer expected");
                return true;
            }
            PyObject *item = PySequence_GetItem(data, int(*val));
            if (item == NULL) {
                PyErr_Clear();
                throw ast::InternalError("Index out of range");
                return true;
            }
            if (in.size() == 2) {
                PyVar newVal = PyVar(in[1]);
                if(PySequence_SetItem(data, int(*val), newVal.get()) == -1) {
                    PyErr_Clear();
                    throw ast::InternalError("Python Variable might be immutable");
                    return true;
                }
                item = PySequence_GetItem(data, int(*val));
            }
            out.push_back(new PyVar(item));
            return true;
        } else {
            throw ast::InternalError("Incompatible type, integer expected");
            return true;
        }
    } else if (PyDict_Check(data)){
        if (in.size() > 2 || in.size() < 1) {
            throw ast::InternalError("Wrong number of arguements, 1 or 2 expected");
            return true;
        }
        PyVar key = PyVar(in[0]); 
        if(PyObject_Hash(key.get()) == -1) {
            PyErr_Clear();
            throw ast::InternalError("Incompatible type, key must be hashable");
            return true;
        }
        if (in.size() == 2) {
            PyVar newVal = PyVar(in[1]);
            PyDict_SetItem(data, key.get(), newVal.get());
        }
        PyObject *item = PyDict_GetItem(data, key.get());
        if (item == NULL) {
            PyErr_Clear();
            throw ast::InternalError("Key not found");
            return true;
        }
        out.push_back(new PyVar(item));
        return true;
    } else if (PyCallable_Check(data)) {
        PyObject *newTuple = PyTuple_New(in.size());
        for (size_t i = 0; i < in.size(); i++) {
            PyVar *item = new PyVar(in[i]);
            PyTuple_SetItem(newTuple, i, item -> get());
        }

        PyObject *ret = PyObject_Call(data, newTuple, NULL);
        if (ret == NULL) {
            PyErr_Clear();
            throw ast::InternalError("An error occured while calling the function");
            return true;
        }

        Py_DECREF(newTuple);
        PyVar *pOut = new PyVar(ret);
        out.push_back(pOut);
        return true;
    } else if (in.size() == 2 && in[0] -> isString()) {
        wchar_t **wattr = in[0] -> getAs<String>() -> get();
        char *attr = new char[wcslen(*wattr) + 1];
        sprintf(attr, "%ws", *wattr);
        if (!PyObject_HasAttrString(data, attr)) {
            std::string err = "Python variable has no attribute '";
            err.append(attr);
            delete attr;
            PyErr_Clear();
            throw ast::InternalError(err + "'");
        }
        PyVar newVal = PyVar(in[1]);
        PyObject_SetAttrString(data, attr, newVal.get());
        return true;
    }
    throw ast::InternalError("Python variable is neither callable nor a sequence or mapped object");
}
}


