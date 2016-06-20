#pragma once
#include <map>
#include <string>
#include <SDL/SDL.h>

class CSWin
{
public:
	CSWin();
	~CSWin();

	void Render() { SDL_RenderPresent(m_psdlRenderer); }
	void Clear() { SDL_RenderClear(m_psdlRenderer); }

	SDL_Surface *SdlSurfaceLoadImg(const std::string& strImage) noexcept;
	void BltSurface(SDL_Texture *psdlTexture, const SDL_Rect& sdlRectSrc, SDL_Rect *psdlRectDst) noexcept;
private:
	static const int c_iCSWinWidth;
	static const int c_iCSWinHeight;

	SDL_Window *m_psdlWin = nullptr;
	SDL_Renderer *m_psdlRenderer = nullptr;
	std::map<std::string, SDL_Surface *> m_mapSprites;
};