# Add source directory
aux_source_directory(src/ SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Laboration_4 ${SOURCES} include/DataFileReader.h src/DataFileReader.cpp include/DataFileReader.h src/DataFilter.cpp include/DataFilter.h src/testProgram.cpp include/testProgram.h)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Laboration_4 PRIVATE include/ ../_Resources/_libs/)