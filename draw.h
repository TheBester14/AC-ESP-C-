#pragma once

#include <iostream>
#include "structs.h"
#include "mycal.h"
#include "entities.h"
#include "player.h"


class Draw
{
		public :	
			HBRUSH hBrushEnemy = CreateSolidBrush(RGB(255, 20, 20));
			HBRUSH hBrushTeam = CreateSolidBrush(RGB(20, 20, 255));
			HBRUSH hBrushNeutral = CreateSolidBrush(RGB(255, 255, 255));
			COLORREF enemyColor = RGB(255, 20, 20);
			COLORREF teamColor = RGB(20, 20, 255);
			COLORREF neutral = RGB(255, 255, 255);

			// Getting Handle and target window for ESP
			HDC hDesktop;
			HWND targetWindow;
			HWND Handle;
			RECT mRect;


			void setupDrawing(HDC HDC_DESKTOP, HWND handle); // Setup the overlay

			void drawFilledRectangles(int x, int y, int w, int z, HBRUSH brushColor); // draws single line i.e filled rectangle

			void drawBorderBox(int x, int y, int w, int z, int thickness, HBRUSH brushColor);

			void drawEsp(int x, int y, float distance, HBRUSH hBrush, COLORREF colorBol, int widths, int heights);

			DWORD WINAPI esp(Entities listofEnemy, Player me, MyMaths calc);
			
};

