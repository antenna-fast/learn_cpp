#include <iostream>
#include <bits/types.h>


using namespace std;

int main(int argc, char** argv)
{
    std::cout << "running: " << argv[0] << std::endl;

	struct tm mytm;

  	//! caution: day, month, year
	// strptime("09/06/2024 08:00:00","%d/%m/%Y %H:%M:%S",&mytm);

	strptime("09/06/2024 08:00:00","%d/%m/%Y %H:%M:%S",&mytm);

	time_t time_last_monday = mktime(&mytm);
	std::cout << "time: " << time_last_monday << std::endl;

    // while (1)
    {
        // timeval start;
        // cout << "start.tv_sec: " << start.tv_sec << endl;
   
    }    

    return 0;
}