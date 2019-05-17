//----------------------------------------------------------------------------------------------
// DeviceAudioManager.cpp
//----------------------------------------------------------------------------------------------
#include "StdAfx.h"

HRESULT CDeviceAudioManager::InitializeAllDeviceInfo(){

	HRESULT hr = S_OK;
	IMMDeviceEnumerator* pEnumerator = NULL;
	IMMDeviceCollection* pCollection = NULL;
	IMMDevice* pDevice = NULL;
	CMMDeviceInfo* pMMDeviceInfo = NULL;
	UINT uiCount = 0;
	EDataFlow eFlow = EDataFlow::eAll;

	ClearMMDeviceInfo();

	IF_FAILED_RETURN(CoCreateInstance(CLSID_MMDeviceEnumerator, NULL, CLSCTX_ALL, IID_IMMDeviceEnumerator, reinterpret_cast<void**>(&pEnumerator)));

	try{

		IF_FAILED_THROW(pEnumerator->EnumAudioEndpoints(eFlow, DEVICE_STATEMASK_ALL, &pCollection));
		IF_FAILED_THROW(pCollection->GetCount(&uiCount));

		m_vpMMDeviceInfo.reserve(uiCount);

		for(UINT ui = 0; ui < uiCount; ui++){

			IF_FAILED_THROW(pCollection->Item(ui, &pDevice));

			pMMDeviceInfo = new (std::nothrow)CMMDeviceInfo();

			IF_FAILED_THROW(pMMDeviceInfo == NULL ? E_OUTOFMEMORY : S_OK);

			m_vpMMDeviceInfo.push_back(pMMDeviceInfo);

			IF_FAILED_THROW(pMMDeviceInfo->InitializeMMDeviceInfo(pDevice));

			SAFE_RELEASE(pDevice);
		}
	}
	catch(HRESULT){}

	if(FAILED(hr))
		ClearMMDeviceInfo();

	SAFE_RELEASE(pDevice);
	SAFE_RELEASE(pCollection);
	SAFE_RELEASE(pEnumerator);

	return hr;
}

HRESULT CDeviceAudioManager::InitializeAllDeviceTopologyInfo(){

	HRESULT hr = S_OK;
	IMMDeviceEnumerator* pEnumerator = NULL;
	IMMDeviceCollection* pCollection = NULL;
	IMMDevice* pDevice = NULL;
	IDeviceTopology* pDeviceTopology = NULL;
	CDeviceTopologyInfo* pDeviceTopologyInfo = NULL;
	UINT uiCount = 0;
	EDataFlow eFlow = EDataFlow::eAll;

	ClearDeviceTopologyInfo();

	IF_FAILED_RETURN(CoCreateInstance(CLSID_MMDeviceEnumerator, NULL, CLSCTX_ALL, IID_IMMDeviceEnumerator, reinterpret_cast<void**>(&pEnumerator)));

	try{

		IF_FAILED_THROW(pEnumerator->EnumAudioEndpoints(eFlow, DEVICE_STATEMASK_ALL, &pCollection));
		IF_FAILED_THROW(pCollection->GetCount(&uiCount));

		m_vpMMDeviceInfo.reserve(uiCount);

		for(UINT ui = 0; ui < uiCount; ui++){

			IF_FAILED_THROW(pCollection->Item(ui, &pDevice));
			IF_FAILED_THROW(pDevice->Activate(IID_IDeviceTopology, CLSCTX_ALL, NULL, reinterpret_cast<void**>(&pDeviceTopology)));

			pDeviceTopologyInfo = new (std::nothrow)CDeviceTopologyInfo();

			IF_FAILED_THROW(pDeviceTopologyInfo == NULL ? E_OUTOFMEMORY : S_OK);

			hr = pDeviceTopologyInfo->InitializeDeviceTopologyInfo(pDeviceTopology);

			if(SUCCEEDED(hr)){

				m_vpDeviceTopologyInfo.push_back(pDeviceTopologyInfo);
			}
			else{

				SAFE_DELETE(pDeviceTopologyInfo);

				if(hr == HRESULT_FROM_WIN32(ERROR_NOT_FOUND))
					hr = S_OK;
				else
					IF_FAILED_THROW(hr);
			}

			SAFE_RELEASE(pDevice);
			SAFE_RELEASE(pDeviceTopology);
		}
	}
	catch(HRESULT){}

	if(FAILED(hr))
		ClearDeviceTopologyInfo();

	SAFE_RELEASE(pDeviceTopology);
	SAFE_RELEASE(pDevice);
	SAFE_RELEASE(pCollection);
	SAFE_RELEASE(pEnumerator);

	return hr;
}

HRESULT CDeviceAudioManager::InitializeDeviceInfo(LPCWSTR wszAudioEndpointID){

	HRESULT hr = S_OK;
	IMMDeviceEnumerator* pEnumerator = NULL;
	IMMDevice* pDevice = NULL;
	CMMDeviceInfo* pMMDeviceInfo = NULL;

	ClearMMDeviceInfo();

	IF_FAILED_RETURN(CoCreateInstance(CLSID_MMDeviceEnumerator, NULL, CLSCTX_ALL, IID_IMMDeviceEnumerator, reinterpret_cast<void**>(&pEnumerator)));

	try{

		IF_FAILED_THROW(pEnumerator->GetDevice(wszAudioEndpointID, &pDevice));

		pMMDeviceInfo = new (std::nothrow)CMMDeviceInfo();

		IF_FAILED_THROW(pMMDeviceInfo == NULL ? E_OUTOFMEMORY : S_OK);

		m_vpMMDeviceInfo.push_back(pMMDeviceInfo);

		IF_FAILED_THROW(pMMDeviceInfo->InitializeMMDeviceInfo(pDevice));
	}
	catch(HRESULT){}

	if(FAILED(hr))
		ClearMMDeviceInfo();

	SAFE_RELEASE(pDevice);
	SAFE_RELEASE(pEnumerator);

	return hr;
}

HRESULT CDeviceAudioManager::InitializeDeviceTopologyInfo(LPCWSTR wszAudioEndpointID){

	HRESULT hr = S_OK;
	IMMDeviceEnumerator* pEnumerator = NULL;
	IMMDevice* pDevice = NULL;
	IDeviceTopology* pDeviceTopology = NULL;
	CDeviceTopologyInfo* pDeviceTopologyInfo = NULL;

	ClearDeviceTopologyInfo();

	IF_FAILED_RETURN(CoCreateInstance(CLSID_MMDeviceEnumerator, NULL, CLSCTX_ALL, IID_IMMDeviceEnumerator, reinterpret_cast<void**>(&pEnumerator)));

	try{

		IF_FAILED_THROW(pEnumerator->GetDevice(wszAudioEndpointID, &pDevice));
		IF_FAILED_THROW(pDevice->Activate(IID_IDeviceTopology, CLSCTX_ALL, NULL, reinterpret_cast<void**>(&pDeviceTopology)));

		pDeviceTopologyInfo = new (std::nothrow)CDeviceTopologyInfo();

		IF_FAILED_THROW(pDeviceTopologyInfo == NULL ? E_OUTOFMEMORY : S_OK);

		m_vpDeviceTopologyInfo.push_back(pDeviceTopologyInfo);

		IF_FAILED_THROW(pDeviceTopologyInfo->InitializeDeviceTopologyInfo(pDeviceTopology));
	}
	catch(HRESULT){}

	if(FAILED(hr))
		ClearDeviceTopologyInfo();

	SAFE_RELEASE(pDeviceTopology);
	SAFE_RELEASE(pDevice);
	SAFE_RELEASE(pEnumerator);

	return hr;
}