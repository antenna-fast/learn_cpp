#include <iostream>

#include "gflags/gflags.h"
#include <glog/logging.h>

// 参数名、缺省值、帮助信息
DEFINE_bool(collect_metrics, false,
            "Activates the collection of runtime metrics. If activated, the "
            "metrics can be accessed via a ROS service.");
DEFINE_string(configuration_directory, "",
              "First directory in which configuration files are searched, "
              "second is always the Cartographer installation to allow "
              "including files from there.");
DEFINE_string(configuration_basename, "",
              "Basename, i.e. not containing any directory prefix, of the "
              "configuration file.");
DEFINE_string(load_state_filename, "",
              "If non-empty, filename of a .pbstream file to load, containing "
              "a saved SLAM state.");
DEFINE_bool(load_frozen_state, true,
            "Load the saved state as frozen (non-optimized) trajectories.");
DEFINE_bool(
    start_trajectory_with_default_topics, true,
    "Enable to immediately start the first trajectory with default topics.");
DEFINE_string(
    save_state_filename, "",
    "If non-empty, serialize state and write it to disk before shutting down.");


using namespace std;

int main(int argc, char** argv) {
    if(argc != 1) {
        std::cout << " argc not match, Usage: " << std::endl;
        return -1;
    }

    google::InitGoogleLogging(argv[0]);
    google::ParseCommandLineFlags(&argc, &argv, true);

    CHECK(!FLAGS_configuration_directory.empty())
        << "-configuration_directory is missing.";
    CHECK(!FLAGS_configuration_basename.empty())
        << "-configuration_basename is missing.";


    std::cout << "running: " << argv[0] << std::endl;
    
    return 0;
}