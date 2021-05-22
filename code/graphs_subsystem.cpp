#include "graphs_subsystem.h"
#include <string>
#include <stdexcept>

using namespace std::string_literals;

GraphsSubsystem::GraphsSubsystem(SDL_Window* window, std::string pathToFont)
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

  if (TTF_Init() == -1)
  {
    throw std::runtime_error("Failed to initialise SDL_ttf: "s + std::string(TTF_GetError()));
  }

  if ( (m_main_font = TTF_OpenFont(pathToFont.c_str(), 28)) == 0)
  {
    throw std::runtime_error("Failed to load font "s + pathToFont + ": "s + std::string(TTF_GetError()));
  }
}


GraphsSubsystem::~GraphsSubsystem()
{
  SDL_DestroyRenderer(m_renderer);
  IMG_Quit();
  m_renderer = nullptr;

  TTF_CloseFont(m_main_font);
  m_main_font = nullptr;
  TTF_Quit();
}


GraphsSubsystem::GraphsSubsystem(GraphsSubsystem&& rhs)
{
  m_renderer = std::exchange(rhs.m_renderer, nullptr);
  m_main_font = std::exchange(rhs.m_main_font, nullptr);
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

Text GraphsSubsystem::load_text(std::string message, SDL_Color color)
{
  return Text(message, *m_renderer, *m_main_font, color);
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
  swap(a.m_main_font, b.m_main_font);
}

