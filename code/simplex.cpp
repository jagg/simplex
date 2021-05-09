#include <SDL.h>
#include <stdio.h>
#include "texture.h"
#include "window_subsystem.h"
#include "graphs_subsystem.h"
#include "text_subsystem.h"
#include "text.h"
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std::string_literals;

bool handleEvents(Scene& scene);

int main(int argc, char* args[])
{

  try
  {
    WindowSubsystem window_subsystem(640, 480);
    GraphsSubsystem graphs_subsystem(window_subsystem.get_window());
    TextSubsystem text_subsystem("W:\\simplex\\data\\VT323-Regular.ttf");

  
    Texture background_texture = graphs_subsystem.load_texture("W:\\simplex\\data\\landscape.png", 0, 0);
    Scene scene(std::move(background_texture));

    Texture hero_texture = graphs_subsystem.load_texture("W:\\simplex\\data\\character1.png", 4, 3);
    hero_texture.set_alpha(100);
    scene.create_sprite("hero"s, 50, 50, std::move(hero_texture));

    // Text title(*text_subsystem.main_font(), renderer, "Mama y la Aranya", {0, 0, 0});
  

    bool quit = false;
    while (!quit)
    {
      quit = handleEvents(scene);
      graphs_subsystem.render(scene);
    }

    return 0;
  }
  catch (std::runtime_error& e)
  {
    std::cerr << e.what() << std::endl;
    return -1;
  }
}


bool handleEvents(Scene& scene)
{
  bool quit = false;
  SDL_Event event;
  while (SDL_PollEvent(&event) != 0)
  {
    if (event.type == SDL_QUIT)
    {
      quit = true;
    }
    else if (event.type == SDL_KEYDOWN)
    {
      switch (event.key.keysym.sym)
      {
        case SDLK_UP:
          scene.move_sprite("hero"s, Direction::up);
          break;

        case SDLK_DOWN:
          scene.move_sprite("hero"s, Direction::down);
          break;

        case SDLK_LEFT:
          scene.move_sprite("hero"s, Direction::left);
          break;

        case SDLK_RIGHT:
          scene.move_sprite("hero"s, Direction::right);
          break;

        default:
          break;
      }
    }
  }
  return quit;
}
