#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "texture.h"
#include "scene.h"

class GraphsSubsystem
{
 public:
  explicit GraphsSubsystem(SDL_Window* window);
  ~GraphsSubsystem();

  GraphsSubsystem(const GraphsSubsystem&) = delete;
  GraphsSubsystem& operator=(const GraphsSubsystem&) = delete;
  GraphsSubsystem(GraphsSubsystem&& rhs);
  GraphsSubsystem& operator=(GraphsSubsystem&& rhs);

  Texture load_texture(std::string pathToPng, int rows, int columns);
  void render(Scene& scene);

  friend void swap(GraphsSubsystem& a, GraphsSubsystem& b) noexcept;
  
 private:
  SDL_Renderer* m_renderer = nullptr;
};
