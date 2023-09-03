#pragma once

#include <iostream>
#include <random>

class RandomGenerator
{
	private:
		std::mt19937_64 random_engine;
	public:
		template<typename value_type>
		value_type generate_random_int(value_type lower_range, value_type higher_range)
		{
			std::uniform_int_distribution<value_type> distribution(lower_range, higher_range);
			return distribution(random_engine);
		}

		template<typename value_type>
		value_type generate_random_real(value_type lower_range, value_type higher_range)
		{
			std::uniform_real_distribution<value_type> distribution(lower_range, higher_range);
			return distribution(random_engine);
		}
};