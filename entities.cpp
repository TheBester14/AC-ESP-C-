#include "entities.h"

using namespace std;

void Entities:: getInfoEntity() {
	uintptr_t amountBase = 0;
	uintptr_t modBase = 0;

	DWORD procID = GetProcId(L"ac_client.exe");
	modBase = GetModuleBaseAddress(procID, L"ac_client.exe");
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, NULL, procID);

	uintptr_t entBase = modBase + 0x10F4F8;

	amountBase = modBase + 0x010F500;

	ReadProcessMemory(hProc, (BYTE*)amountBase, &amount, sizeof(amount), nullptr);

	list.resize(amount);
	for (int i = 1; i < amount; i++) {
		ReadProcessMemory(hProc, LPCVOID(entBase), &list[i].base, sizeof(list[i].base), nullptr);
		ReadProcessMemory(hProc, LPCVOID(list[i].base + (0x4 * i)), &list[i].base, sizeof(list[i].base), nullptr);
		ReadProcessMemory(hProc, LPCVOID(list[i].base + 0x225), &list[i].name, sizeof(list[i].name), nullptr);

		ReadProcessMemory(hProc, LPCVOID(list[i].base + 0x4), &list[i].headPos.x, sizeof(list[i].headPos.x), nullptr);
		ReadProcessMemory(hProc, LPCVOID(list[i].base + 0x8), &list[i].headPos.y, sizeof(list[i].headPos.y), nullptr);
		ReadProcessMemory(hProc, LPCVOID(list[i].base + 0xC), &list[i].headPos.z, sizeof(list[i].headPos.z), nullptr);

		ReadProcessMemory(hProc, LPCVOID(list[i].base + 0x34), &list[i].feetPos.x, sizeof(list[i].feetPos.x), nullptr);
		ReadProcessMemory(hProc, LPCVOID(list[i].base + 0x38), &list[i].feetPos.y, sizeof(list[i].feetPos.y), nullptr);
		ReadProcessMemory(hProc, LPCVOID(list[i].base + 0x3C), &list[i].feetPos.z, sizeof(list[i].feetPos.z), nullptr);

		ReadProcessMemory(hProc, LPCVOID(list[i].base + 0x32C), &list[i].team, sizeof(list[i].team), nullptr);
		ReadProcessMemory(hProc, LPCVOID(list[i].base + 0xF8), &list[i].health, sizeof(list[i].health), nullptr);
	}


}


void Entities::printDebug() {
	cout << "TOTAL PLAYERS IN MAP: " << amount << endl;

	for (int i = 1; i < amount; i++) {
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		cout << "Enemy Name is: " << list[i].name << endl;
		cout << "Team is : " << list[i].team << endl;

	}
}