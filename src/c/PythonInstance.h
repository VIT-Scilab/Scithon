#ifndef __CPYTHON_H__
#define __CPYTHON_H__

#include <Python.h>
#include <direct.h>

static PyObject *Main = NULL;

void Initialize();
void Finalize();
long GetStdOutSize();
void GetStdOut(char*);
PyObject* GetPyObject(char*);

#endif
