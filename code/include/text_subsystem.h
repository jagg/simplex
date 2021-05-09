#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class TextSubsystem
{
 public:
  explicit TextSubsystem(std::string path_to_font);
  ~TextSubsystem();

  TextSubsystem(const TextSubsystem&) = delete;
  TextSubsystem& operator=(const TextSubsystem&) = delete;
  TextSubsystem(TextSubsystem&& rhs);
  TextSubsystem& operator=(TextSubsystem&& rhs);

  friend void swap(TextSubsystem& a, TextSubsystem& b) noexcept;
  
  // TODO I should probably wrap the fonts instead of leaking them like this
  TTF_Font* main_font() { return m_main_font; }

  
 private:
  TTF_Font* m_main_font = nullptr;
};
