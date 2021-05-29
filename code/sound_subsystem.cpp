#include "sound_subsystem.h"
#include <stdexcept>

using namespace std::string_literals;


SoundSubsystem::SoundSubsystem()
{
  if (SDL_Init(SDL_INIT_AUDIO) < 0)
  {
    throw std::runtime_error("Failed to initialise SDL Audio:"s + std::string(SDL_GetError()));
  }

  if (Mix_OpenAudio(4100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
  {
    throw std::runtime_error("Failed to initialise SDL Mixer:"s + std::string(Mix_GetError()));
  }
}

SoundSubsystem::~SoundSubsystem()
{
  Mix_Quit();
}

Music SoundSubsystem::load_music(const std::string path)
{
  return Music(path);
}

SoundEffect SoundSubsystem::load_effect(const std::string path)
{
  return SoundEffect(path);
}



