//----------------------------------------------------------------------------------------------
// AudioPart.cpp
//----------------------------------------------------------------------------------------------
#include "StdAfx.h"

CAudioPart::CAudioPart() :
	m_pConnectorInfo(NULL),
	m_pSubunitInfo(NULL),
	m_partType(PartType::Connector),
	m_lpwszDeviceId(NULL),
	m_uiConnectorCount(0),
	m_uiSubunitCount(0)
{
}

HRESULT CAudioPart::InitializeConnectorInfo(IConnector* pConnector){

	HRESULT hr = S_OK;
	IPart* pPart = NULL;
	IDeviceTopology* pDeviceTopology = NULL;

	ClearAudioPartInfo();

	IF_FAILED_RETURN(pConnector == NULL ? E_POINTER : S_OK);

	try{

		IF_FAILED_THROW(pConnector->QueryInterface(IID_IPart, reinterpret_cast<void**>(&pPart)));
		IF_FAILED_THROW(pPart->GetTopologyObject(&pDeviceTopology));

		IF_FAILED_THROW(pDeviceTopology->GetDeviceId(&m_lpwszDeviceId));
		IF_FAILED_THROW(pDeviceTopology->GetConnectorCount(&m_uiConnectorCount));
		IF_FAILED_THROW(pDeviceTopology->GetSubunitCount(&m_uiSubunitCount));

		m_pConnectorInfo = new (std::nothrow)CConnectorInfo();

		IF_FAILED_THROW(m_pConnectorInfo == NULL ? E_OUTOFMEMORY : S_OK);

		IF_FAILED_THROW(m_pConnectorInfo->InitializeConnectorInfo(pConnector));

		m_partType = PartType::Connector;
	}
	catch(HRESULT){}

	if(FAILED(hr))
		ClearAudioPartInfo();

	SAFE_RELEASE(pDeviceTopology);
	SAFE_RELEASE(pPart);

	return hr;
}

HRESULT CAudioPart::InitializeSubunitInfo(IPart* pPart){

	HRESULT hr = S_OK;
	IDeviceTopology* pDeviceTopology = NULL;

	ClearAudioPartInfo();

	IF_FAILED_RETURN(pPart == NULL ? E_POINTER : S_OK);

	try{

		IF_FAILED_THROW(pPart->GetTopologyObject(&pDeviceTopology));

		IF_FAILED_THROW(pDeviceTopology->GetDeviceId(&m_lpwszDeviceId));
		IF_FAILED_THROW(pDeviceTopology->GetConnectorCount(&m_uiConnectorCount));
		IF_FAILED_THROW(pDeviceTopology->GetSubunitCount(&m_uiSubunitCount));

		m_pSubunitInfo = new (std::nothrow)CSubunitInfo();

		IF_FAILED_THROW(m_pSubunitInfo == NULL ? E_OUTOFMEMORY : S_OK);

		IF_FAILED_THROW(m_pSubunitInfo->InitializeSubunitInfo(pPart));

		m_partType = PartType::Subunit;
	}
	catch(HRESULT){}

	if(FAILED(hr))
		ClearAudioPartInfo();

	SAFE_RELEASE(pDeviceTopology);

	return hr;
}

void CAudioPart::LogAudioPartInfo(){

	TRACE((L"---------------------------------------------------------------------------------------"));
	TRACE((L"AUDIO PART :"));
	TRACE((L"\t-> TOPOLOGY INFO :"));

	TRACE((L"\t\t-> Audio Device ID\t\t%s", m_lpwszDeviceId));
	TRACE((L"\t\t-> Connector Count\t\t%d", m_uiConnectorCount));
	TRACE((L"\t\t-> Subunit Count\t\t%d", m_uiSubunitCount));

	if(m_partType == PartType::Connector && m_pConnectorInfo != NULL){

		m_pConnectorInfo->LogConnectorInfo();
	}
	else if(m_partType == PartType::Subunit && m_pSubunitInfo != NULL){

		m_pSubunitInfo->LogSubunitInfo();
	}
	else{

		TRACE((L"Not initialzed"));
	}

	TRACE((L"---------------------------------------------------------------------------------------"));
}