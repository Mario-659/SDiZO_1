#include "Random.h"

std::default_random_engine Random::engine(std::time(0));

int Random::getRandom(int min, int max) {
    std::uniform_int_distribution<int> distr(min, max);
    return distr(engine);
}

std::vector<int> Random::getRandomVector(int size, int min, int max) {
    std::vector<int> vector(size);
    for (auto i: vector) {
        vector.push_back(getRandom(min, max));
    }
    return vector;
}