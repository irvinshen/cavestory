#include "stdafx.h"

#include <game/CSGame.h>
#include <game/CSWin.h>
#include <game/InputHandler.h>
#include <SDL/SDL.h>

#include <algorithm>

/*static*/ const int CSGame::c_tMaxFps = 50;
/*static*/ const int CSGame::c_tMaxAllowedTime = 1000 / c_tMaxFps;
CSGame::CSGame()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	m_spInputHandler = std::make_unique<InputHandler>();
	MainLoop();
}

CSGame::~CSGame()
{

}

void CSGame::MainLoop() noexcept
{
	CSWin cswin;
	SDL_Event sdlevt;

	while (true)
	{
		if (!SDL_PollEvent(&sdlevt))
			continue;

		int tEventStarted = SDL_GetTicks();

		if (sdlevt.type == SDL_QUIT)
			return;
		else if (sdlevt.type == SDL_KEYDOWN && sdlevt.key.keysym.scancode == SDL_SCANCODE_ESCAPE) // Should prompt, not immediately return
			return;

		HandleEvent(sdlevt);

		int tElapsed = SDL_TICKS_PASSED(tEventStarted, SDL_GetTicks());
		UpdateGame(std::min(c_tMaxAllowedTime, tElapsed));
	}

	return;
}

void CSGame::HandleEvent(const SDL_Event& sdlevt) noexcept
{
	switch (sdlevt.type)
	{
		case SDL_KEYDOWN:
			m_spInputHandler->HandleKeyDown(sdlevt);
			break;
		case SDL_KEYUP:
			m_spInputHandler->HandleKeyUp(sdlevt);
			break;
		default:
			break;
	}
}

void CSGame::UpdateGame(int /*tElapsed*/) noexcept
{

}