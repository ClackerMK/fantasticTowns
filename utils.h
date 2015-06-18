#pragma once

#include <random>
#include <math.h>
#include <SFML\System.hpp>

namespace util{
	template<typename T>
	using range = std::pair<T, T>;


	sf::Vector2i getRandomVector2i (range<int> range_x, range<int> range_y, std::mt19937& rand);
	sf::Vector2f getRandomVector2f (range<float> range_x, range<float> range_y, std::mt19937& rand);

	template<typename T>
	float		getDistanceSqr(sf::Vector2<T> vec1, sf::Vector2<T> vec2);

	template<typename T>
	float		getDistance(sf::Vector2<T> vec1, sf::Vector2<T> vec2);

	template <typename T>
	float getDistanceSqr(sf::Vector2<T> vec1, sf::Vector2<T> vec2)
	{
		return (vec1.x - vec2.x) + (vec1.y - vec2.y);
	}

	template <typename T>
	float getDistance(sf::Vector2<T> vec1, sf::Vector2<T> vec2)
	{
		return std::sqrt(getDistanceSqr(vec1, vec2));
	}

}
