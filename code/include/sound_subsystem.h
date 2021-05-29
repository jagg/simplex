#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <string>
#include "music.h"
#include "sound_effect.h"

class SoundSubsystem
{
 public:
  SoundSubsystem();
  ~SoundSubsystem();

  SoundSubsystem(const SoundSubsystem&) = delete;
  SoundSubsystem& operator=(const SoundSubsystem&) = delete;
  SoundSubsystem(SoundSubsystem&& rhs) = default;
  SoundSubsystem& operator=(SoundSubsystem&& rhs) = default;

  Music load_music(const std::string path);
  SoundEffect load_effect(const std::string path);
};
