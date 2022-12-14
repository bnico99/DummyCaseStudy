#include "FeatureHeader.h"

bool ExternFeature = false;

static bool CppFeature = false;

void enableCppFeature() {
  CppFeature = true;
}

bool isCppFeatureEnabled() {
  return CppFeature;
}
