#pragma once

#include "Includes.h"

#include "ProcHelper.h"

class cSteamSpoof
{
public:
	cSteamSpoof();
	void Initialize();

	void MainSteamDllSpoof();

	void SpoofSteamDll();
	void UnSpoofSteamDll();

	bool IsSteamDllExists();

	bool IsPathExists;
	bool IsSpoofed;

	string sSteamPath;
	string sSteamDll;
	string sNewSteamDll;
private:
	void GetSteamDll();
	string GetSteamPath2();
	bool CheckSpoof();
};