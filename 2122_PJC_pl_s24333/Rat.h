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
    enum Type {WATER, FIRE, EARTH, AIR, STEEL, ICE};
    enum State {PARALYZED, CHARMED, NAUSENED, UNCONSCIOUS, NORMAL};
protected:
    int lvl, cantMove;
    double hp, str, dex, sp, xpWorth, xpToEvolve, maxHp, maxStr, maxDex;
    std::string species;
    Type type;
    State state;
    std::list<Type> adv;
    std::list<Type> dis;
public:
    /**
     * basic attack script that includes elemental affinities
     * @param s
     */
    void attack(Rat & s);
    /**
     * script responsible for evolving player's rats
     */
    void evolve();

    Rat(int lvl, double hp, double str, double dex, double xpWorth, double xpToEvolve, const std::string &species,
        Type type, const std::list<Type> &adv, const std::list<Type> &dis);

    void ult(Rat &enemy);

    double getHp() const;

    double getXpWorth() const;

    int getLvl() const;

    double getStr() const;

    double getDex() const;

    double getUlt() const;

    double getXpToEvolve() const;

    const std::string &getSpecies() const;

    Type getType() const;

    const std::list<Type> &getAdv() const;

    const std::list<Type> &getDis() const;
    void addXp(int const& x);

    void paralyzeForTurns(int const& x);

    State getState() const;

    void setState(State state);

    int getCantMove() const;

    void setCantMove(int cantMove);
};


#endif //INC_2122_PJC_PL_S24333_RAT_H
