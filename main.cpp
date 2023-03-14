#include "Sorts.h"
#include "Tests.h"
#include <chrono>
#include <iostream>
#include <cstdlib>
#include "List.h"

int main() {
    FILE *flog;
    flog = fopen("Graphics.txt", "w");
    fprintf(flog, "%-10s\t%-8s\t%-8s\t%-8s\t%-8s\t%-8s\t%-8s\n", "Size", "Count", "Quick", "Merge", "Selection", "Insertion", "Bubble");
    List lst(countSort);
    CreateList(lst);
    int size = 1000;
    while(!StopSorting(lst)) {
        listnode *p = lst.head;
        fprintf(flog, "%.10d\t", size);
        for (int i = 0; i < lst.length; ++i) {
            srand(time(nullptr));
            int *ar = new int[size];
            for (int j = 0; j < size; ++j) {
                ar[j] = rand();
            }
            if (p->time < 20) {
                auto start = std::chrono::high_resolution_clock::now();
                test_Sort(p->Sort, ar, size);
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<float> res_time = end - start;
                p->time = res_time.count();
                fprintf(flog, "%f\t", p->time);
            }
            else {
                lst.length--;
            }
            p = p->next;
            delete[] ar;
        }
        fprintf(flog, "\n");
        size += size / 3;
    }
    fclose(flog);
    return 0;
}
