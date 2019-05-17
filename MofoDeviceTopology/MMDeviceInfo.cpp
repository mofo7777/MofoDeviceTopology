//----------------------------------------------------------------------------------------------
// MMDeviceInfo.cpp
//----------------------------------------------------------------------------------------------
#include "StdAfx.h"

HRESULT CMMDeviceInfo::InitializeMMDeviceInfo(IMMDevice* pDevice){

	HRESULT hr = S_OK;
	IPropertyStore* pProps = NULL;
	IMMEndpoint* pMMEndpoint = NULL;
	IAudioClient* pAudioClient = NULL;
	IAudioEndpointVolume* pAudioEndpointVolume = NULL;
	IAudioMeterInformation* pAudioMeterInformation = NULL;
	IAudioSessionManager* pAudioSessionManager = NULL;
	IAudioSessionManager2* pAudioSessionManager2 = NULL;
	IBaseFilter* pBaseFilter = NULL;
	IDeviceTopology* pDeviceTopology = NULL;
	IDirectSound* pDirectSound = NULL;
	IDirectSound8* pDirectSound8 = NULL;
	IDirectSoundCapture* pDirectSoundCapture = NULL;
	IMFTrustedOutput* pMFTrustedOutput = NULL;

	// IDirectSoundCapture8 == IDirectSoundCapture

	IF_FAILED_RETURN(pDevice == NULL ? E_POINTER : S_OK);

	ReleaseInfo();

	try{

		IF_FAILED_THROW(pDevice->GetId(&m_sMMDeviceInfo.lpwszID));
		IF_FAILED_THROW(pDevice->GetState(&m_sMMDeviceInfo.dwState));
		IF_FAILED_THROW(pDevice->OpenPropertyStore(STGM_READ, &pProps));
		IF_FAILED_THROW(pDevice->QueryInterface(IID_IMMEndpoint, reinterpret_cast<void**>(&pMMEndpoint)));
		IF_FAILED_THROW(pMMEndpoint->GetDataFlow(&m_sMMDeviceInfo.eAudioFlow));

		GetPropertyKeyDeviceInterfaceFriendlyName(pProps);
		GetPropertyKeyDeviceDeviceDesc(pProps);
		GetPropertyKeyDeviceFriendlyName(pProps);
		GetPropertyKeyDeviceContainerId(pProps);

		GetPropertyKeyAudioEndpointAssociation(pProps);
		GetPropertyKeyAudioEndpointControlPanelPageProvider(pProps);
		GetPropertyKeyAudioEndpointDisable_SysFx(pProps);
		GetPropertyKeyAudioEndpointFormFactor(pProps);
		GetPropertyKeyAudioEndpointFullRangeSpeakers(pProps);
		GetPropertyKeyAudioEndpointGUID(pProps);
		GetPropertyKeyAudioEndpointPhysicalSpeakers(pProps);
		GetPropertyKeyAudioEngineDeviceFormat(pProps);
		GetPropertyKeyAudioEngineOEMFormat(pProps);
		GetPropertyKeyAudioEndpointSupportsEventDrive_Mode(pProps);
		GetPropertyKeyAudioEndpointJackSubType(pProps);

		// todo : IAudioCaptureClient/ISimpleAudioVolume/... ?
		if(SUCCEEDED(pDevice->Activate(IID_IAudioClient, CLSCTX_ALL, NULL, reinterpret_cast<void**>(&pAudioClient))))
			m_sMMDeviceInfo.bIAudioClient = TRUE;
		if(SUCCEEDED(pDevice->Activate(IID_IAudioEndpointVolume, CLSCTX_ALL, NULL, reinterpret_cast<void**>(&pAudioEndpointVolume))))
			m_sMMDeviceInfo.bIAudioEndpointVolume = TRUE;
		if(SUCCEEDED(pDevice->Activate(IID_IAudioMeterInformation, CLSCTX_ALL, NULL, reinterpret_cast<void**>(&pAudioMeterInformation))))
			m_sMMDeviceInfo.bIAudioMeterInformation = TRUE;
		if(SUCCEEDED(pDevice->Activate(IID_IAudioSessionManager, CLSCTX_ALL, NULL, reinterpret_cast<void**>(&pAudioSessionManager))))
			m_sMMDeviceInfo.bIAudioSessionManager = TRUE;
		if(SUCCEEDED(pDevice->Activate(IID_IAudioSessionManager2, CLSCTX_ALL, NULL, reinterpret_cast<void**>(&pAudioSessionManager2))))
			m_sMMDeviceInfo.bIAudioSessionManager2 = TRUE;
		if(SUCCEEDED(pDevice->Activate(IID_IBaseFilter, CLSCTX_ALL, NULL, reinterpret_cast<void**>(&pBaseFilter))))
			m_sMMDeviceInfo.bIBaseFilter = TRUE;
		if(SUCCEEDED(pDevice->Activate(IID_IDeviceTopology, CLSCTX_ALL, NULL, reinterpret_cast<void**>(&pDeviceTopology))))
			m_sMMDeviceInfo.bIDeviceTopology = TRUE;
		if(SUCCEEDED(pDevice->Activate(IID_IDirectSound, CLSCTX_ALL, NULL, reinterpret_cast<void**>(&pDirectSound))))
			m_sMMDeviceInfo.bIDirectSound = TRUE;
		if(SUCCEEDED(pDevice->Activate(IID_IDirectSound8, CLSCTX_ALL, NULL, reinterpret_cast<void**>(&pDirectSound8))))
			m_sMMDeviceInfo.bIDirectSound8 = TRUE;
		if(SUCCEEDED(pDevice->Activate(IID_IDirectSoundCapture, CLSCTX_ALL, NULL, reinterpret_cast<void**>(&pDirectSoundCapture))))
			m_sMMDeviceInfo.bIDirectSoundCapture = TRUE;
		if(SUCCEEDED(pDevice->Activate(IID_IMFTrustedOutput, CLSCTX_ALL, NULL, reinterpret_cast<void**>(&pMFTrustedOutput))))
			m_sMMDeviceInfo.bIMFTrustedOutput = TRUE;

		m_sMMDeviceInfo.bIsInit = TRUE;
	}
	catch(HRESULT){}

	if(FAILED(hr))
		ReleaseInfo();

	SAFE_RELEASE(pProps);
	SAFE_RELEASE(pMMEndpoint);
	SAFE_RELEASE(pAudioClient);
	SAFE_RELEASE(pAudioEndpointVolume);
	SAFE_RELEASE(pAudioMeterInformation);
	SAFE_RELEASE(pAudioSessionManager);
	SAFE_RELEASE(pAudioSessionManager2);
	SAFE_RELEASE(pBaseFilter);
	SAFE_RELEASE(pDeviceTopology);
	SAFE_RELEASE(pDirectSound);
	SAFE_RELEASE(pDirectSound8);
	SAFE_RELEASE(pDirectSoundCapture);
	SAFE_RELEASE(pMFTrustedOutput);

	return hr;
}

void CMMDeviceInfo::LogMMDeviceInfo(){

	TRACE((L"---------------------------------------------------------------------------------------"));
	TRACE((L"MMDEVICE :"));

	if(m_sMMDeviceInfo.bIsInit == FALSE){

		TRACE((L"Not initialzed"));
	}
	else{

		TRACE((L"Audio Device ID\t\t\t\t\t\t\t%s", m_sMMDeviceInfo.lpwszID));

		TRACE_NO_END_LINE((L"Audio Device State\t\t\t\t\t\t"));

		switch(m_sMMDeviceInfo.dwState){

			case DEVICE_STATE_ACTIVE:
				TRACE((L"Active"));
				break;

			case DEVICE_STATE_DISABLED:
				TRACE((L"Disabled"));
				break;

			case DEVICE_STATE_NOTPRESENT:
				TRACE((L"Not present"));
				break;

			case DEVICE_STATE_UNPLUGGED:
				TRACE((L"Unplugged"));
				break;

			default:
				TRACE((L"Unknown"));
				break;
		}

		TRACE_NO_END_LINE((L"Audio Device DataFlow\t\t\t\t\t"));

		switch(m_sMMDeviceInfo.eAudioFlow){

			case EDataFlow::eCapture:
				TRACE((L"Capture"));
				break;

			case EDataFlow::eRender:
				TRACE((L"Render"));
				break;

			case EDataFlow::eAll:
				TRACE((L"Capture + Render"));
				break;

			case EDataFlow::EDataFlow_enum_count:
				TRACE((L"Undefined"));
				break;

			default:
				TRACE((L"Unknown"));
				break;
		}

		TRACE((L"DeviceInterfaceFriendlyName\t\t\t\t%s", m_sMMDeviceInfo.wszDeviceInterfaceFriendlyName ? m_sMMDeviceInfo.wszDeviceInterfaceFriendlyName : L"Null"));
		TRACE((L"DeviceDeviceDesc\t\t\t\t\t\t%s", m_sMMDeviceInfo.wszDeviceDeviceDesc ? m_sMMDeviceInfo.wszDeviceDeviceDesc : L"Null"));
		TRACE((L"DeviceFriendlyName\t\t\t\t\t\t%s", m_sMMDeviceInfo.wszDeviceFriendlyName ? m_sMMDeviceInfo.wszDeviceFriendlyName : L"Null"));
		TRACE((L"DeviceContainerId\t\t\t\t\t\t%s", m_sMMDeviceInfo.lpwszDeviceContainerId ? m_sMMDeviceInfo.lpwszDeviceContainerId : L"Null"));
		TRACE((L"AudioEndpointAssociation\t\t\t\t%s", m_sMMDeviceInfo.wszAudioEndpointAssociation ? m_sMMDeviceInfo.wszAudioEndpointAssociation : L"Null"));
		TRACE((L"AudioEndpointControlPanelPageProvider\t%s", m_sMMDeviceInfo.wszAudioEndpointControlPanelPageProvider ? m_sMMDeviceInfo.wszAudioEndpointControlPanelPageProvider : L"Null"));

		if(m_sMMDeviceInfo.ulAudioEndpointDisableSysFx == ULONG(-1))
			TRACE((L"AudioEndpointDisableSysFx\t\t\t\tUndefined"));
		else if(m_sMMDeviceInfo.ulAudioEndpointDisableSysFx == ENDPOINT_SYSFX_ENABLED)
			TRACE((L"AudioEndpointDisableSysFx\t\t\t\tEnable"));
		else if(m_sMMDeviceInfo.ulAudioEndpointDisableSysFx == ENDPOINT_SYSFX_DISABLED)
			TRACE((L"AudioEndpointDisableSysFx\t\t\t\tDisable"));
		else
			TRACE((L"AudioEndpointDisableSysFx\t\t\t\tError"));

		LogFormFactor(m_sMMDeviceInfo.uiAudioEndpointFormFactor);
		LogSpeaker(m_sMMDeviceInfo.uiAudioEndpointFullRangeSpeakers, L"AudioEndpointFullRangeSpeakers\t\t\t");
		TRACE((L"AudioEndpointGUID\t\t\t\t\t\t%s", m_sMMDeviceInfo.wszAudioEndpointGUID ? m_sMMDeviceInfo.wszAudioEndpointGUID : L"Null"));
		LogSpeaker(m_sMMDeviceInfo.uiAudioEndpointPhysicalSpeakers, L"AudioEndpointPhysicalSpeakers\t\t\t");		

		if(m_sMMDeviceInfo.uiAudioEndpointSupportsEventDriveMode == ULONG(-1))
			TRACE((L"AudioEndpointSupportsEventDriveMode\t\tUndefined"));
		else if(m_sMMDeviceInfo.uiAudioEndpointSupportsEventDriveMode == 0)
			TRACE((L"AudioEndpointSupportsEventDriveMode\t\tDisable"));
		else if(m_sMMDeviceInfo.uiAudioEndpointSupportsEventDriveMode == 1)
			TRACE((L"AudioEndpointSupportsEventDriveMode\t\tEnable"));
		else
			TRACE((L"AudioEndpointSupportsEventDriveMode\t\tError"));

		LogJackSubType(m_sMMDeviceInfo.wszAudioEndpointJackSubType);
		LogWaveFormatExtensible(m_sMMDeviceInfo.wfAudioEngineDeviceFormat, L"AudioEngineDeviceFormat :");
		LogWaveFormatExtensible(m_sMMDeviceInfo.wfAudioEngineOEMFormat, L"AudioEngineOEMFormat :");

		TRACE((L"Interface Support :"));
		TRACE((L"\t-> IAudioClient\t\t\t\t%s", m_sMMDeviceInfo.bIAudioClient ? L"True" : L"False"));
		TRACE((L"\t-> IAudioEndpointVolume\t\t%s", m_sMMDeviceInfo.bIAudioEndpointVolume ? L"True" : L"False"));
		TRACE((L"\t-> IAudioMeterInformation\t%s", m_sMMDeviceInfo.bIAudioMeterInformation ? L"True" : L"False"));
		TRACE((L"\t-> IAudioSessionManager\t\t%s", m_sMMDeviceInfo.bIAudioSessionManager ? L"True" : L"False"));
		TRACE((L"\t-> IAudioSessionManager2\t%s", m_sMMDeviceInfo.bIAudioSessionManager2 ? L"True" : L"False"));
		TRACE((L"\t-> IBaseFilter\t\t\t\t%s", m_sMMDeviceInfo.bIBaseFilter ? L"True" : L"False"));
		TRACE((L"\t-> IDeviceTopology\t\t\t%s", m_sMMDeviceInfo.bIDeviceTopology ? L"True" : L"False"));
		TRACE((L"\t-> IDirectSound\t\t\t\t%s", m_sMMDeviceInfo.bIDirectSound ? L"True" : L"False"));
		TRACE((L"\t-> IDirectSound8\t\t\t%s", m_sMMDeviceInfo.bIDirectSound8 ? L"True" : L"False"));
		TRACE((L"\t-> IDirectSoundCapture\t\t%s", m_sMMDeviceInfo.bIDirectSoundCapture ? L"True" : L"False"));
		TRACE((L"\t-> IMFTrustedOutput\t\t\t%s", m_sMMDeviceInfo.bIMFTrustedOutput ? L"True" : L"False"));
	}

	TRACE((L"---------------------------------------------------------------------------------------"));
}

void CMMDeviceInfo::GetPropertyKeyDeviceInterfaceFriendlyName(IPropertyStore* pProps){

	HRESULT hr = S_OK;
	PROPVARIANT varName;
	PropVariantInit(&varName);

	hr = pProps->GetValue(PKEY_DeviceInterface_FriendlyName, &varName);

	if(SUCCEEDED(hr)){

		if(varName.vt == VT_LPWSTR){

			size_t sz = wcslen(varName.pwszVal);

			if(sz > 0){

				m_sMMDeviceInfo.wszDeviceInterfaceFriendlyName = new (std::nothrow)WCHAR[sz + 1];

				if(m_sMMDeviceInfo.wszDeviceInterfaceFriendlyName){

					wmemcpy(m_sMMDeviceInfo.wszDeviceInterfaceFriendlyName, varName.pwszVal, sz);
					m_sMMDeviceInfo.wszDeviceInterfaceFriendlyName[sz] = '\0';
				}
			}
		}
		else if(varName.vt == VT_EMPTY){

			// todo : error
		}
	}

	PropVariantClear(&varName);
}

void CMMDeviceInfo::GetPropertyKeyDeviceDeviceDesc(IPropertyStore* pProps){

	HRESULT hr = S_OK;
	PROPVARIANT varName;
	PropVariantInit(&varName);

	hr = pProps->GetValue(PKEY_Device_DeviceDesc, &varName);

	if(SUCCEEDED(hr)){

		if(varName.vt == VT_LPWSTR){

			size_t sz = wcslen(varName.pwszVal);

			if(sz > 0){

				m_sMMDeviceInfo.wszDeviceDeviceDesc = new (std::nothrow)WCHAR[sz + 1];

				if(m_sMMDeviceInfo.wszDeviceDeviceDesc){

					wmemcpy(m_sMMDeviceInfo.wszDeviceDeviceDesc, varName.pwszVal, sz);
					m_sMMDeviceInfo.wszDeviceDeviceDesc[sz] = '\0';
				}
			}
		}
		else if(varName.vt == VT_EMPTY){

			// todo : error
		}
	}

	PropVariantClear(&varName);
}

void CMMDeviceInfo::GetPropertyKeyDeviceFriendlyName(IPropertyStore* pProps){

	HRESULT hr = S_OK;
	PROPVARIANT varName;
	PropVariantInit(&varName);

	hr = pProps->GetValue(PKEY_Device_FriendlyName, &varName);

	if(SUCCEEDED(hr)){

		if(varName.vt == VT_LPWSTR){

			size_t sz = wcslen(varName.pwszVal);

			if(sz > 0){

				m_sMMDeviceInfo.wszDeviceFriendlyName = new (std::nothrow)WCHAR[sz + 1];

				if(m_sMMDeviceInfo.wszDeviceFriendlyName){

					wmemcpy(m_sMMDeviceInfo.wszDeviceFriendlyName, varName.pwszVal, sz);
					m_sMMDeviceInfo.wszDeviceFriendlyName[sz] = '\0';
				}
			}
		}
		else if(varName.vt == VT_EMPTY){

			// todo : error
		}
	}

	PropVariantClear(&varName);
}

void CMMDeviceInfo::GetPropertyKeyDeviceContainerId(IPropertyStore* pProps){

	HRESULT hr = S_OK;
	PROPVARIANT varName;
	PropVariantInit(&varName);

	hr = pProps->GetValue(PKEY_Device_ContainerId, &varName);

	if(SUCCEEDED(hr)){

		if(varName.vt == VT_CLSID){

			StringFromCLSID((const IID&)varName.puuid, &m_sMMDeviceInfo.lpwszDeviceContainerId);
		}
		else if(varName.vt == VT_EMPTY){

			// todo : error
		}
	}

	PropVariantClear(&varName);
}

void CMMDeviceInfo::GetPropertyKeyAudioEndpointAssociation(IPropertyStore* pProps){

	HRESULT hr = S_OK;
	PROPVARIANT varName;
	PropVariantInit(&varName);

	hr = pProps->GetValue(PKEY_AudioEndpoint_Association, &varName);

	if(SUCCEEDED(hr)){

		if(varName.vt == VT_LPWSTR){

			size_t sz = wcslen(varName.pwszVal);

			if(sz > 0){

				m_sMMDeviceInfo.wszAudioEndpointAssociation = new (std::nothrow)WCHAR[sz + 1];

				if(m_sMMDeviceInfo.wszAudioEndpointAssociation){

					wmemcpy(m_sMMDeviceInfo.wszAudioEndpointAssociation, varName.pwszVal, sz);
					m_sMMDeviceInfo.wszAudioEndpointAssociation[sz] = '\0';
				}
			}
		}
		else if(varName.vt == VT_EMPTY){

			// todo : error
		}
	}

	PropVariantClear(&varName);
}

void CMMDeviceInfo::GetPropertyKeyAudioEndpointControlPanelPageProvider(IPropertyStore* pProps){

	HRESULT hr = S_OK;
	PROPVARIANT varName;
	PropVariantInit(&varName);

	hr = pProps->GetValue(PKEY_AudioEndpoint_ControlPanelPageProvider, &varName);

	if(SUCCEEDED(hr)){

		if(varName.vt == VT_LPWSTR){

			size_t sz = wcslen(varName.pwszVal);

			if(sz > 0){

				m_sMMDeviceInfo.wszAudioEndpointControlPanelPageProvider = new (std::nothrow)WCHAR[sz + 1];

				if(m_sMMDeviceInfo.wszAudioEndpointControlPanelPageProvider){

					wmemcpy(m_sMMDeviceInfo.wszAudioEndpointControlPanelPageProvider, varName.pwszVal, sz);
					m_sMMDeviceInfo.wszAudioEndpointControlPanelPageProvider[sz] = '\0';
				}
			}
		}
		else if(varName.vt != VT_EMPTY){

			// todo : error
		}
	}

	PropVariantClear(&varName);
}

void CMMDeviceInfo::GetPropertyKeyAudioEndpointDisable_SysFx(IPropertyStore* pProps){

	HRESULT hr = S_OK;
	PROPVARIANT varName;
	PropVariantInit(&varName);

	hr = pProps->GetValue(PKEY_AudioEndpoint_Disable_SysFx, &varName);

	if(SUCCEEDED(hr)){

		if(varName.vt == VT_UI4){

			m_sMMDeviceInfo.ulAudioEndpointDisableSysFx = varName.ulVal;
		}
		else if(varName.vt != VT_EMPTY){

			// todo : error
		}
	}

	PropVariantClear(&varName);
}

void CMMDeviceInfo::GetPropertyKeyAudioEndpointFormFactor(IPropertyStore* pProps){

	HRESULT hr = S_OK;
	PROPVARIANT varName;
	PropVariantInit(&varName);

	hr = pProps->GetValue(PKEY_AudioEndpoint_FormFactor, &varName);

	if(SUCCEEDED(hr)){

		if(varName.vt == VT_UI4){

			m_sMMDeviceInfo.uiAudioEndpointFormFactor = varName.uintVal;
		}
		else if(varName.vt != VT_EMPTY){

			// todo : error
		}
	}

	PropVariantClear(&varName);
}

void CMMDeviceInfo::GetPropertyKeyAudioEndpointFullRangeSpeakers(IPropertyStore* pProps){

	HRESULT hr = S_OK;
	PROPVARIANT varName;
	PropVariantInit(&varName);

	hr = pProps->GetValue(PKEY_AudioEndpoint_FullRangeSpeakers, &varName);

	if(SUCCEEDED(hr)){

		if(varName.vt == VT_UI4){

			m_sMMDeviceInfo.uiAudioEndpointFullRangeSpeakers = varName.uintVal;
		}
		else if(varName.vt != VT_EMPTY){

			// todo : error
		}
	}

	PropVariantClear(&varName);
}

void CMMDeviceInfo::GetPropertyKeyAudioEndpointGUID(IPropertyStore* pProps){

	HRESULT hr = S_OK;
	PROPVARIANT varName;
	PropVariantInit(&varName);

	hr = pProps->GetValue(PKEY_AudioEndpoint_GUID, &varName);

	if(SUCCEEDED(hr)){

		if(varName.vt == VT_LPWSTR){

			size_t sz = wcslen(varName.pwszVal);

			if(sz > 0){

				m_sMMDeviceInfo.wszAudioEndpointGUID = new (std::nothrow)WCHAR[sz + 1];

				if(m_sMMDeviceInfo.wszAudioEndpointGUID){

					wmemcpy(m_sMMDeviceInfo.wszAudioEndpointGUID, varName.pwszVal, sz);
					m_sMMDeviceInfo.wszAudioEndpointGUID[sz] = '\0';
				}
			}
		}
		else if(varName.vt != VT_EMPTY){

			// todo : error
		}
	}

	PropVariantClear(&varName);
}

void CMMDeviceInfo::GetPropertyKeyAudioEndpointPhysicalSpeakers(IPropertyStore* pProps){

	HRESULT hr = S_OK;
	PROPVARIANT varName;
	PropVariantInit(&varName);

	hr = pProps->GetValue(PKEY_AudioEndpoint_PhysicalSpeakers, &varName);

	if(SUCCEEDED(hr)){

		if(varName.vt == VT_UI4){

			m_sMMDeviceInfo.uiAudioEndpointPhysicalSpeakers = varName.uintVal;
		}
		else if(varName.vt != VT_EMPTY){

			// todo : error
		}
	}

	PropVariantClear(&varName);
}

void CMMDeviceInfo::GetPropertyKeyAudioEngineDeviceFormat(IPropertyStore* pProps){

	HRESULT hr = S_OK;
	PROPVARIANT varName;
	PropVariantInit(&varName);

	hr = pProps->GetValue(PKEY_AudioEngine_DeviceFormat, &varName);

	if(SUCCEEDED(hr)){

		if(varName.vt == VT_BLOB){

			int iTest = sizeof(WAVEFORMATEX);
			iTest = sizeof(WAVEFORMATEXTENSIBLE);

			if(varName.blob.cbSize == sizeof(WAVEFORMATEXTENSIBLE)){

				memcpy(&m_sMMDeviceInfo.wfAudioEngineDeviceFormat, varName.blob.pBlobData, sizeof(WAVEFORMATEXTENSIBLE));
			}
			else if(varName.blob.cbSize == sizeof(WAVEFORMATEX)){

				// todo
			}
			else{

				// todo : error
			}
		}
		else if(varName.vt != VT_EMPTY){

			// todo : error
		}
	}

	PropVariantClear(&varName);
}

void CMMDeviceInfo::GetPropertyKeyAudioEngineOEMFormat(IPropertyStore* pProps){

	HRESULT hr = S_OK;
	PROPVARIANT varName;
	PropVariantInit(&varName);

	hr = pProps->GetValue(PKEY_AudioEngine_OEMFormat, &varName);

	if(SUCCEEDED(hr)){

		if(varName.vt == VT_BLOB){

			int iTest = sizeof(WAVEFORMATEX);
			iTest = sizeof(WAVEFORMATEXTENSIBLE);

			if(varName.blob.cbSize == sizeof(WAVEFORMATEXTENSIBLE)){

				memcpy(&m_sMMDeviceInfo.wfAudioEngineOEMFormat, varName.blob.pBlobData, sizeof(WAVEFORMATEXTENSIBLE));
			}
			else if(varName.blob.cbSize == sizeof(WAVEFORMATEX)){

				// todo
			}
			else{

				// todo : error
			}
		}
		else if(varName.vt != VT_EMPTY){

			// todo : error
		}
	}

	PropVariantClear(&varName);
}

void CMMDeviceInfo::GetPropertyKeyAudioEndpointSupportsEventDrive_Mode(IPropertyStore* pProps){

	HRESULT hr = S_OK;
	PROPVARIANT varName;
	PropVariantInit(&varName);

	hr = pProps->GetValue(PKEY_AudioEndpoint_Supports_EventDriven_Mode, &varName);

	if(SUCCEEDED(hr)){

		if(varName.vt == VT_UI4){

			m_sMMDeviceInfo.uiAudioEndpointSupportsEventDriveMode = varName.uintVal;
		}
		else if(varName.vt != VT_EMPTY){

			// todo : error
		}
	}

	PropVariantClear(&varName);
}

void CMMDeviceInfo::GetPropertyKeyAudioEndpointJackSubType(IPropertyStore* pProps){

	HRESULT hr = S_OK;
	PROPVARIANT varName;
	PropVariantInit(&varName);

	hr = pProps->GetValue(PKEY_AudioEndpoint_JackSubType, &varName);

	if(SUCCEEDED(hr)){

		if(varName.vt == VT_LPWSTR){

			size_t sz = wcslen(varName.pwszVal);

			if(sz > 0){

				m_sMMDeviceInfo.wszAudioEndpointJackSubType = new (std::nothrow)WCHAR[sz + 1];

				if(m_sMMDeviceInfo.wszAudioEndpointJackSubType){

					wmemcpy(m_sMMDeviceInfo.wszAudioEndpointJackSubType, varName.pwszVal, sz);
					m_sMMDeviceInfo.wszAudioEndpointJackSubType[sz] = '\0';
				}
			}
		}
		else if(varName.vt != VT_EMPTY){

			// todo : error
		}
	}

	PropVariantClear(&varName);
}

void CMMDeviceInfo::LogFormFactor(const UINT uiFormFactor){

	TRACE_NO_END_LINE((L"AudioEndpointFormFactor :\t\t\t\t"));

	switch(uiFormFactor){

		case EndpointFormFactor::RemoteNetworkDevice:
			TRACE((L"RemoteNetworkDevice"));
			break;

		case EndpointFormFactor::Speakers:
			TRACE((L"Speakers"));
			break;

		case EndpointFormFactor::LineLevel:
			TRACE((L"LineLevel"));
			break;

		case EndpointFormFactor::Headphones:
			TRACE((L"Headphones"));
			break;

		case EndpointFormFactor::Microphone:
			TRACE((L"Microphone"));
			break;

		case EndpointFormFactor::Headset:
			TRACE((L"Headset"));
			break;

		case EndpointFormFactor::Handset:
			TRACE((L"Handset"));
			break;

		case EndpointFormFactor::UnknownDigitalPassthrough:
			TRACE((L"UnknownDigitalPassthrough"));
			break;

		case EndpointFormFactor::SPDIF:
			TRACE((L"SPDIF"));
			break;

		case EndpointFormFactor::DigitalAudioDisplayDevice:
			TRACE((L"DigitalAudioDisplayDevice"));
			break;

		case EndpointFormFactor::EndpointFormFactor_enum_count:
			TRACE((L"EndpointFormFactor_enum_count"));
			break;

		default:
			TRACE((L"Unknown"));
			break;
	}
}

void CMMDeviceInfo::LogWaveFormatExtensible(const WAVEFORMATEXTENSIBLE& waveFormat, LPCWSTR lpcszPropertyName){

	TRACE((lpcszPropertyName));

	// WAVE_FORMAT_PCM
	// WAVE_FORMAT_IEEE_FLOAT
	// WAVE_FORMAT_DRM
	// WAVE_FORMAT_EXTENSIBLE
	// WAVE_FORMAT_ALAW
	// WAVE_FORMAT_MULAW
	// WAVE_FORMAT_ADPCM
	// WAVE_FORMAT_MPEG
	// WAVE_FORMAT_DOLBY_AC3_SPDIF
	// WAVE_FORMAT_WMASPDIF
	if(waveFormat.Format.wFormatTag == WAVE_FORMAT_UNKNOWN){

		TRACE((L"\t-> Undefined or Unknown format tag"));
	}
	else if(waveFormat.Format.wFormatTag == WAVE_FORMAT_EXTENSIBLE){

		TRACE((L"\t-> Channels\t\t\t\t%d", waveFormat.Format.nChannels));
		TRACE((L"\t-> SamplesPerSec\t\t%d", waveFormat.Format.nSamplesPerSec));
		TRACE((L"\t-> AvgBytesPerSec\t\t%d", waveFormat.Format.nAvgBytesPerSec));
		TRACE((L"\t-> BlockAlign\t\t\t%d", waveFormat.Format.nBlockAlign));
		TRACE((L"\t-> BitsPerSample\t\t%d", waveFormat.Format.wBitsPerSample));
		TRACE((L"\t-> Size (22)\t\t\t%d", waveFormat.Format.cbSize));
		TRACE((L"\t-> ValidBitsPerSample\t%d", waveFormat.Samples.wValidBitsPerSample));
		TRACE((L"\t-> SamplesPerBlock\t\t%d", waveFormat.Samples.wSamplesPerBlock));
		TRACE((L"\t-> Reserved\t\t\t\t%d", waveFormat.Samples.wReserved));
		LogSpeaker(waveFormat.dwChannelMask, L"\t-> Channel Mask\t\t\t");

		TRACE_NO_END_LINE((L"\t-> SubFormat Guid\t\t"));

		// SubFormat GUID
		// WAVE_FORMAT_PCM == MEDIASUBTYPE_PCM
		// WAVE_FORMAT_IEEE_FLOAT
		// WAVE_FORMAT_DRM
		// WAVE_FORMAT_ALAW
		// WAVE_FORMAT_MULAW
		// WAVE_FORMAT_ADPCM
		if(waveFormat.SubFormat == WMMEDIASUBTYPE_PCM){

			TRACE((L"MEDIASUBTYPE_PCM"));
		}
		else{

			LPWSTR pwszID = NULL;
			StringFromCLSID(waveFormat.SubFormat, &pwszID);
			TRACE((L"%s", pwszID));
			CoTaskMemFree(pwszID);
		}
	}
	else{

		TRACE((L"\t-> Unknown wave format tag"));
	}
}

void CMMDeviceInfo::LogJackSubType(LPCWSTR wstrGuid){

	// see LogKsNodeType : similar
	TRACE_NO_END_LINE((L"AudioEndpointJackSubType\t\t\t\t"));

	if(wstrGuid){

		GUID guid = GUID_NULL;

		if(SUCCEEDED(CLSIDFromString(wstrGuid, &guid))){

			if(guid == KSNODETYPE_SPEAKER)
				TRACE((L"SPEAKER"));
			else if(guid == KSNODETYPE_DIGITAL_AUDIO_INTERFACE)
				TRACE((L"DIGITAL_AUDIO_INTERFACE"));
			else if(guid == KSNODETYPE_MICROPHONE)
				TRACE((L"MICROPHONE"));
			else if(guid == KSNODETYPE_LINE_CONNECTOR)
				TRACE((L"LINE_CONNECTOR"));
			else if(guid == KSNODETYPE_ANALOG_CONNECTOR)
				TRACE((L"ANALOG_CONNECTOR"));
			else
				TRACE((L"Unknown guid : %s", wstrGuid));
		}
		else{

			TRACE((L"%s", wstrGuid));
		}
	}
	else{

		TRACE((L"Null"));
	}
}