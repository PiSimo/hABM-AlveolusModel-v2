add_executable(test_configurations  src/testConfigurations.cpp)
target_include_directories(test_configurations PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(test_configurations PRIVATE
        project_options
        simulation
        analyser
        basic
        utils
        visualisation
        simulatorAlveolus
        Boost::filesystem)

add_test(NAME configurations_functions_tests COMMAND test_configurations)