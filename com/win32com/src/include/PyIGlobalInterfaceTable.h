// This file declares the IGlobalInterfaceTable.h Interface and Gateway for Python.
// Generated by makegw.py
// ---------------------------------------------------
//
// Interface Declaration

class PyIGlobalInterfaceTable : public PyIUnknown
{
public:
	MAKE_PYCOM_CTOR(PyIGlobalInterfaceTable);
	static IGlobalInterfaceTable *GetI(PyObject *self);
	static PyComTypeObject type;

	// The Python methods
	static PyObject *RegisterInterfaceInGlobal(PyObject *self, PyObject *args);
	static PyObject *RevokeInterfaceFromGlobal(PyObject *self, PyObject *args);
	static PyObject *GetInterfaceFromGlobal(PyObject *self, PyObject *args);

protected:
	PyIGlobalInterfaceTable(IUnknown *pdisp);
	~PyIGlobalInterfaceTable();
};
