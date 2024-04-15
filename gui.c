#include <stdio.h>
#define NK_IMPLEMENTATION
#include "nuklear.h"

int main() {
    /* define font */
    struct nk_font_atlas atlas;
    nk_font_atlas_init_default(&atlas);
    nk_font_atlas_begin(&atlas);
    nk_font *font = nk_font_atlas_add_from_file(&atlas, "Path/To/Your/TTF_Font.ttf", 13, 0);
    /* init gui state */
    struct nk_context ctx;
    nk_init_fixed(&ctx, calloc(1, MAX_MEMORY), MAX_MEMORY, &font);

    enum {EASY, HARD};
    static int op = EASY;
    static float value = 0.6f;
    static int i =  20;

    if (nk_begin(&ctx, "Show", nk_rect(50, 50, 220, 220), NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_CLOSABLE)) {
        /* fixed widget pixel width */
        nk_layout_row_static(&ctx, 30, 80, 1);
        if (nk_button_label(&ctx, "button")) {
            /* event handling */
            printf("Button pressed");
        }

        /* fixed widget window ratio width */
        nk_layout_row_dynamic(&ctx, 30, 2);
        if (nk_option_label(&ctx, "easy", op == EASY)) op = EASY;
        if (nk_option_label(&ctx, "hard", op == HARD)) op = HARD;

        /* custom widget pixel width */
        nk_layout_row_begin(&ctx, NK_STATIC, 30, 2);
        {
            nk_layout_row_push(&ctx, 50);
            nk_label(&ctx, "Volume:", NK_TEXT_LEFT);
            nk_layout_row_push(&ctx, 110);
            nk_slider_float(&ctx, 0, &value, 1.0f, 0.1f);
        }
        nk_layout_row_end(&ctx);
    }
    nk_end(&ctx);
    
    /* clear atlas */
    nk_font_atlas_clear(&atlas);

    return 0;
}
