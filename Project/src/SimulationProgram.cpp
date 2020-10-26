//
// Created by Marcus Roos on 2020-10-18.
// Mittuniversitet
// StudentID: Maro1904
//

#include "SimulationProgram.h"
#include <iostream>
#include <iomanip>
#include <limits>

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
    populateStation();
    populateMap();
    populateTrain();
    scheduleEvents();
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
        std::cout << "6. Train menu" << std::endl;
        std::cout << "7. Station menu" << std::endl;
        std::cout << "8. Vehicle menu"<< std::endl;
        std::cout << "9. Tester." << std::endl;
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
        switch(choice)
        {
            case 0:
                again = false;
                break;
            case 1:
                changeTick();
                break;
            case 2:
                simulation->step(TICK);
                break;
            case 3:
                std::cout << "Next event" <<std::endl;
                break;
            case 4:
                std::cout << "Finish/Complete simulation" <<std::endl;
                break;
            case 5:
                std::cout << "Change log level" <<std::endl;
                statisticsMenu();
                break;
            case 6:
                trainMenu();
                break;
            case 7:
                stationMenu();
                break;
            case 8:
                vehicleMenu();
                break;
            case 9:
                testMenu();
                break;
        }
    }while(again);
}

void SimulationProgram::runSubMenu() {
    bool loop = true;
    while(loop) {
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
                loop = false;
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
    for (int i=0; i<tmpStat.size(); i++) {
        std::stringstream ss;
        char delim;
        std::string stationName;
        int tmpID = 0, tmpType = 6, param1 = 0, param2 = 0, choice;
        ss << tmpStat[i];
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
        testStation.push_back(std::shared_ptr<Station>(
                new Station(stationName, std::move(testVehicle))));
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
    for (int i=0; i<tmpMap.size(); i++) {
        std::stringstream ss;
        ss << tmpMap[i];
        ss >> tmpDep;
        ss >> tmpDest;
        ss >> tmpDist;
        testMap.push_back(std::shared_ptr<Map>(
                new Map(tmpDep, tmpDest, tmpDist)));
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
    for (int i=0; i<tmpTrain.size(); i++) {
        std::stringstream ss;
        ss << tmpTrain[i];
        ss >> tmpID;
        ss >> afromStation;
        ss >> atoStation;
        ss >> tmpdepartureTime;
        tmpdepartureTime.erase(remove(tmpdepartureTime.begin(),
                tmpdepartureTime.end(), ':'), tmpdepartureTime.end());
        adepartureTime = std::stoi(tmpdepartureTime);
        ss >> tmparrivalTime;
        tmparrivalTime.erase(remove(tmparrivalTime.begin(),
                tmparrivalTime.end(), ':'), tmparrivalTime.end());
        aarrivalTime = std::stoi(tmparrivalTime);
        ss >> amaxSpeed;
        while (ss >> tmpInt){
            if (ss.peek() == '\n')
                break;
            else
                amountVehicles.push_back(tmpInt);
        }
        testTrain.push_back(std::shared_ptr<Train>(
                new Train(tmpID, afromStation, atoStation, adepartureTime, aarrivalTime, amaxSpeed, amountVehicles)));
        amountVehicles.clear();
    }
}



void SimulationProgram::runLogmenu() {
    bool loop=true;
    while (loop) {
        std::cout << "===== Log level menu =====" << std::endl;
        std::cout << "1. Low log level" << std::endl;
        std::cout << "2. High log level" << std::endl;
        std::cout << "0. Return" << std::endl;
        std::cout << "Enter choice" << std::endl;
        int choice = 0;
        std::cin >> choice;
        while (std::cin.fail() || choice < 0 || choice > 2) {
            std::cout << "Wrong input.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> choice;
        }
        switch (choice) {
            case 1:
                std::cout << "Low log level" << std::endl;
                break;
            case 2:
                std::cout << "High log level" << std::endl;
                break;
            case 0:
            default:
                loop = false;
                break;
        }
    }
}

void SimulationProgram::printStatistics() {
    std::cout << "Number of vehicles at start of simulation:" << std::endl;
    for (int k=0; k<testStation.size(); k++){
        std::cout << testStation[k]->getStationname() << " = " ;
        std::cout <<testStation[k]->getvecSize() << std::endl;
    }
    for (int k=0; k<testTrain.size(); k++){
        std::cout << testTrain[k]->getDepTime() << std::endl;
        std::cout << "State: " << testTrain[k]->getState() <<std::endl;
    }
}

void SimulationProgram::statisticsMenu() {
    bool loop=true;
    while (loop) {
        std::cout << "===== Log level menu =====" << std::endl;
        std::cout << "1. Change log level [low VAR]" << std::endl;
        std::cout << "2. Print statistics" << std::endl;
        std::cout << "3. Train menu" << std::endl;
        std::cout << "4. Station menu" << std::endl;
        std::cout << "5. Vehicle menu" << std::endl;
        std::cout << "0. Return" << std::endl;
        std::cout << "Enter choice" << std::endl;
        int choice = 0;
        std::cin >> choice;
        while (std::cin.fail() || choice < 0 || choice > 5) {
            std::cout << "Wrong input.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> choice;
        }
        switch (choice) {
            case 1:
                std::cout << "Low log level" << std::endl;
                runLogmenu();
                break;
            case 2: {
                std::cout << "Print statistics" << std::endl;
                printStatistics();
                break;
            }
            case 3:
                trainMenu();
                break;
            case 4:
                stationMenu();
                break;
            case 5:
                vehicleMenu();
                break;
            case 0:
            default:
                loop = false;
                break;
        }
    }
}

void SimulationProgram::trainMenu() {
    bool loop = true;
    while (loop) {
        std::cout << "===== Train menu =====" << std::endl;
        std::cout << "1. Search train by number" << std::endl;
        std::cout << "2. Search train by vehicle id" << std::endl;
        std::cout << "3. Change log level [low VAR]" << std::endl;
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
        if (choice == 0) {
            choice = 4;
        }
        switch (choice) {
            case 1:

                break;
            case 2:

                break;
            case 3:
                runLogmenu();
                break;
            case 0:
            default:
                loop = false;
                break;
        }
    }
}

void SimulationProgram::stationMenu() {
    bool loop = true;
    while (loop) {
        std::cout << "===== Station menu =====" << std::endl;
        std::cout << "1. Show station names" << std::endl;
        std::cout << "2. Show station by name" << std::endl;
        std::cout << "3. Change log level [low VAR]" << std::endl;
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
                for (int i=0; i<testStation.size(); i++)
                std::cout << testStation[i]->getStationname() << std::endl;
                break;
            case 2:

                break;
            case 3:
                runLogmenu();
                break;
            case 0:
            default:
                loop = false;
                break;
        }
    }
}

void SimulationProgram::vehicleMenu() {
    bool loop = true;
    while (loop) {
        std::cout << "===== Vehicle menu =====" << std::endl;
        std::cout << "1. Show vehicle by id" << std::endl;
        std::cout << "2. Change log level [low VAR]" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter choice" << std::endl;
        int choice = 0;
        std::cin >> choice;
        while (std::cin.fail() || choice < 0 || choice > 2) {
            std::cout << "Wrong input.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> choice;
        }
        switch (choice) {
            case 1:
                break;
            case 2:
                runLogmenu();
                break;
            case 0:
            default:
                loop = false;
                break;
        }
    }
}

void SimulationProgram::testMenu() {
    std::cout << "Dedicated to testing functions" << std::endl;

    tryBuild(5);

    /*
    std::vector<int> tmpVec;
    std::string tmpFrom, tmpTo;
    int tmpPull=9;

    for (int i=0; i<testTrain.size(); i++){
        tmpVec = testTrain[tmpPull]->getLogicalVehicles();
        tmpFrom = testTrain[tmpPull]->getFromStation();
        tmpTo = testTrain[tmpPull]->getToStation();
    }
    std::vector<std::shared_ptr<Vehicle>> tmpVehicle;


    for (int i=0; i<testStation.size(); i++){
        if (tmpFrom == testStation[i]->getStationname()){
            std::cout << "Hittade station" << std::endl;
            for (int p=0; p<tmpVec.size(); p++) {
                if (tmpFrom == testStation[i]->getStationname())
                tmpVehicle.push_back(testStation[i]->outgoingVehicle(tmpVec[p]));
            }
            break;
        }
    }

    for (int i=0; i<testTrain.size(); i++) {
        if (tmpFrom == testTrain[i]->getFromStation() && tmpTo == testTrain[i]->getToStation()) {
            testTrain[i]->assembleVehicle(tmpVehicle);
            std::cout << "Deptime: " << testTrain[i]->getDepTime() << std::endl;
            std::cout << "FROM: " << testTrain[i]->getFromStation() << std::endl;
            std::cout << "TO: " << testTrain[i]->getToStation() << std::endl;
            std::cout << "ID: " << testTrain[i]->getID() << std::endl;
            break;
        }
    }
     */
}

/**
  bool pusher=true;
    for (int i=0; i<testTrain.size(); i++) {
        if (pusher) {
            std::cout << "In the end: " << std::endl;
            testTrain[i]->MegaTest();
            pusher = false;
        }
    }

    */

void SimulationProgram::scheduleEvents() {
    std::vector<std::shared_ptr<Train>> tmpTrain;
    tmpTrain = testTrain;
    std::sort(tmpTrain.begin(), tmpTrain.end(), sortByName);
    for (int i=0; i<tmpTrain.size(); i++) {
        int depTime = tmpTrain[i]->getDepTime() - BUILDTIME;
        int ID = tmpTrain[i]->getID();
        simulation->scheduleEvent(new BuildTrain(simulation,this,depTime,ID));
    }
}

bool SimulationProgram::tryBuild(int trainId) {
    int tmpIdx=0;
    std::shared_ptr<Train> tmpTrain;
    for (int i=0; i<testTrain.size(); i++){
        if (trainId == testTrain[i]->getID()){
            tmpTrain = testTrain[i];
            tmpIdx = i;
            break;
        }
    }

    if (tmpTrain && tmpTrain->assembleVehicle(testStation)){
        std::cout << "Started building train ID " << trainId << " at station "
        << testTrain[tmpIdx]->getFromStation() << " with destination to "
        << testTrain[tmpIdx]->getToStation() << std::endl;

        tmpTrain->setState(ASSEMBLED);
        return true;
    }
    else {
        std::cout << " Train " << trainId << " couldn't be built at station "
                  << testTrain[tmpIdx]->getFromStation() << std::endl;

        testTrain[tmpIdx]->delay(DELAYTIME);
        tmpTrain->setState(INCOMPLETE);
        if (!tmpTrain->getDelayed()) {
            tmpTrain->setDelayed(true);
        }
        std::cout << "trainID: " << trainId << std::endl;
        return false;
    }
}

void SimulationProgram::EndTrain(int trainId) {
    std::cout << "Trying to disassemble... " << trainId <<"....."<< std::endl;
    std::shared_ptr<Train> tmpTrain;
    for (int i=0; i<testTrain.size(); i++){
        if (trainId == testTrain[i]->getID()){
            tmpTrain = testTrain[i];
            break;
        }
    }
    int tmpInt = tmpTrain->getsizeVehicle();
    tmpTrain->disassembleTrain(testStation);
    tmpTrain->setState(FINISHED);
    std::cout << "Unloaded " << tmpInt
              << " vehicles from train " << tmpTrain->getID() << " at station " <<
              tmpTrain->getToStation() << std::endl;
}

void SimulationProgram::readyTrain(int trainId) {
    std::shared_ptr<Train> tmpTrain;
    for (int i=0; i<testTrain.size(); i++){
        if (trainId == testTrain[i]->getID()){
            tmpTrain = testTrain[i];
            break;
        }
    }
    tmpTrain->setState(READY);
    std::cout << "Train " << trainId << " is ready for departure from " <<
    tmpTrain->getFromStation() << " to " << tmpTrain->getToStation() << std::endl;
}

int SimulationProgram::dispatchTrain(int trainId) {
    std::shared_ptr<Train> tmpTrain;
    for (int i=0; i<testTrain.size(); i++){
        if (trainId == testTrain[i]->getID()){
            tmpTrain = testTrain[i];
            break;
        }
    }
    int tmpLate = simulation->getTime();
    tmpTrain->setState(RUNNING);
    if(tmpTrain->getDelayed()) {
        tmpLate -= tmpTrain->getDepTime();
    }
    std::cout << "Train " << trainId
    << " left from station " << tmpTrain->getFromStation() << std::endl;
    if (tmpTrain->getDelayed())
        std::cout <<  "The train departed " << tmpLate << " minutes too late."
        << std::endl;
    else {
        std::cout << "Train " << trainId
                  << " left on time from station " << tmpTrain->getFromStation()
                  << " and will be arriving at " << tmpTrain->getToStation() <<
                  " on time. " << std::endl;
    }
    return tmpTrain->getArrTime();
}

void SimulationProgram::arriveTrain(int trainId) {
    std::shared_ptr<Train> tmpTrain;
    for (int i=0; i<testTrain.size(); i++){
        if (trainId == testTrain[i]->getID()){
            tmpTrain = testTrain[i];
            break;
        }
    }
    tmpTrain->setState(ARRIVED);
    std::cout << "Train " << tmpTrain->getID() << " from station " <<
    tmpTrain->getFromStation() << " has arrived at " <<
    tmpTrain->getToStation() << std::endl;
    if (tmpTrain->getDelayed()){
        int lateMins = tmpTrain->getArrTime() - tmpTrain->getTmpArrTime();
        amountDelayed++;
        totalDelay += lateMins;
        std::cout  << " But it arrived " << lateMins << " minutes behind schedule";
    }
    else
        amountSuccess++;
}

void SimulationProgram::endSimulation() {
    std::cout << "End" << std::endl;
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




