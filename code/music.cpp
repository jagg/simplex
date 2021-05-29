#include "music.h"
#include <stdexcept>

using namespace std::string_literals;

Music::Music(const std::string path)
{
  m_music = Mix_LoadMUS(path.c_str());
  if (!m_music)
  {
    throw std::runtime_error("Failed to load chunk from '"s + path + "' : "s + std::string(Mix_GetError()));
  }
}
Music::~Music()
{
  if (m_music)
  {
    Mix_FreeMusic(m_music);
  }
  m_music = nullptr;
}

Music::Music(Music&& rhs)
{
  m_music = std::exchange(rhs.m_music, nullptr);
}

Music& Music::operator=(Music&& rhs)
{
  Music copy(std::move(rhs));
  swap(copy, *this);
  return *this;
}

void Music::play()
{
  Mix_PlayMusic(m_music, -1);
}


void swap(Music& a, Music& b) noexcept
{
  using std::swap;
  swap(a.m_music, b.m_music);
}
