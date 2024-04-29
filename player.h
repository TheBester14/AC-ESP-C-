#pragma once
#include <iostream>
#include <Windows.h>
#include "mem.h"
#include "structs.h"

class Player
{
	public:

		char name[20];
		int base = 0;
		int health = 0;
		float matrix[16];
		vec3d screen;
		vec3d headPos;
		vec3d feetPos;
		int teamC = 0;
		int height = 0;
		int width = 0;

		void getInfoPlayer();
		void printDebug();

};

