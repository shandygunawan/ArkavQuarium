#include <iostream>
#include <math.h>
#include <sstream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#include "oop.hpp"
#include "GlobalLib.h"
#include "LinkedList.h"
#include "Food.h"
#include "Aquarium.h"

using namespace std;

const double speed = 50; // pixels per second


ULL Money;
int Egg;

void update_movement(double time);
void update_event();
void draw_background(Guppy&, Piranha&, Coin&, ULL, int);
void draw_objects();

int main( int argc, char* args[] )
{
    // Inisialisasi
    Money = 50;
    Egg = 0;
    srand(time(NULL));
    Aquarium Aqua;
    
    Guppy EggIcon(SCREEN_WIDTH-140,50);
    Guppy BuyGuppyIcon(50,35);
    Piranha BuyPiranhaIcon(145,40);
    Coin BuyCoinIcon(0,SCREEN_WIDTH-50,40);
    init();

    // Posisi ikan
    bool running = true;
    double prevtime = time_since_start();
    // Run Game
    while (running) {
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        handle_input(BuyGuppyIcon, EggIcon, BuyPiranhaIcon); 
        if (quit_pressed() || Egg == 3) {
            running = false;
            break;
        }

        // Proses masukan yang bersifat "tombol"
        for (auto key : get_tapped_keys()) {
            switch (key) {
            // E untuk keluar
            case SDLK_e:
                running = false;
                break;
            }
        }

        // Handle berbagai kejadian yang ada di akuarium
        update_movement(sec_since_last);    
        // update_movement(Aqua);
        // Gambar akuarium ke dalam windows
        clear_screen();
        draw_background(BuyGuppyIcon, BuyPiranhaIcon, BuyCoinIcon, Money, Egg);
        draw_objects();
        update_screen();
    }
    close();
    return 0;
}

void update_movement(double time){
    // update food
    Aquarium::moveFood();
    Aquarium::moveCoin();
    Aquarium::moveSnail();
    Aquarium::moveGuppy(time);
    Aquarium::movePiranha(time);
    Aquarium::moveCoin();
}

void draw_background(Guppy& guppyIcon, Piranha& piranhaIcon, Coin& coinIcon, ULL money, int egg){
    
    std::string money_text;
    std::string guppyPrice_text;
    std::string piranhaPrice_text;
    std::string eggPrice_text;
    std::ostringstream str1, str2, str3, str4;
    str1 << money; money_text = str1.str();
    str2 << PRICE_GUPPY; guppyPrice_text = str2.str();
    str3 << PRICE_PIRANHA; piranhaPrice_text = str3.str();
    str4 << PRICE_EGG; eggPrice_text = str4.str();

    clear_screen();

    // print Background
    draw_image("SPRITES/back/1.jpg", SCREEN_WIDTH/2, SCREEN_HEIGHT/2);

    // print buyGuppy
    draw_image("SPRITES/util/slot.png", 50, 50);
    draw_image("SPRITES/guppy/small/left/healthy/1.png", guppyIcon.getX(), guppyIcon.getY());
    draw_text(guppyPrice_text, 18, 42, 71, 255, 255, 255);

    // print buyPiranha
    draw_image("SPRITES/util/slot.png", 140, 50);
    draw_image("SPRITES/carnivore/left/healthy/1.png", piranhaIcon.getX(), piranhaIcon.getY());
    draw_text(piranhaPrice_text, 18, 132, 71, 255, 255, 255);

    // print Coin Amount
    draw_image("SPRITES/util/slot.png", SCREEN_WIDTH-50, 50);
    draw_image("SPRITES/coin/gold/1.png", coinIcon.getX(), coinIcon.getY());
    int money_offset=0;
    if      (money < 10)                      { money_offset = 54; }
    else if (money >= 10 && money < 100)      { money_offset = 58; }
    else if (money >= 100 && money < 1000)    { money_offset = 64; }
    else if (money >= 1000 && money < 10000)  { money_offset = 68; }
    else if (money >= 10000 && money < 100000){ money_offset = 74; }
    draw_text(money_text, 18, SCREEN_WIDTH-money_offset, 71, 255, 255, 255);


    // print Egg
    draw_image("SPRITES/util/slot.png", SCREEN_WIDTH-140, 50);
    draw_text(eggPrice_text, 18, SCREEN_WIDTH-158, 71, 255, 255, 255);
    if(egg == 0){
        draw_text("No egg", 16, SCREEN_WIDTH-165, 25, 255, 255, 255);    
    }
    else if (egg == 1){
        draw_image("SPRITES/util/egg1.png",SCREEN_WIDTH-140,50);
    }
    else if (egg == 2){
        draw_image("SPRITES/util/egg2.png",SCREEN_WIDTH-140,50);
    }



    
}

void draw_objects(){
    
    if(Aquarium::listFood.isEmpty() == false){
        
        Food dummyFood;
        for(int i = 1; i <= Aquarium::listFood.getSize(); i++){
            dummyFood = Aquarium::listFood.get(i);
            double x = dummyFood.getX();
            double y = dummyFood.getY();
            draw_image("SmallFood.png", x, y);
        }
    }

    if(Aquarium::listCoin.isEmpty() == false){
        Coin dummyCoin;
        for(int i = 1; i <= Aquarium::listCoin.getSize(); i++){
            dummyCoin = Aquarium::listCoin.get(i);
            double x = dummyCoin.getX();
            double y = dummyCoin.getY();
            draw_image("SPRITES/coin/gold/1.png",x,y);
        }   
    }

    if(Aquarium::listGuppy.isEmpty() == false){
        Guppy dummyGuppy(0,0);
        for(int i = 1; i <= Aquarium::listGuppy.getSize(); i++){
            dummyGuppy = Aquarium::listGuppy.get(i);
            double x = dummyGuppy.getX();
            double y = dummyGuppy.getY();
            if(dummyGuppy.getTahapPertumbuhan() == 1){
                if(dummyGuppy.getDirection() == true){
                    if(dummyGuppy.getFull() == true){
                        draw_image("SPRITES/guppy/small/right/healthy/1.png",x,y);
                    }
                    else {
                        draw_image("SPRITES/guppy/small/right/sick/1.png",x,y);
                    }
                }
                else {
                    if(dummyGuppy.getFull() == true){
                        draw_image("SPRITES/guppy/small/left/healthy/1.png",x,y);
                    }
                    else {
                        draw_image("SPRITES/guppy/small/left/sick/1.png",x,y);
                    }
                }
                
            }
            else if(dummyGuppy.getTahapPertumbuhan() == 2){
                if(dummyGuppy.getDirection() == true){
                    if(dummyGuppy.getFull() == true){
                        draw_image("SPRITES/guppy/medium/right/healthy/1.png",x,y);
                    }
                    else {
                        draw_image("SPRITES/guppy/medium/right/sick/1.png",x,y);
                    }
                }
                else {
                    if(dummyGuppy.getFull() == true){
                        draw_image("SPRITES/guppy/medium/left/healthy/1.png",x,y);
                    }
                    else {
                        draw_image("SPRITES/guppy/medium/left/sick/1.png",x,y);
                    }
                }
            }
            else if(dummyGuppy.getTahapPertumbuhan() == 3){
                if(dummyGuppy.getDirection() == true){
                    if(dummyGuppy.getFull() == true){
                        draw_image("SPRITES/guppy/large/right/healthy/1.png",x,y);
                    }
                    else {
                        draw_image("SPRITES/guppy/large/right/sick/1.png",x,y);
                    }
                }
                else {
                    if(dummyGuppy.getFull() == true){
                        draw_image("SPRITES/guppy/large/left/healthy/1.png",x,y);
                    }
                    else {
                        draw_image("SPRITES/guppy/large/left/sick/1.png",x,y);
                    }
                }
            }
            
        }   
    }


    if(Aquarium::listPiranha.isEmpty() == false){
        
        Piranha dummyPiranha;
        for(int i = 1; i <= Aquarium::listPiranha.getSize(); i++){
            dummyPiranha = Aquarium::listPiranha.get(i);
            double x = dummyPiranha.getX();
            double y = dummyPiranha.getY();
            if(dummyPiranha.getDirection() == true){
                if(dummyPiranha.getFull() == true){
                    draw_image("SPRITES/carnivore/right/healthy/1.png", x, y);
                }
                else {
                    draw_image("SPRITES/carnivore/right/sick/1.png", x, y);   
                }
            }
            else {
                if(dummyPiranha.getFull() == true){
                    draw_image("SPRITES/carnivore/left/healthy/1.png", x, y);
                }
                else {
                    draw_image("SPRITES/carnivore/left/sick/1.png", x, y);   
                }
            }
        
        }   
    }

    if(Aquarium::listSnail.isEmpty() == false){
        Snail dummySnail;
        for(int i = 1; i <= Aquarium::listSnail.getSize(); i++){
            dummySnail = Aquarium::listSnail.get(i);
            double x = dummySnail.getX();
            double y = dummySnail.getY();
            if(dummySnail.getDirection() == true){
                draw_image("SPRITES/snail2/Snail_Right.png", x, y);
            }
            else{
                draw_image("SPRITES/snail2/Snail_Left.png", x, y);
            }
        }
    }


}

/* SAMPLE */

/*
// Gerakkan ikan selama tombol panah ditekan
        // Kecepatan dikalikan dengan perbedaan waktu supaya kecepatan ikan
        // konstan pada komputer yang berbeda.
        for (auto key : get_pressed_keys()) {
            switch (key) {
            case SDLK_UP:
                cy -= speed * sec_since_last;
                break;
            case SDLK_DOWN:
                cy += speed * sec_since_last;
                break;
            case SDLK_LEFT:
                cx -= speed * sec_since_last;
                break;
            case SDLK_RIGHT:
                cx += speed * sec_since_last;
                break;
            }
        }

*/

/*
draw_text("r untuk reset, x untuk keluar", 18, 10, 10, 0, 0, 0);
draw_text(fps_text, 18, 10, 30, 0, 0, 0);
*/

/*
// Proses masukan yang bersifat "tombol"
        for (auto key : get_tapped_keys()) {
            switch (key) {
            // r untuk reset
            case SDLK_r:
                cy = SCREEN_HEIGHT / 2;
                cx = SCREEN_WIDTH / 2;
                break;
            // x untuk keluar
            case SDLK_x:
                running = false;
                break;
            }
        }
 */
