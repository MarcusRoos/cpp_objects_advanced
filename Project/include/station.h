//
// Created by Marcus Roos on 2020-10-19.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_STATION_H
#define DT060G_STATION_H
#include "vehicle.h"
#include <memory>
#include <vector>
/**
 Class Train

 */
class Station {
protected:
    std::string stationName;
    std::vector<std::unique_ptr<Vehicle>> stationVehicles;
public:
    Station();
    virtual ~Station() = default;;
    virtual std::string getStationname(){return stationName;}
};

class GrandCentral : public Station{
protected:

public:
    GrandCentral();
};

class LiegeGuillemins : public Station{
protected:

public:
    LiegeGuillemins();
};

class STPancras : public Station{
protected:

public:
    STPancras();
};

class Dunedin : public Station{
protected:

public:
    Dunedin();
};

class MilanoCentrale : public Station{
protected:

public:
    MilanoCentrale();
};

class Luz : public Station{
protected:

public:
    Luz();
};

class Shinjuku : public Station{
protected:

public:
    Shinjuku();
};

class Hauptbahnhof : public Station{
protected:

public:
    Hauptbahnhof();
};
#endif //DT060G_STATION_H
