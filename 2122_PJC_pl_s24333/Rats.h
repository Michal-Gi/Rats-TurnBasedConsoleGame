//
// Created by Michnik tech tips on 14/06/2022.
//

#ifndef INC_2122_PJC_PL_S24333_RATS_H
#define INC_2122_PJC_PL_S24333_RATS_H


#include "Rat.h"

class AirRat : public Rat {
public:
    AirRat(int level);
};

class WaterRat : public Rat {
public:
    WaterRat(int level);
};

class EarthRat : public Rat {
public:
    EarthRat(int level);
};

class FireRat : public Rat {
public:
    FireRat(int level);
};

class IceRat : public Rat {
public:
    IceRat(int level);
};

class SteelRat : public Rat {
public:
    SteelRat(int level);
};

class SwampRat : public Rat {
public:
    SwampRat(int level);
};

class SewerRat : public Rat {
public:
    SewerRat(int level);
};

class FieldRat : public Rat {
public:
    FieldRat(int level);
};

class ThunderRat : public Rat {
public:
    ThunderRat(int level);
};

class LightningRat : public Rat {
public:
    LightningRat(int level);
};

class GlacialRat : public Rat {
public:
    GlacialRat(int level);
};

class TitaniumRat : public Rat {
public:
    TitaniumRat(int level);
};

class KingRat : public Rat {
public:
    KingRat(int level);
};

class ArceusRat : public Rat {
public:
    ArceusRat(int level);
};


#endif //INC_2122_PJC_PL_S24333_RATS_H
