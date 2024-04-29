add_subdirectory(core)
add_subdirectory(apps/example)
add_subdirectory(apps/alveolus)

target_link_libraries(core PRIVATE project_options project_warnings OpenMP::OpenMP_CXX)
set_target_properties(core PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(simulatorExample PRIVATE project_options project_warnings OpenMP::OpenMP_CXX)
target_link_libraries(simulatorAlveolus PRIVATE project_options project_warnings OpenMP::OpenMP_CXX)


add_executable(hABM main.cpp)
target_link_libraries(hABM PUBLIC
project_options
project_warnings
abm::core
simulatorAlveolus
Boost::filesystem
OpenMP::OpenMP_CXX)

target_include_directories(hABM PRIVATE ${PROJECT_SOURCE_DIR}/src)
