/**
 * Copyright (c) 2016 Chris Marshall
 * All rights reserved.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "exampleobject.h"
#include "compat.h"


typedef struct {
    PyObject_HEAD
} Example;

void Example_dealloc(Example* self) {
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject* Example_new(PyTypeObject* type, PyObject* args, PyObject* kwds) {
    Example* self;

    self = (Example*)type->tp_alloc(type, 0);
    return (PyObject*)self;
}

static int Example_init(Example* self, PyObject* args, PyObject* kwds) {
    return 0;
}

static PyObject* Example_do_something(PyObject* self, PyObject* args) {
    Py_buffer buffer;

    if (!PyArg_ParseTuple(args, "s*", &buffer)) {
        Py_RETURN_NONE;
    }
    PyObject* ret = PyUnicode_FromStringAndSize(buffer.buf, buffer.len);
    PyObject* s = PyUnicode_FromString("Hello, ");
    ret = PyUnicode_Concat(s, ret);
    Py_DECREF(s);
    PyBuffer_Release(&buffer);
    return ret;
}

static PyMethodDef Example_methods[] = {
    {"something", (PyCFunction)Example_do_something, METH_VARARGS, ""},
    {NULL}  /* Sentinel */
};

PyTypeObject ExampleType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "_modulename.Example",                          /* tp_name */
    sizeof(Example),                                /* tp_basicsize */
    0,                                              /* tp_itemsize */
    (destructor)Example_dealloc,                    /* tp_dealloc */
    0,                                              /* tp_print */
    0,                                              /* tp_getattr */
    0,                                              /* tp_setattr */
    0,                                              /* tp_compare */
    0,                                              /* tp_repr */
    0,                                              /* tp_as_number */
    0,                                              /* tp_as_sequence */
    0,                                              /* tp_as_mapping */
    0,                                              /* tp_hash */
    0,                                              /* tp_call */
    0,                                              /* tp_str */
    0,                                              /* tp_getattro */
    0,                                              /* tp_setattro */
    0,                                              /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,       /* tp_flags */
    "Example objects",                              /* tp_doc */
    0,                                              /* tp_traverse */
    0,                                              /* tp_clear */
    0,                                              /* tp_richcompare */
    0,                                              /* tp_weaklistoffset */
    0,                                              /* tp_iter */
    0,                                              /* tp_iternext */
    Example_methods,                                /* tp_methods */
    0,                                              /* tp_members */
    0,                                              /* tp_getset */
    0,                                              /* tp_base */
    0,                                              /* tp_dict */
    0,                                              /* tp_descr_get */
    0,                                              /* tp_descr_set */
    0,                                              /* tp_dictoffset */
    (initproc)Example_init,                         /* tp_init */
    0,                                              /* tp_alloc */
    Example_new,                                    /* tp_new */
};
