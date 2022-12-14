#include "fpcsc/perf_util/feature_cmd.h"
#include "fpcsc/perf_util/sleep.h"

#include <iostream>
#include <string>

volatile long Counter;

int main(int argc, char *argv[]) {
  long NumIterations = fpcsc::getFeatureValue(argc, argv, "--iterations");
  long CountTo = fpcsc::getFeatureValue(argc, argv, "--count_to");

  if (!NumIterations || !CountTo) {
    std::cerr << "Required feature missing." << "\n";
    return 1;
  }

  for (long i = 0; i < NumIterations; ++i) {
    for (Counter = 0; Counter < CountTo; ++Counter) {
    }
  }

  return 0;
}
