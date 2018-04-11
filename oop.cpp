// Anda tidak perlu melakukan perubahan pada file ini untuk memenuhi spek
// wajib. Namun, hal tersebut diperbolehkan.
#include "oop.hpp"

#include <map>
#include <iostream>
#include <chrono>
#include <stdlib.h>

using namespace std::chrono;

high_resolution_clock::time_point start = high_resolution_clock::now();

double time_since_start()
{
    high_resolution_clock::time_point now = high_resolution_clock::now();
        return duration_cast<duration<double>>(now - start).count();
}

SDL_Window* sdlWindow;
SDL_Renderer* renderer;
std::map<std::string, SDL_Surface*> loadedSurfaces;
std::map<int, TTF_Font*> loadedFontSizes;
SDL_Surface* gScreenSurface = NULL;

bool init()
{
    bool success = true;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {

        if(TTF_Init() == -1) {
            printf("TTF_Init: %s\n", TTF_GetError());
            success = false;
        }
        sdlWindow = SDL_CreateWindow( "ArkavQuarium", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( sdlWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            gScreenSurface = SDL_GetWindowSurface( sdlWindow );
            success = true;
        }
    }

    return success;
}

void close()
{
    for (auto const& x : loadedSurfaces)
    {
        SDL_FreeSurface( x.second );
    }

    for (auto const& x : loadedFontSizes)
    {
        TTF_CloseFont( x.second );
    }

    SDL_DestroyWindow( sdlWindow );
    sdlWindow = NULL;

    SDL_Quit();
}

SDL_Surface* loadSurface( std::string path )
{
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    return loadedSurface;
}

void draw_image(std::string filename, int x, int y) {
    if (loadedSurfaces.count(filename) < 1) {
        loadedSurfaces[filename] = loadSurface(filename);
    }

    SDL_Surface* s = loadedSurfaces[filename];
    SDL_Rect dest;
    dest.x = x - s->w/2;
    dest.y = y - s->h/2;
    dest.w = s->w;
    dest.h = s->h;
    SDL_BlitSurface(s, NULL, gScreenSurface, &dest);
}

void draw_text(std::string text, int font_size, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    if (loadedFontSizes.count(font_size) < 1) {
        loadedFontSizes[font_size] = TTF_OpenFont(FONT_NAME, font_size);
    }

    TTF_Font* font = loadedFontSizes[font_size];
    SDL_Surface* result = TTF_RenderText_Blended(font, text.c_str(), {r, g, b});
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = result->w;
    dest.h = result->h;
    SDL_BlitSurface(result, NULL, gScreenSurface, &dest);
    SDL_FreeSurface(result);
}

void clear_screen() {
    SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 255, 255, 255));
}

void update_screen() {
    SDL_UpdateWindowSurface(sdlWindow);
}

bool quit = false;
std::set<SDL_Keycode> pressedKeys;
std::set<SDL_Keycode> tappedKeys;

void handle_input(Guppy& guppyIcon, Guppy& eggIcon, Piranha& piranhaIcon) {
    SDL_Event e;
    if (!tappedKeys.empty()) tappedKeys.clear();
    while( SDL_PollEvent( &e ) != 0 )
    {
        if (e.type == SDL_QUIT ) {
            quit = true;
        }
        else if (e.type == SDL_KEYDOWN && !e.key.repeat) {
            pressedKeys.insert(e.key.keysym.sym);
            tappedKeys.insert(e.key.keysym.sym);
        }
        else if (e.type == SDL_KEYUP) {
            pressedKeys.erase(e.key.keysym.sym);
        }
        else if (e.type == SDL_MOUSEBUTTONDOWN){
            if(e.button.button == SDL_BUTTON_RIGHT){
                if(Aquarium::listCoin.isEmpty() == false){
                    Coin dummyCoin;
                    for(int i = 1; i <= Aquarium::listCoin.getSize(); i++){
                        dummyCoin = Aquarium::listCoin.get(i);
                        if(abs(e.button.x - dummyCoin.getX()) <= TAKE_RADIUS && abs(e.button.y - dummyCoin.getY()) <= TAKE_RADIUS){
                            Money += dummyCoin.getValue();
                            Aquarium::delCoin(dummyCoin);
                        }
                    }
                }
            }
        }
        else if(e.type == SDL_MOUSEBUTTONUP){
            if(e.button.button == SDL_BUTTON_LEFT){
                double distX_guppyIcon = abs(guppyIcon.getX() - e.button.x);
                double distY_guppyIcon = abs(guppyIcon.getY() - e.button.y);
                double distX_piranhaIcon = abs(piranhaIcon.getX() - e.button.x);
                double distY_piranhaIcon = abs(piranhaIcon.getY() - e.button.y);
                double distX_eggIcon = abs(eggIcon.getX() - e.button.x);
                double distY_eggIcon = abs(eggIcon.getY() - e.button.y);

                if( distX_guppyIcon <= INPUT_RADIUS && distY_guppyIcon <= INPUT_RADIUS){
                    // int x = rand()%(SCREEN_WIDTH);
                    // int y = rand()%(SCREEN_HEIGHT-BOTTOM_OFFSET);
                    Aquarium::buyGuppy();
                }
                else if( distX_piranhaIcon <= INPUT_RADIUS && distY_piranhaIcon <= INPUT_RADIUS){
                    Aquarium::buyPiranha();
                }
                else if(distX_eggIcon <= INPUT_RADIUS && distY_eggIcon <= INPUT_RADIUS ) {
                    Aquarium::buyEgg();
                }
                else {
                    Aquarium::buyFood(e.button.x, e.button.y);
                }

            }
        }
    }
}

bool quit_pressed() {
    return quit;
}

const std::set<SDL_Keycode>& get_pressed_keys() {
    return pressedKeys;
}

const std::set<SDL_Keycode>& get_tapped_keys() {
    return tappedKeys;
}
