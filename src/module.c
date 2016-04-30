/**
 * Copyright (c) 2016 Chris Marshall
 * All rights reserved.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <Python.h>
#include "compat.h"

#include "exampleobject.h"


#ifdef __cplusplus
extern "C" {
#endif 


static PyMethodDef module_methods[] = {
    {NULL}  /* Sentinel */
};

MOD_INIT(_modulename)
{
    PyObject* m;

    if (PyType_Ready(&ExampleType) < 0) {
        return MOD_ERROR_VAL;
    }

    MOD_DEF(m, "_modulename", "", module_methods);

    if (m == NULL) {
        return MOD_ERROR_VAL;
    }

    Py_INCREF(&ExampleType);
    PyModule_AddObject(m, "ExampleObj", (PyObject*)&ExampleType);

    return MOD_SUCCESS_VAL(m);
}


#ifdef __cplusplus
}
#endif
