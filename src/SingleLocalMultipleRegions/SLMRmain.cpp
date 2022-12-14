#include "fpcsc/perf_util/sleep.h"

#include <string>

int main(int argc, char *argv[]) {

  bool Slow = false;

  if ((argc >= 2 && argv[1] == std::string("--slow")) ||
      (argc >= 3 && argv[2] == std::string("--slow"))) {
    Slow = true;
  }

  // Multiple regions related to --slow that take different amounts of time.

  if (Slow) {
    fpcsc::sleep_for_secs(5);
  } else {
    fpcsc::sleep_for_secs(2);
  }

  fpcsc::sleep_for_secs(3); // General waiting time

  if (Slow) {
    fpcsc::sleep_for_secs(3);
  } else {
    fpcsc::sleep_for_secs(1);
  }

  fpcsc::sleep_for_secs(4); // General waiting time

  if (Slow) {
    fpcsc::sleep_for_secs(6);
  }

  return 0;
}
