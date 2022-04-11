#include "HeapTest.h"

using namespace std::chrono;

void HeapTest::testHeapPush() {
    std::string filename = "heapPush_1000000.csv";

    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;

    std::ofstream file;
    file.open(filename);

    std::vector<double> times;

    std::vector<int> sampleSizes;
    for(int i=5000; i<100001; i+=5000) sampleSizes.push_back(i);
    for(auto sampleSize: sampleSizes){
        double time = 0.0;

        for(int j=0; j<100; j++) {
            // Generate random sample
            std::vector<int> sample = Random::getRandomVec(sampleSize, -1000, 1000);
            auto array = new Heap(sampleSize);
            for (int k = 0; k < sampleSize; k++) {
                array->push(sample[k]);
            }
            // Generate random values to push
            std::vector<int> randNums = Random::getRandomVec(1000000, -1000, 1000);

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

void HeapTest::testHeapRemoveRandom() {
    std::string filename = "heapRemove_100000.csv";

    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;

    std::ofstream file;
    file.open(filename);

    std::vector<double> times;

    std::vector<int> sampleSizes;
    for(int i=5000; i<100001; i+=5000) sampleSizes.push_back(i);
    for(auto sampleSize: sampleSizes){
        double time = 0.0;

        for(int j=0; j<100; j++) {
            // Generate random sample
            std::vector<int> sample = Random::getRandomVec(sampleSize, -1000, 1000);
            auto array = new Heap(sampleSize);
            for (int k = 0; k < sampleSize; k++) {
                array->push(sample[k]);
            }
            // Generate random values to push
            std::vector<int> randInd = Random::getRandomVec(100000, 0, sampleSize-1);

            // Start timer
            t1 = high_resolution_clock::now();
            // Push 100 new elements
            for (int k = 0; k < randInd.size(); k++) {
                array->remove(randInd[k]);
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
