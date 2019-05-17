//----------------------------------------------------------------------------------------------
// ConnectorInfo.h
//----------------------------------------------------------------------------------------------
#ifndef CONNECTORINFO_H
#define CONNECTORINFO_H

struct SConnectorInfo{

	BOOL bIsInit;
	BOOL bIsConnected;
	ConnectorType connectorType;
	DataFlow dataFlow;
	LPWSTR lpwszConnectorIdConnectedTo;
	LPWSTR lpwszDeviceIdConnectedTo;
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
};

class CConnectorInfo{

	public:

		CConnectorInfo() : m_pKsPreferredFormat(NULL){ ZeroMemory(&m_sConnectorInfo, sizeof(SConnectorInfo)); }
		~CConnectorInfo(){ ClearConnectorInfo(); }

		HRESULT InitializeConnectorInfo(IConnector*);
		void LogConnectorInfo();

	private:

		SConnectorInfo m_sConnectorInfo;

		// KSJACK_DESCRIPTION/KSJACK_DESCRIPTION2
		CJackDescription m_cJackDescription;
		PKSDATAFORMAT m_pKsPreferredFormat;

		void ClearConnectorInfo();
		HRESULT GetKsFormat(IKsFormatSupport*);
		void LogAudioDataFormat();
};

inline void CConnectorInfo::ClearConnectorInfo(){

	CoTaskMemFree(m_pKsPreferredFormat);
	m_pKsPreferredFormat = NULL;
	CoTaskMemFree(m_sConnectorInfo.lpwszConnectorIdConnectedTo);
	CoTaskMemFree(m_sConnectorInfo.lpwszDeviceIdConnectedTo);
	CoTaskMemFree(m_sConnectorInfo.lpwszGlobalId);
	CoTaskMemFree(m_sConnectorInfo.lpwszName);

	ZeroMemory(&m_sConnectorInfo, sizeof(SConnectorInfo));
}

#endif