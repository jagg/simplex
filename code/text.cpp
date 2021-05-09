#include "text.h"

#include <stdexcept>

Text::Text(std::string text, SDL_Renderer& renderer, TTF_Font& font, SDL_Color color)
{
  this->texture = nullptr;
  SDL_Surface* surface = TTF_RenderText_Solid(&font, text.c_str(), color);
  if (!surface)
  {
    throw std::runtime_error(std::string("Failed to load text: ") + text + std::string(":") + std::string(TTF_GetError()));
  }

  this->texture = SDL_CreateTextureFromSurface(&renderer, surface);
  if (!texture)
  {
    SDL_FreeSurface(surface);
    throw std::runtime_error(std::string("Failed to create text:  ") + text + std::string(":") + std::string(SDL_GetError()));
  }

  this->width = surface->w;
  this->height = surface->h;
  this->clips_num = 0;

  SDL_FreeSurface(surface);
}

