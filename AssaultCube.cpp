// AssaultCube.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include "mem.h"
#include "memory.h"
#include "entities.h"
#include "mycal.h"
#include "player.h"
#include "draw.h"

using namespace std;
int main()
{
//    // Get process id
//    DWORD procId = GetProcId(L"ac_client.exe");
//    // Get module base
//    uintptr_t moduleBase = GetModuleBaseAddress(procId, L"ac_client.exe");
//    // Get handle to the process
//    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);
//    uintptr_t dynamicPtrBaseAdress = moduleBase + 0x10f4f4;
//    cout << "Dynamic Pointer Base Adress " << dynamicPtrBaseAdress;
//    int health = 0;
//    int ammo = 0;
//    int speed = 0;
//
//    uintptr_t speedAddr = FindDMAAddy(hProcess, dynamicPtrBaseAdress, { 0x0080 });
//    uintptr_t healthAddr = FindDMAAddy(hProcess, dynamicPtrBaseAdress, { 0x00F8 });
//    uintptr_t ammoAddr = FindDMAAddy(hProcess, dynamicPtrBaseAdress, { 0x0150 });
//    uintptr_t recoilAddr = FindDMAAddy(hProcess, dynamicPtrBaseAdress, { 0x4EE444 });
//    int newHealth = 5000;
//    int newAmmo = 3000;
//    int newRecoil = 0;
//    int newSpeed = 5;
//
//    // Read speed and health
//    ReadProcessMemory(hProcess, (BYTE*)ammoAddr, &ammo, sizeof(speed), nullptr);
//    ReadProcessMemory(hProcess, (BYTE*)healthAddr, &health, sizeof(health), nullptr);
//
//    cout << procId << endl;
//    cout << moduleBase << endl;
//
//    cout << "Current Health: " << std::dec << health << std::endl;
//    cout << "Current Ammo: " << std::dec << ammo << std::endl;
//    cout << "Current Speed: " << std::dec << speed << std::endl;
//
//    int userInput = -1;
    /*while (userInput != 0) {
        cout << "What do you want to do ?\n1.Set Health to 5000\n2.Set Ammo to 3000\n3.Toggle SpeedHack" << endl;
        cin >> userInput;

        if (userInput == 1) {
            WriteProcessMemory(hProcess, (BYTE*)healthAddr, &newHealth, sizeof(newHealth), nullptr);
        }
        else if (userInput == 2) {
            WriteProcessMemory(hProcess, (BYTE*)ammoAddr, &newAmmo, sizeof(newAmmo), nullptr);
        }
        else if (userInput == 3) {
            while (true) {
                if (GetAsyncKeyState(0x57) & 1) {
                    cout << "W is being pressed" << endl;
                   WriteProcessMemory(hProcess, (BYTE*)speedAddr, &newSpeed, sizeof(newSpeed), nullptr);
                }
            }
                
        }
    }*/

    Entities ent;
    Player Me;
    Draw sense;
    MyMaths myCal{};

    Me.getInfoPlayer();
    Me.printDebug();
    ent.getInfoEntity();
    ent.printDebug();

    sense.targetWindow = FindWindow(NULL, L"AssaultCube");
    sense.hDesktop = GetDC(sense.targetWindow);
    sense.setupDrawing(sense.hDesktop, sense.targetWindow);
    sense.esp(ent, Me, myCal);
    return 0;

   }





