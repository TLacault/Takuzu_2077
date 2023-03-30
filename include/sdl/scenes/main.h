#ifndef MAIN_H
#define MAIN_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "assets.h"
#include "input.h"
#include "scene.h"

/* **************************************************************** */

void main_init(Scene scene, Assets assets, SDL_Renderer *ren);
void main_process(Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect);

/* **************************************************************** */

#endif /* MAIN_H */