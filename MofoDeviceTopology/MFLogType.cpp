//----------------------------------------------------------------------------------------------
// MFLogType.cpp
//----------------------------------------------------------------------------------------------
#include "StdAfx.h"

void LogKsNodeType(const GUID& guidKsNode, LPCWSTR wszLog){

	TRACE_NO_END_LINE((L"%s", wszLog));

	if(guidKsNode == KSNODETYPE_SPEAKER){

		TRACE((L"KSNODETYPE_SPEAKER"));
	}
	else if(guidKsNode == KSNODETYPE_MICROPHONE){

		TRACE((L"KSNODETYPE_MICROPHONE"));
	}
	else if(guidKsNode == KSCATEGORY_AUDIO){

		TRACE((L"KSCATEGORY_AUDIO"));
	}
	else if(guidKsNode == KSNODETYPE_AGC){

		TRACE((L"KSNODETYPE_AGC"));
	}
	else if(guidKsNode == KSNODETYPE_MUTE){

		TRACE((L"KSNODETYPE_MUTE"));
	}
	else if(guidKsNode == KSNODETYPE_VOLUME){

		TRACE((L"KSNODETYPE_VOLUME"));
	}
	else if(guidKsNode == KSNODETYPE_SUM){

		TRACE((L"KSNODETYPE_SUM"));
	}
	else if(guidKsNode == KSNODETYPE_DAC){

		TRACE((L"KSNODETYPE_DAC"));
	}
	else if(guidKsNode == KSNODETYPE_ADC){

		TRACE((L"KSNODETYPE_ADC"));
	}
	else if(guidKsNode == KSNODETYPE_LINE_CONNECTOR){

		TRACE((L"KSNODETYPE_LINE_CONNECTOR"));
	}
	else if(guidKsNode == KSNODETYPE_ANALOG_CONNECTOR){

		TRACE((L"KSNODETYPE_ANALOG_CONNECTOR"));
	}
	else if(guidKsNode == KSNODETYPE_LEGACY_AUDIO_CONNECTOR){

		TRACE((L"KSNODETYPE_LEGACY_AUDIO_CONNECTOR"));
	}
	else if(guidKsNode == KSNODETYPE_DIGITAL_AUDIO_INTERFACE){

		TRACE((L"KSNODETYPE_DIGITAL_AUDIO_INTERFACE"));
	}
	else if(guidKsNode == KSNODETYPE_SPDIF_INTERFACE){

		TRACE((L"KSNODETYPE_SPDIF_INTERFACE"));
	}
	else if(guidKsNode == KSNODETYPE_MUX){

		TRACE((L"KSNODETYPE_MUX"));
	}
	else if(guidKsNode == GUID_NULL){

		TRACE((L"GUID_NULL"));
	}
	else{

		LPWSTR pwszID = NULL;
		StringFromCLSID(guidKsNode, &pwszID);
		TRACE((L"Unknown Guid %s", pwszID));
		CoTaskMemFree(pwszID);
	}
}

void LogKsMajorFormatType(const GUID& guidMajorFormat, LPCWSTR wszLog){

	TRACE_NO_END_LINE((L"%s", wszLog));

	if(guidMajorFormat == KSDATAFORMAT_TYPE_STREAM)
		TRACE((L"STREAM"));
	else if(guidMajorFormat == KSDATAFORMAT_TYPE_VIDEO)
		TRACE((L"VIDEO"));
	else if(guidMajorFormat == KSDATAFORMAT_TYPE_AUDIO)
		TRACE((L"AUDIO"));
	else if(guidMajorFormat == KSDATAFORMAT_TYPE_TEXT)
		TRACE((L"TEXT"));
	else if(guidMajorFormat == KSDATAFORMAT_TYPE_MUSIC)
		TRACE((L"MUSIC"));
	else if(guidMajorFormat == KSDATAFORMAT_TYPE_MIDI)
		TRACE((L"MIDI"));
	else if(guidMajorFormat == KSDATAFORMAT_TYPE_STANDARD_ELEMENTARY_STREAM)
		TRACE((L"STANDARD_ELEMENTARY_STREAM"));
	else if(guidMajorFormat == KSDATAFORMAT_TYPE_STANDARD_PES_PACKET)
		TRACE((L"STANDARD_PES_PACKET"));
	else if(guidMajorFormat == KSDATAFORMAT_TYPE_STANDARD_PACK_HEADER)
		TRACE((L"STANDARD_PACK_HEADER"));
	else if(guidMajorFormat == KSDATAFORMAT_TYPE_MPEG2_PES)
		TRACE((L"MPEG2_PES"));
	else if(guidMajorFormat == KSDATAFORMAT_TYPE_MPEG2_PROGRAM)
		TRACE((L"MPEG2_PROGRAM"));
	else if(guidMajorFormat == KSDATAFORMAT_TYPE_MPEG2_TRANSPORT)
		TRACE((L"MPEG2_TRANSPORT"));
	else if(guidMajorFormat == KSDATAFORMAT_TYPE_IMAGE)
		TRACE((L"IMAGE"));
	else if(guidMajorFormat == KSDATAFORMAT_TYPE_ANALOGVIDEO)
		TRACE((L"ANALOGVIDEO"));
	else if(guidMajorFormat == KSDATAFORMAT_TYPE_ANALOGAUDIO)
		TRACE((L"ANALOGAUDIO"));
	else if(guidMajorFormat == KSDATAFORMAT_TYPE_VBI)
		TRACE((L"VBI"));
	else if(guidMajorFormat == KSDATAFORMAT_TYPE_NABTS)
		TRACE((L"NABTS"));
	else if(guidMajorFormat == KSDATAFORMAT_TYPE_AUXLine21Data)
		TRACE((L"AUXLine21Data"));
	else if(guidMajorFormat == KSDATAFORMAT_TYPE_DVD_ENCRYPTED_PACK)
		TRACE((L"DVD_ENCRYPTED_PACK"));
	else if(guidMajorFormat == GUID_NULL)
		TRACE((L"GUID_NULL"));
	else{

		LPWSTR pwszID = NULL;
		StringFromCLSID(guidMajorFormat, &pwszID);
		TRACE((L"%s", pwszID));
		CoTaskMemFree(pwszID);
	}
}

void LogKsSubFormatType(const GUID& guidSubFormat, LPCWSTR wszLog){

	TRACE_NO_END_LINE((L"%s", wszLog));

	if(guidSubFormat == KSDATAFORMAT_SUBTYPE_NONE)
		TRACE((L"NONE"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_WILDCARD)
		TRACE((L"WILDCARD"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_WAVEFORMATEX)
		TRACE((L"WAVEFORMATEX"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_ANALOG)
		TRACE((L"ANALOG"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_PCM)
		TRACE((L"PCM"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_RIFF)
		TRACE((L"RIFF"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_RIFFWAVE)
		TRACE((L"RIFFWAVE"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_MIDI)
		TRACE((L"MIDI"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_MIDI_BUS)
		TRACE((L"MIDI_BUS"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_RIFFMIDI)
		TRACE((L"RIFFMIDI"));
	/*else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_DIRECTMUSIC)
		TRACE((L"DIRECTMUSIC"));*/
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_STANDARD_MPEG1_VIDEO)
		TRACE((L"MPEG1_VIDEO"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_STANDARD_MPEG1_AUDIO)
		TRACE((L"MPEG1_AUDIO"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_STANDARD_MPEG2_VIDEO)
		TRACE((L"MPEG2_VIDEO"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_STANDARD_MPEG2_AUDIO)
		TRACE((L"MPEG2_AUDIO"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_STANDARD_AC3_AUDIO)
		TRACE((L"AC3_AUDIO"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_DSS_VIDEO)
		TRACE((L"DSS_VIDEO"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_DSS_AUDIO)
		TRACE((L"DSS_AUDIO"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_MPEG1Packet)
		TRACE((L"MPEG1Packet"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_MPEG1Payload)
		TRACE((L"MPEG1Payload"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_MPEG1Video)
		TRACE((L"MPEG1Video"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_MPEG2_VIDEO)
		TRACE((L"MPEG2_VIDEO"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_MPEG2_AUDIO)
		TRACE((L"MPEG2_AUDIO"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_LPCM_AUDIO)
		TRACE((L"LPCM_AUDIO"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_AC3_AUDIO)
		TRACE((L"AC3_AUDIO"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_IEC61937_DOLBY_DIGITAL)
		TRACE((L"IEC61937_DOLBY_DIGITAL"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_IEC61937_WMA_PRO)
		TRACE((L"IEC61937_WMA_PRO"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_IEC61937_DTS)
		TRACE((L"IEC61937_DTS"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_IEC61937_MPEG1)
		TRACE((L"IEC61937_MPEG1"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_IEC61937_MPEG2)
		TRACE((L"IEC61937_MPEG2"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_IEC61937_MPEG3)
		TRACE((L"IEC61937_MPEG3"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_IEC61937_AAC)
		TRACE((L"IEC61937_AAC"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_IEC61937_ATRAC)
		TRACE((L"IEC61937_ATRAC"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_IEC61937_ONE_BIT_AUDIO)
		TRACE((L"IEC61937_ONE_BIT_AUDIO"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_IEC61937_DOLBY_DIGITAL_PLUS)
		TRACE((L"IEC61937_DOLBY_DIGITAL_PLUS"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_IEC61937_DOLBY_DIGITAL_PLUS_ATMOS)
		TRACE((L"IEC61937_DOLBY_DIGITAL_PLUS_ATMOS"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_IEC61937_DTS_HD)
		TRACE((L"IEC61937_DTS_HD"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_IEC61937_DOLBY_MLP)
		TRACE((L"IEC61937_DOLBY_MLP"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_IEC61937_DOLBY_MAT20)
		TRACE((L"IEC61937_DOLBY_MAT20"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_IEC61937_DOLBY_MAT21)
		TRACE((L"IEC61937_DOLBY_MAT21"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_IEC61937_DST)
		TRACE((L"IEC61937_DST"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_MPEGLAYER3)
		TRACE((L"MPEGLAYER3"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_MPEG_HEAAC)
		TRACE((L"MPEG_HEAAC"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_WMAUDIO2)
		TRACE((L"WMAUDIO2"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_WMAUDIO3)
		TRACE((L"WMAUDIO3"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_WMAUDIO_LOSSLESS)
		TRACE((L"WMAUDIO_LOSSLESS"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_DTS_AUDIO)
		TRACE((L"DTS_AUDIO"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_SDDS_AUDIO)
		TRACE((L"SDDS_AUDIO"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_SUBPICTURE)
		TRACE((L"SUBPICTURE"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_VPVideo)
		TRACE((L"VPVideo"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_VPVBI)
		TRACE((L"VPVBI"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_JPEG)
		TRACE((L"JPEG"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_IMAGE_RGB32)
		TRACE((L"IMAGE_RGB32"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_L8)
		TRACE((L"L8"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_L8_IR)
		TRACE((L"L8_IR"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_L8_CUSTOM)
		TRACE((L"L8_CUSTOM"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_L16)
		TRACE((L"L16"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_L16_IR)
		TRACE((L"L16_IR"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_D16)
		TRACE((L"D16"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_L16_CUSTOM)
		TRACE((L"L16_CUSTOM"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_MJPG_IR)
		TRACE((L"MJPG_IR"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_MJPG_DEPTH)
		TRACE((L"MJPG_DEPTH"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_MJPG_CUSTOM)
		TRACE((L"MJPG_CUSTOM"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_RAW8)
		TRACE((L"RAW8"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_CC)
		TRACE((L"CC"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_NABTS)
		TRACE((L"NABTS"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_TELETEXT)
		TRACE((L"TELETEXT"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_NABTS_FEC)
		TRACE((L"NABTS_FEC"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_OVERLAY)
		TRACE((L"OVERLAY"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_Line21_BytePair)
		TRACE((L"Line21_BytePair"));
	else if(guidSubFormat == KSDATAFORMAT_SUBTYPE_Line21_GOPPacket)
		TRACE((L"Line21_GOPPacket"));
	else{

		LPWSTR pwszID = NULL;
		StringFromCLSID(guidSubFormat, &pwszID);
		TRACE((L"%s", pwszID));
		CoTaskMemFree(pwszID);
	}
}

void LogKsFormatSpecifier(const KSDATAFORMAT* pKsDataFORMAT, LPCWSTR wszLog){

	if(pKsDataFORMAT == NULL){

		TRACE((L"%s : E_POINTER", wszLog));
		return;
	}

	TRACE_NO_END_LINE((L"%s", wszLog));

	const GUID guidSpecifier = pKsDataFORMAT->Specifier;

	if(guidSpecifier == KSDATAFORMAT_SPECIFIER_NONE){

		TRACE((L"NONE"));
	}
	else if(guidSpecifier == KSDATAFORMAT_SPECIFIER_WAVEFORMATEX){

		TRACE((L"WAVEFORMATEX"));

		if(pKsDataFORMAT->FormatSize == sizeof(KSDATAFORMAT) + sizeof(WAVEFORMATEXTENSIBLE)){

			const BYTE* pByte = (const BYTE*)pKsDataFORMAT;
			const WAVEFORMATEXTENSIBLE* pWaveFormatEx = (const WAVEFORMATEXTENSIBLE*)(pByte + sizeof(KSDATAFORMAT));

			if(pWaveFormatEx->Format.wFormatTag == WAVE_FORMAT_EXTENSIBLE){

				TRACE((L"\t\t\t-> Channels\t\t\t\t%d", pWaveFormatEx->Format.nChannels));
				TRACE((L"\t\t\t-> SamplesPerSec\t\t%d", pWaveFormatEx->Format.nSamplesPerSec));
				TRACE((L"\t\t\t-> AvgBytesPerSec\t\t%d", pWaveFormatEx->Format.nAvgBytesPerSec));
				TRACE((L"\t\t\t-> BlockAlign\t\t\t%d", pWaveFormatEx->Format.nBlockAlign));
				TRACE((L"\t\t\t-> BitsPerSample\t\t%d", pWaveFormatEx->Format.wBitsPerSample));
				TRACE((L"\t\t\t-> Size (22)\t\t\t%d", pWaveFormatEx->Format.cbSize));
				TRACE((L"\t\t\t-> ValidBitsPerSample\t%d", pWaveFormatEx->Samples.wValidBitsPerSample));
				TRACE((L"\t\t\t-> SamplesPerBlock\t\t%d", pWaveFormatEx->Samples.wSamplesPerBlock));
				TRACE((L"\t\t\t-> Reserved\t\t\t\t%d", pWaveFormatEx->Samples.wReserved));
				LogSpeaker(pWaveFormatEx->dwChannelMask, L"\t\t\t-> Channel Mask\t\t\t");

				TRACE_NO_END_LINE((L"\t\t\t-> SubFormat Guid\t\t"));

				// SubFormat GUID
				// WAVE_FORMAT_PCM == MEDIASUBTYPE_PCM
				// WAVE_FORMAT_IEEE_FLOAT
				// WAVE_FORMAT_DRM
				// WAVE_FORMAT_ALAW
				// WAVE_FORMAT_MULAW
				// WAVE_FORMAT_ADPCM
				if(pWaveFormatEx->SubFormat == WMMEDIASUBTYPE_PCM){

					TRACE((L"MEDIASUBTYPE_PCM"));
				}
				else{

					LPWSTR pwszID = NULL;
					StringFromCLSID(pWaveFormatEx->SubFormat, &pwszID);
					TRACE((L"%s", pwszID));
					CoTaskMemFree(pwszID);
				}
			}
			else{

				TRACE((L"\t\t\t-> Unknown wave format tag"));
			}
		}
		else if(pKsDataFORMAT->FormatSize == sizeof(KSDATAFORMAT) + sizeof(WAVEFORMATEX)){

			const BYTE* pByte = (const BYTE*)pKsDataFORMAT;
			const WAVEFORMATEX* pWaveFormat = (const WAVEFORMATEX*)(pByte + sizeof(KSDATAFORMAT));

			TRACE_NO_END_LINE((L"\t\t\t-> WaveFormat\t\t\t%d : ", pWaveFormat->wFormatTag));
			LogWaveFormat(pWaveFormat->wFormatTag);
			TRACE((L"\t\t\t-> Channels\t\t\t\t%d", pWaveFormat->nChannels));
			TRACE((L"\t\t\t-> SamplesPerSec\t\t%d", pWaveFormat->nSamplesPerSec));
			TRACE((L"\t\t\t-> AvgBytesPerSec\t\t%d", pWaveFormat->nAvgBytesPerSec));
			TRACE((L"\t\t\t-> BlockAlign\t\t\t%d", pWaveFormat->nBlockAlign));
			TRACE((L"\t\t\t-> BitsPerSample\t\t%d", pWaveFormat->wBitsPerSample));
			TRACE((L"\t\t\t-> Size (22)\t\t\t%d", pWaveFormat->cbSize));
		}
		else{

			TRACE((L"\t\t\t-> Unknown Wave Format"));
		}
	}
	else if(guidSpecifier == KSDATAFORMAT_SPECIFIER_DSOUND){

		TRACE((L"DSOUND"));
	}
	else if(guidSpecifier == KSDATAFORMAT_SPECIFIER_VC_ID){

		TRACE((L"VC_ID"));
	}
	else if(guidSpecifier == KSDATAFORMAT_SPECIFIER_FILENAME){

		TRACE((L"FILENAME"));
	}
	else if(guidSpecifier == KSDATAFORMAT_SPECIFIER_FILEHANDLE){

		TRACE((L"FILEHANDLE"));
	}
	else if(guidSpecifier == KSDATAFORMAT_SPECIFIER_WILDCARD){

		TRACE((L"SPECIFIER_WILDCARD"));
	}
	else{

		LPWSTR pwszID = NULL;
		StringFromCLSID(guidSpecifier, &pwszID);
		TRACE((L"%s", pwszID));
		CoTaskMemFree(pwszID);
	}
}

void LogSpeaker(const UINT uiSpeaker, LPCWSTR lpcszPropertyName){

	TRACE_NO_END_LINE((L"%s", lpcszPropertyName));

	switch(uiSpeaker){

	case KSAUDIO_SPEAKER_MONO:
		TRACE((L"KSAUDIO_SPEAKER_MONO"));
		break;

	case KSAUDIO_SPEAKER_1POINT1:
		TRACE((L"KSAUDIO_SPEAKER_1POINT1"));
		break;

	case KSAUDIO_SPEAKER_STEREO:
		TRACE((L"KSAUDIO_SPEAKER_STEREO"));
		break;

	case KSAUDIO_SPEAKER_2POINT1:
		TRACE((L"KSAUDIO_SPEAKER_2POINT1"));
		break;

	case KSAUDIO_SPEAKER_3POINT0:
		TRACE((L"KSAUDIO_SPEAKER_3POINT0"));
		break;

	case KSAUDIO_SPEAKER_3POINT1:
		TRACE((L"KSAUDIO_SPEAKER_3POINT1"));
		break;

	case KSAUDIO_SPEAKER_QUAD:
		TRACE((L"KSAUDIO_SPEAKER_QUAD"));
		break;

	case KSAUDIO_SPEAKER_SURROUND:
		TRACE((L"KSAUDIO_SPEAKER_SURROUND"));
		break;

	case KSAUDIO_SPEAKER_5POINT0:
		TRACE((L"KSAUDIO_SPEAKER_5POINT0"));
		break;

	case KSAUDIO_SPEAKER_5POINT1:
		TRACE((L"KSAUDIO_SPEAKER_5POINT1"));
		break;

	case KSAUDIO_SPEAKER_7POINT0:
		TRACE((L"KSAUDIO_SPEAKER_7POINT0"));
		break;

	case KSAUDIO_SPEAKER_7POINT1:
		TRACE((L"KSAUDIO_SPEAKER_7POINT1"));
		break;

	case KSAUDIO_SPEAKER_5POINT1_SURROUND:
		TRACE((L"KSAUDIO_SPEAKER_5POINT1_SURROUND"));
		break;

	case KSAUDIO_SPEAKER_7POINT1_SURROUND:
		TRACE((L"KSAUDIO_SPEAKER_7POINT1_SURROUND"));
		break;

	default:
		TRACE((L"Unknown"));
		break;
	}
}

void LogWaveFormat(const WORD wFormatTag){

	if(wFormatTag == WAVE_FORMAT_UNKNOWN)
		TRACE((L"UNKNOWN"));
	else if(wFormatTag == WAVE_FORMAT_PCM)
		TRACE((L"PCM"));
	else if(wFormatTag == WAVE_FORMAT_ADPCM)
		TRACE((L"ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_IEEE_FLOAT)
		TRACE((L"IEEE_FLOAT"));
	/*else if(wFormatTag == WAVE_FORMAT_VSELP)
		TRACE((L"VSELP"));
	else if(wFormatTag == WAVE_FORMAT_IBM_CVSD)
		TRACE((L"IBM_CVSD"));
	else if(wFormatTag == WAVE_FORMAT_ALAW)
		TRACE((L"ALAW"));
	else if(wFormatTag == WAVE_FORMAT_MULAW)
		TRACE((L"MULAW"));
	else if(wFormatTag == WAVE_FORMAT_DTS)
		TRACE((L"DTS"));
	else if(wFormatTag == WAVE_FORMAT_DRM)
		TRACE((L"DRM"));
	else if(wFormatTag == WAVE_FORMAT_WMAVOICE9)
		TRACE((L"WMAVOICE9"));
	else if(wFormatTag == WAVE_FORMAT_WMAVOICE10)
		TRACE((L"WMAVOICE10"));
	else if(wFormatTag == WAVE_FORMAT_OKI_ADPCM)
		TRACE((L"OKI_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_DVI_ADPCM)
		TRACE((L"DVI_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_IMA_ADPCM)
		TRACE((L"IMA_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_MEDIASPACE_ADPCM)
		TRACE((L"MEDIASPACE_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_SIERRA_ADPCM)
		TRACE((L"SIERRA_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_G723_ADPCM)
		TRACE((L"G723_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_DIGISTD)
		TRACE((L"DIGISTD"));
	else if(wFormatTag == WAVE_FORMAT_DIGIFIX)
		TRACE((L"DIGIFIX"));
	else if(wFormatTag == WAVE_FORMAT_DIALOGIC_OKI_ADPCM)
		TRACE((L"DIALOGIC_OKI_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_MEDIAVISION_ADPCM)
		TRACE((L"MEDIAVISION_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_CU_CODEC)
		TRACE((L"CU_CODEC"));
	else if(wFormatTag == WAVE_FORMAT_HP_DYN_VOICE)
		TRACE((L"HP_DYN_VOICE"));
	else if(wFormatTag == WAVE_FORMAT_YAMAHA_ADPCM)
		TRACE((L"YAMAHA_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_SONARC)
		TRACE((L"SONARC"));
	else if(wFormatTag == WAVE_FORMAT_DSPGROUP_TRUESPEECH)
		TRACE((L"DSPGROUP_TRUESPEECH"));
	else if(wFormatTag == WAVE_FORMAT_ECHOSC1)
		TRACE((L"ECHOSC1"));
	else if(wFormatTag == WAVE_FORMAT_AUDIOFILE_AF36)
		TRACE((L"AUDIOFILE_AF36"));
	else if(wFormatTag == WAVE_FORMAT_APTX)
		TRACE((L"APTX"));
	else if(wFormatTag == WAVE_FORMAT_AUDIOFILE_AF10)
		TRACE((L"AUDIOFILE_AF10"));
	else if(wFormatTag == WAVE_FORMAT_PROSODY_1612)
		TRACE((L"PROSODY_1612"));
	else if(wFormatTag == WAVE_FORMAT_LRC)
		TRACE((L"LRC"));
	else if(wFormatTag == WAVE_FORMAT_DOLBY_AC2)
		TRACE((L"DOLBY_AC2"));
	else if(wFormatTag == WAVE_FORMAT_GSM610)
		TRACE((L"GSM610"));
	else if(wFormatTag == WAVE_FORMAT_MSNAUDIO)
		TRACE((L"MSNAUDIO"));
	else if(wFormatTag == WAVE_FORMAT_ANTEX_ADPCME)
		TRACE((L"ANTEX_ADPCME"));
	else if(wFormatTag == WAVE_FORMAT_CONTROL_RES_VQLPC)
		TRACE((L"CONTROL_RES_VQLPC"));
	else if(wFormatTag == WAVE_FORMAT_DIGIREAL)
		TRACE((L"DIGIREAL"));
	else if(wFormatTag == WAVE_FORMAT_DIGIADPCM)
		TRACE((L"DIGIADPCM"));
	else if(wFormatTag == WAVE_FORMAT_CONTROL_RES_CR10)
		TRACE((L"CONTROL_RES_CR10"));
	else if(wFormatTag == WAVE_FORMAT_NMS_VBXADPCM)
		TRACE((L"NMS_VBXADPCM"));
	else if(wFormatTag == WAVE_FORMAT_CS_IMAADPCM)
		TRACE((L"CS_IMAADPCM"));
	else if(wFormatTag == WAVE_FORMAT_ECHOSC3)
		TRACE((L"ECHOSC3"));
	else if(wFormatTag == WAVE_FORMAT_ROCKWELL_ADPCM)
		TRACE((L"ROCKWELL_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_ROCKWELL_DIGITALK)
		TRACE((L"ROCKWELL_DIGITALK"));
	else if(wFormatTag == WAVE_FORMAT_XEBEC)
		TRACE((L"XEBEC"));
	else if(wFormatTag == WAVE_FORMAT_G721_ADPCM)
		TRACE((L"G721_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_G728_CELP)
		TRACE((L"G728_CELP"));
	else if(wFormatTag == WAVE_FORMAT_MSG723)
		TRACE((L"MSG723"));
	else if(wFormatTag == WAVE_FORMAT_INTEL_G723_1)
		TRACE((L"INTEL_G723_1"));
	else if(wFormatTag == WAVE_FORMAT_INTEL_G729)
		TRACE((L"INTEL_G729"));
	else if(wFormatTag == WAVE_FORMAT_SHARP_G726)
		TRACE((L"SHARP_G726"));
	else if(wFormatTag == WAVE_FORMAT_MPEG)
		TRACE((L"MPEG"));
	else if(wFormatTag == WAVE_FORMAT_RT24)
		TRACE((L"RT24"));
	else if(wFormatTag == WAVE_FORMAT_PAC)
		TRACE((L"PAC"));
	else if(wFormatTag == WAVE_FORMAT_MPEGLAYER3)
		TRACE((L"MPEGLAYER3"));
	else if(wFormatTag == WAVE_FORMAT_LUCENT_G723)
		TRACE((L"LUCENT_G723"));
	else if(wFormatTag == WAVE_FORMAT_CIRRUS)
		TRACE((L"CIRRUS"));
	else if(wFormatTag == WAVE_FORMAT_ESPCM)
		TRACE((L"ESPCM"));
	else if(wFormatTag == WAVE_FORMAT_VOXWARE)
		TRACE((L"VOXWARE"));
	else if(wFormatTag == WAVE_FORMAT_CANOPUS_ATRAC)
		TRACE((L"CANOPUS_ATRAC"));
	else if(wFormatTag == WAVE_FORMAT_G726_ADPCM)
		TRACE((L"G726_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_G722_ADPCM)
		TRACE((L"G722_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_DSAT)
		TRACE((L"DSAT"));
	else if(wFormatTag == WAVE_FORMAT_DSAT_DISPLAY)
		TRACE((L"DSAT_DISPLAY"));
	else if(wFormatTag == WAVE_FORMAT_VOXWARE_BYTE_ALIGNED)
		TRACE((L"VOXWARE_BYTE_ALIGNED"));
	else if(wFormatTag == WAVE_FORMAT_VOXWARE_AC8)
		TRACE((L"VOXWARE_AC8"));
	else if(wFormatTag == WAVE_FORMAT_VOXWARE_AC10)
		TRACE((L"VOXWARE_AC10"));
	else if(wFormatTag == WAVE_FORMAT_VOXWARE_AC16)
		TRACE((L"VOXWARE_AC16"));
	else if(wFormatTag == WAVE_FORMAT_VOXWARE_AC20)
		TRACE((L"VOXWARE_AC20"));
	else if(wFormatTag == WAVE_FORMAT_VOXWARE_RT24)
		TRACE((L"VOXWARE_RT24"));
	else if(wFormatTag == WAVE_FORMAT_VOXWARE_RT29)
		TRACE((L"VOXWARE_RT29"));
	else if(wFormatTag == WAVE_FORMAT_VOXWARE_RT29HW)
		TRACE((L"VOXWARE_RT29HW"));
	else if(wFormatTag == WAVE_FORMAT_VOXWARE_VR12)
		TRACE((L"VOXWARE_VR12"));
	else if(wFormatTag == WAVE_FORMAT_VOXWARE_VR18)
		TRACE((L"VOXWARE_VR18"));
	else if(wFormatTag == WAVE_FORMAT_VOXWARE_TQ40)
		TRACE((L"VOXWARE_TQ40"));
	else if(wFormatTag == WAVE_FORMAT_VOXWARE_SC3)
		TRACE((L"VOXWARE_SC3"));
	else if(wFormatTag == WAVE_FORMAT_VOXWARE_SC3_1)
		TRACE((L"VOXWARE_SC3_1"));
	else if(wFormatTag == WAVE_FORMAT_SOFTSOUND)
		TRACE((L"SOFTSOUND"));
	else if(wFormatTag == WAVE_FORMAT_VOXWARE_TQ60)
		TRACE((L"VOXWARE_TQ60"));
	else if(wFormatTag == WAVE_FORMAT_MSRT24)
		TRACE((L"MSRT24"));
	else if(wFormatTag == WAVE_FORMAT_G729A)
		TRACE((L"G729A"));
	else if(wFormatTag == WAVE_FORMAT_MVI_MVI2)
		TRACE((L"MVI_MVI2"));
	else if(wFormatTag == WAVE_FORMAT_DF_G726)
		TRACE((L"DF_G726"));
	else if(wFormatTag == WAVE_FORMAT_DF_GSM610)
		TRACE((L"DF_GSM610"));
	else if(wFormatTag == WAVE_FORMAT_ISIAUDIO)
		TRACE((L"ISIAUDIO"));
	else if(wFormatTag == WAVE_FORMAT_ONLIVE)
		TRACE((L"ONLIVE"));
	else if(wFormatTag == WAVE_FORMAT_MULTITUDE_FT_SX20)
		TRACE((L"MULTITUDE_FT_SX20"));
	else if(wFormatTag == WAVE_FORMAT_INFOCOM_ITS_G721_ADPCM)
		TRACE((L"INFOCOM_ITS_G721_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_CONVEDIA_G729)
		TRACE((L"CONVEDIA_G729"));
	else if(wFormatTag == WAVE_FORMAT_CONGRUENCY)
		TRACE((L"CONGRUENCY"));
	else if(wFormatTag == WAVE_FORMAT_SBC24)
		TRACE((L"SBC24"));*/
	else if(wFormatTag == WAVE_FORMAT_DOLBY_AC3_SPDIF)
		TRACE((L"DOLBY_AC3_SPDIF"));
	/*else if(wFormatTag == WAVE_FORMAT_MEDIASONIC_G723)
		TRACE((L"MEDIASONIC_G723"));
	else if(wFormatTag == WAVE_FORMAT_PROSODY_8KBPS)
		TRACE((L"PROSODY_8KBPS"));
	else if(wFormatTag == WAVE_FORMAT_ZYXEL_ADPCM)
		TRACE((L"ZYXEL_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_PHILIPS_LPCBB)
		TRACE((L"PHILIPS_LPCBB"));
	else if(wFormatTag == WAVE_FORMAT_PACKED)
		TRACE((L"PACKED"));
	else if(wFormatTag == WAVE_FORMAT_MALDEN_PHONYTALK)
		TRACE((L"MALDEN_PHONYTALK"));
	else if(wFormatTag == WAVE_FORMAT_RACAL_RECORDER_GSM)
		TRACE((L"RACAL_RECORDER_GSM"));
	else if(wFormatTag == WAVE_FORMAT_RACAL_RECORDER_G720_A)
		TRACE((L"RACAL_RECORDER_G720_A"));
	else if(wFormatTag == WAVE_FORMAT_RACAL_RECORDER_G723_1)
		TRACE((L"RACAL_RECORDER_G723_1"));
	else if(wFormatTag == WAVE_FORMAT_RACAL_RECORDER_TETRA_ACELP)
		TRACE((L"RACAL_RECORDER_TETRA_ACELP"));
	else if(wFormatTag == WAVE_FORMAT_NEC_AAC)
		TRACE((L"NEC_AAC"));
	else if(wFormatTag == WAVE_FORMAT_RAW_AAC1)
		TRACE((L"RAW_AAC1"));
	else if(wFormatTag == WAVE_FORMAT_RHETOREX_ADPCM)
		TRACE((L"RHETOREX_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_IRAT)
		TRACE((L"IRAT"));
	else if(wFormatTag == WAVE_FORMAT_VIVO_G723)
		TRACE((L"VIVO_G723"));
	else if(wFormatTag == WAVE_FORMAT_VIVO_SIREN)
		TRACE((L"VIVO_SIREN"));
	else if(wFormatTag == WAVE_FORMAT_PHILIPS_CELP)
		TRACE((L"PHILIPS_CELP"));
	else if(wFormatTag == WAVE_FORMAT_PHILIPS_GRUNDIG)
		TRACE((L"PHILIPS_GRUNDIG"));
	else if(wFormatTag == WAVE_FORMAT_DIGITAL_G723)
		TRACE((L"DIGITAL_G723"));
	else if(wFormatTag == WAVE_FORMAT_SANYO_LD_ADPCM)
		TRACE((L"SANYO_LD_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_SIPROLAB_ACEPLNET)
		TRACE((L"SIPROLAB_ACEPLNET"));
	else if(wFormatTag == WAVE_FORMAT_SIPROLAB_ACELP4800)
		TRACE((L"SIPROLAB_ACELP4800"));
	else if(wFormatTag == WAVE_FORMAT_SIPROLAB_ACELP8V3)
		TRACE((L"SIPROLAB_ACELP8V3"));
	else if(wFormatTag == WAVE_FORMAT_SIPROLAB_G729)
		TRACE((L"SIPROLAB_G729"));
	else if(wFormatTag == WAVE_FORMAT_SIPROLAB_G729A)
		TRACE((L"SIPROLAB_G729A"));
	else if(wFormatTag == WAVE_FORMAT_SIPROLAB_KELVIN)
		TRACE((L"SIPROLAB_KELVIN"));
	else if(wFormatTag == WAVE_FORMAT_VOICEAGE_AMR)
		TRACE((L"VOICEAGE_AMR"));
	else if(wFormatTag == WAVE_FORMAT_G726ADPCM)
		TRACE((L"G726ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_DICTAPHONE_CELP68)
		TRACE((L"DICTAPHONE_CELP68"));
	else if(wFormatTag == WAVE_FORMAT_DICTAPHONE_CELP54)
		TRACE((L"DICTAPHONE_CELP54"));
	else if(wFormatTag == WAVE_FORMAT_QUALCOMM_PUREVOICE)
		TRACE((L"QUALCOMM_PUREVOICE"));
	else if(wFormatTag == WAVE_FORMAT_QUALCOMM_HALFRATE)
		TRACE((L"QUALCOMM_HALFRATE"));
	else if(wFormatTag == WAVE_FORMAT_TUBGSM)
		TRACE((L"TUBGSM"));
	else if(wFormatTag == WAVE_FORMAT_MSAUDIO1)
		TRACE((L"MSAUDIO1"));
	else if(wFormatTag == WAVE_FORMAT_WMAUDIO2)
		TRACE((L"WMAUDIO2"));
	else if(wFormatTag == WAVE_FORMAT_WMAUDIO3)
		TRACE((L"WMAUDIO3"));
	else if(wFormatTag == WAVE_FORMAT_WMAUDIO_LOSSLESS)
		TRACE((L"WMAUDIO_LOSSLESS"));
	else if(wFormatTag == WAVE_FORMAT_WMASPDIF)
		TRACE((L"WMASPDIF"));
	else if(wFormatTag == WAVE_FORMAT_UNISYS_NAP_ADPCM)
		TRACE((L"UNISYS_NAP_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_UNISYS_NAP_ULAW)
		TRACE((L"UNISYS_NAP_ULAW"));
	else if(wFormatTag == WAVE_FORMAT_UNISYS_NAP_ALAW)
		TRACE((L"UNISYS_NAP_ALAW"));
	else if(wFormatTag == WAVE_FORMAT_UNISYS_NAP_16K)
		TRACE((L"UNISYS_NAP_16K"));
	else if(wFormatTag == WAVE_FORMAT_SYCOM_ACM_SYC008)
		TRACE((L"SYCOM_ACM_SYC008"));
	else if(wFormatTag == WAVE_FORMAT_SYCOM_ACM_SYC701_G726L)
		TRACE((L"SYCOM_ACM_SYC701_G726L"));
	else if(wFormatTag == WAVE_FORMAT_SYCOM_ACM_SYC701_CELP54)
		TRACE((L"SYCOM_ACM_SYC701_CELP54"));
	else if(wFormatTag == WAVE_FORMAT_SYCOM_ACM_SYC701_CELP68)
		TRACE((L"SYCOM_ACM_SYC701_CELP68"));
	else if(wFormatTag == WAVE_FORMAT_KNOWLEDGE_ADVENTURE_ADPCM)
		TRACE((L"KNOWLEDGE_ADVENTURE_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_FRAUNHOFER_IIS_MPEG2_AAC)
		TRACE((L"FRAUNHOFER_IIS_MPEG2_AAC"));
	else if(wFormatTag == WAVE_FORMAT_DTS_DS)
		TRACE((L"DTS_DS"));
	else if(wFormatTag == WAVE_FORMAT_CREATIVE_ADPCM)
		TRACE((L"CREATIVE_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_CREATIVE_FASTSPEECH8)
		TRACE((L"CREATIVE_FASTSPEECH8"));
	else if(wFormatTag == WAVE_FORMAT_CREATIVE_FASTSPEECH10)
		TRACE((L"CREATIVE_FASTSPEECH10"));
	else if(wFormatTag == WAVE_FORMAT_UHER_ADPCM)
		TRACE((L"UHER_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_ULEAD_DV_AUDIO)
		TRACE((L"ULEAD_DV_AUDIO"));
	else if(wFormatTag == WAVE_FORMAT_ULEAD_DV_AUDIO_1)
		TRACE((L"ULEAD_DV_AUDIO_1"));
	else if(wFormatTag == WAVE_FORMAT_QUARTERDECK)
		TRACE((L"QUARTERDECK"));
	else if(wFormatTag == WAVE_FORMAT_ILINK_VC)
		TRACE((L"ILINK_VC"));
	else if(wFormatTag == WAVE_FORMAT_RAW_SPORT)
		TRACE((L"RAW_SPORT"));
	else if(wFormatTag == WAVE_FORMAT_ESST_AC3)
		TRACE((L"ESST_AC3"));
	else if(wFormatTag == WAVE_FORMAT_GENERIC_PASSTHRU)
		TRACE((L"GENERIC_PASSTHRU"));
	else if(wFormatTag == WAVE_FORMAT_IPI_HSX)
		TRACE((L"IPI_HSX"));
	else if(wFormatTag == WAVE_FORMAT_IPI_RPELP)
		TRACE((L"IPI_RPELP"));
	else if(wFormatTag == WAVE_FORMAT_CS2)
		TRACE((L"CS2"));
	else if(wFormatTag == WAVE_FORMAT_SONY_SCX)
		TRACE((L"SONY_SCX"));
	else if(wFormatTag == WAVE_FORMAT_SONY_SCY)
		TRACE((L"SONY_SCY"));
	else if(wFormatTag == WAVE_FORMAT_SONY_ATRAC3)
		TRACE((L"SONY_ATRAC3"));
	else if(wFormatTag == WAVE_FORMAT_SONY_SPC)
		TRACE((L"SONY_SPC"));
	else if(wFormatTag == WAVE_FORMAT_TELUM_AUDIO)
		TRACE((L"TELUM_AUDIO"));
	else if(wFormatTag == WAVE_FORMAT_TELUM_IA_AUDIO)
		TRACE((L"TELUM_IA_AUDIO"));
	else if(wFormatTag == WAVE_FORMAT_NORCOM_VOICE_SYSTEMS_ADPCM)
		TRACE((L"NORCOM_VOICE_SYSTEMS_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_FM_TOWNS_SND)
		TRACE((L"FM_TOWNS_SND"));
	else if(wFormatTag == WAVE_FORMAT_MICRONAS)
		TRACE((L"MICRONAS"));
	else if(wFormatTag == WAVE_FORMAT_MICRONAS_CELP833)
		TRACE((L"MICRONAS_CELP833"));
	else if(wFormatTag == WAVE_FORMAT_BTV_DIGITAL)
		TRACE((L"BTV_DIGITAL"));
	else if(wFormatTag == WAVE_FORMAT_INTEL_MUSIC_CODER)
		TRACE((L"INTEL_MUSIC_CODER"));
	else if(wFormatTag == WAVE_FORMAT_INDEO_AUDIO)
		TRACE((L"INDEO_AUDIO"));
	else if(wFormatTag == WAVE_FORMAT_QDESIGN_MUSIC)
		TRACE((L"QDESIGN_MUSIC"));
	else if(wFormatTag == WAVE_FORMAT_ON2_VP7_AUDIO)
		TRACE((L"ON2_VP7_AUDIO"));
	else if(wFormatTag == WAVE_FORMAT_ON2_VP6_AUDIO)
		TRACE((L"ON2_VP6_AUDIO"));
	else if(wFormatTag == WAVE_FORMAT_VME_VMPCM)
		TRACE((L"VME_VMPCM"));
	else if(wFormatTag == WAVE_FORMAT_TPC)
		TRACE((L"TPC"));
	else if(wFormatTag == WAVE_FORMAT_LIGHTWAVE_LOSSLESS)
		TRACE((L"LIGHTWAVE_LOSSLESS"));
	else if(wFormatTag == WAVE_FORMAT_OLIGSM)
		TRACE((L"OLIGSM"));
	else if(wFormatTag == WAVE_FORMAT_OLIADPCM)
		TRACE((L"OLIADPCM"));
	else if(wFormatTag == WAVE_FORMAT_OLICELP)
		TRACE((L"OLICELP"));
	else if(wFormatTag == WAVE_FORMAT_OLISBC)
		TRACE((L"OLISBC"));
	else if(wFormatTag == WAVE_FORMAT_OLIOPR)
		TRACE((L"OLIOPR"));
	else if(wFormatTag == WAVE_FORMAT_LH_CODEC)
		TRACE((L"LH_CODEC"));
	else if(wFormatTag == WAVE_FORMAT_LH_CODEC_CELP)
		TRACE((L"LH_CODEC_CELP"));
	else if(wFormatTag == WAVE_FORMAT_LH_CODEC_SBC8)
		TRACE((L"LH_CODEC_SBC8"));
	else if(wFormatTag == WAVE_FORMAT_LH_CODEC_SBC12)
		TRACE((L"LH_CODEC_SBC12"));
	else if(wFormatTag == WAVE_FORMAT_LH_CODEC_SBC16)
		TRACE((L"LH_CODEC_SBC16"));
	else if(wFormatTag == WAVE_FORMAT_NORRIS)
		TRACE((L"NORRIS"));
	else if(wFormatTag == WAVE_FORMAT_ISIAUDIO_2)
		TRACE((L"ISIAUDIO_2"));
	else if(wFormatTag == WAVE_FORMAT_SOUNDSPACE_MUSICOMPRESS)
		TRACE((L"SOUNDSPACE_MUSICOMPRESS"));
	else if(wFormatTag == WAVE_FORMAT_MPEG_ADTS_AAC)
		TRACE((L"MPEG_ADTS_AAC"));
	else if(wFormatTag == WAVE_FORMAT_MPEG_RAW_AAC)
		TRACE((L"MPEG_RAW_AAC"));
	else if(wFormatTag == WAVE_FORMAT_MPEG_LOAS)
		TRACE((L"MPEG_LOAS"));
	else if(wFormatTag == WAVE_FORMAT_NOKIA_MPEG_ADTS_AAC)
		TRACE((L"NOKIA_MPEG_ADTS_AAC"));
	else if(wFormatTag == WAVE_FORMAT_NOKIA_MPEG_RAW_AAC)
		TRACE((L"NOKIA_MPEG_RAW_AAC"));
	else if(wFormatTag == WAVE_FORMAT_VODAFONE_MPEG_ADTS_AAC)
		TRACE((L"VODAFONE_MPEG_ADTS_AAC"));
	else if(wFormatTag == WAVE_FORMAT_VODAFONE_MPEG_RAW_AAC)
		TRACE((L"VODAFONE_MPEG_RAW_AAC"));
	else if(wFormatTag == WAVE_FORMAT_MPEG_HEAAC)
		TRACE((L"MPEG_HEAAC"));
	else if(wFormatTag == WAVE_FORMAT_VOXWARE_RT24_SPEECH)
		TRACE((L"VOXWARE_RT24_SPEECH"));
	else if(wFormatTag == WAVE_FORMAT_SONICFOUNDRY_LOSSLESS)
		TRACE((L"SONICFOUNDRY_LOSSLESS"));
	else if(wFormatTag == WAVE_FORMAT_INNINGS_TELECOM_ADPCM)
		TRACE((L"INNINGS_TELECOM_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_LUCENT_SX8300P)
		TRACE((L"LUCENT_SX8300P"));
	else if(wFormatTag == WAVE_FORMAT_LUCENT_SX5363S)
		TRACE((L"LUCENT_SX5363S"));
	else if(wFormatTag == WAVE_FORMAT_CUSEEME)
		TRACE((L"CUSEEME"));
	else if(wFormatTag == WAVE_FORMAT_NTCSOFT_ALF2CM_ACM)
		TRACE((L"NTCSOFT_ALF2CM_ACM"));
	else if(wFormatTag == WAVE_FORMAT_DVM)
		TRACE((L"DVM"));
	else if(wFormatTag == WAVE_FORMAT_DTS2)
		TRACE((L"DTS2"));
	else if(wFormatTag == WAVE_FORMAT_MAKEAVIS)
		TRACE((L"MAKEAVIS"));
	else if(wFormatTag == WAVE_FORMAT_DIVIO_MPEG4_AAC)
		TRACE((L"DIVIO_MPEG4_AAC"));
	else if(wFormatTag == WAVE_FORMAT_NOKIA_ADAPTIVE_MULTIRATE)
		TRACE((L"NOKIA_ADAPTIVE_MULTIRATE"));
	else if(wFormatTag == WAVE_FORMAT_DIVIO_G726)
		TRACE((L"DIVIO_G726"));
	else if(wFormatTag == WAVE_FORMAT_LEAD_SPEECH)
		TRACE((L"LEAD_SPEECH"));
	else if(wFormatTag == WAVE_FORMAT_LEAD_VORBIS)
		TRACE((L"LEAD_VORBIS"));
	else if(wFormatTag == WAVE_FORMAT_WAVPACK_AUDIO)
		TRACE((L"WAVPACK_AUDIO"));
	else if(wFormatTag == WAVE_FORMAT_ALAC)
		TRACE((L"ALAC"));
	else if(wFormatTag == WAVE_FORMAT_OGG_VORBIS_MODE_1)
		TRACE((L"OGG_VORBIS_MODE_1"));
	else if(wFormatTag == WAVE_FORMAT_OGG_VORBIS_MODE_2)
		TRACE((L"OGG_VORBIS_MODE_2"));
	else if(wFormatTag == WAVE_FORMAT_OGG_VORBIS_MODE_3)
		TRACE((L"OGG_VORBIS_MODE_3"));
	else if(wFormatTag == WAVE_FORMAT_OGG_VORBIS_MODE_1_PLUS)
		TRACE((L"OGG_VORBIS_MODE_1_PLUS"));
	else if(wFormatTag == WAVE_FORMAT_OGG_VORBIS_MODE_2_PLUS)
		TRACE((L"OGG_VORBIS_MODE_2_PLUS"));
	else if(wFormatTag == WAVE_FORMAT_OGG_VORBIS_MODE_3_PLUS)
		TRACE((L"OGG_VORBIS_MODE_3_PLUS"));
	else if(wFormatTag == WAVE_FORMAT_3COM_NBX)
		TRACE((L"3COM_NBX"));
	else if(wFormatTag == WAVE_FORMAT_OPUS)
		TRACE((L"OPUS"));
	else if(wFormatTag == WAVE_FORMAT_FAAD_AAC)
		TRACE((L"FAAD_AAC"));
	else if(wFormatTag == WAVE_FORMAT_AMR_NB)
		TRACE((L"AMR_NB"));
	else if(wFormatTag == WAVE_FORMAT_AMR_WB)
		TRACE((L"AMR_WB"));
	else if(wFormatTag == WAVE_FORMAT_AMR_WP)
		TRACE((L"AMR_WP"));
	else if(wFormatTag == WAVE_FORMAT_GSM_AMR_CBR)
		TRACE((L"GSM_AMR_CBR"));
	else if(wFormatTag == WAVE_FORMAT_GSM_AMR_VBR_SID)
		TRACE((L"GSM_AMR_VBR_SID"));
	else if(wFormatTag == WAVE_FORMAT_COMVERSE_INFOSYS_G723_1)
		TRACE((L"COMVERSE_INFOSYS_G723_1"));
	else if(wFormatTag == WAVE_FORMAT_COMVERSE_INFOSYS_AVQSBC)
		TRACE((L"COMVERSE_INFOSYS_AVQSBC"));
	else if(wFormatTag == WAVE_FORMAT_COMVERSE_INFOSYS_SBC)
		TRACE((L"COMVERSE_INFOSYS_SBC"));
	else if(wFormatTag == WAVE_FORMAT_SYMBOL_G729_A)
		TRACE((L"SYMBOL_G729_A"));
	else if(wFormatTag == WAVE_FORMAT_VOICEAGE_AMR_WB)
		TRACE((L"VOICEAGE_AMR_WB"));
	else if(wFormatTag == WAVE_FORMAT_INGENIENT_G726)
		TRACE((L"INGENIENT_G726"));
	else if(wFormatTag == WAVE_FORMAT_MPEG4_AAC)
		TRACE((L"MPEG4_AAC"));
	else if(wFormatTag == WAVE_FORMAT_ENCORE_G726)
		TRACE((L"ENCORE_G726"));
	else if(wFormatTag == WAVE_FORMAT_ZOLL_ASAO)
		TRACE((L"ZOLL_ASAO"));
	else if(wFormatTag == WAVE_FORMAT_SPEEX_VOICE)
		TRACE((L"SPEEX_VOICE"));
	else if(wFormatTag == WAVE_FORMAT_VIANIX_MASC)
		TRACE((L"VIANIX_MASC"));
	else if(wFormatTag == WAVE_FORMAT_WM9_SPECTRUM_ANALYZER)
		TRACE((L"WM9_SPECTRUM_ANALYZER"));
	else if(wFormatTag == WAVE_FORMAT_WMF_SPECTRUM_ANAYZER)
		TRACE((L"WMF_SPECTRUM_ANAYZER"));
	else if(wFormatTag == WAVE_FORMAT_GSM_610)
		TRACE((L"GSM_610"));
	else if(wFormatTag == WAVE_FORMAT_GSM_620)
		TRACE((L"GSM_620"));
	else if(wFormatTag == WAVE_FORMAT_GSM_660)
		TRACE((L"GSM_660"));
	else if(wFormatTag == WAVE_FORMAT_GSM_690)
		TRACE((L"GSM_690"));
	else if(wFormatTag == WAVE_FORMAT_GSM_ADAPTIVE_MULTIRATE_WB)
		TRACE((L"GSM_ADAPTIVE_MULTIRATE_WB"));
	else if(wFormatTag == WAVE_FORMAT_POLYCOM_G722)
		TRACE((L"POLYCOM_G722"));
	else if(wFormatTag == WAVE_FORMAT_POLYCOM_G728)
		TRACE((L"POLYCOM_G728"));
	else if(wFormatTag == WAVE_FORMAT_POLYCOM_G729_A)
		TRACE((L"POLYCOM_G729_A"));
	else if(wFormatTag == WAVE_FORMAT_POLYCOM_SIREN)
		TRACE((L"POLYCOM_SIREN"));
	else if(wFormatTag == WAVE_FORMAT_GLOBAL_IP_ILBC)
		TRACE((L"GLOBAL_IP_ILBC"));
	else if(wFormatTag == WAVE_FORMAT_RADIOTIME_TIME_SHIFT_RADIO)
		TRACE((L"RADIOTIME_TIME_SHIFT_RADIO"));
	else if(wFormatTag == WAVE_FORMAT_NICE_ACA)
		TRACE((L"NICE_ACA"));
	else if(wFormatTag == WAVE_FORMAT_NICE_ADPCM)
		TRACE((L"NICE_ADPCM"));
	else if(wFormatTag == WAVE_FORMAT_VOCORD_G721)
		TRACE((L"VOCORD_G721"));
	else if(wFormatTag == WAVE_FORMAT_VOCORD_G726)
		TRACE((L"VOCORD_G726"));
	else if(wFormatTag == WAVE_FORMAT_VOCORD_G722_1)
		TRACE((L"VOCORD_G722_1"));
	else if(wFormatTag == WAVE_FORMAT_VOCORD_G728)
		TRACE((L"VOCORD_G728"));
	else if(wFormatTag == WAVE_FORMAT_VOCORD_G729)
		TRACE((L"VOCORD_G729"));
	else if(wFormatTag == WAVE_FORMAT_VOCORD_G729_A)
		TRACE((L"VOCORD_G729_A"));
	else if(wFormatTag == WAVE_FORMAT_VOCORD_G723_1)
		TRACE((L"VOCORD_G723_1"));
	else if(wFormatTag == WAVE_FORMAT_VOCORD_LBC)
		TRACE((L"VOCORD_LBC"));
	else if(wFormatTag == WAVE_FORMAT_NICE_G728)
		TRACE((L"NICE_G728"));
	else if(wFormatTag == WAVE_FORMAT_FRACE_TELECOM_G729)
		TRACE((L"FRACE_TELECOM_G729"));
	else if(wFormatTag == WAVE_FORMAT_CODIAN)
		TRACE((L"CODIAN"));
	else if(wFormatTag == WAVE_FORMAT_FLAC)
		TRACE((L"FLAC"));*/
	else if(wFormatTag == WAVE_FORMAT_EXTENSIBLE)
		TRACE((L"EXTENSIBLE"));
	else if(wFormatTag == WAVE_FORMAT_DEVELOPMENT)
		TRACE((L"DEVELOPMENT"));
	else
		TRACE((L"Unknown"));
}