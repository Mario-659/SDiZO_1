set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES
        main.cpp
        DoublyLinkedList.h
        DoublyLinkedList.cpp
        Array.h
        Array.cpp
        Heap.h
        Heap.cpp
        BST.h
        BST.cpp
        )

add_executable(${CMAKE_PROJECT_NAME}_run ${SOURCES})

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})