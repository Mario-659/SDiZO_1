#ifndef ALGORITHMS_RANDOM_H
#define ALGORITHMS_RANDOM_H

#include <algorithm>
#include <random>
#include <ctime>
#include <vector>

class Random {
public:
    static int getRandom(int min, int max);

    static std::vector<int> getRandomVector(int size, int min, int max);

private:
    static std::default_random_engine engine;
};


#endif //ALGORITHMS_RANDOM_H
