//----------------------------------------------------------------------------------------------
// StdAfx.h
//----------------------------------------------------------------------------------------------
#ifndef STDAFX_H
#define STDAFX_H

#pragma once
#define WIN32_LEAN_AND_MEAN
#define STRICT

#pragma comment(lib, "KSProxy")
#pragma comment(lib, "Mfuuid")
#pragma comment(lib, "Strmiids")

#include <vector>
using std::vector;

#define INITGUID

#include <WinSDKVer.h>
#include <new>
#include <windows.h>
#include <crtdbg.h>
#include <tchar.h>
#include <assert.h>
#include <strsafe.h>
#include <Objbase.h>
#include <initguid.h>
#include <mmdeviceapi.h>
#include <Functiondiscoverykeys_devpkey.h>
#include <devicetopology.h>
#include <Audioclient.h>
#include <endpointvolume.h>
#include <audiopolicy.h>
#include <dshow.h>
#include <dsound.h>
#include <mfidl.h>
#include <wmsdkidl.h>
#include <ks.h>
#include <ksmedia.h>

#include "MFMacro.h"
#include "MFLogType.h"
#include "ExternTrace.h"
#include "MMDeviceInfo.h"
#include "JackDescription.h"
#include "ConnectorInfo.h"
#include "SubunitInfo.h"
#include "AudioPart.h"
#include "DeviceTopologyInfo.h"
#include "DeviceAudioManager.h"

#endif