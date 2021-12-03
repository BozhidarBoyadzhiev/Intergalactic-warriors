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
#include <windows.h>
#include <iomanip>

//Header Files
#include "randomGeneration.h"; //Random generation function
#include "mainFunctions.h"; //Initializing, load media and close functions
#include "collision.h"; //Collision functins

//Golf ball size
int xSize = 15;
int ySize = 15;

//Velocity
int xVel = 0;
int yVel = 0;

int level = 1;
char holetext[50];

//ball x and y
float x = SCREEN_WIDTH / 2 - xSize / 2;
float y = SCREEN_HEIGHT / 2 - ySize / 2;

//Start structure initializing
SDL_Rect ball;
SDL_Rect ballhole;

SDL_Rect wallOne;
SDL_Rect wallTwo;
SDL_Rect wallThree;
SDL_Rect wallFour;

SDL_Texture* texture;
SDL_Texture* player;
SDL_Texture* hole;
//End structure initializing


void title()
{
	std::cout << "                                                              " << "\n";
	std::cout << "      _____            _____  _____   ______         _____    " << "\n";
	std::cout << "  ___|\\    \\      ____|\\    \\|\\    \\ |\\     \\    ___|\\    \\   " << "\n";
	std::cout << " /    /\\    \\    /     /\\    \\\\\\    \\| \\     \\  /    /\\    \\  " << "\n";
	std::cout << "|    |  |____|  /     /  \\    \\\\|    \\  \\     ||    |  |____| " << "\n";
	std::cout << "|    |    ____ |     |    |    ||     \\  |    ||    |    ____ " << "\n";
	std::cout << "|    |   |    ||     |    |    ||      \\ |    ||    |   |    |" << "\n";
	std::cout << "|    |   |_,  ||\\     \\  /    /||    |\\ \\|    ||    |   |_,  |" << "\n";
	std::cout << "|\\ ___\\___/  /|| \\_____\\/____/ ||____||\\_____/||\\ ___\\___/  /|" << "\n";
	std::cout << "| |   /____ / | \\ |    ||    | /|    |/ \\|   ||| |   /____ / |" << "\n";
	std::cout << " \\|___|    | /   \\|____||____|/ |____|   |___|/ \\|___|    | / " << "\n";
	std::cout << "   \\( |____|/       \\(    )/      \\(       )/     \\( |____|/  " << "\n";
	std::cout << "    '   )/           '    '        '       '       '   )/     " << "\n";
	std::cout << "        '                                              '      " << "\n";
}

void centerstring(std::string s)
{
	int l = s.length();
	int pos = (int)((64 - l) / 2);
	for (int i = 0; i < pos; i++)
		std::cout << " ";

	std::cout << s;
}

int main(int argc, char* argv[])
{

	std::string Menu[4] = { "Start Game", "Info", "How to play", "Exit" };
	int pointer = 0;
	std::string MainMenuText[3] = { "Press Enter to select", "Press Backspace to go back", "MAIN MENU" };

	while (true)
	{
		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Changes text color
		title();
		for (int i = 0; i < 3; i++)
		{
			if (i == 2)
			{
				std::cout << std::endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				centerstring(MainMenuText[i]);
				std::cout << std::endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				centerstring(MainMenuText[i]);
				std::cout << std::endl;
			}
		}
		std::cout << std::endl;

		for (int i = 0; i < 4; i++)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); //Changes color of active options string element
				centerstring(Menu[i]);
				std::cout << std::endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				centerstring(Menu[i]);
				std::cout << std::endl;
			}
		}

		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 3;
				}
				break;
			}

			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer += 1;
				if (pointer == 4)
				{
					pointer = 0;
				}
				break;
			}

			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (pointer)
				{
				case 0:
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

							//Important parameters (FROM HERE)

							sprintf_s(holetext, "Hole: %d", level);

							bool quit = false;
							SDL_Event event{};
							bool drawing = false;

							int w, h;

							ball.w = xSize;
							ball.h = ySize;
							ballhole.w = xSize + 10; ballhole.h = ySize + 10;

							//Important parameters (TO HERE)

							//Initialize random seed
							srand(time(NULL));

							int wherehole = rand() % 4 + 1;

							wallOne = wall1(wallOne, wherehole);
							wallTwo = wall2(wallTwo, wherehole);
							wallThree = wall3(wallThree, wherehole);
							wallFour = wall4(wallFour, wherehole);

							ballhole = holeGeneration(ballhole, wherehole);
							ball = ballGeneration(ball, wherehole);

							//Creating the golf ball
							player = IMG_LoadTexture(renderer, "res/ball.bmp");
							SDL_QueryTexture(player, NULL, NULL, &w, &h);
							hole = IMG_LoadTexture(renderer, "res/hole.bmp");
							SDL_QueryTexture(hole, NULL, NULL, &w, &h);



							//Number of the hole (text)
							TTF_Font* font = TTF_OpenFont("res/arialbi.ttf", 25);
							SDL_Color color = { 255, 255, 255 };
							SDL_Surface* surface = TTF_RenderText_Solid(font,
								holetext, color);
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

								if (event.key.keysym.sym == SDLK_SPACE || event.type == SDL_KEYUP) {
									xVel = GetRandomNumber(2, -2);
									yVel = GetRandomNumber(2, -2);
								}
								else if (event.key.keysym.sym == SDLK_SPACE || event.type == SDL_KEYDOWN) {
									xVel = GetRandomNumber(1, -3);
									yVel = GetRandomNumber(1, -3);
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

								if (collision(ball, wallOne) || collision(ball, wallTwo) || collision(ball, wallThree) || collision(ball, wallFour))
								{
									if (collisionY(ball, wallOne) || collisionY(ball, wallTwo) || collisionY(ball, wallThree) || collisionY(ball, wallFour))
									{
										yVel = -yVel;
									}
									else if ((collisionX(ball, wallOne) || collisionX(ball, wallTwo) || collisionX(ball, wallThree) || collisionX(ball, wallFour)))
									{
										xVel = -xVel;
									}
								}

								ball.x += xVel;
								ball.y += yVel;

								if (event.type == SDL_MOUSEBUTTONUP)
								{
									SDL_DestroyTexture(player);
									SDL_DestroyTexture(hole);
									goto startNewLevel;
								}


								SDL_Delay(10);
								//Setting background color
								SDL_SetRenderDrawColor(renderer, 0x10, 0xB3, 0x2D, 0xFF);
								SDL_RenderClear(renderer);
								//Initializing the player and hole
								SDL_RenderCopy(renderer, player, NULL, &ball);
								SDL_RenderCopy(renderer, hole, NULL, &ballhole);
								//Render wall
								SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
								SDL_RenderDrawRect(renderer, &wallOne);
								SDL_RenderDrawRect(renderer, &wallTwo);
								SDL_RenderDrawRect(renderer, &wallThree);
								SDL_RenderDrawRect(renderer, &wallFour);
								//Rendering the text
								SDL_RenderCopy(renderer, texture, NULL, &dstrect);

								//Check if the ball hits the hole
								if (collision(ball, ballhole))
								{
									level++;
									goto startNewLevel;
								}
								SDL_RenderPresent(renderer);
							}

							SDL_DestroyTexture(texture);
							SDL_FreeSurface(surface);
							TTF_CloseFont(font);
						}
						//Closing everything
						TTF_Quit();
						close();
					}
					Sleep(1000);
					break;
				}
				case 1:
				{
					std::cout << "\n\n\n GONG is an endless, fun golf/pong-type game with many \"features\".\n\n";
					std::cout << " Created by Intergalactic warriors:\n";
					std::cout << " Ivan Georgiev - SCRUM Trainer\n";
					std::cout << " Mariyan Ivanov - Quality Assurance Engineer\n";
					std::cout << " Bozhidar Boyadzhiev - Back-end developer\n";
					std::cout << " Maksim Vasilev - Back-end developer\n";
					while (!GetAsyncKeyState(VK_BACK))
					{

					}
					break;
				}
				case 2:
				{
					std::cout << "\n\n\n Tips:\n";
					std::cout << " 1. The ball is always moving to the top left corner while space is not held\n";
					std::cout << " 2. The closer the ball is next to a screen border, the faster it will move\n";
					std::cout << " 3. Hold Space Bar to make ball go to the bottom right corner\n";
					std::cout << " 4. Press Left or Right Click to reset generation\n";
					std::cout << " 5. Have fun\n";
					while (!GetAsyncKeyState(VK_BACK))
					{

					}
					break;
				}
				case 3:
				{
					return 0;
					break;
				} break;
				}
				break;
			}
		}

		Sleep(300);//Wait
	}
	return 0;
}
