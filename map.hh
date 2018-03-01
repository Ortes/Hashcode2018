 #include <vector>
#include <queue>


class Ride;
class Vehicule;


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
    std::vector<Vehicule> vehicles;
};





class Ride
{
public:
    void print();
    std::vector<int>  start_coord;  // tab [x , y] x ieme ligne  y eme colomn
    std::vector<int>  end_coord;  
    int earliest_start; 
    int lastest_start;
};


class Vehicule
{
public:
  int pos_x;
  int pos_y;
  std::queue<int> done_rides;
  bool is_riding;
};


Map parser();
