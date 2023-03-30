#ifndef CONTROLS_H
#define CONTROLS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "input.h"
#include "scene.h"

/* **************************************************************** */

void controls_init(Scene scene, Assets assets, SDL_Renderer *ren);
void controls_process(Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect);

/* **************************************************************** */

#endif /* CONTROLS_H */