// This file declares the IShellIcon Interface and Gateway for Python.
// Generated by makegw.py
// ---------------------------------------------------
//
// Interface Declaration

class PyIShellIcon : public PyIUnknown
{
public:
	MAKE_PYCOM_CTOR(PyIShellIcon);
	static IShellIcon *GetI(PyObject *self);
	static PyComTypeObject type;

	// The Python methods
	static PyObject *GetIconOf(PyObject *self, PyObject *args);

protected:
	PyIShellIcon(IUnknown *pdisp);
	~PyIShellIcon();
};
// ---------------------------------------------------
//
// Gateway Declaration

class PyGShellIcon : public PyGatewayBase, public IShellIcon
{
protected:
	PyGShellIcon(PyObject *instance) : PyGatewayBase(instance) { ; }
	PYGATEWAY_MAKE_SUPPORT2(PyGShellIcon, IShellIcon, IID_IShellIcon, PyGatewayBase)



	// IShellIcon
	STDMETHOD(GetIconOf)(
		LPCITEMIDLIST pidl,
		UINT flags,
		int __RPC_FAR * index);

};
