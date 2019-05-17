//----------------------------------------------------------------------------------------------
// Main.cpp
//----------------------------------------------------------------------------------------------
#include "StdAfx.h"

#define TRACE_ALL_DEVICES

#ifndef TRACE_ALL_DEVICES
// Audio Device ID
#define AUDIO_DEVICE_TO_TEST L"{0.0.0.00000000}.{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}"
#endif

void main(){

	CDeviceAudioManager cDeviceAudioManager;

	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

	if(hr != S_OK)
		return;

#ifdef TRACE_ALL_DEVICES
	hr = cDeviceAudioManager.InitializeAllDeviceInfo();
#else
	hr = cDeviceAudioManager.InitializeDeviceInfo(AUDIO_DEVICE_TO_TEST);
#endif

	if(SUCCEEDED(hr))
		cDeviceAudioManager.LogAllDeviceInfo();

#ifdef TRACE_ALL_DEVICES
	hr = cDeviceAudioManager.InitializeAllDeviceTopologyInfo();
#else
	hr = cDeviceAudioManager.InitializeDeviceTopologyInfo(AUDIO_DEVICE_TO_TEST);
#endif

	if(SUCCEEDED(hr))
		cDeviceAudioManager.LogDeviceTopologyInfo();

	CoUninitialize();
}