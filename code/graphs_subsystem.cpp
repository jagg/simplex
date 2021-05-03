#include "graphs_subsystem.h"
#include <string>
#include <stdexcept>

using namespace std::string_literals;

GraphsSubsystem::GraphsSubsystem(SDL_Window* window)
{

  m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (!m_renderer)
  {
    throw std::runtime_error("Failed create renderer:"s + std::string(IMG_GetError()));
  }
  else
  {
    SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  }
}


GraphsSubsystem::~GraphsSubsystem()
{
  SDL_DestroyRenderer(m_renderer);
  IMG_Quit();
  m_renderer = nullptr;
}


GraphsSubsystem::GraphsSubsystem(GraphsSubsystem&& rhs)
{
  m_renderer = std::exchange(rhs.m_renderer, nullptr);
}


GraphsSubsystem& GraphsSubsystem::operator=(GraphsSubsystem&& rhs)
{
  GraphsSubsystem copy(std::move(rhs));
  swap(copy, *this);
  return *this;
}


Texture GraphsSubsystem::load_texture(std::string pathToPng, int rows, int columns)
{
  return Texture(pathToPng, *m_renderer, rows * columns);
}


void GraphsSubsystem::render(Scene& scene)
{
  SDL_RenderClear(m_renderer);

  scene.get_background().render(0, 0, *m_renderer);
  for (auto entry : scene.get_sprites())
  {
    entry.second.render(*m_renderer);
  }

  SDL_RenderPresent(m_renderer);
}

void swap(GraphsSubsystem& a, GraphsSubsystem& b) noexcept
{
  using std::swap;
  swap(a.m_renderer, b.m_renderer);
}

