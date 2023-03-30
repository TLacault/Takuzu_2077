#ifndef CREDITS_H
#define CREDITS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "input.h"
#include "scene.h"

/* **************************************************************** */

void credits_init(Scene scene, Assets assets, SDL_Renderer *ren);
void credits_process(Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect);

/* **************************************************************** */

#endif /* CREDITS_H */