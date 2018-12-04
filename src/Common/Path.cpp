#include "Path.h"
#include <string>

std::string Path::root(std::string path) {
#ifdef DEBUG
    std::string root_var_path = "";
#else
    std::string root_var_path = getenv("HOME");
#endif
    root_var_path += ROOT_PATH;
    root_var_path += path;
    return root_var_path;
}

std::string Path::rootVar(std::string path) {
#ifdef DEBUG
    std::string root_var_path = "";
#else
    std::string root_var_path = getenv("HOME");
#endif
    root_var_path += ROOT_PATH;
    root_var_path += ASSETS_PATH;
    root_var_path += path;
    return root_var_path;
}
