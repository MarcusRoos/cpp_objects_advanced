//
// Created by Marcus Roos on 2020-10-18.
// Mittuniversitet
// StudentID: Maro1904
//

#include "SimulationProgram.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <memory>

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

void SimulationProgram::run() {
    bool again = true;
    do{
        std::cout << "===== Train Station Program =====" << std::endl;
        std::cout << "1. Change interval [00:" + std::to_string(TICK) +"]" << std::endl;
        std::cout << "2. Run next interval" << std::endl;
        std::cout << "3. Next event" << std::endl;
        std::cout << "4. Finish (Complete simulation)" << std::endl;
        std::cout << "5. Statistics menu" << std::endl;
        std::cout << "6. Print time table for all trains" << std::endl;
        std::cout << "7. Print information for one specific train" << std::endl;
        std::cout << "8. Print one specific station"<< std::endl;
        std::cout << "9. Following vehicle by ID." << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter choice" << std::endl;
        int choice = 0;
        std::cin >> choice;
        while (std::cin.fail() || choice < 0 || choice > 9) {
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
            case 3:
                std::cout << "Next event" <<std::endl;
                break;
            case 4: {
                endStats();
                pauseFunction();
                again = false;
                submenuLoop = false;
                break;
            }
            case 5:
                statisticsMenu();
                break;
            case 6:
                printTimeTable();
                break;
            case 7:
                printSpecificTrain();
                break;
            case 8:
                printSpecificStation();
                break;
            case 9:
                followVehicle();
                break;
        }
    }while(again);
}

void SimulationProgram::runSubMenu() {
    while(submenuLoop) {
        std::cout << "===== Start Menu =====" << std::endl;
        std::cout << "1. Change start time [00:00]" << std::endl;
        std::cout << "2. Change end time [23:59]" << std::endl;
        std::cout << "3. Start simulation" << std::endl;
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
            case 1:
                std::cout << "Change start time" << std::endl;
                break;
            case 2:
                std::cout << "Change end time" << std::endl;
                break;
            case 3:
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
 * Populators, reads in the three files and stores them in their
 * respective class with pointers.**/
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

void SimulationProgram::printStatistics() {
    std::cout << "Number of vehicles at start of simulation:" << std::endl;
    for (auto & k : testStation){
        std::cout << k->getStationname() << " = " ;
        std::cout <<k->getvecSize() << std::endl;
        k->printTypes();
    }
}

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

void SimulationProgram::printTimeTable() {
    for (auto & i : testTrain){
        std::cout << "Train: "<< i->getID()
        << " "<<i->getFromStation() << " --> " << i->getToStation()
        << " | " << i->getDepPrint() << " <---> "
        << i->getArrPrint() << "|" << std::endl;
    }
}

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

void SimulationProgram::scheduleEvents() {
    std::vector<std::shared_ptr<Train>> tmpTrain;
    tmpTrain = testTrain;
    std::sort(tmpTrain.begin(), tmpTrain.end(), sortByName);
    for (auto & i : tmpTrain) {
        int depTime = i->getDepTime() - BUILDTIME;
        int ID = i->getID();
        simulation->scheduleEvent(new BuildTrain(simulation,this,depTime,ID));
    }
}

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

void SimulationProgram::endSimulation() {
    std::cout << "End of simulation" << std::endl;
}

bool SimulationProgram::sortByName(const std::shared_ptr<Train> &a,
                                   const std::shared_ptr<Train> &b) {
    return a->getDepTime() < b->getDepTime();
}

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

void SimulationProgram::writeToFile(const std::string& aString) {
    outFile << aString;
}

void SimulationProgram::followVehicle() {
    std::cout << "Enter ID of the vehicle to track. Vehicle IDs range from 1 to 741." << std::endl;
    int tmpID=0;
    std::cin >> tmpID;
    for (auto & i : testTrain){
        i->getVehicleID(tmpID);
    }
    for (auto & i : testStation){
        i->getVehicleID(tmpID);
    }
}
