//
// Created by Michnik tech tips on 14/06/2022.
//
#include "Rats.h"

AirRat::AirRat(int level) : Rat(level, 100 + 50 * level, 20 + 10 * level, 5 + level, 10 * level, 20 * level,
                                "Air rat", AIR, {ICE},
                                {EARTH, STEEL}) {}

EarthRat::EarthRat(int level) : Rat(level, 150 + 100 * level, 20 + 10 * level, 4 + 0.5 * level, 10 * level, 20 * level,
                                    "Earth rat", EARTH, {FIRE, ICE, STEEL},
                                    {AIR}) {}

WaterRat::WaterRat(int level) : Rat(level, 100 + 50 * level, 20 + 20 * level, 5 + 0.5 * level, 10 * level, 20 * level,
                                    "Water rat", WATER, {EARTH, FIRE},
                                    {WATER}) {}

FireRat::FireRat(int level) : Rat(level, 100 + 50 * level, 20 + 25 * level, 4 + 0.5 * level, 10 * level, 20 * level,
                                  "Fire rat", FIRE, {WATER, EARTH},
                                  {ICE, STEEL}) {}

IceRat::IceRat(int level) : Rat(level, 100 + 50 * level, 20 + 20 * level, 5 + 0.5 * level, 10 * level, 20 * level,
                                "Ice rat", ICE, {EARTH},
                                {WATER, FIRE, ICE}) {}

SteelRat::SteelRat(int level) : Rat(level, 150 + 100 * level, 15 + 15 * level, 4 + 0.5 * level, 10 * level, 20 * level,
                                    "Water rat", STEEL, {WATER, AIR},
                                    {FIRE, STEEL}) {}

SwampRat::SwampRat(int level) : Rat(level, 100 + 50 * level, 20 + 20 * level, 5 + level, 15 * level, 20 * level,
                                    "Swamp rat", WATER, {EARTH, FIRE},
                                    {WATER}) {}

SewerRat::SewerRat(int level) : Rat(level, 150 + 50 * level, 25 + 20 * level, 6 + level, 15 * level, 20 * level,
                                    "Sewer rat", WATER, {EARTH, FIRE},
                                    {WATER}) {}

FieldRat::FieldRat(int level) : Rat(level, 150 + 75 * level, 20 + 20 * level, 4 + level, 15 * level, 20 * level,
                                    "Field rat", EARTH, {FIRE, ICE, STEEL},
                                    {AIR}) {}

ThunderRat::ThunderRat(int level) : Rat(level, 100 + 50 * level, 25 + 20 * level, 7 + level, 15 * level, 20 * level,
                                        "Thunder rat", AIR, {ICE},
                                        {EARTH, STEEL}) {}

LightningRat::LightningRat(int level) : Rat(level, 150 + 50 * level, 30 + 25 * level, 5 + level, 15 * level, 20 * level,
                                            "Lightning rat", FIRE, {WATER, EARTH},
                                            {ICE, STEEL}) {}

GlacialRat::GlacialRat(int level) : Rat(level, 150 + 75 * level, 20 + 20 * level, 6 + level, 15 * level, 20 * level,
                                        "Glacial rat", ICE, {EARTH},
                                        {WATER, FIRE, ICE}) {}

TitaniumRat::TitaniumRat(int level) : Rat(level, 250 + 150 * level, 15 + 15 * level, 3 + level, 15 * level, 20 * level,
                                          "Titanium rat", STEEL, {WATER, AIR},
                                          {FIRE, STEEL}) {}

KingRat::KingRat(int level) : Rat(level, 200 + 100 * level, 20 + 20 * level, 6 + level, 20 * level, 30 * level,
                                  "the Rat King", WATER, {EARTH, FIRE},
                                  {WATER}) {}

ArceusRat::ArceusRat(int level) : Rat(level, 300 + 100 * level, 40 + 30 * level, 8 + level, 50 * level, 40 * level,
                                      "Arceus the rat god", WATER, {EARTH, FIRE},
                                      {WATER}) {}