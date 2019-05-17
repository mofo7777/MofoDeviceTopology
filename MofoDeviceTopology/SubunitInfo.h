//----------------------------------------------------------------------------------------------
// SubunitInfo.h
//----------------------------------------------------------------------------------------------
#ifndef SUBUNITINFO_H
#define SUBUNITINFO_H

struct SSubunitInfo{

	BOOL bIsInit;
	LPWSTR lpwszGlobalId;
	UINT uiLocalId;
	LPWSTR lpwszName;
	UINT uiControlInterfaceCount;
	GUID guidSubType;
	PartType partType;
	// Interface
	BOOL bIAudioAutoGainControl;
	BOOL bIAudioBass;
	BOOL bIAudioChannelConfig;
	BOOL bIAudioInputSelector;
	BOOL bIAudioLoudness;
	BOOL bIAudioMidrange;
	BOOL bIAudioMute;
	BOOL bIAudioOutputSelector;
	BOOL bIAudioPeakMeter;
	BOOL bIAudioTreble;
	BOOL bIAudioVolumeLevel;
	BOOL bIDeviceSpecificProperty;
	BOOL bIKsFormatSupport;
	BOOL bIKsJackDescription;
	BOOL bIKsJackDescription2;
	// Interface
	UINT uiJackCount;
	// KSJACK_DESCRIPTION
	UINT uiJackCount2;
	// KSJACK_DESCRIPTION2
	BOOL bAutoGainEnable;
	BOOL bMuted;
	UINT uiChannelCount;
};

class CSubunitInfo{

	public:

		CSubunitInfo(){ ZeroMemory(&m_sSubunitInfo, sizeof(SSubunitInfo)); }
		~CSubunitInfo(){ ClearSubunitInfo(); }

		HRESULT InitializeSubunitInfo(IPart*);
		void LogSubunitInfo();
		//const UINT GetLocalId(){ return m_sSubunitInfo.uiLocalId; }

	private:

		SSubunitInfo m_sSubunitInfo;

		void ClearSubunitInfo();
};

inline void CSubunitInfo::ClearSubunitInfo(){

	CoTaskMemFree(m_sSubunitInfo.lpwszGlobalId);
	CoTaskMemFree(m_sSubunitInfo.lpwszName);

	ZeroMemory(&m_sSubunitInfo, sizeof(SSubunitInfo));
}

#endif