#include "SpoofSteamDll.h"

cSteamSpoof::cSteamSpoof()
{
	IsPathExists = false;
	IsSpoofed = false;

	sSteamPath = "";
	sSteamDll = "";
	sNewSteamDll = "";

	Initialize();
}

void cSteamSpoof::Initialize()
{
	GetSteamDll();
	IsSpoofed = CheckSpoof();
}

void cSteamSpoof::GetSteamDll()
{
	const char* cProcName = "Steam.exe";

	string sProcPath = "";
	//string sProcPath = ProcHelper.ProcPath(cProcName);
	//sProcPath = ProcHelper.TreatGetedProcPath(sProcPath, cProcName);

	// Plan B to get Steam Path
	if (sProcPath.size() <= 1)
		sProcPath = GetSteamPath2();

	if (sProcPath.size() > 1)
		IsPathExists = true;
	else
		return;

	sSteamPath = sProcPath;

	sSteamDll = sProcPath + "crashhandler.dll";
	sNewSteamDll = sProcPath + "crashhandler1.dll";
}

string cSteamSpoof::GetSteamPath2()
{
	char value[256];
	DWORD BufferSize = 256;
	RegGetValueA(HKEY_CURRENT_USER, "SOFTWARE\\Valve\\Steam", "SteamPath", RRF_RT_ANY, NULL, (PVOID)&value, &BufferSize);
	sSteamPath = (string)value + "\\";
	return (string)value + "\\";
}

void cSteamSpoof::MainSteamDllSpoof()
{
	SpoofSteamDll();
}

void cSteamSpoof::SpoofSteamDll()
{
	rename(sSteamDll.c_str(), sNewSteamDll.c_str());

	IsSpoofed = CheckSpoof();
}

void cSteamSpoof::UnSpoofSteamDll()
{
	rename(sNewSteamDll.c_str(), sSteamDll.c_str());

	IsSpoofed = CheckSpoof();
}

bool cSteamSpoof::IsSteamDllExists()
{
	wstring wsTemp = wstring(sSteamDll.begin(), sSteamDll.end());
	LPCWSTR lwsSteamDll = wsTemp.c_str();

	if (PathFileExistsW(lwsSteamDll))
		return true;

	return false;
}

bool cSteamSpoof::CheckSpoof()
{
	wstring wsTemp = wstring(sNewSteamDll.begin(), sNewSteamDll.end());
	LPCWSTR lwsSteamDll = wsTemp.c_str();

	if (PathFileExistsW(lwsSteamDll))
		return true;

	return false;
}