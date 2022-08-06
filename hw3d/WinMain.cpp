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
		Window wnd(800, 300, L"I Love You");

		// message pump
		MSG msg;
		BOOL gResult;
		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			while (!wnd.mouse.IsEmpty())
			{
				const auto e = wnd.mouse.Read();
				switch (e.GetType())
				{
				case Mouse::Event::Type::Leave:
					wnd.SetTitle(L"Gone!");
					break;
				case Mouse::Event::Type::Move:
					{
						wchar_t title[256];
						wsprintfW(title, L"Mouse position: (%d, %d)", e.GetPosX(), e.GetPosY());
						wnd.SetTitle(title);
					}
					break;
				}
			}
		}

		if (gResult == -1)
		{
			return -1;
		}

		return msg.wParam;
	}
	catch (const MyException& e)
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