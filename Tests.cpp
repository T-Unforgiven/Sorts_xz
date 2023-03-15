#include <iostream>
#include "Tests.h"

void test_Sort(void(*sorts)(int*, int),int*ar, int size){
    sorts(ar, size);
    int ErrorCounter = 0;
    for(int i = size - 1; i > 0; i--){
        if(ar[i] < ar[i - 1])
            ErrorCounter++;
    }
    if(ErrorCounter == 0)
        std::cout << "Test_is_OK";
    else
        std::cout << "BAD";
    std::cout << std::endl;
}