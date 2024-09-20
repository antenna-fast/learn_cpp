#include <iostream>
#include <string>
#include <vector>

#include <boost/filesystem.hpp>


using namespace std;
namespace fs = boost::filesystem;


int get_filenames(const std::string& dir, std::vector<std::string>& filenames)
{
	fs::path path(dir);
	if (!fs::exists(path))
	{
		return -1;
	}
 
	fs::directory_iterator end_iter;
	for (fs::directory_iterator iter(path); iter!=end_iter; ++iter)
	{
		if (fs::is_regular_file(iter->status()))
		{
			filenames.push_back(iter->path().string());
		}
 
		// if (fs::is_directory(iter->status()))
		// {
		// 	get_filenames(iter->path().string(), filenames);
		// }
	}
 
	return filenames.size();
}


int main()
{
	// string folder_path = "/home/antenna/ssd/TongZhou/0919/images";
	string folder_path = "/home/antenna/ssd/TongZhou/0919";

	std::vector<std::string> file_list;
	get_filenames(folder_path, file_list);

	for (size_t i = 0; i < file_list.size(); i++)
	{
		cout << file_list.at(i) << endl;
	}
	
}