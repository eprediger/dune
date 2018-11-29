#include "YAMLReader.h"
#include <CustomException.h>
#include <Codes.h>

YAMLReader::YAMLReader(const char *filename) :
    file(YAML::LoadFile(filename)) {

}

YAMLReader::~YAMLReader() {}

unsigned YAMLReader::getPlayers() {
    return this->file["max_players"].as<unsigned>();
}
