#include "fpcsc/perf_util/sleep.h"
#include "fpcsc/perf_util/feature_cmd.h"

#include <string>
#include <algorithm>

static void send(void *Data) {
  asm volatile("" : : "g"(Data) : "memory");
}

class PackageData {
public:
  PackageData() = default;
  PackageData(std::string Data) : Data{std::move(Data)}, Size{this->Data.size()} {}

  std::string Data;
  unsigned long Size;
};

PackageData compress(PackageData Data) {
  Data.Data = Data.Data.substr(0, Data.Data.size() / 2);
  fpcsc::sleep_for_secs(3);
  return Data;
}

PackageData addPadding(PackageData Data) {
  Data.Data += "foopadbar";
  fpcsc::sleep_for_secs(1);
  return Data;
}

PackageData encrypt(PackageData Data) {
  std::reverse(Data.Data.begin(), Data.Data.end());
  fpcsc::sleep_for_secs(5);
  return Data;
}

static bool UseEncryption = false;
static bool UseCompression =  false;

void loadConfigFromArgv(int argc, char *argv[]) {
  if (fpcsc::isFeatureEnabled(argc, argv, std::string("--enc"))) {
    UseEncryption = true;
  }
  if (fpcsc::isFeatureEnabled(argc, argv, std::string("--compress"))) {
    UseCompression = true;
  }
}


void sendPackage(PackageData Data) {
  if (UseCompression) {
    Data = compress(Data);
  }
  if (UseEncryption) {
    if (not UseCompression) {
      Data = addPadding(Data);
    }

    Data = encrypt(Data);
  }

  // Sending
  fpcsc::sleep_for_secs(2);
  send(&Data);

  std::puts(Data.Data.c_str());
}

int main(int argc, char *argv[] ) {

  loadConfigFromArgv(argc, argv);

  auto UserData = PackageData(std::string(*argv));

  sendPackage(UserData);

  return 0;
}
