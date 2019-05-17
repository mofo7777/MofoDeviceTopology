//----------------------------------------------------------------------------------------------
// MMDeviceInfo.h
//----------------------------------------------------------------------------------------------
#ifndef MMDEVICEINFO_H
#define MMDEVICEINFO_H

struct SMMDeviceInfo{

	BOOL bIsInit;
	LPWSTR lpwszID;
	DWORD dwState;
	EDataFlow eAudioFlow;
	WCHAR* wszDeviceInterfaceFriendlyName;
	WCHAR* wszDeviceDeviceDesc;
	WCHAR* wszDeviceFriendlyName;
	LPWSTR lpwszDeviceContainerId;
	WCHAR* wszAudioEndpointAssociation;
	WCHAR* wszAudioEndpointControlPanelPageProvider;
	ULONG ulAudioEndpointDisableSysFx;
	UINT uiAudioEndpointFormFactor;
	UINT uiAudioEndpointFullRangeSpeakers;
	WCHAR* wszAudioEndpointGUID;
	UINT uiAudioEndpointPhysicalSpeakers;
	WAVEFORMATEXTENSIBLE wfAudioEngineDeviceFormat;
	WAVEFORMATEXTENSIBLE wfAudioEngineOEMFormat;
	UINT uiAudioEndpointSupportsEventDriveMode;
	WCHAR* wszAudioEndpointJackSubType;
	BOOL bIAudioClient;
	BOOL bIAudioEndpointVolume;
	BOOL bIAudioMeterInformation;
	BOOL bIAudioSessionManager;
	BOOL bIAudioSessionManager2;
	BOOL bIBaseFilter;
	BOOL bIDeviceTopology;
	BOOL bIDirectSound;
	BOOL bIDirectSound8;
	BOOL bIDirectSoundCapture;
	BOOL bIMFTrustedOutput;
};

class CMMDeviceInfo{

	public:

		CMMDeviceInfo(){ ZeroMemory(&m_sMMDeviceInfo, sizeof(SMMDeviceInfo)); }
		~CMMDeviceInfo(){ ReleaseInfo(); }

		HRESULT InitializeMMDeviceInfo(IMMDevice*);
		void LogMMDeviceInfo();

	private:

		SMMDeviceInfo m_sMMDeviceInfo;

		void ReleaseInfo();
		void GetPropertyKeyDeviceInterfaceFriendlyName(IPropertyStore*);
		void GetPropertyKeyDeviceDeviceDesc(IPropertyStore*);
		void GetPropertyKeyDeviceFriendlyName(IPropertyStore*);
		void GetPropertyKeyDeviceContainerId(IPropertyStore*);
		void GetPropertyKeyAudioEndpointAssociation(IPropertyStore*);
		void GetPropertyKeyAudioEndpointControlPanelPageProvider(IPropertyStore*);
		void GetPropertyKeyAudioEndpointDisable_SysFx(IPropertyStore*);
		void GetPropertyKeyAudioEndpointFormFactor(IPropertyStore*);
		void GetPropertyKeyAudioEndpointFullRangeSpeakers(IPropertyStore*);
		void GetPropertyKeyAudioEndpointGUID(IPropertyStore*);
		void GetPropertyKeyAudioEndpointPhysicalSpeakers(IPropertyStore*);
		void GetPropertyKeyAudioEngineDeviceFormat(IPropertyStore*);
		void GetPropertyKeyAudioEngineOEMFormat(IPropertyStore*);
		void GetPropertyKeyAudioEndpointSupportsEventDrive_Mode(IPropertyStore*);
		void GetPropertyKeyAudioEndpointJackSubType(IPropertyStore*);
		void LogFormFactor(const UINT);
		void LogWaveFormatExtensible(const WAVEFORMATEXTENSIBLE&, LPCWSTR);
		void LogJackSubType(LPCWSTR);
};

inline void CMMDeviceInfo::ReleaseInfo(){

	CoTaskMemFree(m_sMMDeviceInfo.lpwszID);
	SAFE_DELETE_ARRAY(m_sMMDeviceInfo.wszDeviceInterfaceFriendlyName);
	SAFE_DELETE_ARRAY(m_sMMDeviceInfo.wszDeviceDeviceDesc);
	SAFE_DELETE_ARRAY(m_sMMDeviceInfo.wszDeviceFriendlyName);
	CoTaskMemFree(m_sMMDeviceInfo.lpwszDeviceContainerId);
	SAFE_DELETE_ARRAY(m_sMMDeviceInfo.wszAudioEndpointAssociation);
	SAFE_DELETE_ARRAY(m_sMMDeviceInfo.wszAudioEndpointControlPanelPageProvider);
	SAFE_DELETE_ARRAY(m_sMMDeviceInfo.wszAudioEndpointGUID);
	SAFE_DELETE_ARRAY(m_sMMDeviceInfo.wszAudioEndpointJackSubType);

	ZeroMemory(&m_sMMDeviceInfo, sizeof(SMMDeviceInfo));

	m_sMMDeviceInfo.ulAudioEndpointDisableSysFx = ULONG(-1);
	m_sMMDeviceInfo.uiAudioEndpointFormFactor = UINT(-1);
	m_sMMDeviceInfo.uiAudioEndpointSupportsEventDriveMode = UINT(-1);
	m_sMMDeviceInfo.eAudioFlow = EDataFlow::EDataFlow_enum_count;
}

#endif