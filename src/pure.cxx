#include <cmath>

#include "logic.hxx"

int logic::pure::stat(control::type::Stat stat, int level, int base, int iv,
                      int ev, control::type::Nature nature) {
    using namespace control::type;
    switch (stat) {
        case HP: {
            return floor((((2.0 * base) + iv + floor(ev / 4.0)) * level) /
                         100.0) +
                   level + 10;
        } break;
        case ATK:
        case DEF:
        case SPATK:
        case SPDEF:
        case SPEED: {
            double nature_mod;
            switch (logic::pure::affinity(nature, stat)) {
                case WEAK: {
                    nature_mod = 0.9;
                } break;
                case NEUTRAL: {
                    nature_mod = 1.0;
                } break;
                case STRONG: {
                    nature_mod = 1.1;
                } break;
            }
            return floor(
                (floor((((2.0 * base) + iv + floor(ev / 4.0)) * level) /
                       100.0) +
                 5) *
                nature_mod);
        } break;
    }
}
control::type::NatureModifier logic::pure::affinity(
    control::type::Nature nature, control::type::Stat stat) {
    using namespace control::type;
    switch (nature) {
        case HARDY:
        case DOCILE:
        case SERIOUS:
        case BASHFUL:
        case QUIRKY: {
            return NEUTRAL;
        } break;
        case LONELY: {
            switch (stat) {
                case HP: {
                    return NEUTRAL;
                } break;
                case ATK: {
                    return STRONG;
                } break;
                case DEF: {
                    return WEAK;
                } break;
                case SPATK: {
                    return NEUTRAL;
                } break;
                case SPDEF: {
                    return NEUTRAL;
                } break;
                case SPEED: {
                    return NEUTRAL;
                } break;
            }
        } break;
        case BRAVE: {
            switch (stat) {
                case HP: {
                    return NEUTRAL;
                } break;
                case ATK: {
                    return STRONG;
                } break;
                case DEF: {
                    return NEUTRAL;
                } break;
                case SPATK: {
                    return NEUTRAL;
                } break;
                case SPDEF: {
                    return NEUTRAL;
                } break;
                case SPEED: {
                    return WEAK;
                } break;
            }
        } break;
        case ADAMANT: {
            switch (stat) {
                case HP: {
                    return NEUTRAL;
                } break;
                case ATK: {
                    return STRONG;
                } break;
                case DEF: {
                    return NEUTRAL;
                } break;
                case SPATK: {
                    return WEAK;
                } break;
                case SPDEF: {
                    return NEUTRAL;
                } break;
                case SPEED: {
                    return NEUTRAL;
                } break;
            }
        } break;
        case NAUGHTY: {
            switch (stat) {
                case HP: {
                    return NEUTRAL;
                } break;
                case ATK: {
                    return STRONG;
                } break;
                case DEF: {
                    return NEUTRAL;
                } break;
                case SPATK: {
                    return NEUTRAL;
                } break;
                case SPDEF: {
                    return WEAK;
                } break;
                case SPEED: {
                    return NEUTRAL;
                } break;
            }
        } break;
        case BOLD: {
            switch (stat) {
                case HP: {
                    return NEUTRAL;
                } break;
                case ATK: {
                    return WEAK;
                } break;
                case DEF: {
                    return STRONG;
                } break;
                case SPATK: {
                    return NEUTRAL;
                } break;
                case SPDEF: {
                    return NEUTRAL;
                } break;
                case SPEED: {
                    return NEUTRAL;
                } break;
            }
        } break;
        case RELAXED: {
            switch (stat) {
                case HP: {
                    return NEUTRAL;
                } break;
                case ATK: {
                    return NEUTRAL;
                } break;
                case DEF: {
                    return STRONG;
                } break;
                case SPATK: {
                    return NEUTRAL;
                } break;
                case SPDEF: {
                    return NEUTRAL;
                } break;
                case SPEED: {
                    return WEAK;
                } break;
            }
        } break;
        case IMPISH: {
            switch (stat) {
                case HP: {
                    return NEUTRAL;
                } break;
                case ATK: {
                    return NEUTRAL;
                } break;
                case DEF: {
                    return STRONG;
                } break;
                case SPATK: {
                    return WEAK;
                } break;
                case SPDEF: {
                    return NEUTRAL;
                } break;
                case SPEED: {
                    return NEUTRAL;
                } break;
            }
        } break;
        case LAX: {
            switch (stat) {
                case HP: {
                    return NEUTRAL;
                } break;
                case ATK: {
                    return NEUTRAL;
                } break;
                case DEF: {
                    return STRONG;
                } break;
                case SPATK: {
                    return NEUTRAL;
                } break;
                case SPDEF: {
                    return WEAK;
                } break;
                case SPEED: {
                    return NEUTRAL;
                } break;
            }
        } break;
        case TIMID: {
            switch (stat) {
                case HP: {
                    return NEUTRAL;
                } break;
                case ATK: {
                    return WEAK;
                } break;
                case DEF: {
                    return NEUTRAL;
                } break;
                case SPATK: {
                    return NEUTRAL;
                } break;
                case SPDEF: {
                    return NEUTRAL;
                } break;
                case SPEED: {
                    return STRONG;
                } break;
            }
        } break;
        case HASTY: {
            switch (stat) {
                case HP: {
                    return NEUTRAL;
                } break;
                case ATK: {
                    return NEUTRAL;
                } break;
                case DEF: {
                    return WEAK;
                } break;
                case SPATK: {
                    return NEUTRAL;
                } break;
                case SPDEF: {
                    return NEUTRAL;
                } break;
                case SPEED: {
                    return STRONG;
                } break;
            }
        } break;
        case JOLLY: {
            switch (stat) {
                case HP: {
                    return NEUTRAL;
                } break;
                case ATK: {
                    return NEUTRAL;
                } break;
                case DEF: {
                    return NEUTRAL;
                } break;
                case SPATK: {
                    return WEAK;
                } break;
                case SPDEF: {
                    return NEUTRAL;
                } break;
                case SPEED: {
                    return STRONG;
                } break;
            }
        } break;
        case NAIVE: {
            switch (stat) {
                case HP: {
                    return NEUTRAL;
                } break;
                case ATK: {
                    return NEUTRAL;
                } break;
                case DEF: {
                    return NEUTRAL;
                } break;
                case SPATK: {
                    return NEUTRAL;
                } break;
                case SPDEF: {
                    return WEAK;
                } break;
                case SPEED: {
                    return STRONG;
                } break;
            }
        } break;
        case MODEST: {
            switch (stat) {
                case HP: {
                    return NEUTRAL;
                } break;
                case ATK: {
                    return WEAK;
                } break;
                case DEF: {
                    return NEUTRAL;
                } break;
                case SPATK: {
                    return STRONG;
                } break;
                case SPDEF: {
                    return NEUTRAL;
                } break;
                case SPEED: {
                    return NEUTRAL;
                } break;
            }
        } break;
        case MILD: {
            switch (stat) {
                case HP: {
                    return NEUTRAL;
                } break;
                case ATK: {
                    return NEUTRAL;
                } break;
                case DEF: {
                    return WEAK;
                } break;
                case SPATK: {
                    return STRONG;
                } break;
                case SPDEF: {
                    return NEUTRAL;
                } break;
                case SPEED: {
                    return NEUTRAL;
                } break;
            }
        } break;
        case QUIET: {
            switch (stat) {
                case HP: {
                    return NEUTRAL;
                } break;
                case ATK: {
                    return NEUTRAL;
                } break;
                case DEF: {
                    return NEUTRAL;
                } break;
                case SPATK: {
                    return STRONG;
                } break;
                case SPDEF: {
                    return NEUTRAL;
                } break;
                case SPEED: {
                    return WEAK;
                } break;
            }
        } break;
        case RASH: {
            switch (stat) {
                case HP: {
                    return NEUTRAL;
                } break;
                case ATK: {
                    return NEUTRAL;
                } break;
                case DEF: {
                    return NEUTRAL;
                } break;
                case SPATK: {
                    return STRONG;
                } break;
                case SPDEF: {
                    return WEAK;
                } break;
                case SPEED: {
                    return NEUTRAL;
                } break;
            }
        } break;
        case CALM: {
            switch (stat) {
                case HP: {
                    return NEUTRAL;
                } break;
                case ATK: {
                    return WEAK;
                } break;
                case DEF: {
                    return NEUTRAL;
                } break;
                case SPATK: {
                    return NEUTRAL;
                } break;
                case SPDEF: {
                    return STRONG;
                } break;
                case SPEED: {
                    return NEUTRAL;
                } break;
            }
        } break;
        case GENTLE: {
            switch (stat) {
                case HP: {
                    return NEUTRAL;
                } break;
                case ATK: {
                    return NEUTRAL;
                } break;
                case DEF: {
                    return WEAK;
                } break;
                case SPATK: {
                    return NEUTRAL;
                } break;
                case SPDEF: {
                    return STRONG;
                } break;
                case SPEED: {
                    return NEUTRAL;
                } break;
            }
        } break;
        case SASSY: {
            switch (stat) {
                case HP: {
                    return NEUTRAL;
                } break;
                case ATK: {
                    return NEUTRAL;
                } break;
                case DEF: {
                    return NEUTRAL;
                } break;
                case SPATK: {
                    return NEUTRAL;
                } break;
                case SPDEF: {
                    return STRONG;
                } break;
                case SPEED: {
                    return WEAK;
                } break;
            }
        } break;
        case CAREFUL: {
            switch (stat) {
                case HP: {
                    return NEUTRAL;
                } break;
                case ATK: {
                    return NEUTRAL;
                } break;
                case DEF: {
                    return NEUTRAL;
                } break;
                case SPATK: {
                    return WEAK;
                } break;
                case SPDEF: {
                    return STRONG;
                } break;
                case SPEED: {
                    return NEUTRAL;
                } break;
            }
        } break;
    }
}
int logic::pure::hitThreashold(int accuracy, int stage_mult, int other) {
    return accuracy * stage_mult * other;
}
double logic::pure::stageMultiplier(int stage) {
    if (stage < -6) return 2 / 8.0;
    switch (stage) {
        case -6: {
            return 2 / 8.0;
        } break;
        case -5: {
            return 2 / 7.0;
        } break;
        case -4: {
            return 2 / 6.0;
        } break;
        case -3: {
            return 2 / 5.0;
        } break;
        case -2: {
            return 2 / 4.0;
        } break;
        case -1: {
            return 2 / 3.0;
        } break;
        case 0: {
            return 2 / 2.0;
        } break;
        case 1: {
            return 3 / 2.0;
        } break;
        case 2: {
            return 4 / 2.0;
        } break;
        case 3: {
            return 5 / 2.0;
        } break;
        case 4: {
            return 6 / 2.0;
        } break;
        case 5: {
            return 7 / 2.0;
        } break;
        case 6: {
            return 8 / 2.0;
        } break;
    }
    return 8 / 2.0;
}
double logic::pure::stageMultiplierAccuracy(int stage) {
    if (stage < -6) return 3 / 9.0;
    switch (stage) {
        case -6: {
            return 3 / 9.0;
        } break;
        case -5: {
            return 3 / 8.0;
        } break;
        case -4: {
            return 3 / 7.0;
        } break;
        case -3: {
            return 3 / 6.0;
        } break;
        case -2: {
            return 3 / 5.0;
        } break;
        case -1: {
            return 3 / 4.0;
        } break;
        case 0: {
            return 3 / 3.0;
        } break;
        case 1: {
            return 4 / 3.0;
        } break;
        case 2: {
            return 5 / 3.0;
        } break;
        case 3: {
            return 6 / 3.0;
        } break;
        case 4: {
            return 7 / 3.0;
        } break;
        case 5: {
            return 8 / 3.0;
        } break;
        case 6: {
            return 9 / 3.0;
        } break;
    }
    return 9 / 3.0;
}
double logic::pure::stageMultiplierEvasion(int stage) {
    return logic::pure::stageMultiplierAccuracy(stage);
}
