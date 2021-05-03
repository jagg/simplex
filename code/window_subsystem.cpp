#include "window_subsystem.h"
#include <string>
#include <stdexcept>

using namespace std::string_literals;

WindowSubsystem::WindowSubsystem(int width, int height)
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    throw std::runtime_error("Failed to initialise SDL:"s + std::string(SDL_GetError()));
  }
  else
  {
    m_window = SDL_CreateWindow("Simplex", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (m_window == nullptr)
    {
      throw std::runtime_error("Failed to create main window:"s + std::string(SDL_GetError()));
    }
  }
}


WindowSubsystem::~WindowSubsystem()
{
  SDL_DestroyWindow(m_window);
  m_window = nullptr;
  SDL_Quit();
}

WindowSubsystem::WindowSubsystem(WindowSubsystem&& rhs)
{
  m_window = std::exchange(rhs.m_window, nullptr);
}

WindowSubsystem& WindowSubsystem::operator=(WindowSubsystem&& rhs)
{
  WindowSubsystem copy(std::move(rhs));
  swap(copy, *this);
  return *this;
}

std::pair<int, int> WindowSubsystem::get_window_size() const
{
  int width {0};
  int height {0};
  SDL_GetWindowSize(m_window, &width, &height);
  return std::pair<int,int> { width, height };
}

SDL_Window* WindowSubsystem::get_window() const
{
  return m_window;
}

void swap(WindowSubsystem& a, WindowSubsystem& b) noexcept
{
  using std::swap;
  swap(a.m_window, b.m_window);
}

