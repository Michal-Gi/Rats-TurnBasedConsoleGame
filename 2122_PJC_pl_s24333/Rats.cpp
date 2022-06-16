//
// Created by Michnik tech tips on 14/06/2022.
//

#include <iostream>
#include "Rats.h"

AirRat::AirRat(int level) : Rat(level, 10 + level / 2, 5 + level / 2, 5 + level, 10 * level, 100 * level,
                                "Air rat", AIR, {ICE},
                                {EARTH, STEEL}) {}

EarthRat::EarthRat(int level) : Rat(level, 25 + level, 5 + level / 2, 2 + level / 2, 10 * level, 100 * level,
                                    "Earth rat", EARTH, {FIRE, ICE, STEEL},
                                    {AIR}) {}

WaterRat::WaterRat(int level) : Rat(level, 10 + level / 2, 5 + level, 4 + level / 2, 10 * level, 100 * level,
                                    "Water rat", WATER, {EARTH, FIRE},
                                    {WATER}) {}

FireRat::FireRat(int level) : Rat(level, 10 + level / 2, 8 + level, 4 + level / 2, 10 * level, 100 * level,
                                  "Fire rat", FIRE, {WATER, EARTH},
                                  {ICE, STEEL}) {}

IceRat::IceRat(int level) : Rat(level, 10 + level / 2, 8 + level, 4 + level / 2, 10 * level, 100 * level,
                                "Ice rat", ICE, {EARTH},
                                {WATER, FIRE, ICE}) {}

SteelRat::SteelRat(int level) : Rat(level, 10 + level / 2, 8 + level, 4 + level / 2, 10 * level, 100 * level,
                                    "Water rat", STEEL, {WATER, AIR},
                                    {FIRE, STEEL}) {}

SwampRat::SwampRat(int level) : Rat(level, 30 + level / 2, 10 + level, 8 + level / 2, 100 * level, 250 * level,
                                    "Swamp rat", WATER, {EARTH, FIRE},
                                    {WATER}) {}

SewerRat::SewerRat(int level) : Rat(level,  25+ level / 2, 11 + level, 9 + level / 2, 100 * level, 250 * level,
                                    "Sewer rat", WATER, {EARTH, FIRE},
                                    {WATER}) {}

FieldRat::FieldRat(int level) : Rat(level, 40 + level, 7 + level / 2, 4 + level / 2, 100 * level, 250 * level,
                                    "Field rat", EARTH, {FIRE, ICE, STEEL},
                                    {AIR}) {}

ThunderRat::ThunderRat(int level) : Rat(level, 20 + level / 2, 7 + level / 2, 12 + level, 100 * level, 250 * level,
                                        "Thunder rat", AIR, {ICE},
                                        {EARTH, STEEL}) {}

LightningRat::LightningRat(int level) : Rat(level, 25 + level / 2, 15 + level, 7 + level / 2, 100 * level, 250 * level,
                                            "Lightning rat", FIRE, {WATER, EARTH},
                                            {ICE, STEEL}) {}

GlacialRat::GlacialRat(int level) : Rat(level, 30 + level / 2, 10 + level, 6 + level / 2, 100 * level, 250 * level,
                                        "Glacial rat", ICE, {EARTH},
                                        {WATER, FIRE, ICE}) {}

TitaniumRat::TitaniumRat(int level) : Rat(level, 50 + level, 10 + level / 2, 4 + level / 4, 100 * level, 250 * level,
                                          "Titanium rat", STEEL, {WATER, AIR},
                                          {FIRE, STEEL}) {}

KingRat::KingRat(int level) : Rat(level,  100+ level / 2, 20 + level, 4 + level / 2, 1000 * level, 2500 * level,
                                  "the Rat King", WATER, {EARTH, FIRE},
                                  {WATER}) {}

ArceusRat::ArceusRat(int level) : Rat(level,  250+ level / 2, 100 + level, 15 + level / 2, 10000 * level, 25000 * level,
                                      "Arceus the rat god", WATER, {EARTH, FIRE},
                                      {WATER}) {}