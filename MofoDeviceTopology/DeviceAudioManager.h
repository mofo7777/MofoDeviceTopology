//----------------------------------------------------------------------------------------------
// DeviceAudioManager.h
//----------------------------------------------------------------------------------------------
#ifndef DEVICEAUDIOMANAGER_H
#define DEVICEAUDIOMANAGER_H

class CDeviceAudioManager{

	public:

		CDeviceAudioManager(){}
		~CDeviceAudioManager(){ ClearMMDeviceInfo(); ClearDeviceTopologyInfo(); }

		HRESULT InitializeAllDeviceInfo();
		HRESULT InitializeAllDeviceTopologyInfo();
		HRESULT InitializeDeviceInfo(LPCWSTR);
		HRESULT InitializeDeviceTopologyInfo(LPCWSTR);
		void LogAllDeviceInfo();
		void LogDeviceTopologyInfo();

	private:

		std::vector<CMMDeviceInfo*> m_vpMMDeviceInfo;
		std::vector<CDeviceTopologyInfo*> m_vpDeviceTopologyInfo;

		void ClearMMDeviceInfo();
		void ClearDeviceTopologyInfo();
};

inline void CDeviceAudioManager::LogAllDeviceInfo(){

	std::vector<CMMDeviceInfo*>::const_iterator it = m_vpMMDeviceInfo.begin();

	for(; it != m_vpMMDeviceInfo.end(); ++it)
		(*it)->LogMMDeviceInfo();
}

inline void CDeviceAudioManager::LogDeviceTopologyInfo(){

	std::vector<CDeviceTopologyInfo*>::const_iterator it = m_vpDeviceTopologyInfo.begin();

	for(; it != m_vpDeviceTopologyInfo.end(); ++it)
		(*it)->LogDeviceTopologyInfo();
}

inline void CDeviceAudioManager::ClearMMDeviceInfo(){

	std::vector<CMMDeviceInfo*>::iterator it = m_vpMMDeviceInfo.begin();

	for(; it != m_vpMMDeviceInfo.end(); ++it)
		SAFE_DELETE(*it);

	m_vpMMDeviceInfo.clear();
}

inline void CDeviceAudioManager::ClearDeviceTopologyInfo(){

	std::vector<CDeviceTopologyInfo*>::iterator it = m_vpDeviceTopologyInfo.begin();

	for(; it != m_vpDeviceTopologyInfo.end(); ++it)
		SAFE_DELETE(*it);

	m_vpDeviceTopologyInfo.clear();
}

#endif