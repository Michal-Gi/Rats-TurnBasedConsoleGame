//

#include <random>
#include <chrono>
#include <iostream>
#include <regex>
#include "Rat.h"

//
// Created by micha on 07.06.2022.
bool isInteger(std::string const &s) {
    std::regex integer_expr("[0-9]+");
    return std::regex_match(s, integer_expr);
}

int convertToInt(std::string const &s) {
    int x = 0;
    for (char i: s) {
        x *= 10;
        x += i - '0';
    }
    return x;
}

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
            std::cout << "critical ";
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
            std::string s;
            bool fuckup = true;
            std::cout << this->species << "'s stats are now:\nstrength - " << this->str << "\ndexterity - " << this->dex << "\nhealth - "
                      << this->hp << '\n';
            while (fuckup) {
                std::cin>>s;
                (isInteger(s))?x=convertToInt(s):x=0;
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
                                                                                   adv(adv), dis(dis), cantMove(0), state(NORMAL), maxDex(dex), maxHp(hp), maxStr(str), sp(0) {}
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
            this->hp = std::min(maxHp, hp);
            break;
        case FIRE:
            std::cout<<"used Fire type ultimate attack! The enemy was hit for "<< str*(lvl+1)<<"points of damage!\n";
            enemy.hp-=str*(lvl+1);
            enemy.setState(BURNING);
            break;
        case EARTH:
            std::cout<<"used Earth type ultimate attack! Health increased till the end of the fight\n";
            hp+=10*(lvl+1);
            break;
        case STEEL:
            std::cout<<"used Steel type ultimate attack!All stats are up till the end of the fight!\n";
            dex+=1*(lvl+1);
            str+=5*(lvl+1);
            break;
        case ICE:
            std::cout<<"used blizzard! Enemy can't move for "<<lvl/2+1<<" turns and your rat is healed for "<< this->str/2+5*(this->lvl/2+1) <<"hp\n";
            this->hp = std::min(this->hp+this->str/2+5*(this->lvl/2+1), maxHp);
            enemy.setState(UNCONSCIOUS);
            enemy.setCantMove(lvl/2+1);
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

void Rat::heal(){
    this->str=this->maxStr;
    this->hp=this->maxHp;
    this->dex=this->maxDex;
}

void Rat::setHp(double hp) {
    Rat::hp = hp;
}

void Rat::setLvl(int lvl) {
    Rat::lvl = lvl;
}

void Rat::setStr(double str) {
    Rat::str = str;
}

void Rat::setDex(double dex) {
    Rat::dex = dex;
}

double Rat::getSp() const {
    return sp;
}

void Rat::setSp(double sp) {
    Rat::sp = sp;
}

void Rat::setXpWorth(double xpWorth) {
    Rat::xpWorth = xpWorth;
}

void Rat::setXpToEvolve(double xpToEvolve) {
    Rat::xpToEvolve = xpToEvolve;
}

double Rat::getMaxHp() const {
    return maxHp;
}

void Rat::setMaxHp(double maxHp) {
    Rat::maxHp = maxHp;
}

double Rat::getMaxStr() const {
    return maxStr;
}

void Rat::setMaxStr(double maxStr) {
    Rat::maxStr = maxStr;
}

double Rat::getMaxDex() const {
    return maxDex;
}

void Rat::setMaxDex(double maxDex) {
    Rat::maxDex = maxDex;
}

void Rat::setSpecies(const std::string &species) {
    Rat::species = species;
}

void Rat::setType(Rat::Type type) {
    Rat::type = type;
}

void Rat::setAdv(const std::list<Type> &adv) {
    Rat::adv = adv;
}

void Rat::setDis(const std::list<Type> &dis) {
    Rat::dis = dis;
}

Rat::Rat(int lvl, int cantMove, double hp, double str, double dex, double sp, double xpWorth, double xpToEvolve,
         double maxHp, double maxStr, double maxDex, const std::string &species, Rat::Type type, Rat::State state,
         const std::list<Type> &adv, const std::list<Type> &dis) : lvl(lvl), cantMove(cantMove), hp(hp), str(str),
                                                                   dex(dex), sp(sp), xpWorth(xpWorth),
                                                                   xpToEvolve(xpToEvolve), maxHp(maxHp), maxStr(maxStr),
                                                                   maxDex(maxDex), species(species), type(type),
                                                                   state(state), adv(adv), dis(dis) {}
