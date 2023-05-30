#pragma once
#include <Windows.h>
#include <thread>
#include <iostream>
#include <chrono>
#include <tchar.h>
#include <winapifamily.h>
#include "enc.h"
#include "lazy.h"
#include "protection.h"
#include "xor.h"
#include "../kdmapper/intel_driver.hpp"
#include "../kdmapper/kdmapper.hpp"
#include "../discord rpc/dsc.h"
#include "../Obsidium SDK/obsidium64.h"
#include <string>
#include "driver.h"
#include <Wininet.h>
#include <csignal>
#include <sys/types.h>

#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "urlmon.lib")

Discord* g_Discord;

bool lol = true;
using namespace std;
string random_string()
{
	string str = ("QWERTYUIOPASDFGHJKLZXCVBNM");
	string newstr;
	int pos;
	while (newstr.size() != 15)
	{
		pos = ((rand() % (str.size() + 1)));
		newstr += str.substr(pos, 1);
	}
	return newstr + "";
}

void changetitle()
{
	while (lol == true)
	{
		std::string consoleTitle = (std::string)E("  Comm Cord Free Spoofer // ") + random_string();
		LI_FN(SetConsoleTitleA)(consoleTitle.c_str());
	}
}

void beep()
{
	LI_FN(Beep)(200, 500);
	LI_FN(Sleep)(500);
	LI_FN(Beep)(300, 500);
	LI_FN(Sleep)(1000);
}

void spoof(BYTE* RawData)
{
	HANDLE iqvw64e_device_handle = intel_driver::Load();

	if (!iqvw64e_device_handle || iqvw64e_device_handle == INVALID_HANDLE_VALUE)
	{
	}

	if (!kdmapper::MapDriver(iqvw64e_device_handle, RawData))
	{
		intel_driver::Unload(iqvw64e_device_handle);
	}

	intel_driver::Unload(iqvw64e_device_handle);
}

std::string replaceAll(std::string subject, const std::string& search,
	const std::string& replace) {
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != std::string::npos) {
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return subject;
}

string DownloadString(string URL) {
	HINTERNET interwebs = InternetOpenA("Mozilla/5.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);
	HINTERNET urlFile;
	string rtn;
	if (interwebs) {
		urlFile = InternetOpenUrlA(interwebs, URL.c_str(), NULL, NULL, NULL, NULL);
		if (urlFile) {
			char buffer[2000];
			DWORD bytesRead;
			do {
				InternetReadFile(urlFile, buffer, 2000, &bytesRead);
				rtn.append(buffer, bytesRead);
				memset(buffer, 0, 2000);
			} while (bytesRead);
			InternetCloseHandle(interwebs);
			InternetCloseHandle(urlFile);
			string p = replaceAll(rtn, "|n", "\r\n");
			return p;
		}
	}
	InternetCloseHandle(interwebs);
	string p = replaceAll(rtn, "|n", "\r\n");
	return p;
}

std::string ReadFromFile(std::string path)
{
	std::string contents;
	std::ifstream file(path, std::ios::in);
	std::getline(file, contents);
	return contents;
}

std::string pcusername()
{
	char acUserName[100];
	DWORD nUserName = sizeof(acUserName);
	GetUserNameA(acUserName, &nUserName);
	return static_cast<std::string>(acUserName);
}

bool CheckVTBlacklist(std::string id, std::string rawlinktoblacklist)
{
	std::string blacklistedcontents = DownloadString(rawlinktoblacklist);
	if (blacklistedcontents.find(id) != std::string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

const int WIDTH = 80;
const int HEIGHT = 25;
const int NUM_PARTICLES = 100;

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Initialize particles
struct Particle {
	int x, y;
	char c;
	int color;
	int velX, velY;
};

void particle()
{
	srand(time(NULL));
	int x, y;
	// Hide the console cursor
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	Particle particles[NUM_PARTICLES];

	for (int i = 0; i < NUM_PARTICLES; i++) {
		particles[i].x = rand() % WIDTH;
		particles[i].y = rand() % HEIGHT;
		particles[i].c = rand() % 26 + 65; // Random capital letter
		particles[i].color = rand() % 7 + 9; // Random color (9-15)
		particles[i].velX = rand() % 3 - 1; // Random velocity (-1, 0, or 1)
		particles[i].velY = rand() % 3 - 1; // Random velocity (-1, 0, or 1)
	}

	// Main loop
	while (true) {
		// Update particles
		for (int i = 0; i < NUM_PARTICLES; i++) {
			particles[i].x += particles[i].velX;
			particles[i].y += particles[i].velY;

			// Bounce particles off the edges of the console
			if (particles[i].x < 0 || particles[i].x >= WIDTH) {
				particles[i].velX = -particles[i].velX;
				particles[i].x += particles[i].velX * 2;
			}

			if (particles[i].y < 0 || particles[i].y >= HEIGHT) {
				particles[i].velY = -particles[i].velY;
				particles[i].y += particles[i].velY * 2;
			}
		}

		// Clear the console
		system("cls");

		// Draw particles
		for (int i = 0; i < NUM_PARTICLES; i++) {
			x = particles[i].x;
			y = particles[i].y;

			gotoxy(x, y);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), particles[i].color);
			cout << particles[i].c;
		}

		// Sleep for a short time to slow down the animation
		Sleep(50);
	}
}

void cleanup() {
	// Find the taskbar window
	HWND taskbarWnd = FindWindow("Shell_TrayWnd", NULL);
	if (taskbarWnd)
	{
		// Hide the taskbar
		ShowWindow(taskbarWnd, SW_SHOW);
	}
}

void signal_handler(int signal) {
	if (signal == SIGINT) {
		cleanup();
		exit(signal);
	}
}

int counter = 3; // amount of seconds

void checkifbeingterminated()
{
	while (true)
	{
		// Set up the signal handler.
		signal(SIGINT, signal_handler);

		// Register the cleanup function to be called on exit.
		atexit(cleanup);
	}
}