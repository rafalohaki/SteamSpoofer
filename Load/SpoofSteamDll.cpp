#include "SpoofSteamDll.h"

cSteamSpoof::cSteamSpoof()
{
	m_isPathExists = false;
	m_isSpoofed = false;

	m_sSteamPath = "";
	m_sSteamDll = "";
	m_sNewSteamDll = "";

	Initialize();
}

void cSteamSpoof::Initialize()
{
	GetSteamDll();
	m_isSpoofed = CheckSpoof();
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
		m_isPathExists = true;
	else
		return;

	m_sSteamPath = sProcPath;

	m_sSteamDll = sProcPath + "crashhandler.dll";
	m_sNewSteamDll = sProcPath + "crashhandler1.dll";
}

void cSteamSpoof::MainSteamDllSpoof()
{
	SpoofSteamDll();
}

void cSteamSpoof::SpoofSteamDll()
{
	rename(m_sSteamDll.c_str(), m_sNewSteamDll.c_str());

	m_isSpoofed = CheckSpoof();
}

void cSteamSpoof::UnSpoofSteamDll()
{
	rename(m_sNewSteamDll.c_str(), m_sSteamDll.c_str());

	m_isSpoofed = CheckSpoof();
}

bool cSteamSpoof::IsSteamDllExists()
{
	wstring wsTemp = wstring(m_sSteamDll.begin(), m_sSteamDll.end());
	LPCWSTR lwsSteamDll = wsTemp.c_str();

	if (PathFileExistsW(lwsSteamDll))
		return true;

	return false;
}

bool cSteamSpoof::CheckSpoof()
{
	wstring wsTemp = wstring(m_sNewSteamDll.begin(), m_sNewSteamDll.end());
	LPCWSTR lwsSteamDll = wsTemp.c_str();

	if (PathFileExistsW(lwsSteamDll))
		return true;

	return false;
}

bool cSteamSpoof::IsPathExist()
{
	return m_isPathExists;
};

bool cSteamSpoof::IsSpoofed()
{
	return m_isSpoofed;
};

string cSteamSpoof::GetSteamPath2()
{
	char value[256];
	DWORD BufferSize = 256;
	RegGetValueA(HKEY_CURRENT_USER, "SOFTWARE\\Valve\\Steam", "SteamPath", RRF_RT_ANY, NULL, (PVOID)&value, &BufferSize);
	m_sSteamPath = (string)value + "\\";
	return (string)value + "\\";
}

string cSteamSpoof::GetSteamPath()
{
	return m_sSteamPath;
};

string cSteamSpoof::GetSteamDllName()
{
	return m_sSteamDll;
};

string cSteamSpoof::GetNewSteamDllName()
{
	return m_sNewSteamDll;
};