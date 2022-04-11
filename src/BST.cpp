#include "BST.h"

BST::BST() {
    top = nullptr;
}

bool BST::push(int value) {
    // If empty create new node at the top
    if(top == nullptr){
        top = new BSTNode(value);
        return true;
    }

    // Search for parent for new value
    BSTNode* next = top;
    BSTNode* parent;
    while(next != nullptr){
        parent = next;
        if(parent->key == value) return false;

        if(parent->key > value){
            next = parent->left;
        }
        else next = parent->right;
    }

    // Create new node and insert it in proper place
    BSTNode* node = new BSTNode(value);
    node->parent = parent;
    if(parent->key > value){
        parent->left = node;
    }
    else parent->right = node;
    return true;
}

bool BST::contains(int value) {
    // If empty return false
    if(top == nullptr) return false;

    // Search for value
    BSTNode* node = top;
    while(node != nullptr){
        if(node->key == value) return true;

        if(node->key > value){
            node = node->left;
        }
        else node = node->right;
    }
    // Return false if value not found
    return false;
}

bool BST::replaceAll(const std::vector<int>& collection) {
    if(collection.empty()) return false;

    this->clear();
    for(auto n: collection){
        push(n);
    }
    return true;
}

bool BST::replaceAll(int* start, int size) {
    if(size <= 0) return false;

    this->clear();
    for(int i=0; i<size; i++){
        this->push(start[i]);
    }
    return true;
}

void BST::transplant(BSTNode* parent, BSTNode* child){
    if(parent->parent == nullptr){
        this->top = child;
    }
    else if(parent == parent->parent->left){
        parent->parent->left = child;
    }
    if(child != nullptr){
        child->parent = parent->parent;
    }
}

bool BST::remove(int value) {
    // Return false if empty
    if(top == nullptr) return false;

    // Find node to remove
    BSTNode* node = top;
    while(node != nullptr && node->key != value){
        if(node->key > value){
            node = node->left;
        }
        else node = node->right;
    }
    // Value not found
    if(node == nullptr) return false;

    // Remove node with found key
    remove(node);
    return true;
}

void clearNode(BSTNode* node){
    if(node == nullptr) return;

    BSTNode* left = node->left;
    BSTNode* right = node->right;
    delete node;
    clearNode(left);
    clearNode(right);
}

void BST::clear() {
    clearNode(top);
    this->top = nullptr;
}

void inorder(BSTNode* node, std::vector<int>* arr){
    if(node == nullptr) return;

    inorder(node->left, arr);
    arr->push_back(node->key);
    inorder(node->right, arr);
}

std::vector<int> BST::toInorder(){
    auto vector = new std::vector<int>;
    inorder(top, vector);
    std::reverse(vector->begin(), vector->end());
    return *vector;
}

BSTNode::BSTNode(int key){
    left = nullptr,
    right = nullptr,
    parent = nullptr;
    this->key = key;
}

void BST::readFromFile(std::string filename) {
    clear();
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
            push(val);
        }
    }
}

void BST::makeRandom(int n, int min, int max) {
    clear();
    std::default_random_engine generator(std::time(0));
    std::uniform_int_distribution<int> distribution(min, max);
    for(int i=0; i<n; i++){
        push(distribution(generator));
    }
}

void printBT(const std::string& prefix, BSTNode* node, bool isLeft){
    if( node != nullptr )
    {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "L__" );

        // print the value of the node
        std::cout << node->key << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "|   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

void BST::print() {
    printBT("", top, false);
}

std::string BST::toString() {
    std::vector<int> arr = toInorder();
    if(arr.empty()) return "[ ]";

    std::string str = "[";
    for(int i : arr){
        str += " " + std::to_string(i);
        str += ",";
    }
    str.pop_back();
    str.push_back(' ');
    str += "]";
    return str;
}

BSTNode* BST::minNode(BSTNode *node) {
    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}

void BST::remove(BSTNode *node) {
    if(node->left == nullptr)
        transplant(node, node->right);
    else if(node->right == nullptr)
        transplant(node, node->left);
    else{
        BSTNode* y = minNode(node->right);
        if(y->parent != node){
            transplant(y, y->right);
            y->right = node->right;
            y->right->parent = y;
        }
        transplant(node, y);
        y->left = node->left;
        y->left->parent = y;
    }
}
