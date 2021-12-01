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
#include <string>

//Screen size
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Golf ball size
int xSize = 15;
int ySize = 15;

//Velocity
int xVel = 0;
int yVel = 0;

int level = 1;

//Flags
bool xcollideflag = false;
bool ycollideflag = false;

//Position for the golf ball in the middle
float xStartPosition = SCREEN_WIDTH / 2 - xSize / 2;
float yStartPosition = SCREEN_WIDTH / 2 - ySize / 2;

//One step back mouse coordinates
float oldxMouse = xStartPosition;
float oldyMouse = yStartPosition;

//ball x and y
float x = SCREEN_WIDTH / 2 - xSize / 2;
float y = SCREEN_HEIGHT / 2 - ySize / 2;

//Start structure initializing
SDL_Rect ball;
SDL_Rect ballhole;

SDL_Window* window = NULL;

SDL_Renderer* renderer = NULL;

SDL_Texture* player;
SDL_Texture* hole;
SDL_Texture* texture;
//End structure initializing

//Initializing function
bool init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		window = SDL_CreateWindow("SDL Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL)
			{
				printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
				success = false;
			}
		}
	}

	return success;
}

//Load Images, text and etc. function
bool loadMedia()
{
	bool success = true;

	return success;
}

//Close function
void close()
{

	texture = NULL;
	window = NULL;
	renderer = NULL;

	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
}

int GetRandomNumber(int high, int low) 
{
	return rand() % high + low;
}

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

bool checkCollision(SDL_Rect r1, SDL_Rect r2)
{
	if (PointInRect(r1.x, r1.y, r2) == true || PointInRect(r1.x + r1.w, r1.y + r1.h, r2) == true) {
		return true;
	}
	else {
		return false;
	}
}

bool checkCollisionX(SDL_Rect r1, SDL_Rect r2)
{
	if (PointInRect(r1.x + r1.w, r1.y, r2) == true) {
		return true;
	}
	else {
		return false;
	}
}

bool checkCollisionY(SDL_Rect r1, SDL_Rect r2)
{
	if (PointInRect(r1.x, r1.y + r1.h, r2) == true) {
		return true;
	}
	else {
		return false;
	}
}

bool XYInRect(const SDL_Rect& rect, int x, int y)
{
	return (true);
}

int main(int argc, char* argv[])
{
	TTF_Init();

	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{

		if (!loadMedia()) {
			printf("Failed to load media\n");
		}
		else {

		startNewLevel:

			char buffer[50];
			sprintf_s(buffer, "Hole: %d", level);

			std::cout << "\nLevel: " << level << "\n\n";

			//Important parameters
			bool quit = false;
			SDL_Event event{};
			int x1 = 0;
			int y1 = 0;
			int x2 = 0;
			int y2 = 0;
			bool drawing = false;

			int powerLength = 0;
			int powerHeight = 0;

			int lineLength = 0;

			int w, h;

			ball.w = xSize;
			ball.h = ySize;

			std::cout << ball.x << ball.y;

			ballhole.w = xSize + 10; ballhole.h = ySize + 10;

			//Initialize random seed
			srand(time(NULL));

			//Set the wall
			SDL_Rect wall1{};
			int whichWall1 = rand() % 2 + 1;
			std::cout << whichWall1 << "\n";
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

			printf("%i %i %i %i\n", wall1.x, wall1.y, wall1.w, wall1.h);

			//Set the wall
			SDL_Rect wall2{};
			int whichWall2 = rand() % 2 + 1;
			std::cout << whichWall2 << "\n";
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

			printf("%i %i %i %i\n", wall2.x, wall2.y, wall2.w, wall2.h);

			//Set the wall
			SDL_Rect wall3{};
			int whichWall3 = rand() % 2 + 1;
			std::cout << whichWall3 << "\n";
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

			printf("%i %i %i %i\n", wall3.x, wall3.y, wall3.w, wall3.h);

			//Set the wall
			SDL_Rect wall4{};
			int whichWall4 = rand() % 2 + 1;
			std::cout << whichWall4 << "\n";
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

			printf("%i %i %i %i\n", wall4.x, wall4.y, wall4.w, wall4.h);

			//hole spawn
			int wherehole = rand() % 4 + 1;
			std::cout << "\n" << wherehole;
			switch (wherehole)
			{
			case 1:
			{
				int rightOrDown = rand() % 2 + 1;
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

			//ball spawn
			/*int whereball = rand() % 4 + 1;
			while (whereball == wherehole)
			{
				whereball = rand() % 4 + 1;
			}
			std::cout << "\n" << whereball;*/
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


			//Creating the golf ball
			player = IMG_LoadTexture(renderer, "res/ball.bmp");
			SDL_QueryTexture(player, NULL, NULL, &w, &h);
			hole = IMG_LoadTexture(renderer, "res/hole.bmp");
			SDL_QueryTexture(hole, NULL, NULL, &w, &h);


			TTF_Font* font = TTF_OpenFont("res/arial.ttf", 25);
			SDL_Color color = { 255, 255, 255 };
			SDL_Surface* surface = TTF_RenderText_Solid(font,
				buffer, color);
			SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

			int texW = 0;
			int texH = 0;
			SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
			SDL_Rect dstrect = { 300, 10, texW, texH };

			while (!quit)
			{

				while (SDL_PollEvent(&event) != 0)
				{
					if (event.type == SDL_QUIT)
					{
						quit = true;
					}

				}
				int mouseX = 0, mouseY = 0;
				SDL_GetMouseState(&mouseX, &mouseY);


				if (event.key.keysym.sym == SDLK_SPACE || event.type == SDL_KEYUP) {
					xVel = GetRandomNumber(2, -2);
					yVel = GetRandomNumber(2, -2);
				}
				else if (event.key.keysym.sym == SDLK_SPACE || event.type == SDL_KEYDOWN) {
					xVel = GetRandomNumber(1, -3);
					yVel = GetRandomNumber(1, -3);
				}

				if (event.type == SDL_MOUSEBUTTONUP)
				{
					goto startNewLevel;
				}

				if (ball.y < 1) {
					yVel = -yVel;
				}

				if (ball.y + ball.h > SCREEN_HEIGHT - 1)
				{
					yVel = -yVel;
				}

				if (ball.x < 1) {
					xVel = -xVel;
				}

				if (ball.x + ball.w > SCREEN_WIDTH - 1)
				{
					xVel = -xVel;
				}

				if (checkCollision(ball, wall1) || checkCollision(ball, wall2) || checkCollision(ball, wall3) || checkCollision(ball, wall4))
				{
					if (checkCollisionY(ball, wall1) || checkCollisionY(ball, wall2) || checkCollisionY(ball, wall3) || checkCollisionY(ball, wall4))
					{
						yVel = -yVel;
					}
					else if ((checkCollisionX(ball, wall1) || checkCollisionX(ball, wall2) || checkCollisionX(ball, wall3) || checkCollisionX(ball, wall4)))
					{
						xVel = -xVel;	
					}
				}

				ball.x += xVel;
				ball.y += yVel;


				SDL_Delay(10);
				//Setting background color
				SDL_SetRenderDrawColor(renderer, 0x10, 0xB3, 0x2D, 0xFF);
				SDL_RenderClear(renderer);
				//Initializing the player and hole
				SDL_RenderCopy(renderer, player, NULL, &ball);
				SDL_RenderCopy(renderer, hole, NULL, &ballhole);
				//Render wall
				SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
				SDL_RenderDrawRect(renderer, &wall1);
				SDL_RenderDrawRect(renderer, &wall2);
				SDL_RenderDrawRect(renderer, &wall3);
				SDL_RenderDrawRect(renderer, &wall4);

				SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
				if (drawing) {
					SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
				}
				SDL_RenderPresent(renderer);

				if (checkCollision(ball, ballhole))
				{
					level++;
					goto startNewLevel;
				}
				SDL_RenderCopy(renderer, texture, NULL, &dstrect);
				SDL_RenderPresent(renderer);
			}

			SDL_DestroyTexture(texture);
			SDL_FreeSurface(surface);
			TTF_CloseFont(font);
		}
		//Closing everything
		TTF_Quit();
		close();

		return 0;
	}
}
