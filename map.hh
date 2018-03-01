#pragma once

#include <vector>
#include <queue>

class Ride;
class Vehicle;


class Map
{
public:
    int rows;
    int column;
    int vehicules;
    int rides;  // numbert of rides
    int bonus;
    int steps;
    void print();
    std::vector<Ride>  rides_vector;
    std::vector<Vehicle> vehicles;
};


class Ride
{
public:
    void print();
    std::vector<int>  start_coord;  // tab [x , y] x ieme ligne  y eme colomn
    std::vector<int>  end_coord;  
    int earliest_start; 
    int lastest_start;
  bool taken = false;
};


class Vehicle
{
public:
  int x = 0;
  int y = 0;
  std::queue<int> done_rides;
  bool was_at_begin = false;
  int current_ride = -1;
};


Map parser();
