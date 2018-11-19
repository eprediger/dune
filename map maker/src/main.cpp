#include "yaml-cpp/yaml.h"
#include <iostream>
#include <vector>
#include <fstream>

int main(int argc, char*argv[]){
    YAML::Node node = YAML::LoadFile(argv[1]);
    int width = 64;
    int height = 64;
    int init_spice = 200;

   
    char sand ='A';
    char rock = 'R';
    char summit = 'M';
    char dune = 'D';
    char precipice = 'P';
    char spice = 'S';

    int max_players = 4;


    node["max_players"] = max_players;


    node["width"] = width;
    node["height"] = height;
    node["INITIAL_SPICE"] = init_spice;
    node["SAND_KEY"] = sand;
    node["ROCK_KEY"] = rock;
    node["SUMMIT_KEY"] = summit;
    node["DUNE_KEY"] = dune;
    node["PRECIPICE_KEY"] = precipice;
    node["SPICED_SAND_KEY"] = spice;

    std::vector<int> pos0;
    pos0.push_back(8);pos0.push_back(8);

    std::vector<int> pos1;
    pos1.push_back(56);pos1.push_back(56);
    
    std::vector<int> pos2;
    pos2.push_back(8);pos2.push_back(56);    

    std::vector<int> pos3;
    pos3.push_back(56);pos3.push_back(8);
    
    node["initial_positions"][0] = pos0;
    node["initial_positions"][1] = pos1;
    node["initial_positions"][2] = pos2;
    node["initial_positions"][3] = pos3;


    for (int i = 0; i<(height/4); i++){
	std::vector<char> vector;
	for (int j = 0; j<width ; j++){
		vector.emplace_back(rock);
	}
	node["rows"][i] = vector;
    }
    for (int i = height/4; i<(height/4)*3; i++){
        std::vector<char> vector;
        for (int j = 0; j<width/4 ; j++){
            vector.emplace_back(rock);
        }
	for (int j = width/4; j<(width/4)*2;j++){
	    vector.emplace_back(spice);
	}
	for (int j = (width/4)*2 ; j<(width/4*3) ; j++){
		vector.emplace_back(sand);
	}
	for (int j = (width/4)*3; j<width;j++){
	    vector.emplace_back(rock);
	}
        node["rows"][i] = vector;
    }

   for (int i = (height/4)*3 ; i<height ; i++){
	std::vector<char> vector;
	for (int j = 0; j<width ; j++){
		vector.emplace_back(rock);
	}
	node["rows"][i] = vector;
   }
    std::ofstream fout("fileUpdate.yaml"); 
    fout << node;
}
