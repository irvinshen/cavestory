#include "stdafx.h"
#include <game/CSWin.h>
#include <SDL/SDL_image.h>

/*static*/ const int CSWin::c_iCSWinWidth = 640;
/*static*/ const int CSWin::c_iCSWinHeight = 480;
CSWin::CSWin()
{
	SDL_CreateWindowAndRenderer(CSWin::c_iCSWinWidth, CSWin::c_iCSWinHeight, 0/*window_flags*/, &m_psdlWin, &m_psdlRenderer);
}

CSWin::~CSWin()
{
	SDL_DestroyWindow(m_psdlWin);
	SDL_DestroyRenderer(m_psdlRenderer);
}

SDL_Surface *CSWin::SdlSurfaceLoadImg(const std::string& strImage) noexcept
{
	if (m_mapSprites.count(strImage) == 0)
		m_mapSprites[strImage] = IMG_Load(strImage.c_str());

	return m_mapSprites[strImage];
}

void CSWin::BltSurface(SDL_Texture *psdlTexture, const SDL_Rect& sdlRectSrc, SDL_Rect *psdlRectDst) noexcept
{
	if (SDL_RenderCopy(m_psdlRenderer, psdlTexture, &sdlRectSrc, psdlRectDst) < 0)
		assert(false); // Print out SDL_GetError()
}