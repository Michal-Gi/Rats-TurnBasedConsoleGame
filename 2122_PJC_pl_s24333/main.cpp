#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <regex>
#include "Rats.h"

/*
 * to do:
 * make fighting loops
 * implement ultimates
 * implement leveling up
 * implement winning the game
 * save and exit/load system
 */
void help();

void preparePlayer(std::vector<Rat> &v);

void prepareEnemies(std::vector<std::vector<Rat>> &v);

void fight(std::vector<Rat> &player, Rat &enemy, std::vector<std::vector<Rat>> &enemies);

bool isInteger(std::string const &s);

int convertToInt(std::string const &s);

int difficulty, currentEnemyBatch, currentEnemyRat, chosenRat;

int main() {
    std::cout << "RATS\n";
    std::string s;
    do {
        std::cout
                << "please enter the difficulty level you want to experience:\n0 - easy\n1 - normal\n2 - tough\n3 - hell\n4 - just don't\n";
        std::cin >> s;
    } while (!isInteger(s));
    difficulty = convertToInt(s);
    std::vector<Rat> player;
    std::vector<std::vector<Rat>> enemies;
    preparePlayer(player);
    prepareEnemies(enemies);
    while (std::cin >> s) {
        if (s == "--fight" || s == "-f") {
            fight(player, enemies.at(currentEnemyBatch).at(currentEnemyRat), enemies);
            continue;
        }
        if (s == "-h" || s == "--help") {
            help();
            continue;
        }
        if (s == "--exit" || s == "-e") {
            std::cout << "Are you sure you want to exit?\n press y for yes or n for no\n";
            std::cin >> s;
            if (s == "y")
                return 0;
            continue;
        }
        std::cout << "nieznane polecenie\n";
    }
    return 0;
}

void help() {
    std::cout << "pomagam\n";
}

/**
 * prepares player's deck of rats
 * @param v empty vector that will be filled with player's rats
 */
void preparePlayer(std::vector<Rat> &v) {
    bool isCharacterDone = false;
    do {
        chosenRat = 0;
        int x;
        std::string input;
        v = {};
        std::vector<Rat> rats = {WaterRat(1), EarthRat(1), FireRat(1), AirRat(1), IceRat(1), SteelRat(1), SwampRat(1),
                                 SewerRat(1), FieldRat(1), ThunderRat(1), GlacialRat(1), LightningRat(1),
                                 TitaniumRat(1),
                                 KingRat(1), ArceusRat(1)};
        for (int i = 1; i < 16; i++) {
            std::cout << i << " - " << rats[i - 1].getSpecies() << '\n';
        }
        while (v.size() < 6) {
            std::cout << "Please enter a number corresponding with the rat you want to add to your deck\n";
            std::cin >> input;
            if (isInteger(input)) {
                x = convertToInt(input);
                if (x > 0 && x < 16) {
                    std::cout << "given argument - " << x << '\n';
                    v.push_back(rats[x - 1]);
                } else
                    std::cout << "Wrong Argument.\ngiven argument - " << x << '\n';
            } else {
                std::cout << "wrong type of argument\n";
            }
        }
        std::cout << "Your deck is composed of:\n";
        for (Rat const &r: v)
            std::cout << r.getSpecies() << '\n';
        std::cout << "Do you want to continue?\ny - yes\nn - no\n";

        std::cin >> input;
        if (input == "y")
            isCharacterDone = true;
    }while(!isCharacterDone);
}

/**
 * prepares all enemies that the player will encounter in the game
 * @param v an empty vector composed of vectors that will hold enemy rats. every nested vector is a single encounter
 */
void prepareEnemies(std::vector<std::vector<Rat>> &v) {
    currentEnemyBatch = 0;
    currentEnemyRat = 0;
    auto seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed);
    for (int i = 0; i < 5; i++) {
        std::vector<Rat> v1 = {};
        for (int j = 0; j < 4; j++) {
            if (i < 5) {
                switch (rng() % 100) {
                    case 0 ... 9:
                        v1.push_back(WaterRat(i + difficulty));
                        break;
                    case 10 ... 19:
                        v1.push_back(EarthRat(i + difficulty));
                        break;
                    case 20 ... 29:
                        v1.push_back(FireRat(i + difficulty));
                        break;
                    case 30 ... 39:
                        v1.push_back(AirRat(i + difficulty));
                        break;
                    case 40 ... 49:
                        v1.push_back(IceRat(i + difficulty));
                        break;
                    case 50 ... 59:
                        v1.push_back(SteelRat(i + difficulty));
                        break;
                    case 60 ... 65:
                        v1.push_back(SwampRat(i + difficulty));
                        break;
                    case 66 ... 71:
                        v1.push_back(SewerRat(i + difficulty));
                        break;
                    case 72 ... 77:
                        v1.push_back(FieldRat(i + difficulty));
                        break;
                    case 78 ... 82:
                        v1.push_back(ThunderRat(i + difficulty));
                        break;
                    case 83 ... 87:
                        v1.push_back(LightningRat(i + difficulty));
                        break;
                    case 88 ... 92:
                        v1.push_back(GlacialRat(i + difficulty));
                        break;
                    case 93 ... 96:
                        v1.push_back(TitaniumRat(i + difficulty));
                        break;
                    case 97 ... 98:
                        v1.push_back(KingRat(i + difficulty));
                        break;
                    default :
                        v1.push_back(ArceusRat(1));
                        break;
                }
            } else {
                if (rng() % 100 == 99)
                    v.push_back({WaterRat(1 + difficulty), EarthRat(1 + difficulty), FireRat(1 + difficulty),
                                 AirRat(1 + difficulty), ArceusRat(1)});
            }
        }
        v.push_back(v1);
    }
}

void fight(std::vector<Rat> &player, Rat &enemy, std::vector<std::vector<Rat>> &enemies) {
    std::string input;
    bool isPlayerAlive = true, isEnemyAlive = true;
    while (isPlayerAlive && isEnemyAlive) {
        std::cout
                << "your turn! what do you want to do?\n1 - attack\n2 - use ultimate attack\n3 - change your rat for another one in your possession\n4 - evolve your rat\n";
        std::cin >> input;
        if(isInteger(input)){
            int x = convertToInt(input);
            bool fuckup = true;
            do{
            switch(x){
                case 1:
                    player.at(chosenRat).attack(enemy);
                    if(enemy.getHp()<=0){
                        isEnemyAlive=false;
                        if(currentEnemyRat == enemies.at(currentEnemyBatch).size()-1){
                            if(currentEnemyBatch == enemies.size()-1){
                                std::cout<<"you won! you are the best rat trainer in all of the land!\n";
                            }else{
                                currentEnemyBatch++;
                                std::cout<<"You've beaten the enemy rat! It was the last one on this level!\n";
                            }
                        }else{
                            currentEnemyRat++;
                            std::cout<<"You've beaten the enemy rat!";
                        }
                    }
                    fuckup = false;
                    break;
                case 2:
                    std::cout<<"used ultimate";
                    fuckup = false;
                    break;
                case 3:
                    std::cout<<"changed rat";
                    fuckup = false;
                    break;
                case 4:
                    std::cout<<"evolve";
                    fuckup = false;
                    break;
                default :
                    std::cout<<"wrong argument";
                    break;
            }}while(fuckup);
        }else
            std::cout<<"Wrong type of argument!\n";
    }
}

bool isInteger(std::string const &s) {
    std::regex integer_expr("[0-9]+");
    return std::regex_match(s, integer_expr);
}

int convertToInt(std::string const &s) {
    int x = 0;
    for (char i : s) {
        x *= 10;
        x += i - '0';
    }
    return x;
}