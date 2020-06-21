#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

template <class T>
void print_int_memory(T i) {
    unsigned char* p = (unsigned char*)&i;
    for (int index = sizeof(i) -1; index >=0; index--) {
        printf("%.2x ", *(p+index));
    }
    printf(" i= %8ld\n", i);
}

int main()
{
    int i = 0x12233445;
    print_int_memory<int>(i);
    long long l = 0x12233445;
    print_int_memory<long long>(l);
 
    i = 1;
    for (int index = 0; index < 32; index++) {
        int temp = i << index;

        print_int_memory<int>(temp);
    }
    return 0;
}
