#ifndef HMMP_RESIZE_H
#define HMMP_RESIZE_H

#include <math.h>

#include "HeightMapModificationProcess.h"


// Resizes a given Heightmap
//
class HMMP_Resize : public CHeightmapModificationProcess
{
private:
    double m_factor;

public:
    HMMP_Resize();

    void setFactor(double factor) {
        m_factor = factor;
    }

    double getFactor()
    {
        return m_factor;
    }

    void operator()(CHeightMap* map, int seed);
};

#endif // HMMP_RESIZE_H
