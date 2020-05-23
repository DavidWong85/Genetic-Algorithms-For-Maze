#include <random>
#include <chrono>
#include "Random.h"

std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
std::uniform_real_distribution<float> distribution(0.0f, 1.0f);

float Random::setRandom() {
	return distribution(generator);
}