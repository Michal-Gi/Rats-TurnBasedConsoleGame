#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "Rats.h"
/*
 * to do:
 * prepare player and enemy
 * make fighting loops
 * implement ultimates
 * implement leveling up
 * implement winning the game
 * save and exit/load system
 * difficulty levels
 */
void pomoc();
void preparePlayer(std::vector<Rat> &v);
void prepareEnemies(std::vector<std::vector<Rat>> &v);
int dificulty;

int main() {
    std::string s;
    std::cout<<"please enter the dificulty level you want to experience:\n0 - easy\n1 - normal\n2 - tough\n 3 - hell\n4 - just don't\n";
    std::cin>>dificulty;
    std::vector<Rat> player;
    std::vector<std::vector<Rat>> enemies;
    //preparePlayer(player);
    prepareEnemies(enemies);
    while(std::cin >> s){
        if(s == "--fight" || s == "-f"){
            for(auto v : enemies){
                for(auto r : v){
                    std::cout<<r.getSpecies()<<" lvl: "<<r.getLvl()<<'\n';
                }
            }
            continue;
        }
        if(s == "-h" || s == "--help"){
            pomoc();
            continue;
        }
        if(s == "--exit" || s == "-e")
            return 0;
        std::cout << "nieznane polecenie\n";
    }
    return 0;
}

void pomoc(){
    std::cout << "pomagam\n";
}

void prepaprePlayer(std::vector<Rat> &v){}

/**
 * prepares all enemies that the player will encounter in the game
 * @param v an empty vector composed of vectors that will hold enemy rats. every nested vector is a single encounter
 */
void prepareEnemies(std::vector<std::vector<Rat>> &v){
    auto seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed);
    for(int i = 0; i<5; i++){
        std::vector<Rat> v1={};
        for(int j = 0; j<4; j++){
            if(i<5){
                switch(rng()%100){
                    case 0 ... 9:
                        v1.push_back(WaterRat(i+dificulty));
                        break;
                    case 10 ... 19:
                        v1.push_back(EarthRat(i+dificulty));
                        break;
                    case 20 ... 29:
                        v1.push_back(FireRat(i+dificulty));
                        break;
                    case 30 ... 39:
                        v1.push_back(AirRat(i+dificulty));
                        break;
                    case 40 ... 49:
                        v1.push_back(IceRat(i+dificulty));
                        break;
                    case 50 ... 59:
                        v1.push_back(SteelRat(i+dificulty));
                        break;
                    case 60 ... 65:
                        v1.push_back(SwampRat(i+dificulty));
                        break;
                    case 66 ... 71:
                        v1.push_back(SewerRat(i+dificulty));
                        break;
                    case 72 ... 77:
                        v1.push_back(FieldRat(i+dificulty));
                        break;
                    case 78 ... 83:
                        v1.push_back(ThunderRat(i+dificulty));
                        break;
                    case 84 ... 89:
                        v1.push_back(LightningRat(i+dificulty));
                        break;
                    case 90 ... 94:
                        v1.push_back(GlacialRat(i+dificulty));
                        break;
                    case 95 ... 97:
                        v1.push_back(TitaniumRat(i+dificulty));
                        break;
                    case 98 ... 99:
                        v1.push_back(KingRat(i+dificulty));
                        break;
                    default :
                        v1.push_back(ArceusRat(1));
                        break;
                }
            }
            else{
                if(rng()%100==99)
                    v.push_back({WaterRat(1+dificulty),  EarthRat(1+dificulty), FireRat(1+dificulty), AirRat(1+dificulty), ArceusRat(1)});
            }
        }
        v.push_back(v1);
    }
}