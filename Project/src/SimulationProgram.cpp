//
// Created by Marcus Roos on 2020-10-18.
// Mittuniversitet
// StudentID: Maro1904
//

#include "SimulationProgram.h"

/**
The run function, this function will be called in the main program, from here a
 it will enter a switch which will call another function from the menu class.
 Here the user will be able to choose what they would like to do with the
 program, at first only the first "create Queue" option will be a available
 as well as the exit option,
 once a queue has been created the rest of the options will open up.
*/

SimulationProgram::SimulationProgram(Simulator* simulation)
        : simulation(simulation), amountDelayed(0), amountSuccess(0), totalDelay(0){
    TICK = 10;
    outFile.open("Trainsim.log", std::fstream::out | std::fstream::trunc);
}

/**
 This is the main menu of the program, it will print the different alternatives
 and allow the user to choose what to do next. Ran by a switch which will take
 the users input and call the relevant function depending on the input.
*/
void SimulationProgram::run() {
    bool again = true;
    do{
        std::cout << "===== Train Station Program =====" << std::endl;
        std::cout << "1. Change interval [00:" + std::to_string(TICK) +"]" << std::endl;
        std::cout << "2. Run next interval" << std::endl;
        std::cout << "3. Finish (Complete simulation)" << std::endl;
        std::cout << "4. Statistics menu" << std::endl;
        std::cout << "5. Print time table for all trains" << std::endl;
        std::cout << "6. Print information for one specific train" << std::endl;
        std::cout << "7. Print one specific station"<< std::endl;
        std::cout << "8. Following vehicle by ID." << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter choice" << std::endl;
        int choice = 0;
        std::cin >> choice;
        while (std::cin.fail() || choice < 0 || choice > 8) {
            std::cout << "Wrong input.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> choice;
        }
        switch(choice)
        {
            case 0:
            default:
                again = false;
                break;
            case 1:
                changeTick();
                break;
            case 2:
                advance();
                break;
            case 3: {
                endStats();
                pauseFunction();
                again = false;
                submenuLoop = false;
                break;
            }
            case 4:
                statisticsMenu();
                break;
            case 5:
                printTimeTable();
                break;
            case 6:
                printSpecificTrain();
                break;
            case 7:
                printSpecificStation();
                break;
            case 8:
                followVehicle();
                break;
        }
    }while(again);
}

/**
 This is the sub menu of the program, this is the first screen the user is
 met with, here they can decide either to start the simulation or straight up
 exit the program. Not a necessary stage, but it would be necessary for further
 development if alternatives to change simulation time were to be added.
*/
void SimulationProgram::runSubMenu() {
    while(submenuLoop) {
        std::cout << "===== Start Menu =====" << std::endl;
        std::cout << "1. Start simulation" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter choice" << std::endl;
        int choice = 0;
        std::cin >> choice;
        while (std::cin.fail() || choice < 0 || choice > 1) {
            std::cout << "Wrong input.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> choice;
        }
        switch (choice) {
            case 1:
                run();
                break;
            case 0:
            default:
                endStats();
                pauseFunction();
                submenuLoop = false;
                break;
        }
    }
}

/**
 * Station populator
 * Will open the file "TrainStations.txt" and read its contents and store
 * in the station vector. Depending on the type it will use different
 * cases to determine which kind of vehicle is being read in. This file
 * contains all the different vechicles located at the different stations
 * at run time.**/
void SimulationProgram::populateStation() {
    testVehicle.clear();
    std::ifstream inFile("TrainStations.txt");
    std::string line;
    std::vector<std::string> tmpStat;
    while (std::getline(inFile, line))
    {
        tmpStat.push_back(line);
    }
    for (const auto & i : tmpStat) {
        std::stringstream ss;
        char delim;
        std::string stationName;
        int tmpID = 0, tmpType = 6, param1 = 0, param2 = 0, choice;
        ss << i;
        ss >> stationName;
        ss >> delim;
        while (!ss.eof()) {
            ss >> tmpID;
            ss >> tmpType;
            choice = tmpType;
            switch (choice) {
                case 0: {
                    ss >> param1;
                    ss >> param2;
                    ss >> delim;
                    ss >> delim;
                    testVehicle.push_back(std::shared_ptr<Vehicle>(
                            new CoachCar(tmpID, tmpType, param1, param2)));
                    break;
                }
                case 1: {
                    ss >> param1;
                    ss >> delim;
                    ss >> delim;
                    testVehicle.push_back(std::shared_ptr<Vehicle>(
                            new SleepingCar(tmpID, tmpType, param1)));
                    break;
                }
                case 2: {
                    ss >> param1;
                    ss >> param2;
                    ss >> delim;
                    ss >> delim;
                    testVehicle.push_back(std::shared_ptr<Vehicle>(
                            new OpenFreight(tmpID, tmpType, param1, param2)));
                    break;
                }
                case 3: {
                    ss >> param1;
                    ss >> delim;
                    ss >> delim;
                    testVehicle.push_back(std::shared_ptr<Vehicle>(
                            new CoveredFreight(tmpID, tmpType, param1)));
                    break;
                }
                case 4: {
                    ss >> param1;
                    ss >> param2;
                    ss >> delim;
                    ss >> delim;
                    testVehicle.push_back(std::shared_ptr<Vehicle>(
                            new ElectricalEngine(tmpID, tmpType, param1,
                                                 param2)));
                    break;
                }
                case 5: {
                    ss >> param1;
                    ss >> param2;
                    ss >> delim;
                    ss >> delim;
                    testVehicle.push_back(std::shared_ptr<Vehicle>(
                            new DieselEngine(tmpID, tmpType, param1, param2)));
                    break;
                }
                case 6: {
                    std::cout << "Type is null" << std::endl;
                    default:
                        break;
                }
            }
        }
        testStation.push_back(std::make_shared<Station>(
                stationName, std::move(testVehicle)));
    }
}
/**
 Map populator
 Works the same as the station function except theres no different
 types to be read so its simply just storing each line in the map vector.
*/
void SimulationProgram::populateMap() {
    testMap.clear();
    std::ifstream inFile("TrainMap.txt");
    std::string line;
    std::vector<std::string> tmpMap;
    while (std::getline(inFile, line))
    {
        tmpMap.push_back(line);
    }
    int tmpDist=0;
    std::string tmpDep, tmpDest;
    for (const auto & i : tmpMap) {
        std::stringstream ss;
        ss << i;
        ss >> tmpDep;
        ss >> tmpDest;
        ss >> tmpDist;
        testMap.push_back(std::make_shared<Map>(
                tmpDep, tmpDest, tmpDist));
    }
}

/**
 Train populator
 Reads the file "Trains.txt" and stores it contents in the train vector.
 This will read all the relevant information in the file and use a stringstream
 to pick out the parts for the different parameters, once it has reached
 end of line it will add all the values to the train vector.
*/
void SimulationProgram::populateTrain() {
    testTrain.clear();
    std::ifstream inFile("Trains.txt");
    std::string line;
    std::vector<int> amountVehicles;
    std::vector<std::string> tmpTrain;
    while (std::getline(inFile, line))
    {
        tmpTrain.push_back(line);
    }
    int tmpID=0, tmpInt=0, adepartureTime=0, aarrivalTime=0;
    std::string afromStation, atoStation, tmpdepartureTime, tmparrivalTime;
    double amaxSpeed;
    for (const auto & i : tmpTrain) {
        std::stringstream ss;
        ss << i;
        ss >> tmpID;
        ss >> afromStation;
        ss >> atoStation;
        ss >> tmpdepartureTime;
        std::string aPrintDep = tmpdepartureTime;
        tmpdepartureTime.erase(remove(tmpdepartureTime.begin(),
                                      tmpdepartureTime.end(), ':'), tmpdepartureTime.end());
        adepartureTime = std::stoi(tmpdepartureTime);
        int temp=0;
        temp = (adepartureTime%100);
        adepartureTime = (adepartureTime/100);
        adepartureTime = (adepartureTime*60)+temp;
        ss >> tmparrivalTime;
        std::string aPrintArr = tmparrivalTime;
        tmparrivalTime.erase(remove(tmparrivalTime.begin(),
                                    tmparrivalTime.end(), ':'), tmparrivalTime.end());
        aarrivalTime = std::stoi(tmparrivalTime);
        temp = (aarrivalTime%100);
        aarrivalTime = (aarrivalTime/100);
        aarrivalTime = (aarrivalTime*60)+temp;
        ss >> amaxSpeed;
        while (ss >> tmpInt){
            if (ss.peek() == '\n')
                break;
            else
                amountVehicles.push_back(tmpInt);
        }
        testTrain.push_back(std::make_shared<Train>(
                tmpID, afromStation, atoStation, adepartureTime, aarrivalTime, amaxSpeed, amountVehicles, aPrintDep, aPrintArr));
        amountVehicles.clear();
    }
}

/**
Simple printing functions, iterates through the testStation vector and calls the
 printTypes function.
*/
void SimulationProgram::printStatistics() {
    for (auto & k : testStation){
        k->printTypes();
    }
}

/**
 Menu for printing different statistic alternatives, uses switch statement to
 determine which function to call.
*/
void SimulationProgram::statisticsMenu() {
    bool loop=true;
    while (loop) {
        std::cout << "===== Log level menu =====" << std::endl;
        std::cout << "1. Print statistics" << std::endl;
        std::cout << "2. Print time table for all trains" << std::endl;
        std::cout << "3. Print information for one specific train" << std::endl;
        std::cout << "4. Print one specific station"<< std::endl;
        std::cout << "0. Return" << std::endl;
        std::cout << "Enter choice" << std::endl;
        int choice = 0;
        std::cin >> choice;
        while (std::cin.fail() || choice < 0 || choice > 4) {
            std::cout << "Wrong input.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> choice;
        }
        switch (choice) {
            case 1: {
                std::cout << "Print statistics" << std::endl;
                printStatistics();
                break;
            }
            case 2:
                printTimeTable();
                break;
            case 3:
                printSpecificTrain();
                break;
            case 4:
                printSpecificStation();
                break;
            case 0:
            default:
                loop = false;
                break;
        }
    }
}

/**
 Prints the time table for all the trains.
*/
void SimulationProgram::printTimeTable() {
    for (auto & i : testTrain){
        std::cout << "Train: "<< i->getID()
        << " "<<i->getFromStation() << " --> " << i->getToStation()
        << " | " << i->getDepPrint() << " <---> "
        << i->getArrPrint() << "|" << " DISTANCE: ";
        for (auto & m : testMap){
            m->printMap(i->getFromStation(), i->getToStation());
        }
    }
}

/**
 Prints the details for one specific train, determined by user input and
 should be the trains ID.
*/
void SimulationProgram::printSpecificTrain() {
    std::cout << "Print a specific train by entering its ID. " << std::endl;
    std::cout << "Trains ID range from 1 to 130. " << std::endl;
    std::cout << "ID: ";
    int tmpIdx=0;
    std::cin >> tmpIdx;
    while (std::cin.fail() || tmpIdx < 1 || tmpIdx > 130) {
        std::cout << "Wrong input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> tmpIdx;
    }
    std::shared_ptr<Train> tmpTrain;
    for (auto & i : testTrain){
        if (tmpIdx == i->getID()){
            tmpTrain = i;
            break;
        }
    }
    tmpTrain->printTypes();
}

/**
 Prints all available vehicles at one specific station, prints a list for the
 user to look at and decide which station they want to print information for.
*/
void SimulationProgram::printSpecificStation() {
    bool loop = true;
    while (loop) {
        std::cout << "===== Station menu =====" << std::endl;
        std::cout << "Show information about which station?" << std::endl;
        std::cout << "Enter choice" << std::endl;
        std::cout << "1. Grand Central" << std::endl;
        std::cout << "2. Liege-Guillemins" << std::endl;
        std::cout << "3. ST.Pancras" << std::endl;
        std::cout << "4. Dunedin" << std::endl;
        std::cout << "5. MilanoCentrale" << std::endl;
        std::cout << "6. Luz" << std::endl;
        std::cout << "7. Shinjuku" << std::endl;
        std::cout << "8. Hauptbahnhof" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter" << std::endl;

        int choice = 0;
        std::cin >> choice;
        while (std::cin.fail() || choice < 0 || choice > 8) {
            std::cout << "Wrong input.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> choice;
        }
        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:{
                    testStation[choice-1]->printTypes();
                    std::string tmpString = testStation[choice-1]->getStationname();
                    for (auto & i : testTrain){
                        i->printAtStation(tmpString);
                    }
                break;
            }
            case 0:
            default:
                loop = false;
                break;
        }
    }
}

/**
 Schedules the events in the priority queue for the trains, used to determine
 which train gets to be built first.
*/
void SimulationProgram::scheduleEvents() {
    std::vector<std::shared_ptr<Train>> tmpTrain;
    SimulationProgram *tmpSimulation = this;
    tmpTrain = testTrain;
    std::sort(tmpTrain.begin(), tmpTrain.end(), sortByTime);
    for (auto & df : tmpTrain) {
        int depTime = df->getDepTime() - BUILDTIME;
        int ID = df->getID();
        simulation->scheduleEvent(new BuildTrain(simulation,tmpSimulation,depTime,ID));
    }
}

/**
 Tries to build the train, if it fails it will return an error and set the
 trains state to incomplete. If it succeeds the trains state will be set to
 assembled and the train will move on to the next stage to be dispatched.
 Also prints current states on the screen and writes it down to the log file
 at the same time.
*/
bool SimulationProgram::tryBuild(int trainId) {
    std::shared_ptr<Train> tmpTrain;
    for (auto & i : testTrain){
        if (trainId == i->getID()){
            tmpTrain = i;
            break;
        }
    }
    std::stringstream ss;
    if (tmpTrain->assembleVehicle(testStation)){
        tmpTrain->setState(ASSEMBLED);
        int tmpT=0, tmpH=0, tmpM=0;
        tmpT = simulation->getTime();
        while (tmpT >= 60){
            tmpH++;
            tmpT -= 60;
        }
        tmpM = tmpT;

        ss << "["<<  std::setw(2) << std::setfill('0') << tmpH
                  <<  ":" <<  std::setw(2) << std::setfill('0') <<tmpM
                  << "] Train [" << trainId << "] (" <<
                  tmpTrain->getState(tmpTrain->getState())<< ") from "
           << tmpTrain->getFromStation() <<" " << tmpTrain->getDepPrint()
           << " to "
           << tmpTrain->getToStation() << " " << tmpTrain->getArrPrint()
           << " speed = " << tmpTrain->getSpeed()
           << " is now assembled, arriving at the platform at "
           << tmpTrain->getArrPrint() << std::endl;
        std::string tmpString = ss.str();
        std::cout << tmpString;
        writeToFile(tmpString);
        return true;
    }
    else {
        tmpTrain->setState(INCOMPLETE);
        tmpTrain->delay(DELAYTIME);
        int tmpT=0, tmpH=0, tmpM=0;
        tmpT = simulation->getTime();
        while (tmpT >= 60){
            tmpH++;
            tmpT -= 60;
        }
        tmpM = tmpT;
        std::stringstream as;
        as << "["<<  std::setw(2) << std::setfill('0') << tmpH
                  <<  ":" <<  std::setw(2) << std::setfill('0') <<tmpM << "]"
         << " Train [" << trainId << "] (" << tmpTrain->getState(tmpTrain->getState())<< ") from "
                  << tmpTrain->getFromStation() <<" " << tmpTrain->getDepPrint() << " to "
                  << tmpTrain->getToStation() << " " << tmpTrain->getArrPrint()
                  << " couldn't be assembled "
                  << tmpTrain->getArrPrint() << std::endl;
        std::string tmpString = as.str();
        std::cout << tmpString;
        writeToFile(tmpString);
        if (!tmpTrain->getDelayed()) {
            tmpTrain->setDelayed(true);
        }
        return false;
    }
}

/**
 Once a train has reached his arrival destination it will be set as finished
 state and the train will be disassembled at the destination station. Just
 as above relevant info will be printed on the screen and logged to the log
 file.
*/
void SimulationProgram::EndTrain(int trainId) {
    std::stringstream ss;
    std::shared_ptr<Train> tmpTrain;
    for (auto & i : testTrain){
        if (trainId == i->getID()){
            tmpTrain = i;
            break;
        }
    }
    tmpTrain->disassembleTrain(testStation);
    tmpTrain->setState(FINISHED);
    int tmpT=0, tmpH=0, tmpM=0;
    tmpT = simulation->getTime();
    while (tmpT >= 60){
        tmpH++;
        tmpT -= 60;
    }
    tmpM = tmpT;
    ss << "["<<  std::setw(2) << std::setfill('0') << tmpH
              <<  ":" <<  std::setw(2) << std::setfill('0') <<tmpM << "]"
     << " Train [" << trainId << "] (" << tmpTrain->getState(tmpTrain->getState())<< ") from "
              << tmpTrain->getFromStation() <<" " << tmpTrain->getDepPrint() << " to "
              << tmpTrain->getToStation() << " " << tmpTrain->getArrPrint()
              << " speed = " << tmpTrain->getSpeed()
              << " has reached its destination and is now being disassembled at "
              << tmpTrain->getToStation() << std::endl;
    std::string tmpString = ss.str();
    std::cout << tmpString;
    writeToFile(tmpString);
}

/**
 Once a train has been marked as assembled it will be marked as ready in this
 function, and once ready its waiting to be dispatched. Just as above the
 current state will be printed on the screen and written to the log file.
*/
void SimulationProgram::readyTrain(int trainId) {
    std::stringstream ss;
    std::shared_ptr<Train> tmpTrain;
    for (auto & i : testTrain){
        if (trainId == i->getID()){
            tmpTrain = i;
            break;
        }
    }
    tmpTrain->setState(READY);
    int tmpT=0, tmpH=0, tmpM=0;
    tmpT = simulation->getTime();
    while (tmpT >= 60){
        tmpH++;
        tmpT -= 60;
    }
    tmpM = tmpT;
    ss << "["<<  std::setw(2) << std::setfill('0') << tmpH
              <<  ":" <<  std::setw(2) << std::setfill('0') <<tmpM << "]"
    << " Train [" << trainId << "] (" << tmpTrain->getState(tmpTrain->getState())<< ") from "
              << tmpTrain->getFromStation() <<" " << tmpTrain->getDepPrint() << " to "
              << tmpTrain->getToStation() << " " << tmpTrain->getArrPrint()
              << " speed = " << tmpTrain->getSpeed()
              << " is now ready at station" << tmpTrain->getFromStation()
              << " and is scheduled to " << tmpTrain->getToStation() << std::endl;
    std::string tmpString = ss.str();
    std::cout << tmpString;
    writeToFile(tmpString);
}

/**
 Once the train is marked as ready it will next be called to be dispatched, once
 here its state will be set to running as the train has been dispatched.
 As previously, contents will be printed and written to log file.
*/
int SimulationProgram::dispatchTrain(int trainId) {
    std::stringstream ss;
    std::shared_ptr<Train> tmpTrain;
    for (auto & i : testTrain){
        if (trainId == i->getID()){
            tmpTrain = i;
            break;
        }
    }
    int tmpLate = simulation->getTime();
    tmpTrain->setState(RUNNING);
    if(tmpTrain->getDelayed()) {
        tmpLate -= tmpTrain->getDepTime();
    }
    int tmpT=0, tmpH=0, tmpM=0;
    tmpT = simulation->getTime();
    while (tmpT >= 60){
        tmpH++;
        tmpT -= 60;
    }
    tmpM = tmpT;
    ss << "["<<  std::setw(2) << std::setfill('0') << tmpH
              <<  ":" <<  std::setw(2) << std::setfill('0') <<tmpM << "]"
              << " Train [" << trainId << "] (" << tmpTrain->getState(tmpTrain->getState())<< ") from "
              << tmpTrain->getFromStation() <<" " << tmpTrain->getDepPrint() << " to "
              << tmpTrain->getToStation() << " " << tmpTrain->getArrPrint()
              << " speed = " << tmpTrain->getSpeed()
              << " has left from " << tmpTrain->getFromStation() << std::endl;
    if (tmpTrain->getDelayed()) {
        ss << "But the train departed " << tmpLate << " minutes too late."
           << std::endl;
        std::string tmpString = ss.str();
        std::cout << tmpString;
        writeToFile(tmpString);
    }

    else {
        std::stringstream as;
        tmpH=0;
        tmpT = simulation->getTime();
        while (tmpT >= 60){
            tmpH++;
            tmpT -= 60;
        }
        tmpM = tmpT;
        as << "["<<  std::setw(2) << std::setfill('0') << tmpH
                  <<  ":" <<  std::setw(2) << std::setfill('0') <<tmpM << "]"
                  << " Train [" << trainId << "] (" << tmpTrain->getState(tmpTrain->getState())<< ") from "
                  << tmpTrain->getFromStation() <<" " << tmpTrain->getDepPrint() << " to "
                  << tmpTrain->getToStation() << " " << tmpTrain->getArrPrint()
                  << " speed = " << tmpTrain->getSpeed()
                  << " is now leaving " << tmpTrain->getFromStation()
                  << " and is scheduled to arrive at " <<
                  tmpTrain->getToStation() << " on time." << std::endl;
        std::string tmpString = as.str();
        std::cout << tmpString;
        writeToFile(tmpString);
    }
    return tmpTrain->getArrTime();
}

/**
 Once the train has reached its arrival station the state will be set as arrived,
 and contents will be printed on screen and written to the log file.
*/
void SimulationProgram::arriveTrain(int trainId) {
    std::stringstream ss;
    std::shared_ptr<Train> tmpTrain;
    for (auto & i : testTrain){
        if (trainId == i->getID()){
            tmpTrain = i;
            break;
        }
    }
    tmpTrain->setState(ARRIVED);
    int tmpT=0, tmpH=0, tmpM=0;
    tmpT = simulation->getTime();
    while (tmpT >= 60){
        tmpH++;
        tmpT -= 60;
    }
    tmpM = tmpT;
    ss << "["<<  std::setw(2) << std::setfill('0') << tmpH
              <<  ":" <<  std::setw(2) << std::setfill('0') <<tmpM << "]"
              << " Train [" << trainId << "] (" << tmpTrain->getState(tmpTrain->getState())<< ") from "
              << tmpTrain->getFromStation() <<" " << tmpTrain->getDepPrint() << " to "
              << tmpTrain->getToStation() << " " << tmpTrain->getArrPrint()
              << " speed = " << tmpTrain->getSpeed()
              << " has arrived at  "
              << tmpTrain->getToStation() << std::endl;
    if (tmpTrain->getDelayed()){
        int lateMins = tmpTrain->getArrTime() - tmpTrain->getTmpArrTime();
        amountDelayed++;
        totalDelay += lateMins;
        std::cout  << " But it arrived " << lateMins << " minutes behind schedule";
        std::string tmpString = ss.str();
        std::cout << tmpString;
        writeToFile(tmpString);
    }
    else {
        amountSuccess++;
        std::string tmpString = ss.str();
        std::cout << tmpString;
        writeToFile(tmpString);
    }
}

/**
 Called at 23:59 to inform the user that the simulation has reached its end.
*/
void SimulationProgram::endSimulation() {
    std::cout << "End of simulation" << std::endl;
}

/**
 Sorts the trains by departure time from early to late.
*/
bool SimulationProgram::sortByTime(const std::shared_ptr<Train> &a,
                                   const std::shared_ptr<Train> &b) {
    return a->getDepTime() < b->getDepTime();
}

/**
 Used to change the tick for the simulation program, I decided to implement
 it as an incremental feature where the user can increase or decrease the
 ticktime by 5 minutes, allowing them to skip 60 minutes at a time, or 5 minutes
 at lowest. The switch case is used to ensure proper formatting once printing.
*/
void SimulationProgram::changeTick() {
    bool loop = true;
    while(loop) {
        std::cout << "===== Change tick =====" << std::endl;
        std::cout << "1. Increase interval by 5 (Maximum of 60min)" << std::endl;
        std::cout << "2. Decrease interval by 5 (Minimum of 5min)" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter choice" << std::endl;
        int choice = 0;
        std::cin >> choice;
        while (std::cin.fail() || choice < 0 || choice > 3) {
            std::cout << "Wrong input.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> choice;
        }
        switch (choice) {
            case 1: {
                if (TICK < 60)
                    TICK += 5;
                std::cout << "Tick is now set to: 00:" << + TICK << std::endl;
                break;
            }
            case 2: {
                if (TICK > 5)
                    TICK -= 5;
                if(TICK >10)
                    std::cout << "Tick is now set to: 00:" << + TICK << std::endl;
                else
                    std::cout << "Tick is now set to: 00:0" << + TICK << std::endl;
                break;
            }
            case 0:
            default:
                loop = false;
                break;
        }
    }
}

/**
 Uses the tick to advance the simulation, will check if the current time + the
 tick time will exceed the total simming time, if it does it means it would
 bypass the 23:59 end of simulation time and take necessary actions to make
 sure it ends at precisely 23:59. If it won't exceed the end simming time it will
 simply call the step function from the simulator class and advance the simulation
 by as much time as determined by the aforementioned tick.
*/
void SimulationProgram::advance() {
    if (simulation->getTime() + TICK >SIMMING){
        int tmpTick=0;
        tmpTick = SIMMING - simulation->getTime();
        simulation->step(tmpTick);
    }
    if (simulation->getTime()<SIMMING) {
        simulation->step(TICK);
    }
    else {
        endSimulation();
    }

    int tmpT=0, tmpH=0, tmpM=0;
    tmpT = simulation->getTime();
    while (tmpT >= 60){
        tmpH++;
        tmpT -= 60;
    }
    tmpM = tmpT;
    std::cout<< std::endl << "Current time: "<<  std::setw(2) << std::setfill('0') << tmpH
    <<  ":" <<  std::setw(2) << std::setfill('0') <<tmpM << std::endl;
}

/**
 Prints the end statistics once the program has ended, shows which trains never
 left their departure station, and shows which trains left and arrived on time.
*/
void SimulationProgram::endStats() {
    std::cout << "These trains never left their departure station: " << std::endl;
    for (auto & i : testTrain) {
        i->printIncomplete();
    }
    std::cout << std::endl;
    std::cout << "These trains was dispatched and arrived on time: " << std::endl;
    for (auto & i : testTrain) {
        i->printComplete();
    }
}

/**
 Writes a the string parameter to a file.
*/
void SimulationProgram::writeToFile(const std::string& aString) {
    outFile << aString;
}

/**
 Used to follow a vehicle and see if its either at a station or attached
 to a train, accepts user input between 1 and 741.
*/
void SimulationProgram::followVehicle() {
    std::cout << "Enter ID of the vehicle to track. Vehicle IDs range from 1 to 741." << std::endl;
    int tmpID = 0;
    std::cin >> tmpID;
    while (std::cin.fail() || tmpID < 1 || tmpID > 741) {
        std::cout << "Wrong input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> tmpID;
    }
    for (auto & i : testTrain){
        i->getVehicleID(tmpID);
    }
    for (auto & i : testStation){
        i->getVehicleID(tmpID);
    }
}