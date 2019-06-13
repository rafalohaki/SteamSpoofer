#include "Includes.h"
#include "Converter.h"
#include "ProcHelper.h"

#include "SpoofSteamDll.h"
#include "DllFinder.h"

#include "LanguageChanger.h"
#include "Other.h"

#include "Do.h"

int main() 
{
	string sMainPath = GetMyPath() + "/";
	SetConsoleSettings();
	StarterText();

	FindSteamExe();
	CloseCSGO();

	cSteamSpoof SteamSpoof;
	SpoofStart(SteamSpoof);
	DoSpoof(SteamSpoof);

	FindDll(sMainPath);
	DllToSteamDir(SteamSpoof, sMainPath);

	RunCSGO();
	ShowWindow(GetConsoleWindow(), 0);
	WorkWhileIsCSGO(SteamSpoof.GetSteamPath());

	Sleep(1000);
	exit(0);
}