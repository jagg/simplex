#pragma once

#include "texture.h"
#include <SDL_ttf.h>

class Text : public Texture
{
 public:
  Text(std::string text, SDL_Renderer& renderer, TTF_Font& font, SDL_Color color);
  ~Text() = default;

  Text(const Text&) = delete;
  Text& operator=(const Text&) = delete;

  Text(Text&& rhs) : Texture(std::move(rhs)) {};
  Text& operator=(Text&& rhs) = default;

};
