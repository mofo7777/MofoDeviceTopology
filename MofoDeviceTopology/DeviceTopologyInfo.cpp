//----------------------------------------------------------------------------------------------
// DeviceTopologyInfo.cpp
//----------------------------------------------------------------------------------------------
#include "StdAfx.h"

CDeviceTopologyInfo::CDeviceTopologyInfo() :
	m_bIsInit(FALSE),
	m_lpwszDeviceId(NULL),
	m_uiConnectorCount(0),
	m_uiSubunitCount(0)
{
}

HRESULT CDeviceTopologyInfo::InitializeDeviceTopologyInfo(IDeviceTopology* pDeviceTopology){

	HRESULT hr = S_OK;
	IConnector* pConnector = NULL;

	clearDeviceTopologyInfo();

	IF_FAILED_RETURN(pDeviceTopology == NULL ? E_POINTER : S_OK);

	try{

		IF_FAILED_THROW(pDeviceTopology->GetDeviceId(&m_lpwszDeviceId));

		IF_FAILED_THROW(pDeviceTopology->GetConnectorCount(&m_uiConnectorCount));

		// AudioEndPointDevice : one connector
		IF_FAILED_THROW(m_uiConnectorCount == 1 ? S_OK : E_FAIL);

		// AudioEndPointDevice : no Subunit
		IF_FAILED_THROW(pDeviceTopology->GetSubunitCount(&m_uiSubunitCount));
		IF_FAILED_THROW(m_uiSubunitCount == 0 ? S_OK : E_FAIL);

		IF_FAILED_THROW(pDeviceTopology->GetConnector(0, &pConnector));

		IF_FAILED_THROW(AddConnector(pConnector));

		IF_FAILED_THROW(GetAllPartsFromConnector(pConnector));

		m_bIsInit = TRUE;
	}
	catch(HRESULT){}

	if(FAILED(hr))
		clearDeviceTopologyInfo();

	SAFE_RELEASE(pConnector);

	return hr;
}

HRESULT CDeviceTopologyInfo::GetAllPartsFromConnector(IConnector* pConnector){

	HRESULT hr = S_OK;
	IConnector* pConnectorFrom = NULL;
	IConnector* pConnectorTo = NULL;
	IPart* pPartFrom = NULL;
	IPart* pPartNext = NULL;
	IPartsList* pParts = NULL;
	BOOL bContinue = TRUE;
	BOOL bConnected = FALSE;
	DataFlow dataFlow;
	UINT uiCount = 0;
	UINT uiIndex = 0;
	PartType partType;

	IF_FAILED_RETURN(pConnector == NULL ? E_POINTER : S_OK);

	pConnectorFrom = pConnector;
	pConnectorFrom->AddRef();

	try{

		do{

			IF_FAILED_THROW(pConnectorFrom->IsConnected(&bConnected));

			if(bConnected == FALSE)
				break;

			IF_FAILED_THROW(pConnectorFrom->GetConnectedTo(&pConnectorTo));
			SAFE_RELEASE(pConnectorFrom);

			IF_FAILED_THROW(AddConnector(pConnectorTo));

			IF_FAILED_THROW(pConnectorTo->QueryInterface(IID_IPart, reinterpret_cast<void**>(&pPartFrom)));
			IF_FAILED_THROW(pConnectorTo->GetDataFlow(&dataFlow));
			SAFE_RELEASE(pConnectorTo);

			while(TRUE)
			{
				// Because DataFlow is Out call EnumPartsIncoming otherwise (In) call EnumPartsOutgoing
				if(dataFlow == DataFlow::Out){

					if(FAILED(pPartFrom->EnumPartsIncoming(&pParts))){

						bContinue = FALSE;
						break;
					}
				}
				else{

					if(FAILED(pPartFrom->EnumPartsOutgoing(&pParts))){

						bContinue = FALSE;
						break;
					}
				}

				IF_FAILED_THROW(pParts->GetCount(&uiCount));

				// should never arrives, EnumParts...going should fail before : E_NOTFOUND
				//IF_FAILED_THROW(uiCount == 0 ? E_FAIL : S_OK);

				// https://docs.microsoft.com/en-us/windows-hardware/drivers/audio/audio-endpoint-builder-algorithm
				// todo : handle here when uiCount > 1
				if(uiCount > 1)
					uiIndex = 1;
				else
					uiIndex = 0;

				IF_FAILED_THROW(pParts->GetPart(uiIndex, &pPartNext));
				SAFE_RELEASE(pParts);

				IF_FAILED_THROW(pPartNext->GetPartType(&partType));				

				if(partType == Connector)
				{
					IF_FAILED_THROW(pPartNext->QueryInterface(IID_IConnector, reinterpret_cast<void**>(&pConnectorFrom)));
					IF_FAILED_THROW(AddConnector(pConnectorFrom));

					SAFE_RELEASE(pPartFrom);
					SAFE_RELEASE(pPartNext);
					break;
				}
				else{

					IF_FAILED_THROW(AddSubunit(pPartNext));

					SAFE_RELEASE(pPartFrom);
					pPartFrom = pPartNext;
					pPartNext = NULL;
				}
			}
		}
		while(bContinue);
	}
	catch(HRESULT){}

	SAFE_RELEASE(pParts);
	SAFE_RELEASE(pPartNext);
	SAFE_RELEASE(pPartFrom);
	SAFE_RELEASE(pConnectorTo);
	SAFE_RELEASE(pConnectorFrom);

	return hr;
}

void CDeviceTopologyInfo::LogDeviceTopologyInfo(){

	TRACE((L"---------------------------------------------------------------------------------------"));
	TRACE((L"DEVICE TOPOLOGY :"));

	if(m_bIsInit == FALSE){

		TRACE((L"Not initialzed"));
	}
	else{

		TRACE((L"Audio Device ID\t\t%s", m_lpwszDeviceId));
		TRACE((L"Connector Count\t\t%d", m_uiConnectorCount));
		TRACE((L"Subunit Count\t\t%d", m_uiSubunitCount));

		std::vector<CAudioPart*>::const_iterator it = m_vpAudioPart.begin();

		for(; it != m_vpAudioPart.end(); ++it)
			(*it)->LogAudioPartInfo();
	}

	TRACE((L"---------------------------------------------------------------------------------------"));
}

HRESULT CDeviceTopologyInfo::AddConnector(IConnector* pConnector){

	HRESULT hr = S_OK;
	CAudioPart* pAudioPart = NULL;

	IF_FAILED_RETURN(pConnector == NULL ? E_POINTER : S_OK);

	pAudioPart = new (std::nothrow)CAudioPart();

	IF_FAILED_THROW(pAudioPart == NULL ? E_OUTOFMEMORY : S_OK);

	m_vpAudioPart.push_back(pAudioPart);

	return pAudioPart->InitializeConnectorInfo(pConnector);
}

HRESULT CDeviceTopologyInfo::AddSubunit(IPart* pPart){

	HRESULT hr = S_OK;
	CAudioPart* pAudioPart = NULL;

	IF_FAILED_RETURN(pPart == NULL ? E_POINTER : S_OK);

	pAudioPart = new (std::nothrow)CAudioPart();

	IF_FAILED_RETURN(pAudioPart == NULL ? E_OUTOFMEMORY : S_OK);

	m_vpAudioPart.push_back(pAudioPart);

	return pAudioPart->InitializeSubunitInfo(pPart);
}