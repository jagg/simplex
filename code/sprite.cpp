#include "sprite.h"

void Sprite::move(Direction direction)
{
  int speed = 5;
  switch(direction)
  {
  case Direction::up: m_y-=speed; break;
  case Direction::down: m_y+=speed; break;
  case Direction::left: m_x-=speed; break;
  case Direction::right: m_x+=speed; break;
  case Direction::stand: break; // do nothing
  }
  m_direction = direction;

  switch(m_direction)
  {
  case Direction::up: m_current_frame = m_current_frame >=9 && m_current_frame <= 10 ? m_current_frame+1 : 9; break;
  case Direction::down: m_current_frame = m_current_frame >=0 && m_current_frame <= 1 ? m_current_frame+1 : 0; break;
  case Direction::left: m_current_frame = m_current_frame >=3 && m_current_frame <= 4 ? m_current_frame+1 : 3; break;
  case Direction::right: m_current_frame = m_current_frame >=6 && m_current_frame <= 7 ? m_current_frame+1 : 6; break;
  case Direction::stand: break; // do nothing
  }

}

void Sprite::render(SDL_Renderer& renderer)
{
  m_texture.render(m_x, m_y, renderer, m_current_frame);
}
