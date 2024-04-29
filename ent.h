#pragma once
#include <vector>
#include <Windows.h>
#include "structs.h"
#include "mem.h"

class Entity
{
public:
	char name[20];
	int health = 0;
	int base = 0;
	float matrix[16];
	vec3d headPos;
	vec3d feetPos;
	int team = 0;
};

