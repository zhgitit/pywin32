// This file implements the IShellBrowser Interface and Gateway for Python.
// Generated by makegw.py

#include "shell_pch.h"
#include "PyIOleWindow.h"
#include "PyIShellBrowser.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
extern BOOL PyObject_AsTBBUTTONs( PyObject *ob, TBBUTTON **ppButtons, UINT *nButtons );
extern void PyObject_FreeTBBUTTONs(TBBUTTON *, UINT);

// Interface Implementation

PyIShellBrowser::PyIShellBrowser(IUnknown *pdisp):
	PyIOleWindow(pdisp)
{
	ob_type = &type;
}

PyIShellBrowser::~PyIShellBrowser()
{
}

/* static */ IShellBrowser *PyIShellBrowser::GetI(PyObject *self)
{
	return (IShellBrowser *)PyIOleWindow::GetI(self);
}

// @pymethod <o PyOLEMENUGROUPWIDTHS>|PyIShellBrowser|InsertMenusSB|Updates a composite menu with container's options
PyObject *PyIShellBrowser::InsertMenusSB(PyObject *self, PyObject *args)
{
	IShellBrowser *pISB = GetI(self);
	if ( pISB == NULL )
		return NULL;
	OLEMENUGROUPWIDTHS menuWidths;
	PyObject *obMenuWidths, *obhmenuShared;
	HMENU hmenuShared;
	if ( !PyArg_ParseTuple(args, "OO:InsertMenusSB",
		&obhmenuShared,		// @pyparm <o PyHANDLE>|hmenuShared||Newly created menu that contains no items
		&obMenuWidths))		// @pyparm <o PyOLEMENUGROUPWIDTHS>|lpMenuWidths||Tuple of 6 ints.  Items 0,2,and 4 are updated when the tuple is returned.
		return NULL;
	if (!PyWinObject_AsHANDLE(obhmenuShared, (HANDLE *)&hmenuShared))
		return NULL;
	if (!PyObject_AsOLEMENUGROUPWIDTHS( obMenuWidths, &menuWidths))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pISB->InsertMenusSB( hmenuShared, &menuWidths );
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pISB, IID_IShellBrowser );
	return PyObject_FromOLEMENUGROUPWIDTHS(&menuWidths);
}

// @pymethod |PyIShellBrowser|SetMenuSB|Attaches a shared menu to a shell view window
PyObject *PyIShellBrowser::SetMenuSB(PyObject *self, PyObject *args)
{
	IShellBrowser *pISB = GetI(self);
	if ( pISB == NULL )
		return NULL;
	HMENU hmenuShared;
	HOLEMENU holemenuRes;
	HWND hwndActiveObject;
	PyObject *obhmenuShared, *obholemenuRes, *obhwndActiveObject;
	if (!PyArg_ParseTuple(args, "OOO:SetMenuSB",
		&obhmenuShared,			// @pyparm <o PyHANDLE>|hmenuShared||Handle to the shared menu
		&obholemenuRes,			// @pyparm <o PyHANDLE>|holemenuRes||Reserved, use only None (or 0)
		&obhwndActiveObject))	// @pyparm <o PyHANDLE>|hwndActiveObject||Handle to the shell window
		return NULL;
	if (!PyWinObject_AsHANDLE(obhmenuShared, (HANDLE *)&hmenuShared))
		return NULL;
	if (!PyWinObject_AsHANDLE(obholemenuRes, (HANDLE *)&holemenuRes))
		return NULL;
	if (!PyWinObject_AsHANDLE(obhwndActiveObject, (HANDLE *)&hwndActiveObject))
		return NULL;

	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pISB->SetMenuSB( hmenuShared, holemenuRes, hwndActiveObject );
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pISB, IID_IShellBrowser );
	Py_INCREF(Py_None);
	return Py_None;

}

// @pymethod |PyIShellBrowser|RemoveMenusSB|Asks container to remove any items it added to a composite menu
PyObject *PyIShellBrowser::RemoveMenusSB(PyObject *self, PyObject *args)
{
	IShellBrowser *pISB = GetI(self);
	if ( pISB == NULL )
		return NULL;
	PyObject *obhmenuShared;
	HMENU hmenuShared;
	if (!PyArg_ParseTuple(args, "O:RemoveMenusSB", 
		&obhmenuShared))	// @pyparm <o PyHANDLE>|hmenuShared||Handle to the composite menu
		return NULL;
	if (!PyWinObject_AsHANDLE(obhmenuShared, (HANDLE *)&hmenuShared))
		return NULL;

	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pISB->RemoveMenusSB( hmenuShared );

	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pISB, IID_IShellBrowser );
	Py_INCREF(Py_None);
	return Py_None;

}

// @pymethod |PyIShellBrowser|SetStatusTextSB|Sets the status text in view's status bar
PyObject *PyIShellBrowser::SetStatusTextSB(PyObject *self, PyObject *args)
{
	IShellBrowser *pISB = GetI(self);
	if ( pISB == NULL )
		return NULL;
	PyObject *obStatusText;
	TmpWCHAR StatusText;
	if (!PyArg_ParseTuple(args, "O:SetStatusTextSB",
		&obStatusText))	// @pyparm str|pszStatusText||New status to be displayed
		return NULL;
	if (!PyWinObject_AsWCHAR(obStatusText, &StatusText))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pISB->SetStatusTextSB(StatusText );
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pISB, IID_IShellBrowser );
	Py_INCREF(Py_None);
	return Py_None;
}

// @pymethod |PyIShellBrowser|EnableModelessSB|Enables or disables modeless dialogs
PyObject *PyIShellBrowser::EnableModelessSB(PyObject *self, PyObject *args)
{
	IShellBrowser *pISB = GetI(self);
	if ( pISB == NULL )
		return NULL;
	BOOL fEnable;
	if (!PyArg_ParseTuple(args, "i:EnableModelessSB", 
		&fEnable))	// @pyparm boolean|fEnable||Use True to enable or False to disable modeless dialog boxes
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pISB->EnableModelessSB( fEnable );

	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pISB, IID_IShellBrowser );
	Py_INCREF(Py_None);
	return Py_None;

}

// @pymethod |PyIShellBrowser|TranslateAcceleratorSB|Translates keystrokes used as menu item activators
PyObject *PyIShellBrowser::TranslateAcceleratorSB(PyObject *self, PyObject *args)
{
	IShellBrowser *pISB = GetI(self);
	if ( pISB == NULL )
		return NULL;
	MSG msg;
	PyObject *obpmsg;
	WORD wID;
	if (!PyArg_ParseTuple(args, "OH:TranslateAcceleratorSB",
		&obpmsg,	// @pyparm <o PyMSG>|pmsg||Keystroke message to be translated
		&wID))		// @pyparm int|wID||Menu command id for the keystroke
		return NULL;
	if (!PyObject_AsMSG(obpmsg, &msg))
		return NULL;

	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pISB->TranslateAcceleratorSB( &msg, wID );
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pISB, IID_IShellBrowser );
	Py_INCREF(Py_None);
	return Py_None;
}

// @pymethod |PyIShellBrowser|BrowseObject|Navigates to a different location
PyObject *PyIShellBrowser::BrowseObject(PyObject *self, PyObject *args)
{
	IShellBrowser *pISB = GetI(self);
	if ( pISB == NULL )
		return NULL;
	PyObject *obpidl;
	LPITEMIDLIST pidl;
	UINT wFlags;
	if ( !PyArg_ParseTuple(args, "OI:BrowseObject",
		&obpidl,	// @pyparm <o PyIDL>|pidl||Item id list that specifies the new browse location, can be None
		&wFlags))	// @pyparm int|wFlags||Combination of shellcon.SBSP_* flags
		return NULL;
	if (!PyObject_AsPIDL(obpidl, &pidl, TRUE))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pISB->BrowseObject( pidl, wFlags );
	PyObject_FreePIDL(pidl);
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pISB, IID_IShellBrowser );
	Py_INCREF(Py_None);
	return Py_None;
}

// @pymethod <o PyIStream>|PyIShellBrowser|GetViewStateStream|Returns a stream that can be used to access view state information
PyObject *PyIShellBrowser::GetViewStateStream(PyObject *self, PyObject *args)
{
	IShellBrowser *pISB = GetI(self);
	if ( pISB == NULL )
		return NULL;
	// @pyparm int|grfMode||Read/write mode, one of STGM_READ,STGM_WRITE,STGM_READWRITE
	DWORD grfMode;
	IStream * ppStrm;
	if ( !PyArg_ParseTuple(args, "l:GetViewStateStream", &grfMode) )
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pISB->GetViewStateStream( grfMode, &ppStrm );
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pISB, IID_IShellBrowser );
	return PyCom_PyObjectFromIUnknown(ppStrm, IID_IStream, FALSE);
}

// @pymethod |PyIShellBrowser|GetControlWindow|Returns a handle to one of the browser's control elements
PyObject *PyIShellBrowser::GetControlWindow(PyObject *self, PyObject *args)
{
	IShellBrowser *pISB = GetI(self);
	if ( pISB == NULL )
		return NULL;
	// @pyparm int|id||One of shellcon.FCW_* values
	UINT id;
	if ( !PyArg_ParseTuple(args, "I:GetControlWindow", &id) )
		return NULL;
	HWND hwnd;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pISB->GetControlWindow( id, &hwnd );
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pISB, IID_IShellBrowser );
	return PyWinLong_FromHANDLE(hwnd);
}

// @pymethod int|PyIShellBrowser|SendControlMsg|Sends a control msg to browser's toolbar or status bar
PyObject *PyIShellBrowser::SendControlMsg(PyObject *self, PyObject *args)
{
	IShellBrowser *pISB = GetI(self);
	if ( pISB == NULL )
		return NULL;
	// @pyparm int|id||shellcon.FCW_TOOLBAR or FCW_STATUS
	// @pyparm int|uMsg||The message to send
	// @pyparm int|wParam||Value is dependent on the message
	// @pyparm long|lParam||Value is dependent on the message
	UINT id;
	UINT uMsg;
	PyObject *obwparam, *oblparam;
	if ( !PyArg_ParseTuple(args, "IIOO:SendControlMsg", &id, &uMsg, &obwparam, &oblparam) )
		return NULL;
	WPARAM wParam;
	LPARAM lParam;
	if (!PyWinObject_AsPARAM(obwparam, &wParam))
		return NULL;
	// WPARAM and LPARAM are defined as UINT_PTR and LONG_PTR, so they can't be used interchangeably without a cast
	if (!PyWinObject_AsPARAM(oblparam, (WPARAM *)&lParam))
		return NULL;
	
	HRESULT hr;
	LRESULT ret;
	PY_INTERFACE_PRECALL;
	hr = pISB->SendControlMsg( id, uMsg, wParam, lParam, &ret );
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pISB, IID_IShellBrowser );
	// LRESULT is defined as LONG_PTR.  This should work for either 32 or 64 bit.
	return PyLong_FromLongLong(ret);
}

// @pymethod <o PyIShellView>|PyIShellBrowser|QueryActiveShellView|Returns the currently displayed view
PyObject *PyIShellBrowser::QueryActiveShellView(PyObject *self, PyObject *args)
{
	IShellBrowser *pISB = GetI(self);
	if ( pISB == NULL )
		return NULL;
	IShellView * ppshv;
	if ( !PyArg_ParseTuple(args, ":QueryActiveShellView") )
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pISB->QueryActiveShellView( &ppshv );
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pISB, IID_IShellBrowser );
	return PyCom_PyObjectFromIUnknown(ppshv, IID_IShellView, FALSE);
}

// @pymethod |PyIShellBrowser|OnViewWindowActive|Callback triggered when a view window is activated
PyObject *PyIShellBrowser::OnViewWindowActive(PyObject *self, PyObject *args)
{
	IShellBrowser *pISB = GetI(self);
	if ( pISB == NULL )
		return NULL;
	// @pyparm <o PyIShellView>|pshv||The activated view object
	PyObject *obpshv;
	IShellView *pshv;
	if ( !PyArg_ParseTuple(args, "O:OnViewWindowActive", &obpshv) )
		return NULL;
	if (!PyCom_InterfaceFromPyInstanceOrObject(obpshv, IID_IShellView, (void **)&pshv, TRUE /* bNoneOK */))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pISB->OnViewWindowActive( pshv );
	if (pshv) pshv->Release();
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pISB, IID_IShellBrowser );
	Py_INCREF(Py_None);
	return Py_None;

}

// @pymethod |PyIShellBrowser|SetToolbarItems|Adds toolbar buttons to the browser's toolbar
PyObject *PyIShellBrowser::SetToolbarItems(PyObject *self, PyObject *args)
{
	IShellBrowser *pISB = GetI(self);
	if ( pISB == NULL )
		return NULL;
	LPTBBUTTONSB lpButtons;
	PyObject *oblpButtons;
	
	
	UINT nButtons;
	UINT uFlags;
	if (!PyArg_ParseTuple(args, "OI:SetToolbarItems",
		&oblpButtons,	// @pyparm <o PyLPTBBUTTONSB>|lpButtons||Sequence of tuples describing the buttons to be added
		&uFlags))		// @pyparm int|uFlags||Indicates button positions, combination of shellcon.FCT_*
		return NULL;
	if (!PyObject_AsTBBUTTONs( oblpButtons, &lpButtons, &nButtons ))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pISB->SetToolbarItems( lpButtons, nButtons, uFlags );
	PyObject_FreeTBBUTTONs(lpButtons, nButtons);
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pISB, IID_IShellBrowser );
	Py_INCREF(Py_None);
	return Py_None;

}

// @object PyIShellBrowser|Exposed by Windows Explorer and the Open File common dialog box to provide services for namespace extensions.
static struct PyMethodDef PyIShellBrowser_methods[] =
{
	{ "InsertMenusSB", PyIShellBrowser::InsertMenusSB, 1 }, // @pymeth InsertMenusSB|Updates a composite menu with container's options
	{ "SetMenuSB", PyIShellBrowser::SetMenuSB, 1 }, // @pymeth SetMenuSB|Attaches a shared menu to a shell view window
	{ "RemoveMenusSB", PyIShellBrowser::RemoveMenusSB, 1 }, // @pymeth RemoveMenusSB|Asks container to remove any items it added to a composite menu
	{ "SetStatusTextSB", PyIShellBrowser::SetStatusTextSB, 1 }, // @pymeth SetStatusTextSB|Sets the status text in view's status bar
	{ "EnableModelessSB", PyIShellBrowser::EnableModelessSB, 1 }, // @pymeth EnableModelessSB|Enables or disables modeless dialogs
	{ "TranslateAcceleratorSB", PyIShellBrowser::TranslateAcceleratorSB, 1 }, // @pymeth TranslateAcceleratorSB|Translates keystrokes used as menu item activators
	{ "BrowseObject", PyIShellBrowser::BrowseObject, 1 }, // @pymeth BrowseObject|Navigates to a different location
	{ "GetViewStateStream", PyIShellBrowser::GetViewStateStream, 1 }, // @pymeth GetViewStateStream|Returns a stream that can be used to access view state information
	{ "GetControlWindow", PyIShellBrowser::GetControlWindow, 1 }, // @pymeth GetControlWindow|Returns a handle to one of the browser's control elements
	{ "SendControlMsg", PyIShellBrowser::SendControlMsg, 1 }, // @pymeth SendControlMsg|Sends a control msg to browser's toolbar or status bar
	{ "QueryActiveShellView", PyIShellBrowser::QueryActiveShellView, 1 }, // @pymeth QueryActiveShellView|Returns the currently displayed view
	{ "OnViewWindowActive", PyIShellBrowser::OnViewWindowActive, 1 }, // @pymeth OnViewWindowActive|Callback triggered when a view window is activated
	{ "SetToolbarItems", PyIShellBrowser::SetToolbarItems, 1}, // @pymeth SetToolbarItems|Adds toolbar buttons to the browser's toolbar
	{ NULL }
};

PyComTypeObject PyIShellBrowser::type("PyIShellBrowser",
		&PyIOleWindow::type,
		sizeof(PyIShellBrowser),
		PyIShellBrowser_methods,
		GET_PYCOM_CTOR(PyIShellBrowser));
// ---------------------------------------------------
//
// Gateway Implementation
STDMETHODIMP PyGShellBrowser::GetWindow(HWND __RPC_FAR * phwnd) {return PyGOleWindow::GetWindow(phwnd);}
STDMETHODIMP PyGShellBrowser::ContextSensitiveHelp(BOOL fEnterMode) {return PyGOleWindow::ContextSensitiveHelp(fEnterMode);}
STDMETHODIMP PyGShellBrowser::InsertMenusSB(
		/* [in] */ HMENU hmenuShared,
		/* [out][in] */ LPOLEMENUGROUPWIDTHS lpMenuWidths)
{
	static const char *method_name = "InsertMenusSB";
	PY_GATEWAY_METHOD;
	PyObject *oblpMenuWidths = PyObject_FromOLEMENUGROUPWIDTHS(lpMenuWidths);
	if (oblpMenuWidths==NULL) return MAKE_PYCOM_GATEWAY_FAILURE_CODE(method_name);
	PyObject *result;
	HRESULT hr=InvokeViaPolicy(method_name, &result, "NO", PyWinLong_FromHANDLE(hmenuShared), oblpMenuWidths);
	Py_DECREF(oblpMenuWidths);
	if (FAILED(hr)) return hr;
	PyObject_AsOLEMENUGROUPWIDTHS(result, lpMenuWidths);
	Py_DECREF(result);
	return PyCom_SetCOMErrorFromPyException(GetIID());
}

STDMETHODIMP PyGShellBrowser::SetMenuSB(
		/* [in] */ HMENU hmenuShared,
		/* [in] */ HOLEMENU holemenuRes,
		/* [in] */ HWND hwndActiveObject)
{
	PY_GATEWAY_METHOD;
	HRESULT hr=InvokeViaPolicy("SetMenuSB", NULL, "NNN", PyWinLong_FromHANDLE(hmenuShared), 
		PyWinLong_FromHANDLE(holemenuRes), PyWinLong_FromHANDLE(hwndActiveObject));
	return hr;
}

STDMETHODIMP PyGShellBrowser::RemoveMenusSB(
		/* [in] */ HMENU hmenuShared)
{
	PY_GATEWAY_METHOD;
	HRESULT hr=InvokeViaPolicy("RemoveMenusSB", NULL, "N", PyWinLong_FromHANDLE(hmenuShared));
	return hr;
}

STDMETHODIMP PyGShellBrowser::SetStatusTextSB(
		/* [unique][in] */ LPCOLESTR pszStatusText)
{
	PY_GATEWAY_METHOD;
	PyObject *obpszStatusText;
	obpszStatusText = MakeOLECHARToObj(pszStatusText);
	HRESULT hr=InvokeViaPolicy("SetStatusTextSB", NULL, "O", obpszStatusText);
	Py_XDECREF(obpszStatusText);
	return hr;
}

STDMETHODIMP PyGShellBrowser::EnableModelessSB(
		/* [in] */ BOOL fEnable)
{
	PY_GATEWAY_METHOD;
	HRESULT hr=InvokeViaPolicy("EnableModelessSB", NULL, "i", fEnable);
	return hr;
}

STDMETHODIMP PyGShellBrowser::TranslateAcceleratorSB(
		/* [in] */ MSG * pmsg,
		/* [in] */ WORD wID)
{
	static const char *method_name = "TranslateAcceleratorSB";
	PY_GATEWAY_METHOD;
	PyObject *obpmsg = PyObject_FromMSG(pmsg);
	if (obpmsg==NULL) return MAKE_PYCOM_GATEWAY_FAILURE_CODE(method_name);
	HRESULT hr=InvokeViaPolicy(method_name, NULL, "OH", obpmsg, wID);
	Py_DECREF(obpmsg);
	return hr;
}

STDMETHODIMP PyGShellBrowser::BrowseObject(
		/* [in] */ LPCITEMIDLIST pidl,
		/* [in] */ UINT wFlags)
{
	PY_GATEWAY_METHOD;
	PyObject *obpidl;
	obpidl = PyObject_FromPIDL(pidl, FALSE);
	HRESULT hr=InvokeViaPolicy("BrowseObject", NULL, "OI", obpidl, wFlags);
	Py_XDECREF(obpidl);
	return hr;
}

STDMETHODIMP PyGShellBrowser::GetViewStateStream(
		/* [in] */ DWORD grfMode,
		/* [out] */ IStream ** ppStrm)
{
	static const char *method_name = "GetViewStateStream";
	PY_GATEWAY_METHOD;
	PyObject *result;
	HRESULT hr=InvokeViaPolicy(method_name, &result, "l", grfMode);
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
	PyObject *obppStrm;
	if (!PyArg_Parse(result, "O" , &obppStrm)) return MAKE_PYCOM_GATEWAY_FAILURE_CODE(method_name);
	BOOL bPythonIsHappy = TRUE;
	if (bPythonIsHappy && !PyCom_InterfaceFromPyInstanceOrObject(obppStrm, IID_IStream, (void **)ppStrm, TRUE /* bNoneOK */))
		 bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) hr = MAKE_PYCOM_GATEWAY_FAILURE_CODE(method_name);
	Py_DECREF(result);
	return hr;
}

STDMETHODIMP PyGShellBrowser::GetControlWindow(
		/* [in] */ UINT id,
		/* [out] */ HWND * phwnd)
{
	static const char *method_name = "GetControlWindow";
	PY_GATEWAY_METHOD;
	PyObject *result;
	HRESULT hr=InvokeViaPolicy(method_name, &result, "I", id);
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
	if (!PyWinObject_AsHANDLE(result, (HANDLE *)phwnd))
		hr = MAKE_PYCOM_GATEWAY_FAILURE_CODE(method_name);
	Py_DECREF(result);
	return hr;
}

STDMETHODIMP PyGShellBrowser::SendControlMsg(
		/* [in] */ UINT id,
		/* [in] */ UINT uMsg,
		/* [in] */ WPARAM wParam,
		/* [in] */ LPARAM lParam,
		/* [in] */ LRESULT * pret)
{
	PY_GATEWAY_METHOD;
	PyObject *result;
	HRESULT hr=InvokeViaPolicy("SendControlMsg", &result, "iiNN", id, uMsg, PyWinObject_FromPARAM(wParam), PyWinObject_FromPARAM(lParam));
	if (PyInt_Check(result) || PyLong_Check(result))
		PyWinLong_AsULONG_PTR(result, (ULONG_PTR *)pret);
	Py_DECREF(result);
	return hr;
}

STDMETHODIMP PyGShellBrowser::QueryActiveShellView(
		/* [out] */ IShellView ** ppshv)
{
	static const char *method_name = "QueryActiveShellView";
	PY_GATEWAY_METHOD;
	PyObject *result;
	HRESULT hr=InvokeViaPolicy(method_name, &result);
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
	PyObject *obppshv;
	if (!PyArg_Parse(result, "O" , &obppshv)) return MAKE_PYCOM_GATEWAY_FAILURE_CODE(method_name);
	BOOL bPythonIsHappy = TRUE;
	if (bPythonIsHappy && !PyCom_InterfaceFromPyInstanceOrObject(obppshv, IID_IShellView, (void **)ppshv, TRUE /* bNoneOK */))
		 bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) hr = MAKE_PYCOM_GATEWAY_FAILURE_CODE(method_name);
	Py_DECREF(result);
	return hr;
}

STDMETHODIMP PyGShellBrowser::OnViewWindowActive(
		/* [in] */ IShellView * pshv)
{
	PY_GATEWAY_METHOD;
	PyObject *obpshv;
	obpshv = PyCom_PyObjectFromIUnknown(pshv, IID_IShellView, TRUE);
	HRESULT hr=InvokeViaPolicy("OnViewWindowActive", NULL, "O", obpshv);
	Py_XDECREF(obpshv);
	return hr;
}

STDMETHODIMP PyGShellBrowser::SetToolbarItems(
		/* [in] */ LPTBBUTTONSB lpButtons,
		/* [in] */ UINT nButtons,
		/* [in] */ UINT uFlags)
{
	static const char *method_name = "SetToolbarItems";
	PY_GATEWAY_METHOD;
// *** The input argument lpButtons of type "LPTBBUTTONSB" was not processed ***
//   - Please ensure this conversion function exists, and is appropriate
//   - The type 'LPTBBUTTONSB' (lpButtons) is unknown.
	PyObject *oblpButtons = Py_None; //PyObject_FromLPTBBUTTONSB(lpButtons);
	Py_INCREF(Py_None);
	if (oblpButtons==NULL) return MAKE_PYCOM_GATEWAY_FAILURE_CODE(method_name);
	HRESULT hr=InvokeViaPolicy(method_name, NULL, "Oii", oblpButtons, nButtons, uFlags);
	Py_DECREF(oblpButtons);
	return hr;
}

