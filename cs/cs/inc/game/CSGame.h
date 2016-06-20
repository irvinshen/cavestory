#pragma once

class CSWin;
class InputHandler;
union SDL_Event;

class CSGame
{
public:
	CSGame();
	~CSGame();
private:
	void MainLoop() noexcept;
	void HandleEvent(const SDL_Event& sdlevt) noexcept;
	void UpdateGame(int tElapsed) noexcept;

	static const int c_tMaxFps;
	static const int c_tMaxAllowedTime;

	std::unique_ptr<InputHandler> m_spInputHandler = nullptr;
};