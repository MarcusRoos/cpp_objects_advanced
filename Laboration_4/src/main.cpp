#include "testProgram.h"
//#include "memstat.hpp"

int main() {
    testProgram mainmenu(DataFileReader<std::string>("Values.dat","ReadErrors.dat"));
    mainmenu.run();
    return 0;
}
