#pragma once

#include "texture.h"

enum class Direction { up, down, left, right, stand };

class Sprite
{
 public:
  Sprite(const Texture& txt, int x_coord, int y_coord) : m_texture(txt), m_x(x_coord), m_y(y_coord) {};
  void move(Direction direction);
  void render(SDL_Renderer& renderer);

 private:
  const Texture& m_texture;
  int m_x = 0;
  int m_y = 0;
  int m_current_frame = 0;
  Direction m_direction = Direction::stand;
};
