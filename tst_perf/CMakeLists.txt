set(BINARY ${CMAKE_PROJECT_NAME}_perf)

include_directories(${PROJECT_SOURCE_DIR}/src)

set(PERF_SRC
        main.cpp
        Random.h
        Random.cpp
        ArrayTest.h
        ArrayTest.cpp
        ListTest.h
        ListTest.cpp
        HeapTest.h
        HeapTest.cpp
        BSTTest.h
        BSTTest.cpp
        )

add_executable(${CMAKE_PROJECT_NAME}_perf ${PERF_SRC})

target_link_libraries(${CMAKE_PROJECT_NAME}_perf PUBLIC ${CMAKE_PROJECT_NAME}_lib)