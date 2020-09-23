# Add source directory
aux_source_directory(src/ SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Laboration_2 ${SOURCES} src/testProgram.cpp include/testProgram.h src/Menu.cpp include/Menu.h src/MenuItem.cpp include/MenuItem.h src/Account.cpp include/Account.h)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Laboration_2 PRIVATE include/ ../_Resources/_libs/)