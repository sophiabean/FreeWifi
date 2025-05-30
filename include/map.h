/*
 * map.h
 */

#ifndef MAP_H_
#define MAP_H_

class Map {
public:
	
	struct single_landmark_s{

		int id_i ; // Landmark ID
		float x_f; // Landmark x-position in the map (global coordinates)
		float y_f; // Landmark y-position in the map (global coordinates)
	};

	std::vector<single_landmark_s> landmark_list ; // List of landmarks in the map
	double min_x; // Minimum possible x position in the map
	double max_x; // Maximum possible x position in the map
	double min_y; // Minimum possible y position in the map
	double max_y; // Maximum possible y position in the map

};



#endif /* MAP_H_ */