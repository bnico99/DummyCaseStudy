#ifndef FEATURE_HEADER_H
#define FEATURE_HEADER_H

extern bool ExternFeature;

static inline bool HeaderFeature = false;

inline void enableExternFeature() {
  ExternFeature = true;
}

void enableCppFeature();
bool isCppFeatureEnabled();

#endif // FEATURE_HEADER_H
