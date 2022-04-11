#include "ListTest.h"

using namespace std::chrono;

void ListTest::testPushFront(){
    std::string filename = "listTestPushFront_1000000.csv";

    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;

    std::ofstream file;
    file.open(filename);

    std::vector<double> times;

    std::vector<int> sampleSizes = {5000, 8000, 10000, 16000, 20000,40000,60000,100000};
    for(auto sampleSize: sampleSizes){
        double time = 0.0;

        for(int j=0; j<50; j++) {
            // Generate random sample
            std::vector<int> sample = Random::getRandomVec(sampleSize, -1000, 1000);
            auto array = new DoublyLinkedList();
            for (int k = 0; k < sampleSize; k++) {
                array->pushFront(sample[k]);
            }
            // Generate random values to push
            std::vector<int> randNums = Random::getRandomVec(1000000, -1000, 1000);

            // Start timer
            t1 = high_resolution_clock::now();
            // Push 100 new elements
            for (int k = 0; k < randNums.size(); k++) {
                array->pushFront(randNums[k]);
            }
            // Stop timer
            t2 = high_resolution_clock::now();
            duration<double> timeElapsed = duration_cast<duration<double>>(t2 - t1);
            // Add time
            time += timeElapsed.count();
        }

        double avgTime = time / 50;
        file<<sampleSize<<","<< avgTime <<std::endl;
        std::cout << "sample: " << sampleSize << "done" << std::endl;
    }
    file.close();
}

void ListTest::testPushBack() {
    std::string filename = "listTestPushBack_1000000.csv";

    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;

    std::ofstream file;
    file.open(filename);

    std::vector<double> times;

    std::vector<int> sampleSizes = {5000, 8000, 10000, 16000, 20000,40000,60000,100000};
    for(auto sampleSize: sampleSizes){
        double time = 0.0;

        for(int j=0; j<50; j++) {
            // Generate random sample
            std::vector<int> sample = Random::getRandomVec(sampleSize, -1000, 1000);
            auto array = new DoublyLinkedList();
            for (int k = 0; k < sampleSize; k++) {
                array->pushFront(sample[k]);
            }
            // Generate random values to push
            std::vector<int> randNums = Random::getRandomVec(1000000, -1000, 1000);

            // Start timer
            t1 = high_resolution_clock::now();
            // Push 100 new elements
            for (int k = 0; k < randNums.size(); k++) {
                array->pushFront(randNums[k]);
            }
            // Stop timer
            t2 = high_resolution_clock::now();
            duration<double> timeElapsed = duration_cast<duration<double>>(t2 - t1);
            // Add time
            time += timeElapsed.count();
        }

        double avgTime = time / 50;
        file<<sampleSize<<","<< avgTime <<std::endl;
        std::cout << "sample: " << sampleSize << "done" << std::endl;
    }
    file.close();
}

void ListTest::testPushRandom() {
    std::string filename = "listPushRandom_100.csv";

    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;

    std::ofstream file;
    file.open(filename);

    std::vector<double> times;

    std::vector<int> sampleSizes = {5000, 8000, 10000, 16000, 20000,40000,60000,100000};
    for(auto sampleSize: sampleSizes){
        double time = 0.0;

        for(int j=0; j<50; j++) {
            // Generate random sample
            std::vector<int> sample = Random::getRandomVec(sampleSize, -1000, 1000);
            auto array = new DoublyLinkedList();
            for (int k = 0; k < sampleSize; k++) {
                array->pushFront(sample[k]);
            }
            // Generate random values to push
            std::vector<int> randNums = Random::getRandomVec(100, -1000, 1000);
            std::vector<int> randInd = Random::getRandomVec(100, 0, sampleSize-1);

            // Start timer
            t1 = high_resolution_clock::now();
            // Push 100 new elements
            for (int k = 0; k < randNums.size(); k++) {
                array->insert (randNums[k], randInd[k]);
            }
            // Stop timer
            t2 = high_resolution_clock::now();
            duration<double> timeElapsed = duration_cast<duration<double>>(t2 - t1);
            // Add time
            time += timeElapsed.count();
            std::cout << j << " ";
        }

        double avgTime = time / 50;
        file<<sampleSize<<","<< avgTime <<std::endl;
        std::cout << "sample: " << sampleSize << "done" << std::endl;
    }
    file.close();
}

void ListTest::testFindRandom() {
    std::string filename = "listFindRandom_100.csv";

    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;

    std::ofstream file;
    file.open(filename);

    std::vector<double> times;

    std::vector<int> sampleSizes = {5000, 8000, 10000, 16000, 20000,40000,60000,100000};
    for(auto sampleSize: sampleSizes){
        double time = 0.0;

        for(int j=0; j<25; j++) {
            // Generate random sample
            std::vector<int> sample = Random::getRandomVec(sampleSize, -1000, 1000);
            auto array = new DoublyLinkedList();
            for (int k = 0; k < sampleSize; k++) {
                array->pushFront(sample[k]);
            }
            // Generate random values to find
            std::vector<int> randInd = Random::getRandomVec(100, 0, sampleSize-1);

            // Start timer
            t1 = high_resolution_clock::now();
            // Push 100 new elements
            for (int k = 0; k < 100; k++) {
                array->contains(randInd[k]);
            }
            // Stop timer
            t2 = high_resolution_clock::now();
            duration<double> timeElapsed = duration_cast<duration<double>>(t2 - t1);
            // Add time
            time += timeElapsed.count();
            std::cout << j << " ";
        }

        double avgTime = time / 25;
        file<<sampleSize<<","<< avgTime <<std::endl;
        std::cout << "sample: " << sampleSize << "done" << std::endl;
    }
    file.close();
}