//
// Created by micha on 07.06.2022.
//

#ifndef INC_2122_PJC_PL_S24333_RAT_H
#define INC_2122_PJC_PL_S24333_RAT_H

#include <list>
#include <string>

/**
 * klasa abstrakcyjna będąca tameplatem każdego potwora
 */
class Rat {
public:
    enum Type {WATER, FIRE, EARTH, AIR, STEEL, ICE};
protected:
    int lvl;
    double hp, str, dex, sp, xpWorth, xpToEvolve;
    std::string species;
    Type type;
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

    void ult();

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
};


#endif //INC_2122_PJC_PL_S24333_RAT_H
