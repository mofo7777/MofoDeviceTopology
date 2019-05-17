//----------------------------------------------------------------------------------------------
// AudioPart.h
//----------------------------------------------------------------------------------------------
#ifndef AUDIOPART_H
#define AUDIOPART_H

class CAudioPart{

	public:

		CAudioPart();
		~CAudioPart(){ ClearAudioPartInfo(); }

		HRESULT InitializeConnectorInfo(IConnector*);
		HRESULT InitializeSubunitInfo(IPart*);
		void LogAudioPartInfo();
		//const UINT GetSubunitLocalId(){ return m_pSubunitInfo ? m_pSubunitInfo->GetLocalId() : 0; }

	private:

		CConnectorInfo* m_pConnectorInfo;
		CSubunitInfo* m_pSubunitInfo;
		PartType m_partType;

		LPWSTR m_lpwszDeviceId;
		UINT m_uiConnectorCount;
		UINT m_uiSubunitCount;

		void ClearAudioPartInfo();
};

inline void CAudioPart::ClearAudioPartInfo(){

	SAFE_DELETE(m_pConnectorInfo);
	SAFE_DELETE(m_pSubunitInfo);
	CoTaskMemFree(m_lpwszDeviceId);
	m_lpwszDeviceId = NULL;
	m_uiConnectorCount = 0;
	m_uiSubunitCount = 0;
}

#endif