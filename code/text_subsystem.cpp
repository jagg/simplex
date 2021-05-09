#include "text_subsystem.h"
#include <stdexcept>

using namespace std::string_literals;


TextSubsystem::TextSubsystem(std::string path_to_font)
{
  if (TTF_Init() == -1)
  {
    throw std::runtime_error("Failed to initialise SDL_ttf: "s + std::string(TTF_GetError()));
  }

  if ( (m_main_font = TTF_OpenFont(path_to_font.c_str(), 28)) == 0)
  {
    throw std::runtime_error("Failed to load font "s + path_to_font + ": "s + std::string(TTF_GetError()));
  }
}

TextSubsystem::~TextSubsystem()
{
  TTF_CloseFont(m_main_font);
  m_main_font = nullptr;
  TTF_Quit();
}

TextSubsystem::TextSubsystem(TextSubsystem&& rhs)
{
  m_main_font = std::exchange(rhs.m_main_font, nullptr);
}


TextSubsystem& TextSubsystem::operator=(TextSubsystem&& rhs)
{
  TextSubsystem copy(std::move(rhs));
  swap(copy, *this);
  return *this;
}

void swap(TextSubsystem& a, TextSubsystem& b) noexcept
{
  using std::swap;
  swap(a.m_main_font, b.m_main_font);
}



