#include <fstream>
#include <ctime>
#include "write.hh"


Write::Write(std::vector<Vehicle> v)
    :vehicles_(v)
{}


void Write::compute_res()
{
    std::time_t now = std::time(0);
    char* dt = std::ctime(&now);

    std::string res= "result";
    std::string tmp_r(dt);

    //res += tmp_r;
    
    std::ofstream fichier(res, std::ios::out | std::ios::trunc); 

    if(fichier)  // si l
    {
	for(size_t i = 0; i < vehicles_.size(); ++i)
	{
	    auto tmp = vehicles_[i];
	    if(tmp.done_rides.size() > 0)
	    {
		fichier << tmp.done_rides.size() << " ";
        while(!tmp.done_rides.empty())
		{
            if(tmp.done_rides.size() != 1)
            {
                fichier <<  tmp.done_rides.front() << " ";
                tmp.done_rides.pop();
            }
            else
            {
                fichier << tmp.done_rides.front() << std::endl;
	            tmp.done_rides.pop();
            }
        }
        }
        }
	fichier.close();  // on referme le fichier
    }
    else  // sinon
      std::cerr << "Erreur à l'ouverture !" << std::endl;
}
