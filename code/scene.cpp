#include "scene.h"

Scene::Scene(Texture backgr_texture) : background(std::move(backgr_texture)) {}

void Scene::create_sprite(std::string id, int x, int y, Texture texture)
{
  // TODO The textures should have its own id, so that they can be shared
  textures.insert({ id, std::move(texture) });
  Sprite sprite(textures.at(id), x, y);
  sprites.insert({ id, sprite });

}

void Scene::delete_sprite(std::string id)
{
  sprites.erase(id);
}

void Scene::move_sprite(std::string id, Direction direction)
{
  Sprite& sprite = sprites.at(id);
  sprite.move(direction);
}

const std::unordered_map<std::string, Sprite>& Scene::get_sprites() const
{
  return sprites;
}

const Texture& Scene::get_background() const
{
  return background;
}
             
