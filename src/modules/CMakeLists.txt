target_include_directories(app PRIVATE .)

target_sources(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/display.c)

target_sources(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/ui_helpers.c)