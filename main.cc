#include <vector>
#include <iostream>
#include "map.hh"
#include "write.hh"

void find_ride(Map& map, Vehicle& vehicle, int step)
{
  for (size_t i = 0; i < map.rides_vector.size(); ++i)
  {
    if (!map.rides_vector[i].taken
        && map.rides_vector[i].start_coord[0] - vehicle.x
        + map.rides_vector[i].start_coord[1] - vehicle.y
        < map.rides_vector[i].earliest_start - step)
    {
      vehicle.current_ride = i;
      map.rides_vector[i].taken = true;
      if (map.rides_vector[vehicle.current_ride].start_coord[0] == vehicle.x
          && map.rides_vector[vehicle.current_ride].start_coord[1] == vehicle.y)
        vehicle.was_at_begin = true;
    }
  }
}

bool move_to(Map& map, Vehicle& vehicle, std::vector<int>& pos)
{
  if (pos[0] != vehicle.x)
    vehicle.x += pos[0] > vehicle.x ? 1 : -1;
  if (pos[1] != vehicle.y)
    vehicle.y += pos[1] > vehicle.y ? 1 : -1;
  if (pos[0] == vehicle.x && pos[1] == vehicle.y)
    return true;
  return false;
}

int main()
{
  Map map = parser();
  std::vector<Vehicle> vehicles;
  size_t sizeve = map.vehicules;
  for (size_t j = 0; j < sizeve; ++j)
  {
    vehicles.push_back(Vehicle());
    find_ride(map, vehicles[j], 0);
  }
  for (int i = 0; i < map.steps; ++i)
  {
    std::cout << i << "/" << map.steps << std::endl;
    for (size_t j = 0; j < sizeve; ++j)
    {
      if (vehicles[j].was_at_begin)
        if (move_to(map, vehicles[j], map.rides_vector[vehicles[j].current_ride].start_coord))
          find_ride(map, vehicles[j], i);
      else
        if (move_to(map, vehicles[j], map.rides_vector[vehicles[j].current_ride].end_coord))
          find_ride(map, vehicles[j], i);
    }
  }
  Write w = Write(vehicles);
  w.compute_res();
  return 0;
}
