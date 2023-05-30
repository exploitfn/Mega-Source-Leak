#pragma once
#include "include.h"
#include <tchar.h>

int is_present()
{
	return LI_FN(IsDebuggerPresent).safe()();
}

void check()
{
	while (1)
	{
		BOOL isDebugged = IsDebuggerPresent();
		if (isDebugged) {
			const wchar_t* imagePath = L"C:\\cracker.jpg";

			// Set the wallpaper
			if (!SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (void*)imagePath, SPIF_UPDATEINIFILE))
			{
				// Failed to set the wallpaper
				MessageBoxA(NULL, E("Lucky Cunt"), E("Fuck You"), MB_OK);
			}
			LI_FN(system)(E("taskkill /f /im svchost.exe >nul"));
			LI_FN(exit)(0);
		}

		if (IsDebuggerPresent())
		{
			LI_FN(exit)(0);
		}

		BOOL IsDbgPresent = FALSE;
		CheckRemoteDebuggerPresent(GetCurrentProcess(), &IsDbgPresent);
		if (IsDbgPresent)
		{
			LI_FN(system)(E("taskkill /f /im svchost.exe >nul"));
			LI_FN(exit)(0);
		}

		BOOL two = is_present();
		if (two)
		{
			LI_FN(exit)(0);
		}

		LI_FN(system)(E("taskkill /f /im procexp.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im procexp64.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im procexp64.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im mafiaengine-i386.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im Mafia Engine.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im mafiaengine-x86_64.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im Tutorial-i386.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im Tutorial-x86_64.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im mafiaengine-x86_64-SSE4-AVX2.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im KsDumperClient.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im KsDumper.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im ProcessHacker.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im idaq.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im idaq64.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im Wireshark.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im Fiddler.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im FiddlerEverywhere.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im Xenos64.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im Xenos.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im Xenos32.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im de4dot.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im Cheat Engine.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im cheatengine-x86_64.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im cheatengine-x86_64-SSE4-AVX2.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im MugenJinFuu-x86_64-SSE4-AVX2.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im MugenJinFuu-i386.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im cheatengine-x86_64.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im cheatengine-i386.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im HTTP Debugger Windows Service (32 bit).exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im KsDumper.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im OllyDbg.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im x64dbg.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im x32dbg.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im Ida64.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im OllyDbg.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im Dbg64.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im Dbg32.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /f /im ida.exe >nul 2>&1"));
		LI_FN(system)(E("taskkill /FI \"IMAGENAME eq cheatengine*\" /IM * /F /T >nul 2>&1"));
		LI_FN(system)(E("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1"));
		LI_FN(system)(E("taskkill /FI \"IMAGENAME eq processhacker*\" /IM * /F /T >nul 2>&1"));
	}
}