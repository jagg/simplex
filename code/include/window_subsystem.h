#pragma once

#include <SDL.h>
#include <utility>

class WindowSubsystem
{
 public:
  WindowSubsystem(int width, int height);
  ~WindowSubsystem();

  WindowSubsystem(const WindowSubsystem&) = delete;
  WindowSubsystem& operator=(const WindowSubsystem&) = delete;
  WindowSubsystem(WindowSubsystem&& rhs);
  WindowSubsystem& operator=(WindowSubsystem&& rhs);

  std::pair<int, int> get_window_size() const;
  SDL_Window* get_window() const;

  friend void swap(WindowSubsystem& a, WindowSubsystem& b) noexcept;
  
 private:
  SDL_Window* m_window = nullptr;

};

