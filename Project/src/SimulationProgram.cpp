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
void SimulationProgram::run() {
    bool again = true;
    do
    {
        menu.printMenuItems();
        switch(menu.menuChoice())
        {
            case 0:
                again = false;
                break;
            case 1:
                break;
            case 2:
                std::cout << "Run next interval. Current time [00:40 VAR]" <<std::endl;
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

SimulationProgram::SimulationProgram() {
    menu.setTitle("**** Class test menu ****");
    menu.addItem("1. Change interval [00:10]", true);
    menu.addItem("2. Run next interval", true);
    menu.addItem("3. Next event", true);
    menu.addItem("4. Finish (Complete simulation)", true);
    menu.addItem("5. Statistics menu", true);
    menu.addItem("6. Train menu", true);
    menu.addItem("7. Station menu", true);
    menu.addItem("8. Vehicle menu", true);
    menu.addItem("9. Tester.", true);
    menu.addItem("0. Return", true);
    populateStation();
    populateMap();
    populateTrain();
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
        tmpdepartureTime.erase(remove(tmpdepartureTime.begin(), tmpdepartureTime.end(), ':'), tmpdepartureTime.end());
        adepartureTime = std::stoi(tmpdepartureTime);
        ss >> tmparrivalTime;
        tmparrivalTime.erase(remove(tmparrivalTime.begin(), tmparrivalTime.end(), ':'), tmparrivalTime.end());
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
    std::sort(testTrain.begin(), testTrain.end(), sortByName);
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
    for (int i=0; i<testTrain.size(); i++){
        std::cout << "Time " <<testTrain[i]->getDepTime() << std::endl;
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
    tryBuild(2);
    std::vector<int> tmpVec;
    std::string tmpName;
    int tmpPull=9;

    for (int i=0; i<testTrain.size(); i++){
        tmpVec = testTrain[tmpPull]->getLogicalVehicles();
        tmpName = testTrain[tmpPull]->getFromStation();
    }
    std::vector<std::shared_ptr<Vehicle>> tmpVehicle;
    std::cout << "Dedicated to testing functions" << std::endl;
    for (int i=0; i<testStation.size(); i++){
        if (tmpName == testStation[i]->getStationname()){
            std::cout << "Hittade station" << std::endl;
            for (int p=0; p<tmpVec.size(); p++) {
                if (tmpName == testStation[i]->getStationname())
                tmpVehicle.push_back(testStation[i]->outgoingVehicle(tmpVec[p]));
            }
            break;
        }
    }

    for (int i=0; i<testTrain.size(); i++) {
        if (tmpName == testTrain[i]->getFromStation()) {
            testTrain[i]->assembleVehicle(tmpVehicle);
            std::cout << "Deptime: " << testTrain[i]->getDepTime() << std::endl;
            break;
        }
    }

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

}

bool SimulationProgram::tryBuild(int trainId) {
    std::cout << "Try build" << std::endl;
    return false;
}

void SimulationProgram::readyTrain(int trainId) {
    std::cout << "ready train" << std::endl;
}

int SimulationProgram::dispatchTrain(int trainId) {
    std::cout << "dispatch train" << std::endl;
    return 0;
}

void SimulationProgram::arriveTrain(int trainId) {
    std::cout << "Arrive train " << std::endl;
}

void SimulationProgram::stripTrain(int trainId) {
    std::cout << " Strip train" << std::endl;
}

void SimulationProgram::disassembleTrain() {
    std::cout << " Close tracks" << std::endl;
}

bool SimulationProgram::sortByName(const std::shared_ptr<Train> &a,
                                   const std::shared_ptr<Train> &b) {
    return a->getDepTime() < b->getDepTime();
}




