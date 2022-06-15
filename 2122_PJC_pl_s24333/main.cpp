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

void prepareEnemies(std::vector<std::vector<Rat>> &v){
    auto seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed);
    std::vector<Rat> v1;
    std::vector<Rat> v2;
    std::vector<Rat> v3;
    std::vector<Rat> v4;
    std::vector<Rat> v5;
    switch(rng()%5){
        case 0:
            v1 = {FireRat(1+dificulty), EarthRat(1+dificulty), IceRat(1+dificulty), AirRat(1+dificulty)};
            break;
        case 1:
            v1 = {WaterRat(1+dificulty), SteelRat(1+dificulty), IceRat(1+dificulty), AirRat(1+dificulty)};
            break;
        case 2:
            v1 = {FireRat(1+dificulty), WaterRat(1+dificulty), SteelRat(1+dificulty), EarthRat(1+dificulty)};
            break;
        default:
            v1 = {WaterRat(1+dificulty),  EarthRat(1+dificulty), FireRat(1+dificulty), AirRat(1+dificulty)};
            break;
    }
    v.push_back(v1);
}