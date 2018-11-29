#ifndef __YAML_READER_H__
#define __YAML_READER_H__

#include <yaml-cpp/yaml.h>

class YAMLReader {
public:
    YAMLReader(const char *filename);
    ~YAMLReader();
    unsigned getPlayers();
private:
    YAML::Node file;
};


#endif  // __YAML_READER_H__
