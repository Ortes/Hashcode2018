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

    res += tmp_r;
    
    std::ofstream fichier(res, std::ios::out | std::ios::trunc); 

    if(fichier)  // si l
    {
	for(size_t i = 0; i < vehicles_.size(); ++i)
	{
	    auto tmp = vehicles_[i];
	    if(tmp.done_rides.size() > 0)
	    {
		fichier << tmp.done_rides.size() << " ";
		for(auto i = tmp.done_rides.begin(); i != tmp.done_rides.end(); ++i)
		{
		    if(i + 1 == tmp.done_rides.end())
			fichier << *i << std::endl;
		    else
			fichier << *i << " ";
		    
		}
	    }
	}
	fichier.close();  // on referme le fichier
    }
    else  // sinon
      std::cerr << "Erreur à l'ouverture !" << std::endl;
}
