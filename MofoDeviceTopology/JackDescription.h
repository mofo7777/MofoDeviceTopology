//----------------------------------------------------------------------------------------------
// JackDescription.h
//----------------------------------------------------------------------------------------------
#ifndef JACKDESCRIPTION_H
#define JACKDESCRIPTION_H

class CJackDescription{

	public:

		CJackDescription(){}
		~CJackDescription(){}

		HRESULT InitializeJackDescriptionInfo(IKsJackDescription*);
		HRESULT InitializeJackDescription2Info(IKsJackDescription2*);
		void LogJackDescriptionInfo();
		void LogJackDescription2Info();

	private:

		std::vector<KSJACK_DESCRIPTION> m_vJackDescription;
		std::vector<KSJACK_DESCRIPTION2> m_vJackDescription2;

		void LogJackPosition(const DWORD);
		void LogJackJackColor(const COLORREF);
		void LogJackConnectionType(const EPcxConnectionType);
		void LogJackGeoLocation(const EPcxGeoLocation GeoLocation);
		void LogJackGenLocation(const EPcxGenLocation GenLocation);
		void LogJackPortConnection(const EPxcPortConnection PortConnection);
};

#endif