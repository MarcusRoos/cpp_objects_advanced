# Add source directory
aux_source_directory(src/ SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Project ${SOURCES} src/vehicle.cpp include/vehicle.h src/train.cpp include/train.h src/MenuItem.cpp src/MenuItem.cpp include/MenuItem.h src/Menu.cpp include/Menu.h src/SimulationProgram.cpp include/SimulationProgram.h src/station.cpp include/station.h)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Project PRIVATE include/ ../_Resources/_libs/)