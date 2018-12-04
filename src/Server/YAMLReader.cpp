#include "YAMLReader.h"
#include <string>

YAMLReader::YAMLReader(const std::string filename) :
	config(YAML::LoadFile(filename)) {}
