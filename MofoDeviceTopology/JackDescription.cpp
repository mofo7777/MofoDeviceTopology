//----------------------------------------------------------------------------------------------
// JackDescription.cpp
//----------------------------------------------------------------------------------------------
#include "StdAfx.h"

HRESULT CJackDescription::InitializeJackDescriptionInfo(IKsJackDescription* pKsJackDescription){

	HRESULT hr = S_OK;
	UINT uiJackCount;
	KSJACK_DESCRIPTION sDescription;

	IF_FAILED_RETURN(pKsJackDescription == NULL ? E_POINTER : S_OK);

	IF_FAILED_RETURN(pKsJackDescription->GetJackCount(&uiJackCount));

	m_vJackDescription.reserve(uiJackCount);

	for(UINT ui = 0; ui < uiJackCount; ui++){

		if(SUCCEEDED(pKsJackDescription->GetJackDescription(ui, &sDescription)))
			m_vJackDescription.push_back(sDescription);
	}

	return hr;
}

HRESULT CJackDescription::InitializeJackDescription2Info(IKsJackDescription2* pKsJackDescription2){

	HRESULT hr = S_OK;
	UINT uiJackCount;
	KSJACK_DESCRIPTION2 sDescription2;

	IF_FAILED_RETURN(pKsJackDescription2 == NULL ? E_POINTER : S_OK);

	IF_FAILED_RETURN(pKsJackDescription2->GetJackCount(&uiJackCount));

	m_vJackDescription2.reserve(uiJackCount);

	for(UINT ui = 0; ui < uiJackCount; ui++){

		if(SUCCEEDED(pKsJackDescription2->GetJackDescription2(ui, &sDescription2)))
			m_vJackDescription2.push_back(sDescription2);
	}

	return hr;
}

void CJackDescription::LogJackDescriptionInfo(){

	int iIndex = 0;

	TRACE((L"\t\t-> Jack Count : %d", m_vJackDescription.size()));

	std::vector<KSJACK_DESCRIPTION>::iterator it = m_vJackDescription.begin();

	for(; it != m_vJackDescription.end(); ++it){

		TRACE((L"\t\t\t-> Jack index %d", iIndex));
		TRACE((L"\t\t\t\t-> Jack connected\t\t\t%s", it->IsConnected ? L"True" : L"False"));

		LogJackPosition(it->ChannelMapping);
		LogJackJackColor(it->Color);
		LogJackConnectionType(it->ConnectionType);
		LogJackGeoLocation(it->GeoLocation);
		LogJackGenLocation(it->GenLocation);
		LogJackPortConnection(it->PortConnection);

		iIndex++;
	}
}

void CJackDescription::LogJackDescription2Info(){

	int iIndex = 0;

	TRACE((L"\t\t-> Jack Count : %d", m_vJackDescription2.size()));

	std::vector<KSJACK_DESCRIPTION2>::iterator it = m_vJackDescription2.begin();

	for(; it != m_vJackDescription2.end(); ++it){

		TRACE((L"\t\t\t-> Jack index %d", iIndex));

		TRACE((L"\t\t\t\t-> Jack State\t\t\t%d", it->DeviceStateInfo));

		TRACE_NO_END_LINE((L"\t\t\t\t-> Jack Capabilities\t"));

		if(it->JackCapabilities == JACKDESC2_PRESENCE_DETECT_CAPABILITY)
			TRACE((L"PRESENCE_DETECT"));
		else if(it->JackCapabilities == JACKDESC2_DYNAMIC_FORMAT_CHANGE_CAPABILITY)
			TRACE((L"DYNAMIC_FORMAT_CHANGE"));
		else
			TRACE((L"Unknown"));

		iIndex++;
	}
}

void CJackDescription::LogJackPosition(const DWORD dwSpeakerPosition){

	TRACE_NO_END_LINE((L"\t\t\t\t-> Jack Position\t\t\t"));

	// Only Windows Seven, for Vista it is different
	if(dwSpeakerPosition & SPEAKER_FRONT_LEFT)
		TRACE_NO_END_LINE((L"FRONT_LEFT "));
	if(dwSpeakerPosition & SPEAKER_FRONT_RIGHT)
		TRACE_NO_END_LINE((L"FRONT_RIGHT "));
	if(dwSpeakerPosition & SPEAKER_FRONT_CENTER)
		TRACE_NO_END_LINE((L"FRONT_CENTER "));
	if(dwSpeakerPosition & SPEAKER_LOW_FREQUENCY)
		TRACE_NO_END_LINE((L"LOW_FREQUENCY "));
	if(dwSpeakerPosition & SPEAKER_BACK_LEFT)
		TRACE_NO_END_LINE((L"BACK_LEFT "));
	if(dwSpeakerPosition & SPEAKER_BACK_RIGHT)
		TRACE_NO_END_LINE((L"BACK_RIGHT "));
	if(dwSpeakerPosition & SPEAKER_FRONT_LEFT_OF_CENTER)
		TRACE_NO_END_LINE((L"FRONT_LEFT_OF_CENTER "));
	if(dwSpeakerPosition & SPEAKER_FRONT_RIGHT_OF_CENTER)
		TRACE_NO_END_LINE((L"FRONT_RIGHT_OF_CENTER "));
	if(dwSpeakerPosition & SPEAKER_BACK_CENTER)
		TRACE_NO_END_LINE((L"BACK_CENTER "));
	if(dwSpeakerPosition & SPEAKER_SIDE_LEFT)
		TRACE_NO_END_LINE((L"SIDE_LEFT "));
	if(dwSpeakerPosition & SPEAKER_SIDE_RIGHT)
		TRACE_NO_END_LINE((L"SIDE_RIGHT "));
	if(dwSpeakerPosition & SPEAKER_TOP_CENTER)
		TRACE_NO_END_LINE((L"TOP_CENTER "));
	if(dwSpeakerPosition & SPEAKER_TOP_FRONT_LEFT)
		TRACE_NO_END_LINE((L"TOP_FRONT_LEFT "));
	if(dwSpeakerPosition & SPEAKER_TOP_FRONT_CENTER)
		TRACE_NO_END_LINE((L"TOP_FRONT_CENTER "));
	if(dwSpeakerPosition & SPEAKER_TOP_FRONT_RIGHT)
		TRACE_NO_END_LINE((L"TOP_FRONT_RIGHT "));
	if(dwSpeakerPosition & SPEAKER_TOP_BACK_LEFT)
		TRACE_NO_END_LINE((L"TOP_BACK_LEFT "));
	if(dwSpeakerPosition & SPEAKER_TOP_BACK_CENTER)
		TRACE_NO_END_LINE((L"TOP_BACK_CENTER "));
	if(dwSpeakerPosition & SPEAKER_TOP_BACK_RIGHT)
		TRACE_NO_END_LINE((L"TOP_BACK_RIGHT "));

	TRACE_NO_END_LINE((L"\n"));
}

void CJackDescription::LogJackJackColor(const COLORREF color){

	TRACE_NO_END_LINE((L"\t\t\t\t-> Jack Color\t\t\t\t"));

	switch(color){

		case 0x00000000:
			TRACE((L"Black"));
			break;

		case 0x000000ff:
			TRACE((L"Blue"));
			break;

		case 0x00008000:
			TRACE((L"Green"));
			break;

		case 0x00ff0000:
			TRACE((L"Red"));
			break;

		case 0x00ffa500:
			TRACE((L"Orange"));
			break;

		default:
			TRACE((L"Unknown"));
			break;
	}
}

void CJackDescription::LogJackConnectionType(const EPcxConnectionType ConnectionType){

	TRACE_NO_END_LINE((L"\t\t\t\t-> Jack Connection Type\t\t"));

	switch(ConnectionType){
			
		case EPcxConnectionType::eConnType3Point5mm:
			TRACE((L"ConnType3Point5mm"));
			break;

		case EPcxConnectionType::eConnTypeQuarter:
			TRACE((L"ConnTypeQuarter"));
			break;

		case EPcxConnectionType::eConnTypeAtapiInternal:
			TRACE((L"ConnTypeAtapiInternal"));
			break;

		case EPcxConnectionType::eConnTypeRCA:
			TRACE((L"ConnTypeRCA"));
			break;

		case EPcxConnectionType::eConnTypeOptical:
			TRACE((L"ConnTypeOptical"));
			break;

		case EPcxConnectionType::eConnTypeOtherDigital:
			TRACE((L"ConnTypeOtherDigital"));
			break;

		case EPcxConnectionType::eConnTypeOtherAnalog:
			TRACE((L"ConnTypeOtherAnalog"));
			break;

		case EPcxConnectionType::eConnTypeMultichannelAnalogDIN:
			TRACE((L"ConnTypeMultichannelAnalogDIN"));
			break;

		case EPcxConnectionType::eConnTypeXlrProfessional:
			TRACE((L"ConnTypeXlrProfessional"));
			break;

		case EPcxConnectionType::eConnTypeRJ11Modem:
			TRACE((L"ConnTypeRJ11Modem"));
			break;

		case EPcxConnectionType::eConnTypeCombination:
			TRACE((L"ConnTypeCombination"));
			break;

		case EPcxConnectionType::eConnTypeUnknown:
			TRACE((L"ConnTypeUnknown"));
			break;

		default:
			TRACE((L"Unknown"));
			break;
	}
}

void CJackDescription::LogJackGeoLocation(const EPcxGeoLocation GeoLocation){

	TRACE_NO_END_LINE((L"\t\t\t\t-> Jack Geo Location\t\t"));

	switch(GeoLocation){

		case EPcxGeoLocation::eGeoLocRear:
			TRACE((L"GeoLocRear"));
			break;

		case EPcxGeoLocation::eGeoLocFront:
			TRACE((L"GeoLocFront"));
			break;

		case EPcxGeoLocation::eGeoLocLeft:
			TRACE((L"GeoLocLeft"));
			break;

		case EPcxGeoLocation::eGeoLocRight:
			TRACE((L"GeoLocRight"));
			break;

		case EPcxGeoLocation::eGeoLocTop:
			TRACE((L"GeoLocTop"));
			break;

		case EPcxGeoLocation::eGeoLocBottom:
			TRACE((L"GeoLocBottom"));
			break;

		case EPcxGeoLocation::eGeoLocRearPanel:
			TRACE((L"GeoLocRearPanel"));
			break;

		case EPcxGeoLocation::eGeoLocRiser:
			TRACE((L"GeoLocRiser"));
			break;

		case EPcxGeoLocation::eGeoLocInsideMobileLid:
			TRACE((L"GeoLocInsideMobileLid"));
			break;

		case EPcxGeoLocation::eGeoLocDrivebay:
			TRACE((L"GeoLocDrivebay"));
			break;

		case EPcxGeoLocation::eGeoLocHDMI:
			TRACE((L"GeoLocHDMI"));
			break;

		case EPcxGeoLocation::eGeoLocOutsideMobileLid:
			TRACE((L"GeoLocOutsideMobileLid"));
			break;

		case EPcxGeoLocation::eGeoLocATAPI:
			TRACE((L"GeoLocATAPI"));
			break;

		case EPcxGeoLocation::eGeoLocNotApplicable:
			TRACE((L"GeoLocNotApplicable"));
			break;

		case EPcxGeoLocation::eGeoLocReserved6:
			TRACE((L"GeoLocReserved6"));
			break;

		default:
			TRACE((L"Unknown"));
			break;
	}
}

void CJackDescription::LogJackGenLocation(const EPcxGenLocation GenLocation){

	TRACE_NO_END_LINE((L"\t\t\t\t-> Jack General Location\t"));

	switch(GenLocation){

		case EPcxGenLocation::eGenLocPrimaryBox:
			TRACE((L"GenLocPrimaryBox"));
			break;

		case EPcxGenLocation::eGenLocInternal:
			TRACE((L"GenLocInternal"));
			break;

		case EPcxGenLocation::eGenLocSeparate:
			TRACE((L"GenLocSeparate"));
			break;

		case EPcxGenLocation::eGenLocOther:
			TRACE((L"GenLocOther"));
			break;

		default:
			TRACE((L"Unknown"));
			break;
	}
}

void CJackDescription::LogJackPortConnection(const EPxcPortConnection PortConnection){

	TRACE_NO_END_LINE((L"\t\t\t\t-> Jack Port Connection\t\t"));

	switch(PortConnection){

		case EPxcPortConnection::ePortConnJack:
			TRACE((L"PortConnJack"));
			break;

		case EPxcPortConnection::ePortConnIntegratedDevice:
			TRACE((L"PortConnIntegratedDevice"));
			break;

		case EPxcPortConnection::ePortConnBothIntegratedAndJack:
			TRACE((L"PortConnBothIntegratedAndJack"));
			break;

		case EPxcPortConnection::ePortConnUnknown:
			TRACE((L"PortConnUnknown"));
			break;

		default:
			TRACE((L"Unknown"));
			break;
	}
}