cmake_minimum_required(VERSION 3.20.0)

set(SHIELD ssd1306_128x64)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(tlamp)

#list(APPEND BOARD_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/Users/caiodias/Documents/GitHub/tlamp_main_car_9160)

# APP START
target_sources(app PRIVATE src/main.c)
# APP END

# Include source directory
target_include_directories(app PRIVATE src)
target_include_directories(app PRIVATE include)
target_include_directories(app PRIVATE src/modules)

# Application directories
add_subdirectory(src/modules)
