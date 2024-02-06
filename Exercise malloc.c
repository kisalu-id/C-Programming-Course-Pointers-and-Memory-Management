/*
Write a program that dynamically allocates memory for an array of integers, fills it with user-provided values, and then frees the allocated memory.
Requirements:

    Dynamically allocate memory for an array of integers based on user input for the array size.
    Prompt the user to input integer values for each element of the array.
    Display the array elements after they've been entered.
    Free the dynamically allocated memory before the program terminates.

Example:

Enter the size of the array: 5
Enter 5 integer values:
Value 1: 10
Value 2: 20
Value 3: 30
Value 4: 40
Value 5: 50

Array elements: 10 20 30 40 50
Memory deallocated successfully.
*/



#include <stdio.h>
#include <stdlib.h>

int * allocMem (int);

int main () {
     //! showMemory(start=438)
    int *arr;
    int size;
    
    printf("Enter the size of the array:\n");
    scanf("%d", &size);
    arr = allocMem(size);
    
    printf("Enter %d values of type integer:\n", size);
    for (int i=0; i<size; i++) {
        printf("Value %d: ", (i+1));
        scanf("%d", (arr + i));
    }
    
    printf("Array elements: ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    printf("\n\nMemory successfully deallocated.");
    return 0;
}

int * allocMem (int size) {
    int *arr = ((int *) malloc(size * sizeof(int)));
    return arr;
}
