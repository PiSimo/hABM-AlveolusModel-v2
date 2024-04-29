#!/bin/bash

# first program argument is how your your new simulator is called
# you still have to add the simulator to the main.cpp and the test/src/testConfigurations.cpp

cp -r apps/example/ apps/$1

replace_word=$1

replace_word="$(tr '[:lower:]' '[:upper:]' <<< ${1:0:1})${1:1}"

find ./apps/$1 -depth -name "*Example*" -execdir bash -c 'mv "$1" "${1//Example/'"$replace_word"'}"' _ {} \;

find ./apps/$1 -depth -name "*example*" -execdir bash -c 'mv "$1" "${1//example/'"$1"'}"' _ {} \;

find ./apps/$1 -type f -print0 | xargs -0 sed -i "s/Example/$replace_word/g"

find ./apps/$1 -type f -print0 | xargs -0 sed -i "s/example/$1/g"

sed -i "/add_subdirectory(apps\/example)/a add_subdirectory(apps\/$1)" CMakeLists.txt

sed -i "/target_link_libraries(simulatorExample PRIVATE project_options project_warnings OpenMP::OpenMP_CXX)/a target_link_libraries(simulator$replace_word PRIVATE project_options project_warnings OpenMP::OpenMP_CXX)" CMakeLists.txt

sed -i "/abm::core/a simulator$replace_word" CMakeLists.txt
