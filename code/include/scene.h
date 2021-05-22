#pragma once

#include <unordered_map>
#include "sprite.h"
#include "text.h"

class Scene
{
 public:
  explicit Scene(Texture backgr_texture);

  void create_sprite(std::string id, int x, int y, Texture texture);
  void delete_sprite(std::string id);
  void move_sprite(std::string id, Direction direction);
  const std::unordered_map<std::string, Sprite>& get_sprites() const;
  
  const Texture& get_background() const;

 private:
  std::unordered_map<std::string, Texture> m_textures;
  std::unordered_map<std::string, Sprite> m_sprites;
  std::unordered_map<std::string, Text> m_text_map;
  Texture m_background;
};
