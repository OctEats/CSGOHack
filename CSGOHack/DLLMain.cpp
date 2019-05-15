#include "Includes.h"

DWORD WINAPI SetupCheat(HINSTANCE Module) {
	AllocConsole();

	freopen_s((FILE * *)stdin, "CONIN$", "r", stdin);
	freopen_s((FILE * *)stdout, "CONOUT$", "w", stdout);

	return true;
}

BOOL APIENTRY DllMain(HMODULE Module, DWORD Reason, LPVOID Reserved) {
	switch (Reason) {
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(Module);
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)SetupCheat, NULL, NULL, NULL);
		break;
	}
	return true;
}