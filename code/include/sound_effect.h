#pragma once

#include <SDL.h>
#include <SDL_Mixer.h>
#include <string>

class SoundEffect
{
 public:
  ~SoundEffect();

  SoundEffect(const SoundEffect&) = delete;
  SoundEffect& operator=(const SoundEffect&) = delete;
  SoundEffect(SoundEffect&& rhs);
  SoundEffect& operator=(SoundEffect&& rhs);

  void play();
  
  friend void swap(SoundEffect& a, SoundEffect& b) noexcept;
  
 private:
  explicit SoundEffect(const std::string path);
  Mix_Chunk* m_sound = nullptr;

  friend class SoundSubsystem;
};

