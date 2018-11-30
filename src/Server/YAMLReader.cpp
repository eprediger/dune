#include "YAMLReader.h"

YAMLReader::YAMLReader(const char *filename) :
	config(YAML::LoadFile(filename)) {}
