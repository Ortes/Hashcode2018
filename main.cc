#include <vector>
#include "map.hh"
#include "write.hh"

void find_ride(Map& map, Vehicle& vehicle, int step)
{
  for (size_t i = 0; i < map.rides_vector.size(); ++i)
    if (!map.rides_vector[i].taken
        && map.rides_vector[i].start_coord[0] - vehicle.x
        + map.rides_vector[i].start_coord[1] - vehicle.y
        < map.rides_vector[i].earliest_start - step)
      vehicle.current_ride = i;
}

int main()
{
  Map map = parser();
  std::vector<Vehicle> vehicles;
  for (size_t j = 0; j < vehicles.size(); ++j)
    find_ride(map, vehicles[j], 0);
  for (int i = 0; i < map.steps; ++i)
  {
    for (size_t j = 0; j < vehicles.size(); ++j)
    {
      if (vehicles[j].was_at_begin)
      {
        if (map.rides_vector[vehicles[j].current_ride].end_coord[0] != vehicles[j].x)
          vehicles[j].x += map.rides_vector[vehicles[j].current_ride].end_coord[0] > vehicles[j].x ? 1 : -1;
      
        if (map.rides_vector[vehicles[j].current_ride].end_coord[1] != vehicles[j].y)
          vehicles[j].y += map.rides_vector[vehicles[j].current_ride].end_coord[1] > vehicles[j].y ? 1 : -1;

        if (map.rides_vector[vehicles[j].current_ride].end_coord[0] == vehicles[j].x
            && map.rides_vector[vehicles[j].current_ride].end_coord[1] == vehicles[j].y)
          find_ride(map, vehicles[j], i);
      }
      else
      {
        if (map.rides_vector[vehicles[j].current_ride].start_coord[0] != vehicles[j].x)
          vehicles[j].x += map.rides_vector[vehicles[j].current_ride].start_coord[0] > vehicles[j].x ? 1 : -1;
      
        if (map.rides_vector[vehicles[j].current_ride].start_coord[1] != vehicles[j].y)
          vehicles[j].y += map.rides_vector[vehicles[j].current_ride].start_coord[1] > vehicles[j].y ? 1 : -1;

        if (map.rides_vector[vehicles[j].current_ride].start_coord[0] == vehicles[j].x
            && map.rides_vector[vehicles[j].current_ride].start_coord[1] == vehicles[j].y)
        {
          vehicles[j].push(vehicles[j].current_ride);
          find_ride(map, vehicles[j], i);
        }
      }
    }
  }
  Write w = Write(vehicles);
  w.compute_res();
  return 0;
}
