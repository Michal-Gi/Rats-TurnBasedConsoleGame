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
    enum State {UNCONSCIOUS, NORMAL, BURNING};
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

    void heal();

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

    void setHp(double hp);

    void setLvl(int lvl);

    void setStr(double str);

    void setDex(double dex);

    double getSp() const;

    void setSp(double sp);

    void setXpWorth(double xpWorth);

    void setXpToEvolve(double xpToEvolve);

    double getMaxHp() const;

    void setMaxHp(double maxHp);

    double getMaxStr() const;

    void setMaxStr(double maxStr);

    double getMaxDex() const;

    void setMaxDex(double maxDex);

    void setSpecies(const std::string &species);

    void setType(Type type);

    void setAdv(const std::list<Type> &adv);

    void setDis(const std::list<Type> &dis);
};


#endif //INC_2122_PJC_PL_S24333_RAT_H
