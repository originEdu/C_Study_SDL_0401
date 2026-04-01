#include "SDL.h"
#include "SDL_main.h"

#pragma comment(lib,"SDL2")
#pragma comment(lib,"SDL2main")

int SDL_main(int arg, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING); //초기화
	
	//구조체는 귀찮으니 패스
	int WindowX = 100;
	int WindowY = 100;
	int WindowW = 600;
	int WindowH = 600;

	SDL_Window* MyWindow = SDL_CreateWindow("Hello", WindowX, WindowY, WindowW, WindowH, SDL_WINDOW_SHOWN); //창 생성
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, 0); // 렌더러 생성
	SDL_Event MyEvent; //이벤트 생성

	bool isRunning = true; 
	
	//Rect X,Y
	int X = 0;
	int Y = 0;
	//TileSize
	int TileSize = 30;

	while (isRunning)
	{
		SDL_PollEvent(&MyEvent); //이벤트 받기
		//X버튼이나 ESC눌리면 창닫기
		Uint32 EventType =  MyEvent.type;
		SDL_Keycode KeyCode = MyEvent.key.keysym.sym;
		if (EventType == SDL_QUIT ||
			(EventType == SDL_KEYDOWN && KeyCode == SDLK_ESCAPE))
		{ 
			isRunning = false;
		}
		if (EventType == SDL_KEYDOWN)
		{
			switch (KeyCode)
			{
			case 'w':
				Y--;
				if (Y < 0)
				{
					Y = 0;
				}
				break;
			case 's':
				Y++;
				if (Y > ((WindowH - TileSize) / TileSize))
				{
					Y = ((WindowH - TileSize) / TileSize);
				}
				break;
			case 'a':
				X--;
				if (X < 0)
				{
					X = 0;
				}
				break;
			case 'd':
				X++;
				if (X > ((WindowW - TileSize) / TileSize))
				{
					X = ((WindowW - TileSize) / TileSize);
				}
				break;
			default:
				break;
			}
		}

		SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 255); //무슨색?
		SDL_RenderClear(MyRenderer); //이전에 그려진거 지워

		SDL_SetRenderDrawColor(MyRenderer, 0, 255, 0, 255);
		SDL_Rect Rect = {X* TileSize,Y* TileSize,TileSize,TileSize };
		SDL_RenderFillRect(MyRenderer, &Rect);

		SDL_RenderPresent(MyRenderer); //GPU에 토스
	}

	SDL_DestroyRenderer(MyRenderer); //렌더러 파괴
	SDL_DestroyWindow(MyWindow); //창 파괴

	SDL_Quit(); //종료
	return 0;
}