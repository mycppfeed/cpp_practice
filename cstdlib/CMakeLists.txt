add_executable(macros macros.cpp)

if (BUILD_TYPE STREQUAL debug)
    target_link_libraries(macros Catch2::Catch2)
    # ParseAndAddCatchTests(macros)
    # catch_discover_tests(macros TEST_SPEC exit_code)
    catch_discover_tests(macros)
endif()

install(TARGETS macros RUNTIME DESTINATION bin)