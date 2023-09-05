#include "Math.h"

float Math::RandomFloat(float min, float max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0, 1);
    return dist(gen);
}

void Math::srandStart() {
	srand((unsigned)time(NULL));
}