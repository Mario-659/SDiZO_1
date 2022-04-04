#include "DoublyLinkedList.h"

#include <fstream>
#include <conio.h>
#include<string>
#include<iostream>

//For random numbers
#include <algorithm>
#include <random>
#include <bits/stdc++.h>

using namespace std;


DoublyLinkedList::DoublyLinkedList(){
    head = nullptr;
    tail = nullptr;
}

bool DoublyLinkedList::isEmpty(){
    return head == nullptr;
}

int DoublyLinkedList::size(){
    if(isEmpty()) return 0;

    int currentSize = 0;
    Node* currentNode = head;
    do{
        currentNode = currentNode->next;
        currentSize++;
    }
    while(currentNode != nullptr);
    return currentSize;
}


void DoublyLinkedList::pushBack(int val){
    //Create new node if list is empty
    if(isEmpty()) {
        head = new Node(val, nullptr, nullptr);
        tail = head;
    }
    else{
        //link new node to the last one
        tail->next = new Node(val, nullptr, tail);
        tail = tail->next;
    }
}

void DoublyLinkedList::pushFront(int val) {
    if(isEmpty()){
        head = new Node(val, nullptr, nullptr);
        tail = head;
    }
    else{
        head->prev = new Node(val, head, nullptr);
        head = head->prev;
    }
}

bool DoublyLinkedList::insert(int val, int index) {
    if(index < 0) return false;
    if(index == 0) {
        pushFront(val);
        return true;
    }
    //return false if list is empty and given index != 0
    if(isEmpty()) return false;

    //search index
    int currentIndex = 1;
    Node* currentNode = head;
    while(currentNode->next != nullptr){
        //if found node
        if(currentIndex == index){
            Node* newNode = new Node(val, currentNode->next, currentNode);
            //set nodes in next and prev nodes
            newNode->prev->next = newNode;
            newNode->next->prev = newNode;
            return true;
        }
        currentIndex++;
        currentNode = currentNode->next;
    }

    //if index==size (same as pushBack)
    if(currentNode == tail){
        //link new node to the last one
        tail->next = new Node(val, nullptr, tail);
        tail = tail->next;
        return true;
    }

    //node not found
    cout << "index out of range" << std::endl;
    return false;
}

bool DoublyLinkedList::contains(int val) {
    if(isEmpty()) return false;

    Node* currentNode = head;
    do{
        if(currentNode->data == val) return true;
        currentNode = currentNode->next;
    }
    while(currentNode != nullptr);
    //value not found
    return false;
}

bool DoublyLinkedList::pop_head() {
    if(isEmpty()){
        return false;
    }
    Node* oldNode = head;
    head = head->next;
    delete oldNode;
    if(head != nullptr) head->prev = nullptr;
    else tail = head;
    return true;
}

bool DoublyLinkedList::pop_tail() {
    if(isEmpty()){
        return false;
    }

    Node* oldNode = tail;
    tail = tail->prev;
    delete oldNode;
    if(tail != nullptr) tail->next = nullptr;
    else head = tail;
    return true;
}

bool DoublyLinkedList::remove(int index){
    if(isEmpty() || index < 0) return false;
    if(index == 0) return pop_head();

    Node* currentNode = head->next;
    int currentIndex = 1;
    while(currentNode != nullptr){
        if(index == currentIndex){
            Node* nextNode = currentNode->next;
            Node* prevNode = currentNode->prev;

            //if node to remove is the tail
            if(nextNode == nullptr) this->tail = prevNode;
                //else
            else nextNode->prev = prevNode;

            //if note to remove is the head
            if(prevNode == nullptr) this->head = nextNode;
                //else
            else prevNode->next = nextNode;

            delete currentNode;
            return true;
        }
        //next node and increment index
        currentNode = currentNode->next;
        currentIndex++;
    }
    //if index not found (out of range)
    return false;
}

bool DoublyLinkedList::removeValue(int value)  {

    Node* currentNode = head;
    while(currentNode != nullptr){
        if(currentNode->data == value){
            Node* nextNode = currentNode->next;
            Node* prevNode = currentNode->prev;

            //if node to remove is the tail
            if(nextNode == nullptr) this->tail = prevNode;
                //else
            else nextNode->prev = prevNode;

            //if note to remove is the head
            if(prevNode == nullptr) this->head = nextNode;
                //else
            else prevNode->next = nextNode;

            delete currentNode;
            return true;
        }
        //next node and increment index
        currentNode = currentNode->next;
    }
    //if value not found (out of range)
    return false;
}

void DoublyLinkedList::readFromFile(std::string filename){
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
            this->pushFront(val);
        }
    }
}

void DoublyLinkedList::makeRandom(int size){
    clear();
    std::default_random_engine generator(std::time(0));
    std::uniform_int_distribution<int> distribution(INT_MIN, INT_MAX);
    for(int i=0; i<size; i++){
        this->pushFront(distribution(generator));
    }
}

void DoublyLinkedList::clear(){
    Node* currentNode = head;
    while(currentNode!= nullptr){
        Node* toDelete = currentNode;
        currentNode = currentNode->next;
        delete toDelete;
    }
    head = nullptr;
    tail = nullptr;
}

std::string DoublyLinkedList::toString() {
    if(isEmpty()) {
        return "[ ]";
    }
    std::string array = "[ ";
    Node* currentNode = head;
    while(currentNode != nullptr){
        array += std::to_string(currentNode->data) + ", ";
        currentNode = currentNode->next;
    }
    array.erase(array.end()-2);
    array += "]";
    return array;
}

std::string DoublyLinkedList::toStringInv()  {
    if(isEmpty()) {
        return "[ ]";
    }
    std::string array = "[ ";
    Node* currentNode = tail;
    while(currentNode != nullptr){
        array += std::to_string(currentNode->data) + ", ";
        currentNode = currentNode->prev;
    }
    array.erase(array.end()-2);
    array += "]";
    return array;
}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}
