//
// Created by Marcus Roos on 2020-10-18.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_TRAIN_H
#define DT060G_TRAIN_H
#include <string>
#include <memory>
#include <vector>
#include "vehicle.h"
#include "constants.h"
#include "station.h"
#include <list>
#include <iostream>
#include <algorithm>
/**
 Class Train
 This class will handle all information regarding trains, it will store the
 relevant information regarding trains as indicated by the private data members.
 It contains several functions to help the assembly and disassemly of trains
 and their corresponding vehicles, it also contains several functions for
 printing and different return values.
 */
class Train {
protected:
    // Private data members
    enum State state;
    int trainId, departureTime, arrivalTime, tmpArrivalTime;
    std::string fromStation, toStation, arrPrint, depPrint;
    double maxSpeed;
    bool delayed;
    std::vector<int> logicalVehicles;
    std::vector<std::shared_ptr<Vehicle>> trainVehicles;
    std::shared_ptr<Station> from, to;
public:
    /**
* Default constructor
*
* @param None
* @return None.
*/
    Train();
    /**
* Default Destructor
*
* @param None
* @return None.
*/
    ~Train() = default;
    /**
* Initializing constructor, uses the multiple parameters to initialize a train
     * object.
*
* @param Int, String, String, Int, Int, Double, Vector, String, String
* @return None.
*/
    Train(int aID, std::string aFrom, std::string aTo, int aDtime, int aAtime, double aSpeed, std::vector<int> aLogicalVehicles, std::string printD, std::string printA);
    /**
* Function to assemble vehicles and attach them to a train
*
* @param vector of pointers to station
* @return Bool.
*/
    bool assembleVehicle(const std::vector<std::shared_ptr<Station>>& aStation);
    /**
* Function to disassemble vehicles and de attach them from a train
*
* @param vector of pointers to station
* @return Bool.
*/
    void disassembleTrain(const std::vector<std::shared_ptr<Station>>& aStation);
    /**
* Returns ID of the train
*
* @param None.
* @return Integer.
*/
    int getID();
    /**
* Returns trains depart station
*
* @param None.
* @return String.
*/
    std::string getFromStation();
    /**
* Returns trains arrival station
*
* @param None.
* @return String.
*/
    std::string getToStation();
    /**
* Returns trains arrival station station in form of a string
*
* @param None.
* @return String.
*/
    std::string getArrPrint();
    /**
* Returns trains departure station station in form of a string
*
* @param None.
* @return String.
*/
    std::string getDepPrint();
    /**
* Returns state of the train as a string
*
* @param None.
* @return String.
*/
    std::string getState(State);
    /**
* Returns trains departure time in form of an integer
*
* @param None.
* @return Integer.
*/
    int getDepTime();
    /**
* Returns trains arrival time in form of an integer
*
* @param None.
* @return Integer.
*/
    int getArrTime();
    /**
* Returns trains arrival time in form of an integer, temporary arrival time to
     * calculate delay
*
* @param None.
* @return Integer.
*/
    int getTmpArrTime();
    /**
* Returns trains state as type state
*
* @param None.
* @return State.
*/
    enum State getState();
    /**
* Sets the state of the train
*
* @param State.
* @return None.
*/
    void setState( State aState ){state = aState;}
    /**
* Calculates delay for vehicle
*
* @param Integer.
* @return None.
*/
    void delay(int time){arrivalTime+=time;departureTime+=time;}
    /**
* Sets a trains status to delayed, indicating that is in indeed delayed
*
* @param Bool.
* @return None.
*/
    void setDelayed(bool nDelayed){delayed = nDelayed;}
    /**
* Returns maxspeed of the train
*
* @param None.
* @return Double.
*/
    double getSpeed();
    /**
* Returns whether train is delayed or not
*
* @param None.
* @return Bool.
*/
    bool getDelayed();
    /**
* Prints data for the train and its types
*
* @param None.
* @return None.
*/
    void printTypes();
    /**
* Prints all trains which never left their station
*
* @param None.
* @return None.
*/
    void printIncomplete();
    /**
* Prints all trains which left their station
*
* @param None.
* @return None.
*/
    void printComplete();
    /**
* Returns the ID of a vehicle to keep track of which train it is attached to
*
* @param Unsigned integer.
* @return Bool.
*/
    bool getVehicleID(unsigned int aID);
    /**
* Prints which station the train is currently at
*
* @param String.
* @return None.
*/
    void printAtStation(const std::string& tmpStat);
};

#endif //DT060G_TRAIN_H
