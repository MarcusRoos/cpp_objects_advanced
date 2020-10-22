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
            case 1:
                break;
            case 2:
                break;
            case 3:
                populateTrain();
                break;
            case 4:
                populateMap();
                break;
            case 5:
                std::cout << "Boop 5" << std::endl;
                break;
            case 6:
                break;
            case 7:
                printVehicleStart();
                break;
            case 8:
                again = false;
                break;
        }
    }while(again);
}

SimulationProgram::SimulationProgram() {
    menu.setTitle("**** Class test menu ****");
    menu.addItem("---", true);
    menu.addItem("---", true);
    menu.addItem("---", true);
    menu.addItem("---", true);
    menu.addItem("---", true);
    menu.addItem("---", true);
    menu.addItem("Test loaded files, for now.", true);
    menu.addItem("Exit", true);
    populateStation();
    populateMap();
    populateTrain();
}

void SimulationProgram::runSubMenu() {
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
    if (choice == 0){
        choice = 4;
    }
    switch (choice) {
        case 1:
            run();
            break;
        case 2:
            run();
            break;
        case 3:
            run();
            break;
        case 4:
        default:
            break;
    }
}

void SimulationProgram::printVehicleStart() {
    std::cout << "Number of vehicles at start of simulation:" << std::endl;
    for (int k=0; k<testStation.size(); k++){
        testStation[k]->printStation();
        std::cout << testStation[k]->getStationname() << " = " ;
        std::cout <<testStation[k]->getvecSize() << std::endl;
    }
    for (int k=0; k<testTrain.size(); k++){
        testTrain[k]->trainTester();
    }
    for (int k=0; k<testMap.size(); k++){
        testMap[k]->printMap();
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
    int tmpID=0, tmpInt=0;
    std::string afromStation, atoStation, adepartureTime, aarrivalTime;
    double amaxSpeed;
    for (int i=0; i<tmpTrain.size(); i++) {
        std::stringstream ss;
        ss << tmpTrain[i];
        ss >> tmpID;
        ss >> afromStation;
        ss >> atoStation;
        ss >> adepartureTime;
        ss >> aarrivalTime;
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

