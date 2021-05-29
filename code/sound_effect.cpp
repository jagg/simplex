#include "sound_effect.h"
#include <stdexcept>

using namespace std::string_literals;

SoundEffect::SoundEffect(const std::string path)
{
  m_sound = Mix_LoadWAV(path.c_str());
  if (!m_sound)
  {
    throw std::runtime_error("Failed to load chunk from '"s + path + "' : "s + std::string(Mix_GetError()));
  }
}
SoundEffect::~SoundEffect()
{
  if (m_sound)
  {
    Mix_FreeChunk(m_sound);
  }
  m_sound = nullptr;
}

SoundEffect::SoundEffect(SoundEffect&& rhs)
{
  m_sound = std::exchange(rhs.m_sound, nullptr);
}

SoundEffect& SoundEffect::operator=(SoundEffect&& rhs)
{
  SoundEffect copy(std::move(rhs));
  swap(copy, *this);
  return *this;
}

void SoundEffect::play()
{
  Mix_PlayChannel(-1, m_sound, 0);
}


void swap(SoundEffect& a, SoundEffect& b) noexcept
{
  using std::swap;
  swap(a.m_sound, b.m_sound);
}
