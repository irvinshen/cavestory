#pragma once
#include <SDL/SDL.h>
#include <map>

class InputHandler
{
public:
	~InputHandler() { }
	void HandleKeyDown(const SDL_Event& evt) noexcept;
	void HandleKeyUp(const SDL_Event& evt) noexcept;
private:
	std::map<SDL_Scancode, bool> m_mapHeld;
};
