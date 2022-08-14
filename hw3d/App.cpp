#include "App.h"

App::App()
	: wnd(800, 600, L"App")
{
}

int App::Go()
{
	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		DoFrame();
	}

	if (gResult == -1)
	{
		throw HWND_LAST_EXCEPT();
	}

	return msg.wParam;
}

void App::DoFrame()
{

}
