#include "choice.h"

#include <assert.h>

#include "button.h"
#include "input.h"
#include "text.h"

Choice choice_create(SDL_Rect hitbox, char **choices, int nb_choice, int default_choice, Assets assets,
                     SDL_Renderer *ren) {
    Choice button = malloc(sizeof(struct Choice_s));
    assert(button);

    button->hitbox = hitbox;
    button->scaled = hitbox;

    button->hitbox_prev.x = hitbox.x + (7 * hitbox.w / 100);
    button->hitbox_prev.y = hitbox.y + (18 * hitbox.h / 100);
    button->hitbox_prev.w = 5 * hitbox.w / 100;
    button->hitbox_prev.h = 63 * hitbox.h / 100;
    button->scaled_prev = button->hitbox_prev;

    button->hitbox_next.x = hitbox.x + (88 * hitbox.w / 100);
    button->hitbox_next.y = hitbox.y + (18 * hitbox.h / 100);
    button->hitbox_next.w = 5 * hitbox.w / 100;
    button->hitbox_next.h = 63 * hitbox.h / 100;
    button->scaled_next = button->hitbox_next;

    button->choices = malloc(sizeof(struct Text_s) * nb_choice);
    assert(button->choices);

    SDL_Rect label_hitbox;
    label_hitbox.w = strlen(choices[default_choice]) * (3 * hitbox.w / 100);
    label_hitbox.x = hitbox.x + (hitbox.w / 2) - (hitbox.w / 2);
    label_hitbox.y = hitbox.y;
    label_hitbox.h = 80 * hitbox.h / 100;
    for (int i = 0; i < nb_choice; i++) {
        button->choices[i] = text_create(assets, choices[i], RAJDHANI, LIGHT_BLUE, label_hitbox, ren);
    }

    button->current_choice = default_choice;
    button->nb_choice = nb_choice;

    button->pressed = false;
    button->hovered = false;

    return button;
}

void choice_delete(Choice button) {
    for (int i = 0; i < button->nb_choice; i++) {
        text_delete(button->choices[i]);
    }
    free(button->choices);
    free(button);
}

void choice_render(Choice button, Assets assets, SDL_Renderer *ren, SDL_Rect win_rect, Input input) {
    (void)input;
    button->scaled = scale_rect(button->hitbox, win_rect);

    // Center the text in the button
    button->choices[button->current_choice]->scaled =
        scale_rect(button->choices[button->current_choice]->hitbox, win_rect);
    button->choices[button->current_choice]->scaled.x +=
        button->scaled.w / 2 - button->choices[button->current_choice]->scaled.w / 2;
    button->choices[button->current_choice]->scaled.y +=
        button->scaled.h / 2 - button->choices[button->current_choice]->scaled.h / 2;

    SDL_RenderCopy(ren, BT(assets, CHOICE, CHOICE_BACKGROUND), NULL, &button->scaled);
    text_render(button->choices[button->current_choice], ren);
}

bool choice_pressed(Choice button, Input input, SDL_Rect win_rect, Assets assets) {
    button->scaled = scale_rect(button->hitbox, win_rect);
    button->scaled_prev = scale_rect(button->hitbox_prev, win_rect);
    button->scaled_next = scale_rect(button->hitbox_next, win_rect);

    if (left_click(button->scaled_prev, input)) {
        if (button->current_choice == 0) {
            button->current_choice = button->nb_choice - 1;
        } else {
            button->current_choice--;
        }
        // play decrement sound
        (void)assets;
        return true;
    } else if (left_click(button->scaled_next, input)) {
        if (button->current_choice == button->nb_choice - 1) {
            button->current_choice = 0;
        } else {
            button->current_choice++;
        }
        // play increment sound
        (void)assets;
        return true;
    }
    return false;
}

bool choice_hovered(Choice button, Input input, SDL_Rect win_rect, Assets assets) {
    button->scaled = scale_rect(button->hitbox, win_rect);

    if (is_hovered(button->scaled, input)) {
        if (button->hovered == false) {
            // play hover sound
            (void)assets;
        }
        button->hovered = true;
        return true;
    }
    button->hovered = false;
    return false;
}