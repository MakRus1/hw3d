#pragma 

#include "Window.h"

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
)
{
	try
	{
		Window wnd(800, 300, L"Donkey Fart Box");

		// message pump
		MSG msg;
		BOOL gResult;
		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}


		if (gResult == -1)
		{
			return -1;
		}

		return msg.wParam;
	}
	catch (const ChiliException& e)
	{
		wchar_t wtext[256];
		std::mbstowcs(wtext, e.what(), strlen(e.what()) + 1);
		LPWSTR temp_what = wtext;
		std::mbstowcs(wtext, e.what(), strlen(e.what()) + 1);
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