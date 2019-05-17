//----------------------------------------------------------------------------------------------
// MFLogType.h
//----------------------------------------------------------------------------------------------
#ifndef MFLogType_H
#define MFLogType_H

void LogKsNodeType(const GUID&, LPCWSTR);
void LogKsMajorFormatType(const GUID&, LPCWSTR);
void LogKsSubFormatType(const GUID&, LPCWSTR);
void LogKsFormatSpecifier(const KSDATAFORMAT*, LPCWSTR);
void LogSpeaker(const UINT, LPCWSTR);
void LogWaveFormat(const WORD);

#endif