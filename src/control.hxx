#ifndef CONTROL_HXX
#define CONTROL_HXX
namespace control {
namespace type {
enum Status {
    BURN,
    FREEZE,
    PARALYSIS,
    POISON,
    TOXIC,
    SLEEP,
};  // persists outside of battle/after switch out, only 1 at a time
enum StatusVolatile {
    BOUND,
    NO_ESCAPE,
    CONFUSION,
    CURSE,
    DROWSY,
    EMBARGO,
    ENCORE,
    FLINCH,
    HEAL_BLOCK,
    IDENTIFIED,
    INFATUATION,
    LEECH_SEED,
    NIGHTMARE,
    PERISH_SONG,
    TAUNT,
    TELEKINESIS,
    TORMENT
};
/* enum BattleStatus { */
/*     AQUA_RING, */
/*     BRACING, */
/* }; // volatile battle only status */
enum Nature {
    HARDY,
    LONELY,
    BRAVE,
    ADAMANT,
    NAUGHTY,
    BOLD,
    DOCILE,
    RELAXED,
    IMPISH,
    LAX,
    TIMID,
    HASTY,
    SERIOUS,
    JOLLY,
    NAIVE,
    MODEST,
    MILD,
    QUIET,
    BASHFUL,
    RASH,
    CALM,
    GENTLE,
    SASSY,
    CAREFUL,
    QUIRKY,
};
enum NatureModifier {
    WEAK,
    NEUTRAL,
    STRONG,
};
enum Stat {
    HP,
    ATK,
    DEF,
    SPATK,
    SPDEF,
    SPEED,
};
}  // namespace type
}  // namespace control
#endif
