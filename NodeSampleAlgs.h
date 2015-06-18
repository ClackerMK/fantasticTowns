#pragma once

#include <vector>
#include <math.h>

using std::abs;

enum SAMPLE_MODE {
	MINIMUM_ELEVATION,
	MINIMUM_ELEVATION_DIFF,
	EVEN_ELEVATION_DIFF
};

// Choose the lowest Value of the Vector, creates a pattern simmilar to a river
int minimumElevationSelection(const std::vector<float> &elevations);

// Chooses the Elevation with the least Difference from the last selected Elevation, smoothing the road
int leastEleveationDifferenceSelection(const std::vector<float> &elevations, float last);

// Selectes the Elevation with the the minimum difference between distance covered and elevation ratio and the goal distance and elevation ration
int evenElevationDifferenceSelection(const std::vector<float> &elevations, float elevation_dest, float distance_dest, float distance_progress);
