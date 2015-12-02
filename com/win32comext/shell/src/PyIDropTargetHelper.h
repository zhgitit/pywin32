// This file declares the IDropTargetHelper Interface and Gateway for Python.
// Generated by makegw.py
// ---------------------------------------------------
//
// Interface Declaration

class PyIDropTargetHelper : public PyIUnknown
{
public:
	MAKE_PYCOM_CTOR(PyIDropTargetHelper);
	static IDropTargetHelper *GetI(PyObject *self);
	static PyComTypeObject type;

	// The Python methods
	static PyObject *DragEnter(PyObject *self, PyObject *args);
	static PyObject *DragOver(PyObject *self, PyObject *args);
	static PyObject *DragLeave(PyObject *self, PyObject *args);
	static PyObject *Drop(PyObject *self, PyObject *args);
	static PyObject *Show(PyObject *self, PyObject *args);

protected:
	PyIDropTargetHelper(IUnknown *pdisp);
	~PyIDropTargetHelper();
};
// ---------------------------------------------------
//
// Gateway Declaration

class PyGDropTargetHelper : public PyGatewayBase, public IDropTargetHelper
{
protected:
	PyGDropTargetHelper(PyObject *instance) : PyGatewayBase(instance) { ; }
	PYGATEWAY_MAKE_SUPPORT2(PyGDropTargetHelper, IDropTargetHelper, IID_IDropTargetHelper, PyGatewayBase)



	// IDropTargetHelper
	STDMETHOD(DragEnter)(
		HWND hwnd,
		IDataObject * pDataObj,
		POINT *pt,
		DWORD dwEffect);

	STDMETHOD(DragOver)(
		POINT *pt,
		DWORD dwEffect);

	STDMETHOD(DragLeave)(
		void);

	STDMETHOD(Drop)(
		IDataObject * pDataObj,
		POINT *pt,
		DWORD dwEffect);
	STDMETHOD(Show)(
		BOOL fShow);
};
