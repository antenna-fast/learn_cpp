//
// Created by yaohua on 2022/4/27.
//

#include <iostream>
#include <ctime>

using namespace std;

int main(){

    // time_t now = time(0);
    // cout << "now: " << now << endl;

    // char *dt = ctime(&now);
    // cout << "dt: " << dt << endl;


    struct tm mytm;
	// time_t t;
  	//! caution: day, month, year
	// std::string ts = "19/01/2025 08:00:00";	
	// // strptime("04/02/2024 08:00:00", "%d/%m/%Y %H:%M:%S", &mytm);
	// strptime(ts.c_str(), "%d/%m/%Y %H:%M:%S", &mytm);

    mytm.tm_mday = 19;
    mytm.tm_mon = 1 - 1;
    mytm.tm_year = 2025 - 1900;
    mytm.tm_hour = 8;
    mytm.tm_min = 0;
    mytm.tm_sec = 0;
    mytm.tm_isdst = -1;

    
    std::cout << "mytm day: " << mytm.tm_mday << std::endl;
    std::cout << "mytm mon: " << mytm.tm_mon << std::endl;
    std::cout << "mytm year: " << mytm.tm_year << std::endl;
    std::cout << "mytm hour: " << mytm.tm_hour << std::endl;

	time_t time_last_monday = mktime(&mytm);
	std::cout << "time_last_monday: " << time_last_monday << std::endl;


    return 0;
}