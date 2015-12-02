// This file implements the IProvideTaskPage Interface for Python.
// Generated by makegw.py

#include "PyIProvideTaskPage.h"
#include "PyWinObjects.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIProvideTaskPage::PyIProvideTaskPage(IUnknown *pdisp):
	PyIUnknown(pdisp)
{
	ob_type = &type;
}

PyIProvideTaskPage::~PyIProvideTaskPage()
{
}

/* static */ IProvideTaskPage *PyIProvideTaskPage::GetI(PyObject *self)
{
	return (IProvideTaskPage *)PyIUnknown::GetI(self);
}

// @pymethod |PyIProvideTaskPage|GetPage|Return a property sheet page handle for the spedified type (TASKPAGE_TASK,TASKPAGE_SCHEDULE,TASKPAGE_SETTINGS)
// @comm There's not yet anything useful that can be done with this handle - return type subject to change
PyObject *PyIProvideTaskPage::GetPage(PyObject *self, PyObject *args)
{
	IProvideTaskPage *pIPTP = GetI(self);
	if ( pIPTP == NULL )
		return NULL;
	TASKPAGE tpType;
	// @pyparm int|tpType||Type of page to retreive (TASKPAGE_TASK,TASKPAGE_SCHEDULE,TASKPAGE_SETTINGS)
	// @pyparm bool|PersistChanges||Indicates if changes should be saved automatically
	HPROPSHEETPAGE phPage;
	BOOL bPersistChanges;
	if ( !PyArg_ParseTuple(args, "ii:GetPage", &tpType, &bPersistChanges))
		return NULL;

	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPTP->GetPage(tpType, bPersistChanges, &phPage);
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPTP, IID_IProvideTaskPage );
	return PyWinLong_FromHANDLE(phPage);
}

// @object PyIProvideTaskPage|Description of the interface
static struct PyMethodDef PyIProvideTaskPage_methods[] =
{
	{ "GetPage", PyIProvideTaskPage::GetPage, 1 }, // @pymeth GetPage|Return a property sheet page handle for the spedified type (TASKPAGE_TASK,TASKPAGE_SCHEDULE,TASKPAGE_SETTINGS)
	{ NULL }
};

PyComTypeObject PyIProvideTaskPage::type("PyIProvideTaskPage",
		&PyIUnknown::type,
		sizeof(PyIProvideTaskPage),
		PyIProvideTaskPage_methods,
		GET_PYCOM_CTOR(PyIProvideTaskPage));
