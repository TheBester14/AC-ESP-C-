#pragma once
#include "iostream"
#include <Windows.h>
#include <vector>
#include "structs.h"
#include "mem.h"
#include "ent.h"
using namespace std;

class Entities
{
public:
	unsigned int amount = 0;
	vector<Entity> list { amount };

	void getInfoEntity();
	void printDebug();
};

