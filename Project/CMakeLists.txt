# Add source directory
aux_source_directory(src/ SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Project ${SOURCES} src/vehicle.cpp include/vehicle.h src/train.cpp include/train.h src/MenuItem.cpp src/MenuItem.cpp include/MenuItem.h src/Menu.cpp include/Menu.h src/SimulationProgram.cpp include/SimulationProgram.h src/station.cpp include/station.h src/map.cpp include/map.h src/Management.cpp include/Management.h src/Events.cpp include/Events.h src/Simulator.cpp include/Simulator.h)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Project PRIVATE include/ ../_Resources/_libs/)