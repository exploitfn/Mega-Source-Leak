#include "MAC.hpp"

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

CMAC::CMAC()
{
	//Seeding for random numbers
	srand((unsigned)time(0));
}

string CMAC::GenerateMAC()
{
	stringstream temp;
	int number = 0;
	string result;

	for (int i = 0; i < 6; i++)
	{
		number = rand() % 254;
		if (i != 0)
			temp << setfill('0') << setw(2) << hex << number;
		else
			temp << "02";
		if (i != 5)
		{
			temp << "-";
		}
	}
	result = temp.str();

	for (auto& c : result)
	{
		c = toupper(c);
	}
	return result;
}

void CMAC::showAdapterList()
{
	PIP_ADAPTER_INFO pAdapterInfo;
	PIP_ADAPTER_INFO pAdapter = NULL;
	DWORD dwRetVal = 0;
	UINT i;

	ULONG ulOutBufLen = sizeof(IP_ADAPTER_INFO);
	pAdapterInfo = (IP_ADAPTER_INFO*)MALLOC(sizeof(IP_ADAPTER_INFO));
	if (pAdapterInfo == NULL)
	{
		cout << ("  Error: Allocating memory needed to call GetAdaptersinfo.") << endl;
	}

	if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW)
	{
		FREE(pAdapterInfo);
		pAdapterInfo = (IP_ADAPTER_INFO*)MALLOC(ulOutBufLen);
		if (pAdapterInfo == NULL)
		{
			cout << ("  Error: Allocating memory needed to call GetAdaptersinfo") << endl;
		}
	}

	if ((dwRetVal = GetAdaptersInfo(pAdapterInfo, &ulOutBufLen)) == NO_ERROR)
	{
		pAdapter = pAdapterInfo;
		while (pAdapter)
		{
			cout << ("\n\t  ComboIndex: \t") << pAdapter->ComboIndex << endl;
			cout << ("\t  Adapter Name: \t") << pAdapter->AdapterName << endl;
			cout << ("\t  Adapter Description: \t") << pAdapter->Description << endl;
			cout << ("\t  Adapter Address: \t");
			for (i = 0; i < pAdapter->AddressLength; i++)
			{
				if (i == (pAdapter->AddressLength - 1))
					printf("%.2X\n", (int)pAdapter->Address[i]);
				else
					printf("%.2X-", (int)pAdapter->Address[i]);
			}
			cout << ("\t  IP Address: \t") << pAdapter->IpAddressList.IpAddress.String << endl;
			cout << ("\t  IP Mask: \t") << pAdapter->IpAddressList.IpMask.String << endl;
			cout << ("\t  Gateway: \t") << pAdapter->GatewayList.IpAddress.String << endl;
			pAdapter = pAdapter->Next;
		}
	}
	else
	{
		cout << ("GetAdaptersInfo failed with error: ") << dwRetVal << endl;
	}
	if (pAdapterInfo)
		FREE(pAdapterInfo);
}

unordered_map<string, string> CMAC::getAdapters()
{
	PIP_ADAPTER_INFO pAdapterInfo;
	PIP_ADAPTER_INFO pAdapter = NULL;
	DWORD dwRetVal = 0;

	unordered_map<string, string> result;
	stringstream temp;
	string str_mac;

	ULONG ulOutBufLen = sizeof(IP_ADAPTER_INFO);
	pAdapterInfo = (IP_ADAPTER_INFO*)MALLOC(sizeof(IP_ADAPTER_INFO));
	if (pAdapterInfo == NULL)
	{
		cerr << ("  [!] Error: Allocating memory needed to call GetAdaptersInfo") << endl;
	}

	if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW)
	{
		FREE(pAdapterInfo);
		pAdapterInfo = (IP_ADAPTER_INFO*)MALLOC(ulOutBufLen);
		if (pAdapterInfo == NULL)
		{
			cerr << ("  [!] Error: Adapter is NULL after calling GetAdaptersInfo") << endl;
		}
	}

	if ((dwRetVal = GetAdaptersInfo(pAdapterInfo, &ulOutBufLen)) == NO_ERROR)
	{
		pAdapter = pAdapterInfo;
		while (pAdapter)
		{
			for (UINT i = 0; i < pAdapter->AddressLength; i++)
			{
				temp << setfill('0') << setw(2) << hex << (int)pAdapter->Address[i];
				if (i != pAdapter->AddressLength - 1)
				{
					temp << "-";
				}
			}
			str_mac = temp.str();
			temp.str("");
			temp.rdbuf();
			for (auto& c : str_mac)
			{
				c = toupper(c);
			}

			result.insert({ pAdapter->Description, str_mac });
			pAdapter = pAdapter->Next;
		}
	}
	else
	{
		cout << ("  [!] GetAdaptersInfo failed with error: ") << dwRetVal << endl;
	}
	if (pAdapterInfo)
		FREE(pAdapterInfo);

	return result;
}

void CMAC::SpoofMAC()
{
	vector <string> list;
	unordered_map<string, string> AdapterDetails = getAdapters();
	for (auto& itm : AdapterDetails)
	{
		list.push_back(itm.first);
	}

	//cout << "\n[+]List of Available Adapters: " << endl;
	int range = 0;
	for (auto itm = list.begin(); itm != list.end(); itm++)
	{
		//cout << '\t' << range + 1 << ")" << *itm << endl;
		range++;
	}

	int selection = 1;

	while (selection < range + 1)
	{
		string wstr(list.at(selection - 1).begin(), list.at(selection - 1).end());
		const char* wAdapterName = wstr.c_str();

		bool bRet = false;
		HKEY hKey = NULL;
		if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, ("SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}"), 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS)
		{
			DWORD dwIndex = 0;
			TCHAR Name[1024];
			DWORD cName = 1024;
			while (RegEnumKeyExA(hKey, dwIndex, Name, &cName, NULL, NULL, NULL, NULL) == ERROR_SUCCESS)
			{
				HKEY hSubKey = NULL;
				if (RegOpenKeyExA(hKey, Name, 0, KEY_ALL_ACCESS, &hSubKey) == ERROR_SUCCESS)
				{
					BYTE Data[1204];
					DWORD cbData = 1024;
					if (RegQueryValueExA(hSubKey, ("DriverDesc"), NULL, NULL, Data, &cbData) == ERROR_SUCCESS)
					{
						if (_tcscmp((TCHAR*)Data, wAdapterName) == 0)
						{
							string temp = GenerateMAC();
							string newMAC = temp;
							temp.erase(std::remove(temp.begin(), temp.end(), '-'), temp.end());

							string wstr_newMAC(temp.begin(), temp.end());
							const char* newMACAddr = wstr_newMAC.c_str();

							if (RegSetValueExA(hSubKey, ("NetworkAddress"), 0, REG_SZ, (const BYTE*)newMACAddr, sizeof(TCHAR) * ((DWORD)_tcslen(newMACAddr) + 1)) == ERROR_SUCCESS)
							{
							}
						}
					}
					RegCloseKey(hSubKey);
				}
				cName = 1024;
				dwIndex++;
			}
			RegCloseKey(hKey);
		}
		else
		{
		}
		cout << " " << endl;

		selection++;
	}
}

void CMAC::RestartAdapters()
{
	//cout << _("[+] Disabling adapters...") << endl;
	cout << ("  [+] Resetting Adapters Please Wait\n  [+] This Will Be Fixed Automatically") << endl;
	system("WMIC PATH WIN32_NETWORKADAPTER WHERE PHYSICALADAPTER=TRUE CALL DISABLE >nul 2>&1"); // >nul 2>&1
	//cout << _("[+] Enabling adapters...") << endl;
	system(("WMIC PATH WIN32_NETWORKADAPTER WHERE PHYSICALADAPTER=TRUE CALL ENABLE >nul 2>&1"));
}