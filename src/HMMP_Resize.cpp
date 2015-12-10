#include "HMMP_Resize.h"

HMMP_Resize::HMMP_Resize():
    m_factor(1.0)
{

}

void HMMP_Resize::operator ()(CHeightMap* map, int seed)
{
    int size_x, size_y;

    size_x = std::ceil(map->getSize().x * m_factor);
    size_y = std::ceil(map->getSize().y * m_factor);

    CHeightMap newmap(size_x, size_y);

    for (int x = 0; x < size_x; x++)
    {
        for (int y = 0; y < size_y; y++)
        {
            newmap.setValue(sf::Vector2u(x,y), map->getValue(sf::Vector2f(static_cast<float>(x)/m_factor, static_cast<float>(y)/m_factor)));
        }
    }
    (*map) = newmap;

}
