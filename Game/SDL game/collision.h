//Libraries
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <cmath>
#include <iostream>
#include <list>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool PointInRect(int x, int y, SDL_Rect rec)
{
	if (x > rec.x && y > rec.y && x < rec.x + rec.w && y < rec.y + rec.h)
	{
		return true;
	}
	else {
		return false;
	}
}

bool collision(SDL_Rect r1, SDL_Rect r2)
{
	if (PointInRect(r1.x, r1.y, r2) == true || PointInRect(r1.x + r1.w, r1.y + r1.h, r2) == true) {
		return true;
	}
	else {
		return false;
	}
}

bool collisionX(SDL_Rect r1, SDL_Rect r2)
{
	if (PointInRect(r1.x + r1.w, r1.y, r2) == true) {
		return true;
	}
	else {
		return false;
	}
}

bool collisionY(SDL_Rect r1, SDL_Rect r2)
{
	if (PointInRect(r1.x, r1.y + r1.h, r2) == true) {
		return true;
	}
	else {
		return false;
	}
}