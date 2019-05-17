//----------------------------------------------------------------------------------------------
// MFMacro.h
//----------------------------------------------------------------------------------------------
#ifndef MFMACRO_H
#define MFMACRO_H

#define CLSID_MMDeviceEnumerator __uuidof(MMDeviceEnumerator)

template <class T> inline void SAFE_RELEASE(T*& p){

	if(p){
		p->Release();
		p = NULL;
	}
}

template<class T> inline void SAFE_DELETE(T*& p){

	if(p){
		delete p;
		p = NULL;
	}
}

template<class T> inline void SAFE_DELETE_ARRAY(T*& p){

	if(p){
		delete[] p;
		p = NULL;
	}
}

#define IF_FAILED_RETURN(x) { hr = (x); if( FAILED(hr) ) { return hr; } }
#define IF_FAILED_THROW(x) { hr = (x); if( FAILED(hr) ) { throw hr; } }

#ifdef _DEBUG
class DebugLog{

	public:

		static void Initialize(){
			_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
			//_CrtSetBreakAlloc(155);
		}

		static void Close(){
			int bLeak = _CrtDumpMemoryLeaks();
			assert(bLeak == FALSE);
		}

		static void Trace(const WCHAR* sFormatString, ...){

			HRESULT hr = S_OK;
			va_list va;

			const DWORD TRACE_STRING_LEN = 512;

			WCHAR message[TRACE_STRING_LEN];

			va_start(va, sFormatString);
			hr = StringCchVPrintf(message, TRACE_STRING_LEN, sFormatString, va);
			va_end(va);

			if(SUCCEEDED(hr)){

				size_t size = _tcslen(message);

				if(size != 0 && size < TRACE_STRING_LEN){
					message[size] = '\n';
					message[size + 1] = '\0';
				}

				_CrtDbgReport(_CRT_WARN, NULL, NULL, NULL, "%S", message);
			}
		}

		static void TraceNoEndLine(const WCHAR* sFormatString, ...){

			HRESULT hr = S_OK;
			va_list va;

			const DWORD TRACE_STRING_LEN = 512;

			WCHAR message[TRACE_STRING_LEN];

			va_start(va, sFormatString);
			hr = StringCchVPrintf(message, TRACE_STRING_LEN, sFormatString, va);
			va_end(va);

			if(SUCCEEDED(hr)){

				_CrtDbgReport(_CRT_WARN, NULL, NULL, NULL, "%S", message);
			}
		}
};

#define TRACE_INIT() DebugLog::Initialize()
#define TRACE(x) DebugLog::Trace x
#define TRACE_NO_END_LINE(x) DebugLog::TraceNoEndLine x
#define TRACE_CLOSE() DebugLog::Close()

#else
#define TRACE(x) x
#define TRACE_NO_END_LINE(x) x
#endif

#endif