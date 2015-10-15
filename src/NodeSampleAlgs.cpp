#include "NodeSampleAlgs.h"

// Choose the lowest Value of the Vector, creates a pattern simmilar to a river
int minimumElevationSelection(const std::vector<float> &elevations)
{
	if (elevations.size() == 0)
		return -1;

	float min_ele = elevations[0];
	int x = 0;

	for (int i = 1; i < elevations.size(); i++)
	{
		if (min_ele > elevations[i])
		{
			x = i;
			min_ele = elevations[i];
		}
	}

	return x;
}

// Chooses the Elevation with the least Difference from the last selected Elevation, smoothing the road
int leastEleveationDifferenceSelection(const std::vector<float> &elevations, float last)
{
	if (elevations.size() == 0)
		return -1;
	
	float min_diff = abs(last - elevations[0]);
	int x = 0;

	for (int i = 1; i < elevations.size(); i++)
	{
		if (abs(last - elevations[i]) < min_diff)
		{
			x = i;
			min_diff = abs(last - elevations[i]);
		}
	}
	return x;
}

// Selectes the Elevation with the the minimum difference between distance covered and elevation ratio and the goal distance and elevation ration
int evenElevationDifferenceSelection(const std::vector<float> &elevations, float elevation_dest, float distance_dest, float distance_progress)
{
	if (elevations.size() == 0)
		return -1;

	float min = abs(elevations[0] / distance_progress - elevation_dest / distance_dest);
	int x = 0;

	for (int i = 1; i < elevations.size(); i++)
	{
		if (abs(elevations[i] / distance_progress - elevation_dest / distance_dest) < min)
		{
			x = i;
			min = abs(elevations[i] / distance_progress - elevation_dest / distance_dest);
		}
	}
	return x;
}