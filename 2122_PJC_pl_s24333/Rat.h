//
// Created by micha on 07.06.2022.
//

#ifndef INC_2122_PJC_PL_S24333_RAT_H
#define INC_2122_PJC_PL_S24333_RAT_H

#include <list>
#include <string>

/**
 * A class that is the template for every rat in the game
 * rats are creatures used in battles
 */
class Rat {
public:
    enum Type {
        WATER, FIRE, EARTH, AIR, STEEL, ICE
    };
    enum State {
        UNCONSCIOUS, NORMAL, BURNING
    };
protected:
    int lvl, cantMove;
    double hp, str, dex, sp, xpWorth, xpToEvolve, maxHp, maxStr, maxDex;
    State state;
    Type type;
    std::list<Type> adv;
    std::list<Type> dis;
    std::string species;
public:
    /**
     * basic attack script that includes elemental affinities
     * @param s rat that player wants to attack
     */
    void attack(Rat &s);

    /**
     * script responsible for evolving player's rats
     */
    void evolve();

    /**
     * function used to fully heal a rat and remove all negative statuses
     */
    void heal();


    Rat(int lvl, double hp, double str, double dex, double xpWorth, double xpToEvolve, std::string species,
        Type type, std::list<Type> adv, std::list<Type> dis);

    Rat(int lvl, int cantMove, double hp, double str, double dex, double sp, double xpWorth, double xpToEvolve,
        double maxHp, double maxStr, double maxDex, State state, Type type, std::list<Type> adv,
        std::list<Type> dis, std::string species);

    void ult(Rat &enemy);

    double getHp() const;

    double getXpWorth() const;

    int getLvl() const;

    double getStr() const;

    double getDex() const;

    double getXpToEvolve() const;

    const std::string &getSpecies() const;

    Type getType() const;

    const std::list<Type> &getAdv() const;

    const std::list<Type> &getDis() const;

    void addXp(int const &x);

    State getState() const;

    void setState(State state);

    int getCantMove() const;

    void setCantMove(int cantMove);

    void setHp(double hp);

    double getSp() const;

    void setSp(double sp);

    double getMaxHp() const;

    double getMaxStr() const;

    double getMaxDex() const;
};


#endif //INC_2122_PJC_PL_S24333_RAT_H
