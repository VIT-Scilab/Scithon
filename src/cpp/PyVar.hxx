#ifndef __CPPPYTHON_H__
#define __CPPPYTHON_H__

#include <Python.h>
#include "user.hxx"
#include "alltypes.hxx"

extern "C" {
#include "dynlib_scithon_src.h"
#include "PythonInstance.h"  
}

namespace types{
class SCITHON_SRC_IMPEXP PyVar : public UserType {
public:
    PyObject *data;

    PyVar(PyObject *_data);

    PyVar(InternalType *_data);

    ~PyVar();

    std::wstring getTypeStr() const override;

    std::wstring getShortTypeStr() const override;

    PyVar* clone() override;

    bool hasToString() override;

    bool toString(std::wostringstream& ostr);

    PyObject* get();

    bool extract(const std::wstring& name, InternalType *& out) override;

    bool isInvokable() const override;

    bool hasInvokeOption() const override {
        return true;
    }

    bool invoke(types::typed_list & in, types::optional_list & opt, int _iRetCount, types::typed_list & out, const ast::Exp & e) override;

    InternalType* sciParse();
};
}

#endif

