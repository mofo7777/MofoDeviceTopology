//----------------------------------------------------------------------------------------------
// DeviceTopologyInfo.h
//----------------------------------------------------------------------------------------------
#ifndef DEVICETOPOLOGYINFO_H
#define DEVICETOPOLOGYINFO_H

class CDeviceTopologyInfo{

	public:

		CDeviceTopologyInfo();
		~CDeviceTopologyInfo(){ clearDeviceTopologyInfo(); }

		HRESULT InitializeDeviceTopologyInfo(IDeviceTopology*);
		void LogDeviceTopologyInfo();

	private:

		BOOL m_bIsInit;
		LPWSTR m_lpwszDeviceId;
		UINT m_uiConnectorCount;
		UINT m_uiSubunitCount;

		std::vector<CAudioPart*> m_vpAudioPart;

		HRESULT GetAllPartsFromConnector(IConnector*);
		void clearDeviceTopologyInfo();
		HRESULT AddConnector(IConnector*);
		HRESULT AddSubunit(IPart*);
};

inline void CDeviceTopologyInfo::clearDeviceTopologyInfo(){

	m_bIsInit = FALSE;
	CoTaskMemFree(m_lpwszDeviceId);
	m_lpwszDeviceId = NULL;
	m_uiConnectorCount = 0;
	m_uiSubunitCount = 0;

	std::vector<CAudioPart*>::iterator it = m_vpAudioPart.begin();

	for(; it != m_vpAudioPart.end(); ++it)
		SAFE_DELETE(*it);

	m_vpAudioPart.clear();
}

#endif