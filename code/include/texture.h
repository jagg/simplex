#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <cstdint>

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
  void enable_alpha_blending();
  void set_alpha(uint8_t alpha);

  int clipsNum() { return clips_num; }
  

  friend void swap(Texture& a, Texture& b) noexcept;
  
 protected:
  Texture() {}; // To be used by derived classes
  SDL_Texture* texture = nullptr;
  int width = 0;
  int height = 0;
  int clips_num = 0;
};


