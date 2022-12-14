#include "fpcsc/perf_util/sleep.h"

#include <cstdlib>

static int x2 = 0;

int preCalculate(int z) {
  if (x2 < 10) return 0;
  return 1;
}

void bar(int z) {
  for (int i = 0; i < z; i++) {
    fpcsc::sleep_for_millisecs(200);
  }
}

void baz(int z) {
  int flag = preCalculate(z);
  for (int i = flag; i < z; i++) {
    fpcsc::sleep_for_millisecs(300);
  }
}

void foo(int y, int z, int iters) {
  for (int i = 0; i < iters; i++) {
    for (int j = 0; j < y; j++) {
      fpcsc::sleep_for_millisecs(100);
    }
  }
  bar(z);
  baz(z);
}

int main(int argc, char *argv[]) {
  int x1 __attribute__((feature_variable("x1"))) = std::atoi(argv[1]);
  int x2 __attribute__((feature_variable("x2"))) = std::atoi(argv[2]);
  int iters __attribute__((feature_variable("iters"))) = std::atoi(argv[3]);

  int y = x1 * 3;
  int z = x2 / 7;

  foo(y, z, iters);

  return 0;
}
