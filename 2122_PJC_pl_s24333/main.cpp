#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <regex>
#include "Rats.h"

/*
 * to do:
 * save and exit/load system
 */
void help();

void preparePlayer(std::vector<Rat> &v);

void prepareEnemies(std::vector<std::vector<Rat>> &v);

void fight(std::vector<Rat> &player, Rat &enemy, std::vector<std::vector<Rat>> &enemies, bool &won);

bool isInteger(std::string const &s);

int convertToInt(std::string const &s);

int difficulty, currentEnemyBatch, currentEnemyRat, chosenRat;

void changeRat(std::vector<Rat> const& player);

bool didPlayerLoose(std::vector<Rat> const& player);

int main() {
    bool didPlayerWin = false;
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
            fight(player, enemies.at(currentEnemyBatch).at(currentEnemyRat), enemies, didPlayerWin);
            if(didPlayerLoose(player))
                return 0;
            if(didPlayerWin)
                return 0;
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
        std::cout << "unknown command, for help enter -h or --help\n";
    }
    return 0;
}

void help() {
    std::cout << "I'm helping\n";
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
    } while (!isCharacterDone);
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

void fight(std::vector<Rat> &player, Rat &enemy, std::vector<std::vector<Rat>> &enemies, bool &won) {
    auto seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed);
    std::string input;
    bool isPlayerAlive = true, isEnemyAlive = true;
    bool fuckup = true;
    while (isPlayerAlive && isEnemyAlive) {
        do {
            std::cout
                    << "your turn! what do you want to do?\n1 - attack\n2 - use ultimate attack\n3 - change your rat for another one in your possession\n4 - evolve your rat\n";
            std::cin >> input;
            if (isInteger(input)) {
                int x = convertToInt(input);
                switch (x) {
                    case 1:
                        player.at(chosenRat).attack(enemy);
                        if (enemy.getHp() <= 0) {
                            isEnemyAlive = false;
                            player.at(chosenRat).addXp(enemy.getXpWorth());
                            if (currentEnemyRat == enemies.at(currentEnemyBatch).size() - 1) {
                                if (currentEnemyBatch == enemies.size() - 1) {
                                    std::cout << "you won! you are the best rat trainer in all of the land!\n";
                                    won = true;
                                } else {
                                    currentEnemyBatch++;
                                    std::cout << "You've beaten the enemy rat! It was the last one on this level!\n";
                                }
                            } else {
                                currentEnemyRat++;
                                std::cout << "You've beaten the enemy rat!\n";
                            }
                        }
                        fuckup = false;
                        break;
                    case 2:
                        if(player.at(chosenRat).getSp()>=100){
                            player.at(chosenRat).ult(enemy);
                            fuckup = false;
                        }else
                            std::cout<<"to use ultimate attack you need 100 sp, currently your "<<player.at(chosenRat).getSpecies()<<" has only "<<player.at(chosenRat).getSp()<<" sp\n";
                        break;
                    case 3:{
                        changeRat(player);
                        fuckup = false;
                        break;
                    }
                    case 4:
                        if(player.at(chosenRat).getXpToEvolve()<=0){
                            player.at(chosenRat).evolve();
                            fuckup=false;
                        }else{
                            std::cout<<player.at(chosenRat).getSpecies()<<" requires "<< player.at(chosenRat).getXpToEvolve()<<" xp to evolve";
                        }
                        break;
                    default :
                        std::cout << "wrong argument\n";
                        break;
                }
            } else
                std::cout << "Wrong type of argument!\n";
        } while (fuckup);
        player.at(chosenRat).setSp(player.at(chosenRat).getSp()+20);
        if(isEnemyAlive){
            if(enemy.getState()==Rat::NORMAL)
            {
                std::cout<<"enemy turn! Hostile "<<enemy.getSpecies()<<" attacks!\n";
                enemy.attack(player.at(chosenRat));
                if(player.at(chosenRat).getHp()<=0){
                    isPlayerAlive=false;
                }
            }
            else{
                if(enemy.getState()==Rat::BURNING){
                    int x = rng()%10;
                    if(enemy.getType()==Rat::FIRE){
                        std::cout<<" burning fire type rats heals them!\n"<<enemy.getState()<<" is healed for "<<x<<" hp!\n";
                        enemy.setHp(std::min(enemy.getMaxHp(), enemy.getHp()+x));
                    }
                    else{
                        std::cout<< "enemy "<<enemy.getSpecies()<<" is "<<enemy.getState()<<" it can't attack for "<<enemy.getCantMove()-1<<" more turns and receives "<< x <<"\n";
                        enemy.setCantMove(enemy.getCantMove()-1);
                        enemy.setHp(enemy.getHp()-x);
                        if(enemy.getHp()<=0)
                            isEnemyAlive=false;
                    }
                }
                else{
                    std::cout<< "enemy "<<enemy.getSpecies()<<" is "<<enemy.getState()<<" and can't attack for "<<enemy.getCantMove()-1<<" more turns\n";
                    enemy.setCantMove(enemy.getCantMove()-1);
                }
            }
        }
        if(!isPlayerAlive){
            if(didPlayerLoose(player))
                std::cout<<"you lost the game\n";
            else
                isPlayerAlive=true;
        }

    }
}
void changeRat(std::vector<Rat> const& player){
    bool done = false;
    while(!done){
        std::string input;
        std::cout<<"enter the number corresponding with the rat you want to chose\n";
        for(int i =0; i<player.size(); i++)
            std::cout<<i << " - "<<player.at(i).getSpecies()<< " lvl "<< player.at(i).getLvl()<<((player.at(i).getHp()<0)?(" unconscious"):(" alive"))<<'\n';
        std::cin>>input;
        if(isInteger(input)){
            int y = convertToInt(input);
            if(y>=0 && y<6){
                if(player.at(y).getHp()>0){
                    chosenRat = y;
                    std::cout<<"selected rat is "<<player.at(chosenRat).getSpecies()<< " lvl "<< player.at(chosenRat).getLvl()<<'\n';
                    done = true;
                }
                else
                    std::cout<<"chosen Rat is inaccessible\n";
            }
            else
                std::cout<<"wrong number\n";
        }
        else
            std::cout<<"wrong type of argument\n";
    }
}
bool didPlayerLoose(std::vector<Rat> const& player){
    if(player.at(chosenRat).getHp()>0)
        return false;
    for(Rat r : player){
        if(r.getHp()>0){
            changeRat(player);
            return false;
        }
    }
    return true;
}