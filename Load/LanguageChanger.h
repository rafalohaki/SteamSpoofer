#pragma once

#include "Includes.h"

namespace Lang
{
	string CANT_RENAME = "Cant to Rename Injector. Closing...";

	string STEAM_PATH_NOT_FOUNDED = "Steam path not Founded. Need to Run Steam.exe. Closing...";

	string SEARCH_STEAM = "Searching Steam.exe...";
	string STEAM_CLOSED = "Steam.exe Closes. Open Steam. Closing...";
	string STEAM_FOUNDED = "Steam.exe Found!";

	string SEARCH_CSGO = "Searching csgo.exe...";
	string CSGO_FOUNDED_FOR_INJECT = "csgo.exe Running, trying to Close...";
	string CANT_CLOSE_CSGO_FOR_INJECT = "Cant Close csgo.exe. Try to Close csgo.exe and Run Loader. Closing...";
	string CSGO_NOT_FOUNDED_FOR_INJECT = "Good, csgo.exe Closed, starting Inject!";
	string INJECT_ERROR = "Injecting Error. Closing...";
	string CANT_INJECT = "Cant Injecting. Closing...";
	string CAN_INJECT = "Injecting!";
	string CANT_FIND_DLL = "Cant Find Hack Dll. Closing...";
	string CAN_FIND_DLL = "Finded Hack Dll!";
	string DLL_IS = "Starting Inject ";
	string WAIT_CSGO = "Waiting csgo.exe...";
	string CSGO_FOUNDED = "csgo.exe Found!";


	void LoadRussian()
	{
		CANT_RENAME = "Не могу переименовать инжектор. Закрытие...";
		STEAM_PATH_NOT_FOUNDED = "Папка Стима не найдена. Нужно запустить Стим. Закрытие...";
		SEARCH_STEAM = "Ищу Steam.exe...";
		STEAM_CLOSED = "Steam.exe закрыт. Откройте Стим. Закрытие...";
		STEAM_FOUNDED = "Steam.exe Найден!";
		SEARCH_CSGO = "Ищу csgo.exe...";
		CSGO_FOUNDED_FOR_INJECT = "csgo.exe открыт, пытаюсь закрыть...";
		CANT_CLOSE_CSGO_FOR_INJECT = "Не удалось закрыть csgo.exe. Попробуйте запустить первым лоадер. Закрытие...";
		CSGO_NOT_FOUNDED_FOR_INJECT = "Хорошо, csgo.exe закрыт, начинаю инжект!";
		INJECT_ERROR = "Ошибка при инжекте. Закрытие...";
		CANT_INJECT = "Не получится Заинжектить. Закрытие...";
		CAN_INJECT = "Можно Инжектить!";
		CANT_FIND_DLL = "Не могу найти длл чита. Закрытие...";
		CAN_FIND_DLL = "Длл чита найдена!";
		DLL_IS = "Начинаю инжект ";
		WAIT_CSGO = "Ожидание csgo.exe...";
		CSGO_FOUNDED = "csgo.exe Найден!";
	}

	string GetWinLanguage()
	{
		WCHAR wcBuffer[16];
		GetSystemDefaultLocaleName(wcBuffer, 16);

		return ws2s(wcBuffer);
	}


}