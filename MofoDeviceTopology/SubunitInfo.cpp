//----------------------------------------------------------------------------------------------
// SubunitInfo.cpp
//----------------------------------------------------------------------------------------------
#include "StdAfx.h"

HRESULT CSubunitInfo::InitializeSubunitInfo(IPart* pPart){

	HRESULT hr = S_OK;
	IAudioAutoGainControl* pAudioAutoGainControl = NULL;
	IAudioBass* pAudioBass = NULL;
	IAudioChannelConfig* pAudioChannelConfig = NULL;
	IAudioInputSelector* pAudioInputSelector = NULL;
	IAudioLoudness* pAudioLoudness = NULL;
	IAudioMidrange* pAudioMidrange = NULL;
	IAudioMute* pAudioMute = NULL;
	IAudioOutputSelector* pAudioOutputSelector = NULL;
	IAudioPeakMeter* pAudioPeakMeter = NULL;
	IAudioTreble* pAudioTreble = NULL;
	IAudioVolumeLevel* pAudioVolumeLevel = NULL;
	IDeviceSpecificProperty* pDeviceSpecificProperty = NULL;
	IKsFormatSupport* pKsFormatSupport = NULL;
	IKsJackDescription* pKsJackDescription = NULL;
	IKsJackDescription2* pKsJackDescription2 = NULL;

	ZeroMemory(&m_sSubunitInfo, sizeof(SSubunitInfo));

	IF_FAILED_RETURN(pPart == NULL ? E_POINTER : S_OK);

	try{

		IF_FAILED_THROW(pPart->GetGlobalId(&m_sSubunitInfo.lpwszGlobalId));
		IF_FAILED_THROW(pPart->GetLocalId(&m_sSubunitInfo.uiLocalId));
		IF_FAILED_THROW(pPart->GetName(&m_sSubunitInfo.lpwszName));
		IF_FAILED_THROW(pPart->GetControlInterfaceCount(&m_sSubunitInfo.uiControlInterfaceCount));
		IF_FAILED_THROW(pPart->GetSubType(&m_sSubunitInfo.guidSubType));
		IF_FAILED_THROW(pPart->GetPartType(&m_sSubunitInfo.partType));

		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioAutoGainControl, reinterpret_cast<void**>(&pAudioAutoGainControl)))){

			pAudioAutoGainControl->GetEnabled(&m_sSubunitInfo.bAutoGainEnable);
			m_sSubunitInfo.bIAudioAutoGainControl = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioBass, reinterpret_cast<void**>(&pAudioBass)))){

			m_sSubunitInfo.bIAudioBass = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioChannelConfig, reinterpret_cast<void**>(&pAudioChannelConfig)))){

			m_sSubunitInfo.bIAudioChannelConfig = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioInputSelector, reinterpret_cast<void**>(&pAudioInputSelector)))){

			m_sSubunitInfo.bIAudioInputSelector = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioLoudness, reinterpret_cast<void**>(&pAudioLoudness)))){

			m_sSubunitInfo.bIAudioLoudness = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioMidrange, reinterpret_cast<void**>(&pAudioMidrange)))){

			m_sSubunitInfo.bIAudioMidrange = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioMute, reinterpret_cast<void**>(&pAudioMute)))){

			pAudioMute->GetMute(&m_sSubunitInfo.bMuted);
			m_sSubunitInfo.bIAudioMute = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioOutputSelector, reinterpret_cast<void**>(&pAudioOutputSelector)))){

			m_sSubunitInfo.bIAudioOutputSelector = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioPeakMeter, reinterpret_cast<void**>(&pAudioPeakMeter)))){

			m_sSubunitInfo.bIAudioPeakMeter = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioTreble, reinterpret_cast<void**>(&pAudioTreble)))){

			m_sSubunitInfo.bIAudioTreble = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioVolumeLevel, reinterpret_cast<void**>(&pAudioVolumeLevel)))){

			// todo : IPerChannelDbLevel : GetLevel/GetLevelRange
			pAudioVolumeLevel->GetChannelCount(&m_sSubunitInfo.uiChannelCount);
			m_sSubunitInfo.bIAudioVolumeLevel = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IDeviceSpecificProperty, reinterpret_cast<void**>(&pDeviceSpecificProperty)))){

			m_sSubunitInfo.bIDeviceSpecificProperty = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IKsFormatSupport, reinterpret_cast<void**>(&pKsFormatSupport)))){

			m_sSubunitInfo.bIKsFormatSupport = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IKsJackDescription, reinterpret_cast<void**>(&pKsJackDescription)))){

			pKsJackDescription->GetJackCount(&m_sSubunitInfo.uiJackCount);
			m_sSubunitInfo.bIKsJackDescription = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IKsJackDescription2, reinterpret_cast<void**>(&pKsJackDescription2)))){

			pKsJackDescription2->GetJackCount(&m_sSubunitInfo.uiJackCount2);
			m_sSubunitInfo.bIKsJackDescription2 = TRUE;
		}

		m_sSubunitInfo.bIsInit = TRUE;
	}
	catch(HRESULT){}

	if(FAILED(hr))
		ClearSubunitInfo();

	SAFE_RELEASE(pAudioAutoGainControl);
	SAFE_RELEASE(pAudioBass);
	SAFE_RELEASE(pAudioChannelConfig);
	SAFE_RELEASE(pAudioInputSelector);
	SAFE_RELEASE(pAudioLoudness);
	SAFE_RELEASE(pAudioMidrange);
	SAFE_RELEASE(pAudioMute);
	SAFE_RELEASE(pAudioOutputSelector);
	SAFE_RELEASE(pAudioPeakMeter);
	SAFE_RELEASE(pAudioTreble);
	SAFE_RELEASE(pAudioVolumeLevel);
	SAFE_RELEASE(pDeviceSpecificProperty);
	SAFE_RELEASE(pKsFormatSupport);
	SAFE_RELEASE(pKsJackDescription);
	SAFE_RELEASE(pKsJackDescription2);

	return hr;
}

void CSubunitInfo::LogSubunitInfo(){

	TRACE((L"---------------------------------------------------------------------------------------"));
	TRACE((L"SUBUNIT TOPOLOGY :"));

	if(m_sSubunitInfo.bIsInit == FALSE){

		TRACE((L"Not initialzed"));
	}
	else{

		TRACE((L"Subunit IPart Global Id\t\t\t%s", m_sSubunitInfo.lpwszGlobalId ? m_sSubunitInfo.lpwszGlobalId : L"Null"));
		TRACE((L"Subunit IPart Local Id\t\t\t%d", m_sSubunitInfo.uiLocalId));
		TRACE((L"Subunit IPart Name\t\t\t\t%s", m_sSubunitInfo.lpwszName ? m_sSubunitInfo.lpwszName : L"Null"));
		TRACE((L"Subunit IPart IControl count\t%d", m_sSubunitInfo.uiControlInterfaceCount));
		LogKsNodeType(m_sSubunitInfo.guidSubType, L"Subunit Ipart SubType Guid\t\t");

		TRACE_NO_END_LINE((L"IPart Type\t\t\t\t\t\t"));

		switch(m_sSubunitInfo.partType){

			case PartType::Connector:
				TRACE((L"Connector"));
				break;

			case PartType::Subunit:
				TRACE((L"Subunit"));
				break;

			default:
				TRACE((L"Unknown PartType Type"));
				break;
		}

		TRACE((L"Interface Support :"));
		TRACE((L"\t-> IAudioAutoGainControl\t%s", m_sSubunitInfo.bIAudioAutoGainControl ? L"True" : L"False"));
		TRACE((L"\t-> IAudioBass\t\t\t\t%s", m_sSubunitInfo.bIAudioBass ? L"True" : L"False"));
		TRACE((L"\t-> IAudioChannelConfig\t\t%s", m_sSubunitInfo.bIAudioChannelConfig ? L"True" : L"False"));
		TRACE((L"\t-> IAudioInputSelector\t\t%s", m_sSubunitInfo.bIAudioInputSelector ? L"True" : L"False"));
		TRACE((L"\t-> IAudioLoudness\t\t\t%s", m_sSubunitInfo.bIAudioLoudness ? L"True" : L"False"));
		TRACE((L"\t-> IAudioMidrange\t\t\t%s", m_sSubunitInfo.bIAudioMidrange ? L"True" : L"False"));
		TRACE((L"\t-> IAudioMute\t\t\t\t%s", m_sSubunitInfo.bIAudioMute ? L"True" : L"False"));
		TRACE((L"\t-> IAudioOutputSelector\t\t%s", m_sSubunitInfo.bIAudioOutputSelector ? L"True" : L"False"));
		TRACE((L"\t-> IAudioPeakMeter\t\t\t%s", m_sSubunitInfo.bIAudioPeakMeter ? L"True" : L"False"));
		TRACE((L"\t-> IAudioTreble\t\t\t\t%s", m_sSubunitInfo.bIAudioTreble ? L"True" : L"False"));
		TRACE((L"\t-> IAudioVolumeLevel\t\t%s", m_sSubunitInfo.bIAudioVolumeLevel ? L"True" : L"False"));
		TRACE((L"\t-> IDeviceSpecificProperty\t%s", m_sSubunitInfo.bIDeviceSpecificProperty ? L"True" : L"False"));
		TRACE((L"\t-> IKsFormatSupport\t\t\t%s", m_sSubunitInfo.bIKsFormatSupport ? L"True" : L"False"));
		TRACE((L"\t-> IKsJackDescription\t\t%s", m_sSubunitInfo.bIKsJackDescription ? L"True" : L"False"));
		TRACE((L"\t-> IKsJackDescription2\t\t%s", m_sSubunitInfo.bIKsJackDescription2 ? L"True" : L"False"));

		if(m_sSubunitInfo.bIAudioAutoGainControl)
			TRACE((L"\t-> AudioAutoGainControl :\n\t\t-> Auto Gain Control\t%s", m_sSubunitInfo.bAutoGainEnable ? L"True" : L"False"));
		if(m_sSubunitInfo.bIAudioMute)
			TRACE((L"\t-> AudioMute :\n\t\t-> Enable\t%s", m_sSubunitInfo.bMuted ? L"True" : L"False"));
		if(m_sSubunitInfo.bIAudioVolumeLevel)
			TRACE((L"\t-> AudioVolumeLevel :\n\t\t-> Channel Count\t%d", m_sSubunitInfo.uiChannelCount));

		// Normally apply to connector
		if(m_sSubunitInfo.bIKsJackDescription)
			TRACE((L"\t-> JackDescription :\n\t\t-> Jack Count : %d", m_sSubunitInfo.uiJackCount));
		if(m_sSubunitInfo.bIKsJackDescription2)
			TRACE((L"\t-> JackDescription2 :\n\t\t-> Jack Count : %d", m_sSubunitInfo.uiJackCount2));
	}

	TRACE((L"---------------------------------------------------------------------------------------"));
}