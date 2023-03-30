#include "sounds.h"

#include "button.h"
#include "env.h"
#include "input.h"

/* **************************************************************** */

void sounds_init(Scene sounds, Assets assets, SDL_Renderer *ren) {
    scene_init(sounds, 0, 0, 4, 0, 3, 0, 0);

    (void)assets;
    (void)ren;

    SDL_Rect hitbox = {842, 283, 660, 59};
    sounds->slider_b[0] = slider_create(hitbox, 50, 0, 100, assets, ren);

    hitbox = (SDL_Rect){842, 359, 660, 59};
    sounds->slider_b[1] = slider_create(hitbox, 50, 0, 100, assets, ren);

    hitbox = (SDL_Rect){842, 435, 660, 59};
    sounds->slider_b[2] = slider_create(hitbox, 100, 0, 100, assets, ren);

    hitbox = (SDL_Rect){842, 632, 660, 59};
    sounds->toggle_b[0] = toggle_create(hitbox, true);

    hitbox = (SDL_Rect){842, 707, 660, 59};
    sounds->toggle_b[1] = toggle_create(hitbox, true);

    hitbox = (SDL_Rect){842, 783, 660, 59};
    sounds->toggle_b[2] = toggle_create(hitbox, true);

    hitbox = (SDL_Rect){842, 859, 660, 59};
    sounds->toggle_b[3] = toggle_create(hitbox, true);
}

void sounds_process(Scene *scenes, Input input, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect) {
    if (scenes[SOUNDS]->is_active == false)
        return;

    (void)ren;

    SDL_Rect hitbox = {715, 67, 180, 28};
    hitbox = scale_rect(hitbox, win_rect);
    if (is_hovered(hitbox, input)){
        Mix_PlayChannel(-1, SOUND(assets, SOUND_HOVER), 0);
    }
    if (left_click(hitbox, input)) {
        Mix_PlayChannel(-1, SOUND(assets, SOUND_SWIPE), 0);
        scenes[CONTROLS]->is_active = true;
        scenes[SOUNDS]->is_active = false;
    }

    hitbox = (SDL_Rect){1055, 67, 174, 28};
    hitbox = scale_rect(hitbox, win_rect);
    if (left_click(hitbox, input)) {
        Mix_PlayChannel(-1, SOUND(assets, SOUND_SWIPE), 0);
        scenes[GRAPHICS]->is_active = true;
        scenes[SOUNDS]->is_active = false;
    }

    hitbox = (SDL_Rect){1394, 67, 107, 28};
    hitbox = scale_rect(hitbox, win_rect);
    if (left_click(hitbox, input)) {
        Mix_PlayChannel(-1, SOUND(assets, SOUND_SWIPE), 0);
        scenes[STATS]->is_active = true;
        scenes[SOUNDS]->is_active = false;
    }

    if (slider_dragged(scenes[SOUNDS]->slider_b[0], input, assets, ren, win_rect)) {
        int value = scenes[SOUNDS]->slider_b[0]->value;
        value = value * 20 / 100;
        Mix_Volume(-1, value);
        Mix_PlayChannel(-1, SOUND(assets, SOUND_SWIPE), 0);
    }

    if (slider_dragged(scenes[SOUNDS]->slider_b[1], input, assets, ren, win_rect)) {
        int value = scenes[SOUNDS]->slider_b[1]->value;
        value = value * 20 / 100;
        Mix_Volume(0, value);
        Mix_PlayChannel(-1, SOUND(assets, SOUND_SWIPE), 0);
    }

    if (slider_dragged(scenes[SOUNDS]->slider_b[2], input, assets, ren, win_rect)) {
        printf("[slider 2]: %d\n", scenes[SOUNDS]->slider_b[2]->value);
        Mix_PlayChannel(-1, SOUND(assets, SOUND_SWIPE), 0);
    }

    if (toggle_pressed(scenes[SOUNDS]->toggle_b[0], input, win_rect, assets)) {
        if (scenes[SOUNDS]->toggle_b[0]->state){
            Mix_PlayChannel(-1, SOUND(assets, SOUND_AFFIRMATIVE), 0);
        }else{
            Mix_PlayChannel(-1, SOUND(assets, SOUND_NEGATIVE), 0);
        }
        printf("[toggle 0]: %d\n", scenes[SOUNDS]->toggle_b[0]->state);
    }

    if (toggle_pressed(scenes[SOUNDS]->toggle_b[1], input, win_rect, assets)) {
        printf("[toggle 1]: %d\n", scenes[SOUNDS]->toggle_b[1]->state);
    }

    if (toggle_pressed(scenes[SOUNDS]->toggle_b[2], input, win_rect, assets)) {
        if (scenes[SOUNDS]->toggle_b[2]->state){
            Mix_PlayChannel(-1, SOUND(assets, SOUND_AFFIRMATIVE), 0);
        }else{
            Mix_PlayChannel(-1, SOUND(assets, SOUND_NEGATIVE), 0);
        }
        printf("[toggle 2]: %d\n", scenes[SOUNDS]->toggle_b[2]->state);
    }

    if (toggle_pressed(scenes[SOUNDS]->toggle_b[3], input, win_rect, assets)) {
        if (scenes[SOUNDS]->toggle_b[3]->state){
            Mix_PlayChannel(-1, SOUND(assets, SOUND_AFFIRMATIVE), 0);
        }else{
            Mix_PlayChannel(-1, SOUND(assets, SOUND_NEGATIVE), 0);
        }
        printf("[toggle 3]: %d\n", scenes[SOUNDS]->toggle_b[3]->state);
    }

    if (slider_dragged(scenes[SOUNDS]->slider_b[0], input, assets, ren, win_rect)) {
        printf("[slider 0]: %d\n", scenes[SOUNDS]->slider_b[0]->value);
    }
}

/* **************************************************************** */