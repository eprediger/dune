#ifndef __PATH_H__
#define __PATH_H__

#include <string>

#ifdef DEBUG

#define ROOT_PATH "../"
#define ASSETS_PATH ""
#define CONFIG_PATH "config.yaml"

#else
#define ROOT_PATH "/usr/"
#define ASSETS_PATH "var/dune/"
#define CONFIG_PATH "etc/dune/config.yaml"

#endif

class Path {
public:
    static std::string root(std::string path);
    static std::string rootVar(std::string path);
};

#endif //__PATH_H__
