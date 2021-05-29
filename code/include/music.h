#pragma once

#include <SDL.h>
#include <SDL_Mixer.h>
#include <string>

class Music
{
 public:
  ~Music();

  Music(const Music&) = delete;
  Music& operator=(const Music&) = delete;
  Music(Music&& rhs);
  Music& operator=(Music&& rhs);

  void play();
  
  friend void swap(Music& a, Music& b) noexcept;
  
 private:
  explicit Music(const std::string path);
  Mix_Music* m_music = nullptr;

  friend class SoundSubsystem;
};

