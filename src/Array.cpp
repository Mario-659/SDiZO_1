#include "Array.h"

void Array::copyValues(int source[], int sourcecurrSize, int* destination){
    for (int i = 0; i < sourcecurrSize; ++i) {
        *destination = source[i];
        destination++;
    }
}

Array::Array(){
    currSize = 0;
    array = new int[0];
}

void Array::pushFront(int val){
    int* oldArray = array;
    array = new int[++currSize];
    array[0] = val;
    copyValues(oldArray, currSize - 1, array+1);
    delete oldArray;
}

void Array::pushBack(int val){
    int* oldArray = array;
    array = new int[++currSize];
    copyValues(oldArray, currSize - 1, array);
    array[currSize-1] = val;
    delete oldArray;
}

bool Array::insert(int index, int value){
    // index out of bounds
    if(index<0 || index>currSize) return false;

    int* oldArray = array;
    array = new int[++currSize];
    copyValues(oldArray, index, array);
    array[index] = value;
    copyValues(oldArray+index, currSize-1 - index, array+index+1);

    delete oldArray;
    return true;
}

bool Array::remove(int index){
    // index out of bounds
    if(index<0 || index>=currSize) return false;

    int* oldArray = array;
    array = new int[--currSize];
    copyValues(oldArray, index, array);
    copyValues(oldArray+index+1, currSize - index, array+index);

    delete oldArray;
    return true;
}

bool Array::contains(int value){
    for(int i=0; i<currSize; i++){
        if(array[i] == value) return true;
    }
    return false;
}

std::string Array::toString(){
    std::string arr = "[";
    for(int i=0; i<currSize; i++){
        arr += " " + std::to_string(array[i]);
        arr += ",";
    }
    arr += "]";
    return arr;
}

void Array::readFromFile(std::string filename) {
    delete array;
	currSize = 0;
	array = new int[0];
    std::fstream file;
    file.open(filename, std::ios::in);
    if(file.is_open()){
        std::string line;

        // Ignore first line
        std::getline(file, line);
        if(line.empty()) return;

        while(std::getline(file, line)){
            if(line.empty() || line == "\n") return;
            int val = std::stoi(line);
            this->pushBack(val);
        }
    }
}

void Array::makeRandom(int size) {
    delete array;
	currSize = 0;
    array = new int[0];
    std::default_random_engine generator(std::time(0));
    std::uniform_int_distribution<int> distribution(INT_MIN, INT_MAX);
    for(int i=0; i<size; i++){
        pushFront(distribution(generator));
    }
}

Array::~Array() {
    delete array;
}

int Array::size() {
    return currSize;
}

