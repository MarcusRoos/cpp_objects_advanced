# Add source directory
aux_source_directory(src/ SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Laboration_1 ${SOURCES} src/Management.cpp include/Management.h src/MainMenu.cpp include/MainMenu.h src/Menu.cpp include/Menu.h src/MenuItem.cpp include/MenuItem.h)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Laboration_1 PRIVATE include/ ../_Resources/_libs/)