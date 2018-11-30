#ifndef __YAML_READER_H__
#define __YAML_READER_H__

#include <yaml-cpp/yaml.h>

class YAMLReader {
public:
	explicit YAMLReader(const char *filename);

	virtual ~YAMLReader() = default;

protected:
	YAML::Node config;
};

#endif  // __YAML_READER_H__
