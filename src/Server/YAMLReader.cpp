#include "YAMLReader.h"

YAMLReader::YAMLReader(const std::string filename) :
	config(YAML::LoadFile(filename)) {}
