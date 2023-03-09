#include "allegro.h"
#include <stdio.h>
#include <conio.h>

#define DEFAULT_SCREEN_WIDTH 320
#define DEFAULT_SCREEN_HEIGHT 240

int width = DEFAULT_SCREEN_WIDTH, height = DEFAULT_SCREEN_HEIGHT;

int main()
{
    RGB palette[256];

    if (allegro_init() != 0) return 1;

    install_keyboard();

    if (set_gfx_mode(GFX_AUTODETECT, width, height, 0, 0) != 0)
    {
        if (set_gfx_mode(GFX_SAFE, width, height, 0, 0) != 0)
        {
            set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
            allegro_message("Unable to set any graphic mode\n%s\n", allegro_error);
            return 1;
        }
    }

    /* Create the bitmap */
    BITMAP *buffer = create_bitmap(320, 200);

    /* read in the bitmap files */
    BITMAP *character = load_bitmap("Isabella_w.bmp", palette);
    if (character)
    {
    	while (!key[KEY_ESC])
    	{
    	    blit(buffer, screen, 0, 0, 0, 0, 700, 480);
    		//dimensiones de la imagen = 102*79
            blit(character, screen, 0, 0, 20, 20, 102, 79); // imagen en pantalla
    	}
    }

    rect(buffer, 0, 0, 10, 10, makecol(255, 255, 255));
    
    readkey();
    
    // clear_to_color(buffer, makecol(0, 255, 255));

    /* destroy the bitmap */
    destroy_bitmap(buffer);
    /* Exit from Allegro*/
    allegro_exit();
    return 0;
}

END_OF_MAIN()
