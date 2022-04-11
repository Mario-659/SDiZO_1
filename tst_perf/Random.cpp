#include "Random.h"

std::default_random_engine Random::engine(std::time(0));

int Random::getRandom(int min, int max) {
    std::uniform_int_distribution<int> distr(min, max);
    return distr(engine);
}

int* Random::getRandomArr(int size, int min, int max) {
    int* start = new int[size];
    for(int i=0; i<size; i++){
        start[i] = getRandom(min, max);
    }
    return start;
}

std::vector<int> Random::getRandomVec(int size, int min, int max) {
    std::vector<int> vec;
    for(int i=0; i<size; i++){
        vec.push_back(getRandom(min, max));
    }
    return vec;
}
