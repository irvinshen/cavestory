#include "stdafx.h"
#include <game/InputHandler.h>

void InputHandler::HandleKeyDown(const SDL_Event& evt) noexcept
{
	assert(evt.type == SDL_KEYDOWN);

	if (evt.key.repeat != 0)
		m_mapHeld[evt.key.keysym.scancode] = true;
}

void InputHandler::HandleKeyUp(const SDL_Event& evt) noexcept
{
	assert(evt.type == SDL_KEYUP);
	m_mapHeld[evt.key.keysym.scancode] = false;
}