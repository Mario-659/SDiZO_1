#include <iostream>
#include "Hello.cpp"

int main() {
    Hello* hello = new Hello;
    std::cout << hello->getHelloValue() << std::endl;
    return 0;
}
