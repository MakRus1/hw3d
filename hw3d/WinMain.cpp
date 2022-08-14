#pragma 

#include "App.h"

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
)
{
	try
	{
		return App{}.Go();
	}
	catch (const MyException& e)
	{
		wchar_t wtext[256];
		std::mbstowcs(wtext, e.what(), strlen(e.what()) + 1);
		LPWSTR temp_what = wtext;
		std::mbstowcs(wtext, e.GetType(), strlen(e.GetType()) + 1);
		LPWSTR temp_type = wtext;
		MessageBox(nullptr, temp_what, temp_type, MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		wchar_t wtext[256];
		std::mbstowcs(wtext, e.what(), strlen(e.what()) + 1);
		LPWSTR temp_what = wtext;
		MessageBox(nullptr, temp_what, L"Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, L"No details available", L"Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}