#include "scene.h"

Scene::Scene(Texture backgr_texture) : m_background(std::move(backgr_texture)) {}

void Scene::create_sprite(std::string id, int x, int y, Texture texture)
{
  // TODO The textures should have its own id, so that they can be shared
  m_textures.insert({ id, std::move(texture) });
  Sprite sprite(m_textures.at(id), x, y);
  m_sprites.insert({ id, sprite });
}

void Scene::delete_sprite(std::string id)
{
  m_sprites.erase(id);
}

void Scene::move_sprite(std::string id, Direction direction)
{
  Sprite& sprite = m_sprites.at(id);
  sprite.move(direction);
}

const std::unordered_map<std::string, Sprite>& Scene::get_sprites() const
{
  return m_sprites;
}

const Texture& Scene::get_background() const
{
  return m_background;
}
             
