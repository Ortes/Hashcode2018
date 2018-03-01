class Map
{
    int rows;
    int column;
    int rides;  // numbert of rides
    int bonus;
    int steps;

    std::vector<Vehicles>  rides_vector;
}





class Vehicule
{
    std::vector<int>  start_coord;  // tab [x , y] x ieme ligne  y eme colomn
    std::vector<int>  end_coord;  
    int earliest_start; 
    int lastest_start;
}
