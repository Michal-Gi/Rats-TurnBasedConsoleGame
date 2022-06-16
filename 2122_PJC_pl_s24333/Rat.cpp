//
// Created by micha on 07.06.2022.
//

#include <random>
#include <chrono>
#include <iostream>
#include "Rat.h"

void Rat::attack(Rat &s) {
    auto seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed);
    int roll = rng() % 20;
    double affinityModificator = 1;
    for (auto t: this->adv) {
        if (t == s.type)
            affinityModificator = 2;
    }
    for (auto t: this->dis) {
        if (t == s.type)
            affinityModificator = 0.5;
    }
    std::cout << "the roll was " << roll + this->dex << '\n';
    if (roll + this->dex > 9 + s.dex) {
        std::cout<<this->species<<" makes a ";
        double dmg=0;
        if (roll == 20) {
            std::cout << "critikal ";
            dmg+= this->str * affinityModificator;
        }
        std::cout << "hit!";
        dmg+= this->str * affinityModificator;
        std::cout<<" Dealing "<<dmg<<" points of damage to "<<s.species<<'\n';
        s.hp-=dmg;
        if (affinityModificator == 2)
            std::cout << "It was supper effective!\n";
        if (affinityModificator == 0.5)
            std::cout << "It definitely was not effective!\n";
    } else {
        std::cout << "MISS!\nneeded to hit: " << 10 + s.dex << '\n';
    }
}

double Rat::getHp() const {
    return hp;
}

double Rat::getXpWorth() const {
    return xpWorth;
}

void Rat::evolve() {
    if (xpToEvolve <= 0) {
        this->lvl++;
        this->xpToEvolve = 100 * this->lvl;
        for (int i = 0; i < 2; i++) {
            std::cout << "enter a number of the stat you want to upgrade\n";
            std::cout << "1 - strength\n";
            std::cout << "2 - dexterity\n";
            std::cout << "3 - health\n";
            int x;
            bool fuckup = true;
            std::cout << this->species << "'s stats are now:\nstrength - " << this->str << "\ndexterity - " << this->dex << "\nhealth - "
                      << this->hp << '\n';
            while (fuckup) {
                std::cin >> x;
                switch (x) {
                    case 1 : {
                        this->str += 5;
                        this->maxStr +=5;
                        std::cout << "strength increased by 5\n";
                        fuckup = false;
                        break;
                    }
                    case 2 : {
                        this->dex += 1;
                        this->maxDex+=1;
                        std::cout << "dexterity increased by 1\n";
                        fuckup = false;
                        break;
                    }
                    case 3 : {
                        this->hp += 10;
                        this->maxHp+=10;
                        std::cout << "health increased by 10\n";
                        fuckup = false;
                        break;
                    }
                    default :
                        std::cout << "wrong argument\n";
                        break;
                }
            }
        }
        std::cout << this->species << "'s stats are now:\nstrength - " << this->str << "\ndexterity - " << this->dex << "\nhealth - "
                  << this->hp << '\n';
    }
}

Rat::Rat(int lvl, double hp, double str, double dex, double xpWorth, double xpToEvolve, const std::string &species,
         Rat::Type type, const std::list<Type> &adv, const std::list<Type> &dis) : lvl(lvl), hp(hp), str(str), dex(dex),
                                                                                   xpWorth(xpWorth),
                                                                                   xpToEvolve(xpToEvolve),
                                                                                   species(species), type(type),
                                                                                   adv(adv), dis(dis), cantMove(0), state(NORMAL), maxDex(dex), maxHp(hp), maxStr(str) {}
void Rat::ult(Rat& enemy){
    switch(this->type){
        case AIR:
            std::cout<<"used Air type ultimate attack! the enemy is now unconscious!\n";
            enemy.setCantMove(this->lvl+1);
            enemy.setState(UNCONSCIOUS);
            break;
        case WATER:
            std::cout<<"used Water type ultimate attack! Your rat was healed for "<< this->str+5*(this->lvl+1) <<"!\n";
            this->hp += this->str+5*(this->lvl+1);
            if(hp>maxHp)
                hp=maxHp;
            break;
        case FIRE:
            std::cout<<"used Fire type ultimate attack! The enemy was hit for "<< str*(lvl+1)<<"points of damage!\n";
            enemy.hp-=str*(lvl+1);
            break;
        case EARTH:
            std::cout<<"used Earth type ultimate attack!\n";
            break;
        case STEEL:
            std::cout<<"used Steel type ultimate attack!\n";
            break;
        case ICE:
            std::cout<<"used Ice type ultimate attack!\n";
            break;
    }
}
int Rat::getLvl() const {
    return lvl;
}

double Rat::getStr() const {
    return str;
}

double Rat::getDex() const {
    return dex;
}

double Rat::getUlt() const {
    return sp;
}

double Rat::getXpToEvolve() const {
    return xpToEvolve;
}

const std::string &Rat::getSpecies() const {
    return species;
}

Rat::Type Rat::getType() const {
    return type;
}

const std::list<Rat::Type> &Rat::getAdv() const {
    return adv;
}

const std::list<Rat::Type> &Rat::getDis() const {
    return dis;
}

void Rat::addXp(int const& x) {
    xpToEvolve-=x;
}

void Rat::paralyzeForTurns(int const& x){
    this->cantMove+=x;
}

Rat::State Rat::getState() const {
    return state;
}

void Rat::setState(Rat::State state) {
    Rat::state = state;
}

int Rat::getCantMove() const {
    return cantMove;
}

void Rat::setCantMove(int cantMove) {
    Rat::cantMove = cantMove;
}
