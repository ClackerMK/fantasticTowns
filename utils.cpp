#include "utils.h"

sf::Vector2i util::getRandomVector2i(range<int> range_x, range<int> range_y, std::mt19937& rand)
{
	sf::Vector2i op;
	op.x = std::uniform_int_distribution<>(range_x.first, range_x.second)(rand);
	op.y = std::uniform_int_distribution<>(range_y.first, range_y.second)(rand);
	return op;
}

sf::Vector2f util::getRandomVector2f(range<float> range_x, range<float> range_y, std::mt19937& rand)
{
	sf::Vector2f op;
	op.x = std::uniform_real_distribution<>(range_x.first, range_x.second)(rand);
	op.y = std::uniform_real_distribution<>(range_y.first, range_y.second)(rand);
	return op;
}