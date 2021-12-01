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

int wherehole = rand() % 4 + 1;

SDL_Rect wall1(SDL_Rect wall1)
{
	//Set the wall
	int whichWall1 = rand() % 2 + 1;
	switch (whichWall1)
	{
	case 1:
	{
		int wallPos = 1 + rand() % 4;
		switch (wallPos)
		{
		case 1:
		{
			wall1.y = 50 + rand() % 20;
			wall1.x = 50 + rand() % 206;
			wall1.w = 30 + rand() % 10;
			wall1.h = 150 + rand() % 50;
			break;
		}
		case 2:
		{
			wall1.y = 50 + rand() % 20;
			wall1.x = 50 + rand() % 206;
			wall1.w = 30 + rand() % 10;
			wall1.h = 150 + rand() % 25;
			break;
		}
		case 3:
		{
			wall1.y = 50 + rand() % 20;
			wall1.x = 50 + rand() % 206;
			wall1.w = 30 + rand() % 10;
			wall1.h = 150 + rand() % 25;
			break;
		}
		case 4:
		{
			wall1.y = 50 + rand() % 20;
			wall1.x = 50 + rand() % 206;
			wall1.w = 40 + rand() % 10;
			wall1.h = 150 + rand() % 55;
			break;
		}
		}
		break;
	}
	case 2:
	{
		int wallPos = 1 + rand() % 4;
		switch (wallPos)
		{
		case 1:
		{
			wall1.y = 50 + rand() % 142;
			wall1.x = 50 + rand() % 130;
			wall1.w = 150 + rand() % 50;
			wall1.h = 30 + rand() % 10;
			break;
		}
		case 2:
		{
			wall1.y = 50 + rand() % 142;
			wall1.x = 50 + rand() % 130;
			wall1.w = 150 + rand() % 50;
			wall1.h = 30 + rand() % 10;
			break;
		}
		case 3:
		{
			wall1.y = 50 + rand() % 142;
			wall1.x = 50 + rand() % 130;
			wall1.w = 150 + rand() % 50;
			wall1.h = 30 + rand() % 10;
			break;
		}
		case 4:
		{
			wall1.y = 50 + rand() % 142;
			wall1.x = 50 + rand() % 130;
			wall1.w = 150 + rand() % 50;
			wall1.h = 30 + rand() % 10;
			break;
		}
		}
		break;
	}
	}

	return wall1;
}

SDL_Rect wall2(SDL_Rect wall2)
{
	//Set the wall
	int whichWall2 = rand() % 2 + 1;
	switch (whichWall2)
	{
	case 1:
	{
		int wallPos = 1 + rand() % 4;
		switch (wallPos)
		{
		case 1:
		{
			wall2.y = 50 + rand() % 20;
			wall2.x = 380 + rand() % 210;
			wall2.w = 30 + rand() % 10;
			wall2.h = 150 + rand() % 50;
			break;
		}
		case 2:
		{
			wall2.y = 50 + rand() % 20;
			wall2.x = 380 + rand() % 210;
			wall2.w = 30 + rand() % 10;
			wall2.h = 150 + rand() % 25;
			break;
		}
		case 3:
		{
			wall2.y = 50 + rand() % 20;
			wall2.x = 380 + rand() % 210;
			wall2.w = 30 + rand() % 10;
			wall2.h = 150 + rand() % 25;
			break;
		}
		case 4:
		{
			wall2.y = 50 + rand() % 20;
			wall2.x = 380 + rand() % 210;
			wall2.w = 40 + rand() % 10;
			wall2.h = 150 + rand() % 55;
			break;
		}
		}
		break;
	}
	case 2:
	{
		int wallPos = 1 + rand() % 4;
		switch (wallPos)
		{
		case 1:
		{
			wall2.y = 50 + rand() % 142;
			wall2.x = 380 + rand() % 80;
			wall2.w = 150 + rand() % 50;
			wall2.h = 30 + rand() % 10;
			break;
		}
		case 2:
		{
			wall2.y = 50 + rand() % 142;
			wall2.x = 380 + rand() % 80;
			wall2.w = 150 + rand() % 50;
			wall2.h = 30 + rand() % 10;
			break;
		}
		case 3:
		{
			wall2.y = 50 + rand() % 142;
			wall2.x = 380 + rand() % 80;
			wall2.w = 150 + rand() % 50;
			wall2.h = 30 + rand() % 10;
			break;
		}
		case 4:
		{
			wall2.y = 50 + rand() % 142;
			wall2.x = 380 + rand() % 80;
			wall2.w = 150 + rand() % 50;
			wall2.h = 30 + rand() % 10;
			break;
		}
		}
		break;
	}
	}

	return wall2;
}

SDL_Rect wall3(SDL_Rect wall3)
{
	//Set the wall
	int whichWall3 = rand() % 2 + 1;
	switch (whichWall3)
	{
	case 1:
	{
		int wallPos = 1 + rand() % 4;
		switch (wallPos)
		{
		case 1:
		{
			wall3.y = 240 + rand() % 50;
			wall3.x = 50 + rand() % 206;
			wall3.w = 30 + rand() % 10;
			wall3.h = 150 + rand() % 50;
			break;
		}
		case 2:
		{
			wall3.y = 240 + rand() % 50;
			wall3.x = 50 + rand() % 206;
			wall3.w = 30 + rand() % 10;
			wall3.h = 150 + rand() % 25;
			break;
		}
		case 3:
		{
			wall3.y = 240 + rand() % 50;
			wall3.x = 50 + rand() % 206;
			wall3.w = 30 + rand() % 10;
			wall3.h = 150 + rand() % 25;
			break;
		}
		case 4:
		{
			wall3.y = 240 + rand() % 50;
			wall3.x = 50 + rand() % 206;
			wall3.w = 40 + rand() % 10;
			wall3.h = 150 + rand() % 55;
			break;
		}
		}
		break;
	}
	case 2:
	{
		int wallPos = 1 + rand() % 4;
		switch (wallPos)
		{
		case 1:
		{
			wall3.y = 280 + rand() % 150;
			wall3.x = 50 + rand() % 130;
			wall3.w = 150 + rand() % 50;
			wall3.h = 30 + rand() % 10;
			break;
		}
		case 2:
		{
			wall3.y = 280 + rand() % 150;
			wall3.x = 50 + rand() % 130;
			wall3.w = 150 + rand() % 50;
			wall3.h = 30 + rand() % 10;
			break;
		}
		case 3:
		{
			wall3.y = 280 + rand() % 150;
			wall3.x = 50 + rand() % 130;
			wall3.w = 150 + rand() % 50;
			wall3.h = 30 + rand() % 10;
			break;
		}
		case 4:
		{
			wall3.y = 280 + rand() % 150;
			wall3.x = 50 + rand() % 130;
			wall3.w = 150 + rand() % 50;
			wall3.h = 30 + rand() % 10;
			break;
		}
		}
		break;
	}
	}

	return wall3;
}

SDL_Rect wall4(SDL_Rect wall4)
{
	//Set the wall
	int whichWall4 = rand() % 2 + 1;
	switch (whichWall4)
	{
	case 1:
	{
		int wallPos = 1 + rand() % 4;
		switch (wallPos)
		{
		case 1:
		{
			wall4.y = 240 + rand() % 50;
			wall4.x = 380 + rand() % 210;
			wall4.w = 30 + rand() % 10;
			wall4.h = 150 + rand() % 50;
			break;
		}
		case 2:
		{
			wall4.y = 240 + rand() % 50;
			wall4.x = 380 + rand() % 210;
			wall4.w = 30 + rand() % 10;
			wall4.h = 150 + rand() % 25;
			break;
		}
		case 3:
		{
			wall4.y = 240 + rand() % 50;
			wall4.x = 380 + rand() % 210;
			wall4.w = 30 + rand() % 10;
			wall4.h = 150 + rand() % 25;
			break;
		}
		case 4:
		{
			wall4.y = 240 + rand() % 50;
			wall4.x = 380 + rand() % 210;
			wall4.w = 40 + rand() % 10;
			wall4.h = 150 + rand() % 55;
			break;
		}
		}
		break;
	}
	case 2:
	{
		int wallPos = 1 + rand() % 4;
		switch (wallPos)
		{
		case 1:
		{
			wall4.y = 280 + rand() % 150;
			wall4.x = 380 + rand() % 80;
			wall4.w = 150 + rand() % 50;
			wall4.h = 30 + rand() % 10;
			break;
		}
		case 2:
		{
			wall4.y = 280 + rand() % 150;
			wall4.x = 380 + rand() % 80;
			wall4.w = 150 + rand() % 50;
			wall4.h = 30 + rand() % 10;
			break;
		}
		case 3:
		{
			wall4.y = 280 + rand() % 150;
			wall4.x = 380 + rand() % 80;
			wall4.w = 150 + rand() % 50;
			wall4.h = 30 + rand() % 10;
			break;
		}
		case 4:
		{
			wall4.y = 280 + rand() % 150;
			wall4.x = 380 + rand() % 80;
			wall4.w = 150 + rand() % 50;
			wall4.h = 30 + rand() % 10;
			break;
		}
		}
		break;
	}
	}

	return wall4;
}

SDL_Rect ballGeneration(SDL_Rect ball)
{

	switch (wherehole)
	{
	case 4:
	{
		int rightOrDown = rand() % 2 + 1;
		switch (rightOrDown)
		{
		case 1:
		{
			ball.x = rand() % 30 + 180;
			ball.y = 30;
			break;
		}
		case 2:
		{
			ball.x = 30;
			ball.y = rand() % 30 + 140;
			break;
		}
		}
	}
	case 3:
	{
		int leftOrDown = rand() % 2 + 1;
		switch (leftOrDown)
		{
		case 1:
		{
			ball.x = rand() % 210 + 400;
			ball.y = 30;
			break;
		}

		case 2:
		{
			ball.x = 580;
			ball.y = rand() % 30 + 140;
			break;
		}
		}
		break;
	}
	case 2:
	{
		int upOrRight = rand() % 2 + 1;
		switch (upOrRight)
		{
		case 1:
		{
			ball.x = 30;
			ball.y = rand() % 50 + 210;
			break;
		}

		case 2:
		{
			ball.x = rand() % 30 + 180;
			ball.y = 430;
			break;
		}
		}
		break;
	}
	case 1:
	{
		int leftOrUp = rand() % 2 + 1;
		switch (leftOrUp)
		{
		case 1:
		{
			ball.x = 580;
			ball.y = rand() % 50 + 210;
			break;
		}

		case 2:
		{
			ball.x = rand() % 210 + 400;
			ball.y = 430;
			break;
		}
		}
		break;
	}
	}

	return ball;
}

SDL_Rect holeGeneration(SDL_Rect ballhole)
{

	switch (wherehole)
	{
	case 1:
	{
		int rightOrDown = rand() % 4 + 1;
		switch (rightOrDown)
		{
		case 1:
		{
			ballhole.x = rand() % 30 + 180;
			ballhole.y = 30;
			break;
		}
		case 2:
		{
			ballhole.x = 30;
			ballhole.y = rand() % 30 + 140;
			break;
		}
		}
	}
	case 2:
	{
		int leftOrDown = rand() % 2 + 1;
		switch (leftOrDown)
		{
		case 1:
		{
			ballhole.x = rand() % 210 + 400;
			ballhole.y = 30;
			break;
		}

		case 2:
		{
			ballhole.x = 580;
			ballhole.y = rand() % 30 + 140;
			break;
		}
		}
		break;
	}
	case 3:
	{
		int upOrRight = rand() % 2 + 1;
		switch (upOrRight)
		{
		case 1:
		{
			ballhole.x = 30;
			ballhole.y = rand() % 50 + 210;
			break;
		}

		case 2:
		{
			ballhole.x = rand() % 30 + 180;
			ballhole.y = 430;
			break;
		}
		}
		break;
	}
	case 4:
	{
		int leftOrUp = rand() % 2 + 1;
		switch (leftOrUp)
		{
		case 1:
		{
			ballhole.x = 580;
			ballhole.y = rand() % 50 + 210;
			break;
		}

		case 2:
		{
			ballhole.x = rand() % 210 + 400;
			ballhole.y = 430;
			break;
		}
		}
		break;
	}
	}

	return ballhole;
}

int GetRandomNumber(int high, int low)
{
	return rand() % high + low;
}