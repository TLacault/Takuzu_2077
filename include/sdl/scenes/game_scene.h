#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "input.h"
#include "scene.h"

/* **************************************************************** */

void game_init(Scene scene, Assets assets, SDL_Renderer *ren);
void game_process(Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect);

/* **************************************************************** */

bool main_menu(Scene *scenes);

#endif /* GAME_SCENE_H */