#ifndef MOCK_PERCEPTION_MODULE_
#define MOCK_PERCEPTION_MODULE_

#include <vector>

#include "Point2D.h"
#include "Node.h"
#include "Marker.h"

class MockPerceptionModule
{
public:
	MockPerceptionModule(std::vector<char> actual_map, int row, int col);
	/**
	 * @brief perceive the surroundings of a location, update obstacle info to the map
	 * @param map contains obsacle info of the map
	 * @param location the location to perceive surroudings
	 */
	void PerceiveSurroundings(std::vector<bool> &map, int location);
private: 
	std::vector<char> actual_map_; // the map of the actual world, i.e., the map to explore.
	int row_;  // number of rows
	int col_;  // number of columns

	/**
	 * @brief perceive the location, update obstacle info to the map
	 * @param map contains obsacle info of the map
	 * @param location the location to perceive
	 */
	void PerceiveLocation(std::vector<bool> &map, int location);
};
#endif // !MOCK_PERCEPTION_MODULE_