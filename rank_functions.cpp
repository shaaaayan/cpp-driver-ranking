#include <iostream>
#include <iomanip>
#include <vector>
#include "rank_functions.h"

using std::cin, std::cout, std::endl, std::string, std::vector;

//-------------------------------------------------------
// Name: load_driver_data
// PostCondition: returned vector contains data gotten from standard in and rank initialized to 0
//---------------------------------------------------------
std::vector<driver> load_driver_data() {
    std::vector<driver> drivers;

    for (int i = 0; i < 9; ++i) {
        driver d;
        if (!(cin >> d.time >> d.country >> d.number)) return {};

        std::string full_name;
        std::getline(cin, full_name);
        d.lastname = trim(full_name);

        if (d.time <= 0) return {};
        if (d.country.size() != 3) return {};
        for (char c : d.country) if (!isupper(c)) return {};
        if (d.number > 99) return {};
        if (d.lastname.length() < 2) return {};
        for (char c : d.lastname)
            if (!isalpha(c) && !isspace(c)) return {};

        d.rank = 0;
        drivers.push_back(d);
    }

    return drivers;

}

//-------------------------------------------------------
// Name: set_rankings
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places sets the ranks. That updated vector is returned
//---------------------------------------------------------
std::vector<driver> set_rankings(std::vector<driver> v) {
    for (unsigned int rank = 1; rank <= v.size(); ++rank) {
        double best_time = 1e9;
        int best_index = -1;
        for (unsigned int i = 0; i < v.size(); ++i) {
            if (v[i].rank == 0 && v[i].time < best_time) {
                best_time = v[i].time;
                best_index = i;
            }
        }
        if (best_index != -1) {
            v[best_index].rank = rank;
        }
    }
    return v;

}

std::string trim(std::string s){
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end = s.find_last_not_of(" \t\n\r");
    if (start == std::string::npos) return "";
    return s.substr(start, end - start + 1);
}

//-------------------------------------------------------
// Name: print_results
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays then along with a delta in time from the start
//---------------------------------------------------------
void print_results(std::vector<driver> v)
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= v.size(); j++)
	{
		
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < v.size(); i++)
		{
			if(v.at(i).rank == 1) // has to be a better way, but need the starting time
			{
				best_time = v.at(i).time;
			}
			
			
			if(v.at(i).rank == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << v.at(i).time << " " << std::setw(15) << std::left << v.at(i).lastname << "\t" << "(" << v.at(i).country << ")  +" << (v.at(i).time - best_time) << std::endl; 
			}
			
		}
	}	
}