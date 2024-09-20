
    std::sort(sub_dirs.begin(), sub_dirs.end(), 
                        [](string a, string b ) 
                        {return atoi(a.substr(a.find_last_of("/")+1).c_str()) < atoi(b.substr(b.find_last_of("/")+1).c_str()) ; } );

