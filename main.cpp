#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include "Cerveau.h"
#include <SDL/SDL.h>




bool bouclePrincipale(SDL_Surface* screen);
void definirPixel(SDL_Surface *surface, int x, int y, Uint32 pixel);

int main ( int argc, char** argv )
{
    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create a new window
    SDL_Surface* screen = SDL_SetVideoMode(1024, 762, 16,
                                           SDL_HWSURFACE|SDL_DOUBLEBUF);
    if ( !screen )
    {
        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }




    bouclePrincipale(screen);





    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}



bool bouclePrincipale(SDL_Surface* screen)
{
    Cerveau monCerveau;
    bool done = false;
    int x, y, f;
    int r=27, v=72, b=1, t=0;

    while (!done)
    {

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {

            switch (event.type)
            {

            case SDL_QUIT:
                done = true;
                break;


            case SDL_KEYDOWN:
                {

                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = true;
                    break;
                }
            }
        }

        // clear screen
        /*r=(r*v);
        v=(r+v);
        b=b*b*b;*/
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, r+t, v*t-t, b+2*t));

        for(x=0;x<screen->w;x++)
        {
            for(y=0;y<screen->h;y++)
            {
                f=int((t*0.2)*x*y)%255;
                b=f;
                v=255-f;
                r=t*(b-v)/(b+v);
                definirPixel(screen, x, y, SDL_MapRGB(screen->format, r, v, b));
            }
        }

        // finally, update the screen :)
        SDL_Flip(screen);

        t++;
        t%=10000000;
    }

    return EXIT_SUCCESS;
}

void definirPixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{

    int nbOctetsParPixel = surface->format->BytesPerPixel;

    if ((x<surface->w) && (y<surface->h) && (x>=0) && (y>=0))
    {


    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * nbOctetsParPixel;


    switch(nbOctetsParPixel)
    {
        case 1:
            *p = pixel;
            break;

        case 2:
            *(Uint16 *)p = pixel;
            break;

        case 3:
            /*Suivant l'architecture de la machine*/
            if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            {
                p[0] = (pixel >> 16) & 0xff;
                p[1] = (pixel >> 8) & 0xff;
                p[2] = pixel & 0xff;
            }
            else
            {
                p[0] = pixel & 0xff;
                p[1] = (pixel >> 8) & 0xff;
                p[2] = (pixel >> 16) & 0xff;
            }
            break;

        case 4:
            *(Uint32 *)p = pixel;
            break;
    }
    }
}
