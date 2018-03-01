#include <iostream>
#include <vector>


#include "map.hh" 


Map parser()
{
    std::string token;
    std::string line;
    bool map_info = false;
    Map map;
    while(std::cin)
    {
        if(map_info == false)
        {
                std::cin >> token;
            //parssing de la premiere ligne 
                map.rows = std::stoi(token);
                std::cin >> token;
                map.column = std::stoi(token);
                std::cin >> token;
                map.vehicules = std::stoi(token);
                std::cin >> token;
                map.rides = std::stoi(token);
                std::cin >> token;
                map.bonus = std::stoi(token);
                std::cin >> token;
                map.steps = std::stoi(token);
                std::cin >> token;
            map_info = true;
        }
        Ride ride;
        ride.start_coord.push_back(std::stoi(token));
                std::cin >> token;
        ride.start_coord.push_back(std::stoi(token));
                std::cin >> token;
        ride.end_coord.push_back(std::stoi(token));
                std::cin >> token;
        ride.end_coord.push_back(std::stoi(token));
                std::cin >> token;
        ride.earliest_start = std::stoi(token);
                std::cin >> token;
        ride.lastest_start = std::stoi(token);
        map.rides_vector.push_back(ride);
        std::cin >> token;
    }
    return map;
}

void Map::print()
{
    std::cout << rows << " rows, " << column << " columns, " << vehicules << " vehicules, " << rides << " rides, " << bonus << " bonus and " << steps << " steps" << std::endl;

    for( auto& i : rides_vector)
    {
        i.print();
    }
}

void Ride::print()
{
    std::cout << "ride from [" << start_coord[0] <<" ,"<<  start_coord[1] << "] to [" <<  end_coord[0] << " ," <<  end_coord[1] << "], earliest start " << earliest_start << ", latest finist " << lastest_start << std::endl;

}
