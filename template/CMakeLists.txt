cmake_minimum_required(VERSION 3.15) # Or a version you prefer

project(CP-RE:Nix) # Project name - you can customize this if needed

set(CMAKE_CXX_STANDARD 20) # Or c++20, etc. - Set your desired C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF) # Encourage standard C++

# --- Release Build Flags ---
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -DONLINE_JUDGE")

# --- Debug Build Flags ---
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g")

add_executable(main src/main.cpp) # Define the executable target

# Create a custom target for running (optional, for convenience)
add_custom_target(run
    COMMAND ${CMAKE_BINARY_DIR}/main < ${CMAKE_SOURCE_DIR}/input/input.txt
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running executable with input/input.txt"
    VERBATIM
)

add_custom_target(format
    COMMAND clang-format -i ${CMAKE_SOURCE_DIR}/src/main.cpp
    COMMENT "Formatting src/main.cpp with clang-format"
    VERBATIM
)

add_custom_target(clean_build
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
    COMMENT "Cleaning build directory"
    VERBATIM
)

# Optional: Install target (might not be strictly needed for CP, but good practice)
install(TARGETS main DESTINATION bin)