#ifndef __MAP_READER_H__
#define __MAP_READER_H__

#include "YAMLReader.h"

class MapReader : public YAMLReader {
public:
	explicit MapReader(const char* filename);

	~MapReader();

	// Retorna contenido del campo "max_players"
	unsigned getPlayers() const;
};

#endif	// __MAP_READER_H__
