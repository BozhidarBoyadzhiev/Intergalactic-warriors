//Libraries
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string>
#include <cmath>
#include <iostream>

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

SDL_Window* window = NULL;

SDL_Renderer* renderer = NULL;

SDL_Surface* gScreenSurface = NULL;

SDL_Surface* gHelloWorld = NULL;

SDL_Texture* player;
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
			SDL_Event event;

			//Set the wall
			SDL_Rect wall{};
			wall.x = 90;
			wall.y = 40;
			wall.w = 40;
			wall.h = 400;
			while (!quit)
			{
				//Creating the golf ball
				player = IMG_LoadTexture(renderer, "res/ball.bmp");
				SDL_QueryTexture(player, NULL, NULL, &w, &h);

				//Setting background color
				SDL_SetRenderDrawColor(renderer, 0x10, 0xB3, 0x2D, 0xFF);
				SDL_RenderClear(renderer);

				//Initializing the player
				SDL_RenderCopy(renderer, player, NULL, &texr);

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

							//Getting mouse coordinates on left click
							SDL_GetMouseState(&xMouse, &yMouse);
							printf("%i %i\n", xMouse, yMouse);

							oldxMouse = xMouse;
							oldyMouse = yMouse;

							////Changing the player coordinates
							//if ((xMouse <= 500 && xMouse >= 300) || yMouse <= 240) {
							//	texr.x = xMouse / 2;
							//	texr.y = yMouse * 2;
							//}
							//else {
							//	texr.x = xMouse * 2;
							//	texr.y = yMouse / 2;
							//}

							//if (x == 640) {
							//	texr.x = xMouse / 2;
							//}
							//else if (y == 480) {
							//	texr.y = yMouse / 2;
							//}
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
							if ((texr.x < 0 || texr.x > SCREEN_WIDTH || (texr.x + mCollider.w > SCREEN_WIDTH) || checkCollision(mCollider, wall)) && SDL_KEYUP)
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
							if ((texr.y < 0 || texr.y > SCREEN_HEIGHT || (texr.y + mCollider.h > SCREEN_HEIGHT) || checkCollision(mCollider, wall)) && SDL_KEYUP)
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

							/**/
						//Initializing the player's new coordinates
						SDL_RenderCopy(renderer, player, NULL, &texr);
					}

					//Render wall
					SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
					SDL_RenderDrawRect(renderer, &wall);


					//Calling the text function
					//TTF_Init();
					//text();

					//Middle horizontal line
					//SDL_UpdateWindowSurface(window);
					//SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
					//SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

					SDL_RenderPresent(renderer);
				}
			}
		}
		//Closing everything
		TTF_Quit();
		close();

		return 0;
	}
}