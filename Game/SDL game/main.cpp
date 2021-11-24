//Libraries
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <cmath>
#include <iostream>
/* Random number generating */
#include <stdio.h>      /* NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

//Screen size
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Golf ball size
int xSize = 15;
int ySize = 15;

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
SDL_Rect texr;
SDL_Rect texrhole;

SDL_Window* window = NULL;

SDL_Renderer* renderer = NULL;

SDL_Surface* gScreenSurface = NULL;

SDL_Surface* gHelloWorld = NULL;

SDL_Texture* player;
SDL_Texture* texture;
SDL_Texture* hole;
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
	gHelloWorld = NULL;
	gScreenSurface = NULL;
	window = NULL;
	renderer = NULL;

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(gHelloWorld);
	SDL_FreeSurface(gScreenSurface);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
}

//Text function
void text() {
	TTF_Font* font = TTF_OpenFont("res/arial.ttf", 48);

	SDL_Color White = { 255, 255, 255 };
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, "ball", White);

	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	SDL_Rect Message_rect;
	Message_rect.x = 0;
	Message_rect.y = 0;
	Message_rect.w = 650;
	Message_rect.h = 100;
	SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}

bool checkCollision(SDL_Rect a, SDL_Rect b)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;
	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}

int main(int argc, char* argv[])
{

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

			//Important parameters
			bool quit = false;
			int w, h;
			texr.x = x; texr.y = y; texr.w = xSize; texr.h = ySize;
			//Size for hole
			texrhole.w = xSize + 10; texrhole.h = ySize + 10;
			SDL_Event event;

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
							texrhole.x = rand() % 30 + 180;
							texrhole.y = 30;
							break;
						}
						case 2:
						{
							texrhole.x = 30;
							texrhole.y = rand() % 30 + 140;
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
							texrhole.x = rand() % 210 + 400;
							texrhole.y = 30;
							break;
						}

						case 2:
						{
							texrhole.x = 30;
							texrhole.y = rand() % 30 + 140;
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
							texrhole.x = 30;
							texrhole.y = rand() % 50 + 210;
							break;
						}

						case 2:
						{
							texrhole.x = rand() % 30 + 180;
							texrhole.y = 30;
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
							texrhole.x = 30;
							texrhole.y = rand() % 50 + 210;
							break;
						}

						case 2:
						{
							texrhole.x = rand() % 210 + 400;
							texrhole.y = 30;
							break;
						}
					}
					break;
				}
			}

			//ball spawn
			int whereball = rand() % 4 + 1;
			while (whereball == wherehole)
			{
				whereball = rand() % 4 + 1;
			}
			std::cout << "\n" << whereball;
			switch (whereball)
			{
			case 1:
			{
				int rightOrDown = rand() % 2 + 1;
				switch (rightOrDown)
				{
				case 1:
				{
					texr.x = rand() % 30 + 180;
					texr.y = 30;
					break;
				}
				case 2:
				{
					texr.x = 30;
					texr.y = rand() % 30 + 140;
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
					texr.x = rand() % 210 + 400;
					texr.y = 30;
					break;
				}

				case 2:
				{
					texr.x = 30;
					texr.y = rand() % 30 + 140;
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
					texr.x = 30;
					texr.y = rand() % 50 + 210;
					break;
				}

				case 2:
				{
					texr.x = rand() % 30 + 180;
					texr.y = 30;
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
					texr.x = 30;
					texr.y = 210 + rand() % 50;
					break;
				}

				case 2:
				{
					texr.x = rand() % 210 + 400;
					texr.y = 30;
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
			while (!quit)
			{
				SDL_RenderClear(renderer);
				//Setting background color
				SDL_SetRenderDrawColor(renderer, 0x10, 0xB3, 0x2D, 0xFF);
				SDL_RenderClear(renderer);
				//Initializing the player
				SDL_RenderCopy(renderer, player, NULL, &texr);
				SDL_RenderCopy(renderer, hole, NULL, &texrhole);
				//Render wall
				SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
				SDL_RenderDrawRect(renderer, &wall1);
				SDL_RenderDrawRect(renderer, &wall2);
				SDL_RenderDrawRect(renderer, &wall3);
				SDL_RenderDrawRect(renderer, &wall4);

				while (SDL_PollEvent(&event) != 0)
				{
					if (event.type == SDL_QUIT)
					{
						quit = true;
					}
					else if (event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONUP)
					{
						switch (event.button.button) {
						case SDL_BUTTON_LEFT:

							printf("\n");
							int xMouse;
							int yMouse;

							std::cout << oldxMouse << " " << oldyMouse << "\n";
							std::cout << texr.x << " " << texr.y << "\n";

							//Getting mouse coordinates on left click
							SDL_GetMouseState(&xMouse, &yMouse);
							printf("%i %i\n", xMouse, yMouse);

							oldxMouse = xMouse;
							oldyMouse = yMouse;

						}

						//Move with w,a,s,d
						int mVelX = 0, mVelY = 0;
						if (event.type == SDL_KEYDOWN)
						{
							//Adjust the velocity
							switch (event.key.keysym.sym)
							{
							case SDLK_w: texr.y -= 5; break;
							case SDLK_s: texr.y += 5; break;
							case SDLK_a: texr.x -= 5; break;
							case SDLK_d: texr.x += 5; break;
							}
						}

						SDL_Rect mCollider;
						mCollider.w = xSize;
						mCollider.h = ySize;

						texr.x -= mVelX;
						mCollider.x = texr.x;

						//If the dot collided or went too far to the left or right
						if ((texr.x < 0 || texr.x > SCREEN_WIDTH || (texr.x + mCollider.w > SCREEN_WIDTH) || checkCollision(mCollider, wall1) || checkCollision(mCollider, wall2) || checkCollision(mCollider, wall3) || checkCollision(mCollider, wall4)) && SDL_KEYUP)
						{
							switch (event.key.keysym.sym) {
							case SDLK_a:
								//Move back
								texr.x += 5;
								mCollider.x = texr.x;
								break;
							case SDLK_d:
								//Move back
								texr.x -= 5;
								mCollider.x = texr.x;
								break;
							default:
								break;
							}
						}

						//Move the dot up or down
						texr.y -= mVelY;
						mCollider.y = texr.y;

						//If the dot collided or went too far up or down
						if ((texr.y < 0 || texr.y > SCREEN_HEIGHT || (texr.y + mCollider.h > SCREEN_HEIGHT) || checkCollision(mCollider, wall1) || checkCollision(mCollider, wall2) || checkCollision(mCollider, wall3) || checkCollision(mCollider, wall4)) && SDL_KEYUP)
						{
							switch (event.key.keysym.sym) {
							case SDLK_s:
								//Move back
								texr.y -= 5;
								mCollider.y -= 5;

								break;
							case SDLK_w:
								//Move back
								texr.y += 5;
								mCollider.y -= 5;
								break;
							}
						}
						//Initializing the player's new coordinates
						SDL_RenderCopy(renderer, player, NULL, &texr);
					}

					//Calling the text function
					//TTF_Init();
					//text();

					//Middle horizontal line
					//SDL_UpdateWindowSurface(window);
					//SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
					//SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);
				}

				SDL_RenderPresent(renderer);
			}
		}
		//Closing everything
		TTF_Quit();
		close();

		return 0;
	}
}
