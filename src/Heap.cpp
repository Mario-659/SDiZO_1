#include "Heap.h"

Heap::Heap(int maxSize) {
    arr = new int[maxSize];
    this->maxSize = maxSize;
    currSize = 0;
}

Heap::Heap(int* start, int size, int maxSize) {
    this->maxSize = maxSize;
    arr = start;
    currSize = size;
    makeHeap();
}

void Heap::makeHeap(){
    for (int i = (currSize-2 / 2); i >= 0; i--) {
        heapify(i);
    }
}

bool Heap::push(int value) {
    // Check if maximum size reached
    if(currSize == maxSize) return false;

    // Add element at the end of an array
    arr[currSize] = value;

    // Move to higher level if value is bigger than its parent
    int currInd = currSize;
    while(arr[getParent(currInd)] < arr[currInd]){
        std::swap(arr[currInd], arr[getParent(currInd)]);

        currInd = getParent(currInd);
    }
    currSize++;
    return true;
}

bool Heap::contains(int value){
    int index = 0;
    while(index < currSize){
        if(arr[index] == value) return true;
        index++;
    }
    return false;
}

bool Heap::remove(int index){
    if(index < 0 || currSize == 0 || index >= currSize) return false;

    arr[index] = arr[currSize - 1];
    currSize--;
    heapify(index);
    return true;
}

int Heap::extractMax() {
    if(currSize == 0) return 0;
    int maxValue = arr[0];
    arr[0] = arr[currSize - 1];
    currSize--;
    heapify(0);
    return maxValue;
}

void Heap::heapify(int index) {
    // get children
    int l = getLeft(index);
    int r = getRight(index);
    int largest;
    // check which is the largest: value at index, its left child or its right child
    if(l <= currSize && arr[l] > arr[index]){
        largest = l;
    }
    else largest = index;
    if(r <= currSize && arr[r] > arr[largest]){
        largest = r;
    }
    // if element at index is not the largest swap with largest and repeat for largest (down the tree)
    if(largest != index){
        std::swap(arr[index], arr[largest]);
        heapify(largest);
    }
}

int Heap::getParent(int index) {
    return (index-1) / 2;
}

int Heap::getLeft(int index) {
    return 2*index + 1;
}

int Heap::getRight(int index) {
    return 2*index + 2;
}

int* Heap::getArray() {
    return arr;
}

void Heap::readFromFile(std::string filename) {
    std::fstream file;
    file.open(filename, std::ios::in);
    if(file.is_open()){
        std::string line;

        // First line as number
        std::getline(file, line);
        if(line.empty()) return;
        int size = std::stoi(line);

        // If number of values in file exceeds max size return
        if(size > this->maxSize) return;

        // Make new array
        int* tab = new int[this->maxSize];

        // Add values from file to new array, return if missing value
        for(int i=0; i<size; i++){
            if(line.empty() || line == "\n") return;
            int val = std::stoi(line);
            tab[i] = val;
            tab++;
        }

        delete this->arr;
        this->currSize = size;
        this->arr = tab;
        makeHeap();
    }
}

Heap::~Heap(){
    delete arr;
}

int Heap::getSize() {
    return currSize;
}

void Heap::makeRandom(int n) {
    if(n > maxSize || n < 0) return;

    std::default_random_engine generator(std::time(0));
    std::uniform_int_distribution<int> distribution(INT_MIN, INT_MAX);
    int* tab = new int[maxSize];
    for(int i=0; i<n; i++){
        tab[i] = distribution(generator);
    }

    delete this->arr;
    this->arr = tab;
    currSize = n;
    makeHeap();
}

std::string Heap::toString(){
    if(currSize == 0) return "[ ]";

    std::string str = "[";
    for(int i=0; i < currSize; i++){
        str += " " + std::to_string(arr[i]);
        str += ",";
    }
    str.pop_back();
    str.push_back(' ');
    str += "]";
    return str;
}

void Heap::print() {
    printBT("", 0, false);
}

void Heap::printBT(const std::string& prefix, int index, bool isLeft)
{
    if (index < currSize)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "L__");
        // print the value of the node
        std::cout << arr[index] << std::endl;
        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "|   " : "    "), getRight(index), true);
        printBT(prefix + (isLeft ? "|   " : "    "), getLeft(index), false);
    }
}
