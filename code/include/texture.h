#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Texture
{
 public:
  Texture(std::string path, SDL_Renderer& renderer, int clips);
  ~Texture();

  Texture(const Texture&) = delete;
  Texture& operator=(const Texture&) = delete;

  Texture(Texture&& rhs);
  Texture& operator=(Texture&& rhs);
  
  void render(int x, int y, SDL_Renderer& renderer, int clip = 0) const;
  void modulate(Uint8 red, Uint8 green, Uint8 blue) const;
  int clipsNum() { return clips_num; }

  friend void swap(Texture& a, Texture& b) noexcept;
  
 private:
  SDL_Texture* texture;
  int width;
  int height;
  int clips_num;
};


