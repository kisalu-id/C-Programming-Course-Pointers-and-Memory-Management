#include <stdio.h>

void swapFifth(int *, int *);

int main(void) {
    //! showMemory(start=65520)
    int arr[] = {5, 6, 7, 8, 9, 10};
    int *ptrA, *ptrB;
    
    printf("Array: %d, %d, %d, %d, %d, %d\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
    printf("Addresses: %p, %p, %p, %p, %p, %p\n", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5]);
    
    ptrA = arr;
    ptrB = &arr[0]; //same as ptrA=arr;
    
    *ptrA = 1;
    *(ptrA + 1) = 2; 
    
    *arr = 10; //arr has the address of the 1st element of the array => it modifies it
    *(arr + 1) = 19;
    ptrA++; //current address ++
    *ptrA = 20;
    
    ptrA += 1;
    *ptrA = 30;
    
    arr[4] = (ptrA[3]) + 10;
    
    swapFifth (&arr[4], &arr[5]);
    
    
    printf("Array updated: %d, %d, %d, %d, %d, %d\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
    
    return 0;
}
void swapFifth (int * a, int * b) {
    * b = * a;
}
