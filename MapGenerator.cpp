#include "MapGenerator.h"
#include "PerlinNoise.h"

std::vector<double> MapGenerator::generate() {

	std::vector<double> map(101 * 101);

	PerlinNoise noise;
	for (unsigned int i = 0; i < 101; i++)
		for (unsigned int j = 0; j < 101; j++)
			map[(size_t)i * 101 + j] = noise.noise(i * 0.07, j * 0.07, 0.9);
	return map;
}