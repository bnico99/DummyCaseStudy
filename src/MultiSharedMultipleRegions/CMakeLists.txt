add_test_binary("MultiSharedMultipleRegions")

add_executable(
  MultiSharedMultipleRegions

  MSMRmain.cpp
  FeatureHeader.cpp
)

set_target_properties(MultiSharedMultipleRegions PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)
