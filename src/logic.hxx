#ifndef LOGIC_HXX
#define LOGIC_HXX

#include "control.hxx"

namespace logic {
namespace pure {
// stat calculation
int stat(control::type::Stat, int level, int base, int iv, int ev,
         control::type::Nature);
// nature weak/netural/advantage table
control::type::NatureModifier affinity(control::type::Nature,
                                       control::type::Stat);
// accuracy evasion
int hitThreashold(int accuracy, int stage_mult,
                  int other);  // compute a threashold t that can be compared to
                               // a random variable r (in [1, 100]) to determine
                               // if an attack hits or not
double stageMultiplier(int stage);
double stageMultiplierAccuracy(int stage);
double stageMultiplierEvasion(int stage);
}  // namespace pure
}  // namespace logic
#endif
