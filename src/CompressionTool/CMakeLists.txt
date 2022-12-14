add_test_binary("CompressionTool")

add_executable(
        CompressionTool

        main.cpp
)

set_target_properties(CompressionTool PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)
