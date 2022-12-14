#include "fpcsc/perf_util/sleep.h"

#include <string>

int main(int argc, char *argv[]) {

  bool Slow = false;

  if ((argc >= 2 && argv[1] == std::string("--slow")) ||
      (argc >= 3 && argv[2] == std::string("--slow"))) {
    Slow = true;
  }

  if (Slow) {
    fpcsc::sleep_for_secs(5);
  } else {
    fpcsc::sleep_for_secs(2);
  }

  return 0;
}
