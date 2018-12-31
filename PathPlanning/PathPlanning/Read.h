#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
struct MapData
{
	int rows;
	int cols;
	std::vector<char> map;
	int start;
	int goal;
};
namespace Read
{
	MapData ReadMapFile(std::string);
}

