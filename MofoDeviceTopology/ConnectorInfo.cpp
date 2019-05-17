//----------------------------------------------------------------------------------------------
// ConnectorInfo.cpp
//----------------------------------------------------------------------------------------------
#include "StdAfx.h"

HRESULT CConnectorInfo::InitializeConnectorInfo(IConnector* pConnector){

	HRESULT hr = S_OK;
	IPart* pPart = NULL;

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

	ClearConnectorInfo();

	IF_FAILED_RETURN(pConnector == NULL ? E_POINTER : S_OK);

	try{

		IF_FAILED_THROW(pConnector->IsConnected(&m_sConnectorInfo.bIsConnected));
		IF_FAILED_THROW(pConnector->GetType(&m_sConnectorInfo.connectorType));
		IF_FAILED_THROW(pConnector->GetDataFlow(&m_sConnectorInfo.dataFlow));

		if(m_sConnectorInfo.connectorType != ConnectorType::Software_IO){

			// todo : handle E_NOTFOUND for Software_IO
			IF_FAILED_THROW(pConnector->GetConnectorIdConnectedTo(&m_sConnectorInfo.lpwszConnectorIdConnectedTo));
			IF_FAILED_THROW(pConnector->GetDeviceIdConnectedTo(&m_sConnectorInfo.lpwszDeviceIdConnectedTo));
		}

		IF_FAILED_THROW(pConnector->QueryInterface(IID_IPart, reinterpret_cast<void**>(&pPart)));
		IF_FAILED_THROW(pPart->GetGlobalId(&m_sConnectorInfo.lpwszGlobalId));
		IF_FAILED_THROW(pPart->GetLocalId(&m_sConnectorInfo.uiLocalId));
		IF_FAILED_THROW(pPart->GetName(&m_sConnectorInfo.lpwszName));
		IF_FAILED_THROW(pPart->GetControlInterfaceCount(&m_sConnectorInfo.uiControlInterfaceCount));
		IF_FAILED_THROW(pPart->GetSubType(&m_sConnectorInfo.guidSubType));
		IF_FAILED_THROW(pPart->GetPartType(&m_sConnectorInfo.partType));

		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioAutoGainControl, reinterpret_cast<void**>(&pAudioAutoGainControl)))){

			m_sConnectorInfo.bIAudioAutoGainControl = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioBass, reinterpret_cast<void**>(&pAudioBass)))){

			m_sConnectorInfo.bIAudioBass = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioChannelConfig, reinterpret_cast<void**>(&pAudioChannelConfig)))){

			m_sConnectorInfo.bIAudioChannelConfig = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioInputSelector, reinterpret_cast<void**>(&pAudioInputSelector)))){

			m_sConnectorInfo.bIAudioInputSelector = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioLoudness, reinterpret_cast<void**>(&pAudioLoudness)))){

			m_sConnectorInfo.bIAudioLoudness = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioMidrange, reinterpret_cast<void**>(&pAudioMidrange)))){

			m_sConnectorInfo.bIAudioMidrange = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioMute, reinterpret_cast<void**>(&pAudioMute)))){

			m_sConnectorInfo.bIAudioMute = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioOutputSelector, reinterpret_cast<void**>(&pAudioOutputSelector)))){

			m_sConnectorInfo.bIAudioOutputSelector = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioPeakMeter, reinterpret_cast<void**>(&pAudioPeakMeter)))){

			m_sConnectorInfo.bIAudioPeakMeter = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioTreble, reinterpret_cast<void**>(&pAudioTreble)))){

			m_sConnectorInfo.bIAudioTreble = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IAudioVolumeLevel, reinterpret_cast<void**>(&pAudioVolumeLevel)))){

			m_sConnectorInfo.bIAudioVolumeLevel = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IDeviceSpecificProperty, reinterpret_cast<void**>(&pDeviceSpecificProperty)))){

			m_sConnectorInfo.bIDeviceSpecificProperty = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IKsFormatSupport, reinterpret_cast<void**>(&pKsFormatSupport)))){

			GetKsFormat(pKsFormatSupport);
			m_sConnectorInfo.bIKsFormatSupport = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IKsJackDescription, reinterpret_cast<void**>(&pKsJackDescription)))){

			m_cJackDescription.InitializeJackDescriptionInfo(pKsJackDescription);
			m_sConnectorInfo.bIKsJackDescription = TRUE;
		}
		if(SUCCEEDED(pPart->Activate(CLSCTX_ALL, IID_IKsJackDescription2, reinterpret_cast<void**>(&pKsJackDescription2)))){

			m_cJackDescription.InitializeJackDescription2Info(pKsJackDescription2);
			m_sConnectorInfo.bIKsJackDescription2 = TRUE;
		}

		m_sConnectorInfo.bIsInit = TRUE;
	}
	catch(HRESULT){}

	if(FAILED(hr))
		ClearConnectorInfo();

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

	SAFE_RELEASE(pPart);

	return hr;
}

void CConnectorInfo::LogConnectorInfo(){

	TRACE((L"---------------------------------------------------------------------------------------"));
	TRACE((L"CONNECTOR TOPOLOGY :"));

	if(m_sConnectorInfo.bIsInit == FALSE){

		TRACE((L"Not initialzed"));
	}
	else{

		TRACE((L"Connected\t\t\t\t\t\t\t%s", m_sConnectorInfo.bIsConnected ? L"True" : L"False"));
		TRACE_NO_END_LINE((L"Connector Type\t\t\t\t\t\t"));

		switch(m_sConnectorInfo.connectorType){

			case ConnectorType::Unknown_Connector:
				TRACE((L"Unknown_Connector"));
				break;

			case ConnectorType::Physical_Internal:
				TRACE((L"Physical_Internal"));
				break;

			case ConnectorType::Physical_External:
				TRACE((L"Physical_External"));
				break;

			case ConnectorType::Software_IO:
				TRACE((L"Software_IO"));
				break;

			case ConnectorType::Software_Fixed:
				TRACE((L"Software_Fixed"));
				break;

			case ConnectorType::Network:
				TRACE((L"Network"));
				break;

			default:
				TRACE((L"Unknown"));
				break;
		}

		TRACE_NO_END_LINE((L"Connector DataFlow\t\t\t\t\t"));

		switch(m_sConnectorInfo.dataFlow){

			case DataFlow::In:
				TRACE((L"In"));
				break;

			case DataFlow::Out:
				TRACE((L"Out"));
				break;

			default:
				TRACE((L"Unknown DataFlow Type"));
				break;
		}

		TRACE((L"Connector Id Connected To\t\t\t%s", m_sConnectorInfo.lpwszConnectorIdConnectedTo ? m_sConnectorInfo.lpwszConnectorIdConnectedTo : L"Null"));
		TRACE((L"Connector Device Id Connected To\t%s", m_sConnectorInfo.lpwszDeviceIdConnectedTo ? m_sConnectorInfo.lpwszDeviceIdConnectedTo : L"Null"));
		TRACE((L"Connector IPart Global Id\t\t\t%s", m_sConnectorInfo.lpwszGlobalId ? m_sConnectorInfo.lpwszGlobalId : L"Null"));
		TRACE((L"Connector IPart Local Id\t\t\t%d", m_sConnectorInfo.uiLocalId));
		TRACE((L"Connector IPart Name\t\t\t\t%s", m_sConnectorInfo.lpwszName ? m_sConnectorInfo.lpwszName : L"Null"));
		TRACE((L"Connector IPart IControl count\t\t%d", m_sConnectorInfo.uiControlInterfaceCount));
		LogKsNodeType(m_sConnectorInfo.guidSubType, L"Connector Ipart SubType Guid\t\t");

		TRACE_NO_END_LINE((L"IPart Type\t\t\t\t\t\t\t"));

		switch(m_sConnectorInfo.partType){

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
		TRACE((L"\t-> IAudioAutoGainControl\t%s", m_sConnectorInfo.bIAudioAutoGainControl ? L"True" : L"False"));
		TRACE((L"\t-> IAudioBass\t\t\t\t%s", m_sConnectorInfo.bIAudioBass ? L"True" : L"False"));
		TRACE((L"\t-> IAudioChannelConfig\t\t%s", m_sConnectorInfo.bIAudioChannelConfig ? L"True" : L"False"));
		TRACE((L"\t-> IAudioInputSelector\t\t%s", m_sConnectorInfo.bIAudioInputSelector ? L"True" : L"False"));
		TRACE((L"\t-> IAudioLoudness\t\t\t%s", m_sConnectorInfo.bIAudioLoudness ? L"True" : L"False"));
		TRACE((L"\t-> IAudioMidrange\t\t\t%s", m_sConnectorInfo.bIAudioMidrange ? L"True" : L"False"));
		TRACE((L"\t-> IAudioMute\t\t\t\t%s", m_sConnectorInfo.bIAudioMute ? L"True" : L"False"));
		TRACE((L"\t-> IAudioOutputSelector\t\t%s", m_sConnectorInfo.bIAudioOutputSelector ? L"True" : L"False"));
		TRACE((L"\t-> IAudioPeakMeter\t\t\t%s", m_sConnectorInfo.bIAudioPeakMeter ? L"True" : L"False"));
		TRACE((L"\t-> IAudioTreble\t\t\t\t%s", m_sConnectorInfo.bIAudioTreble ? L"True" : L"False"));
		TRACE((L"\t-> IAudioVolumeLevel\t\t%s", m_sConnectorInfo.bIAudioVolumeLevel ? L"True" : L"False"));
		TRACE((L"\t-> IDeviceSpecificProperty\t%s", m_sConnectorInfo.bIDeviceSpecificProperty ? L"True" : L"False"));
		TRACE((L"\t-> IKsFormatSupport\t\t\t%s", m_sConnectorInfo.bIKsFormatSupport ? L"True" : L"False"));
		TRACE((L"\t-> IKsJackDescription\t\t%s", m_sConnectorInfo.bIKsJackDescription ? L"True" : L"False"));
		TRACE((L"\t-> IKsJackDescription2\t\t%s", m_sConnectorInfo.bIKsJackDescription2 ? L"True" : L"False"));

		if(m_sConnectorInfo.bIKsFormatSupport){

			TRACE((L"\t-> FormatSupport :"));
			LogAudioDataFormat();
		}
		if(m_sConnectorInfo.bIKsJackDescription){

			TRACE((L"\t-> JackDescription :"));
			m_cJackDescription.LogJackDescriptionInfo();
		}
		if(m_sConnectorInfo.bIKsJackDescription2){

			TRACE((L"\t-> JackDescription2 :"));
			m_cJackDescription.LogJackDescription2Info();
		}
	}

	TRACE((L"---------------------------------------------------------------------------------------"));
}

HRESULT CConnectorInfo::GetKsFormat(IKsFormatSupport* pKsFormatSupport){

	HRESULT hr = S_OK;

	IF_FAILED_RETURN(pKsFormatSupport == NULL ? E_POINTER : S_OK);

	hr = pKsFormatSupport->GetDevicePreferredFormat(&m_pKsPreferredFormat);

	return hr;
}

void CConnectorInfo::LogAudioDataFormat(){

	if(m_pKsPreferredFormat == NULL){

		TRACE((L"\t\t-> Preferred Format Null"));
	}
	else{

		TRACE_NO_END_LINE((L"\t\t-> Flags\t\t\t"));

		if(m_pKsPreferredFormat->Flags == KSDATAFORMAT_ATTRIBUTES)
			TRACE((L"ATTRIBUTES"));
		else
			TRACE((L"%d", m_pKsPreferredFormat->Flags));

		TRACE((L"\t\t-> FormatSize\t\t%d (KSDATAFORMAT : %d - WAVEFORMATEXTENSIBLE : %d - WAVEFORMATEX : %d)",
			m_pKsPreferredFormat->FormatSize, sizeof(KSDATAFORMAT), sizeof(WAVEFORMATEXTENSIBLE), sizeof(WAVEFORMATEX)));

		LogKsMajorFormatType(m_pKsPreferredFormat->MajorFormat, L"\t\t-> MajorFormat\t\t");
		LogKsSubFormatType(m_pKsPreferredFormat->SubFormat, L"\t\t-> SubFormat\t\t");

		TRACE_NO_END_LINE((L"\t\t-> SampleSize\t\t"));

		if(m_pKsPreferredFormat->SampleSize == 0)
			TRACE((L"Variable"));
		else
			TRACE((L"%d", m_pKsPreferredFormat->SampleSize));

		LogKsFormatSpecifier(m_pKsPreferredFormat, L"\t\t-> Specifier\t\t");
	}
}