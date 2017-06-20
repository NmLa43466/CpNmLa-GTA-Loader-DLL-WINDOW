#include "main.h"

void DLL_EXPORT FuncOpenDLL(){
    HWND windowhandle = FindWindow(NULL, L"GTA: San Andreas"); 
	DWORD pid = 0x51;
	GetWindowThreadProcessId(windowhandle, &pid);
	if(windowhandle)
	{
	
		OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid), MessageBox(NULL, L"Windows GTA is Now Open ^> sucess!", L"Success!", MB_OK | MB_ICONASTERISK);
	}
	else
	{
		MessageBoxA(0, "The Windows GTA Is Not Open", "DLL SAY Plase Open handle.", MB_OK | MB_ICONERROR);
	    // MessageBoxA(0, "DLL SAYYYYYS", "DLLMESAGE", MB_OK);
		}
	
}


BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD dwReason, LPVOID lpvReserved) //main code
{
	switch (dwReason) { // reason of open dll
	case DLL_PROCESS_ATTACH: // inject
		DisableThreadLibraryCalls(hinstDLL);
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)FuncOpenDLL, 0, 0, 0);
		MessageBoxA(0, "DLL is Load .. OPEN ..", "DLLMessage", MB_OK | MB_ICONINFORMATION);
		break;
	case DLL_PROCESS_DETACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}

/*
BOOL WINAPI DLLMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason){
	case DLL_PROCESS_ATTACH:
			break;

	case DLL_PROCESS_DETACH:
				break;

	case DLL_THREAD_ATTACH:
					break;

	case DLL_THREAD_DETACH:

	        break;

			return TRUE;
	}
}
*/
