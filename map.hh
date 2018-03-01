
class Ride;

class Map
{
public:
    int rows;
    int column;
    int rides;  // numbert of rides
    int bonus;
    int steps;

    std::vector<Ride>  rides_vector;
     std::vector<Vehicle> vehicles;
};





class Ride
{
public:
    std::vector<int>  start_coord;  // tab [x , y] x ieme ligne  y eme colomn
    std::vector<int>  end_coord;  
    int earliest_start; 
    int lastest_start;
};


class Vehicule
{
public:
  int pos x;
  int pos y;
  std::queue<int> done_rides;
  bool is_riding;
};


Map parser(std::string path);
