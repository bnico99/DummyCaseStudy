#include "FeatureHeader.h"

#include "fpcsc/perf_util/sleep.h"
#include "fpcsc/perf_util/feature_cmd.h"

#include <string>

int main(int argc, char *argv[] ) {
  bool Slow = false;

  if (fpcsc::isFeatureEnabled(argc, argv, std::string("--slow"))) {
    Slow = true;
  }

  if (fpcsc::isFeatureEnabled(argc, argv, std::string("--header"))) {
    HeaderFeature = true;
  }

  if (fpcsc::isFeatureEnabled(argc, argv, std::string("--extern"))) {
    enableExternFeature();
  }

  if (fpcsc::isFeatureEnabled(argc, argv, std::string("--cpp"))) {
    enableCppFeature();
  }

  // Multiple regions related to --slow that take different amounts of time.

  if (Slow) {
    fpcsc::sleep_for_secs(5);
  } else {
    fpcsc::sleep_for_secs(3);
  }

  fpcsc::sleep_for_secs(2); // General waiting time

  if (HeaderFeature) {
    fpcsc::sleep_for_secs(3);
  } else {
    fpcsc::sleep_for_secs(1);
  }

  fpcsc::sleep_for_secs(2); // General waiting time

  if (ExternFeature) {
    fpcsc::sleep_for_secs(6);
  }

  fpcsc::sleep_for_secs(2); // General waiting time

  if (isCppFeatureEnabled()) {
    fpcsc::sleep_for_secs(3);
  }

  return 0;
}
