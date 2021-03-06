#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "texture.h"
#include "text.h"
#include "scene.h"

class GraphsSubsystem
{
 public:
  GraphsSubsystem(SDL_Window* window, std::string pathToFont);
  ~GraphsSubsystem();

  GraphsSubsystem(const GraphsSubsystem&) = delete;
  GraphsSubsystem& operator=(const GraphsSubsystem&) = delete;
  GraphsSubsystem(GraphsSubsystem&& rhs);
  GraphsSubsystem& operator=(GraphsSubsystem&& rhs);

  Texture load_texture(std::string pathToPng, int rows, int columns);
  Text load_text(std::string message, SDL_Color color);
  void render(Scene& scene);

  friend void swap(GraphsSubsystem& a, GraphsSubsystem& b) noexcept;
  
 private:
  SDL_Renderer* m_renderer = nullptr;
  TTF_Font* m_main_font = nullptr;
};
