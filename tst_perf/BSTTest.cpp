#include "BSTTest.h"

using namespace std::chrono;

void BSTTest::testBSTPush() {
    std::string filename = "BSTPush_1000.csv";

    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;

    std::ofstream file;
    file.open(filename);

    std::vector<double> times;

    std::vector<int> sampleSizes;
    for(int i=50000; i<1000001; i+=50000) sampleSizes.push_back(i);
    for(auto sampleSize: sampleSizes){
        double time = 0.0;

        for(int j=0; j<100; j++) {
            // Generate random sample
            std::vector<int> sample = Random::getRandomVec(sampleSize, -1000, 1000);
            auto array = new BST();
            for (int k = 0; k < sampleSize; k++) {
                array->push(sample[k]);
            }
            // Generate random values to push
            std::vector<int> randNums = Random::getRandomVec(1000, -1000, 1000);

            // Start timer
            t1 = high_resolution_clock::now();
            // Push 100 new elements
            for (int k = 0; k < randNums.size(); k++) {
                array->push(randNums[k]);
            }
            // Stop timer
            t2 = high_resolution_clock::now();
            duration<double> timeElapsed = duration_cast<duration<double>>(t2 - t1);
            // Add time
            time += timeElapsed.count();
        }

        double avgTime = time / 100;
        file<<sampleSize<<","<< avgTime <<std::endl;
        std::cout << "sample: " << sampleSize << "done" << std::endl;
    }
    file.close();
}

void BSTTest::testBSTFindRandom() {
    std::string filename = "BSTFind_1000.csv";

    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;

    std::ofstream file;
    file.open(filename);

    std::vector<double> times;
    std::vector<int> sampleSizes;
    for(int i=700000; i<1000001; i+=50000) sampleSizes.push_back(i);
    for(auto sampleSize: sampleSizes){
        double time = 0.0;

        for(int j=0; j<100; j++) {
            // Generate random sample
            std::vector<int> sample = Random::getRandomVec(sampleSize, -1000, 1000);
            auto array = new BST();
            for (int k = 0; k < sampleSize; k++) {
                array->push(sample[k]);
            }
            // Generate random values to push
            std::vector<int> randInd = Random::getRandomVec(1000, 0, sampleSize-1);

            // Start timer
            t1 = high_resolution_clock::now();
            // Push 100 new elements
            for (int k = 0; k < randInd.size(); k++) {
                array->contains(sample[randInd[k]]);
            }
            // Stop timer
            t2 = high_resolution_clock::now();
            duration<double> timeElapsed = duration_cast<duration<double>>(t2 - t1);
            // Add time
            time += timeElapsed.count();
        }

        double avgTime = time / 100;
        file<<sampleSize<<","<< avgTime <<std::endl;
        std::cout << "sample: " << sampleSize << "done" << std::endl;
    }
    file.close();
}
