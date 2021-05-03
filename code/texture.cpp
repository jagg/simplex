#include "texture.h"
#include <stdexcept>

Texture::Texture(std::string path, SDL_Renderer& renderer, int clips) : clips_num(clips)
{
  this->texture = nullptr;
  SDL_Surface* surface = IMG_Load(path.c_str());
  if (!surface)
  {
    throw std::runtime_error(std::string("Failed to load image ") + path + std::string(":") + std::string(IMG_GetError()));
  }
  SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 0xFF, 0xFF));

  this->texture = SDL_CreateTextureFromSurface(&renderer, surface);
  if (!texture)
  {
    SDL_FreeSurface(surface);
    throw std::runtime_error(std::string("Failed to create texture for  ") + path + std::string(":") + std::string(SDL_GetError()));
  }

  this->width = surface->w;
  this->height = surface->h;

  SDL_FreeSurface(surface);
}

Texture::~Texture()
{
  if (this->texture)
  {
    SDL_DestroyTexture(texture);
    this->texture = nullptr;
    this->width = 0;
    this->height = 0;
    this->clips_num = 0;
  }
}

Texture::Texture(Texture&& rhs)
{
  texture = std::exchange(rhs.texture, nullptr);
  width = std::exchange(rhs.width, 0);
  height = std::exchange(rhs.height, 0);
  clips_num = std::exchange(rhs.clips_num, 0);
}

Texture& Texture::operator=(Texture&& rhs)
{
  Texture copy(std::move(rhs));
  swap(copy, *this);
  return *this;
}

void swap(Texture& a, Texture& b) noexcept
{
  using std::swap;
  swap(a.texture, b.texture);
  swap(a.width, b.width);
  swap(a.height, b.height);
  swap(a.clips_num, b.clips_num);
}

void Texture::render(int x, int y, SDL_Renderer& renderer, int clip) const
{
  // TODO This assumes 4x3 sprite sheets
  SDL_Rect clip_rect;
  if (clips_num == 0)
  {
    clip_rect = { 0, 0, this->width, this->height };
  }
  else
  {
    int column = clip % 3;
    int row = clip / 3;
    clip_rect = { column * this->width/3, row * this->height/4, this->width/3, this->height/4 };
  }

  SDL_Rect pos_rect = { x, y, clip_rect.w, clip_rect.h };
  
  SDL_RenderCopy(&renderer, this->texture, &clip_rect, &pos_rect);
}

void Texture::modulate(Uint8 red, Uint8 green, Uint8 blue) const
{
  SDL_SetTextureColorMod(this->texture, red, green, blue);
}
