#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "map.hh"


class Write
{
public:
    Write(std::vector<Vehicle> v);

    void compute_res();
    
private:

    std::vector<Vehicle> vehicles_;
    
};
