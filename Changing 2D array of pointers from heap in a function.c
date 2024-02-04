/*Exercise I made up to understand all these topics better.
Task: change '1' to '3' in the rowOne array inside the heap, not the stack.
How: create a pointer to an array, pass it to a function, change the values in the heap while leaving the values in the stack as they are. Free the heap at the end.*/

#include <stdio.h>
#include <stdlib.h>

void change(int **);
void displayResult(int **, int);
void showStackVars(int *, int *);

int main() {
    //! showMemory(start=272)
    int **rows = (int **)malloc(4 * sizeof(int *)); //we'll have 4 arrays (=4 pointers)
    for (int i=0; i<4; i++) {
        rows[i] = (int *)malloc(3 * sizeof(int)); //each of them contains 3 integers
    }

    //initialize values in stack
    int valuesRowOne[3] = {1, 1, 1};
    int valuesRowTwo[3] = {5, 5, 5};

    //copy them to heap and duplicate twice, so we'll have 4 rows instead of 2
    for (int i=0; i<3; i++) {
        rows[0][i] = valuesRowOne[i];
        rows[1][i] = valuesRowTwo[i];
        rows[2][i] = rows[0][i];
        rows[3][i] = rows[1][i];
    }
    
    printf("Values of stack variables, before changing:\n");
    showStackVars(valuesRowOne, valuesRowTwo);

    change(rows);
    
    printf("Values of heap variables after changing:\n");
    displayResult(rows, 4);

    //free allocated memory in heap for each individual row of "3" and "5"
    for (int i = 0; i < 4; i++) {
        free(rows[i]);
    }
    //free a pointer to arrays
    free(rows);
    
    printf("Values of variables from stack, they weren't changed, as intended:\n");
    showStackVars(valuesRowOne, valuesRowTwo);
    
    printf("I freed the heap. Displaying values after freeing heap memory may lead to unexpected results, but at least in some IDE's you can see it:\n");
    displayResult(rows, 4);
    
    return 0;
}


void change(int **a) {
    for (int j=0; j<3; j++) {
        for (int i=0; i<3; i++) {
            *((*(a + j)) + i) = 3;
        }
    j++;
    }
}

void displayResult(int **rows, int numRows) {
    for (int i=0; i<numRows; i++) {
        for (int j=0; j<3; j++) {
            printf("%d ", rows[i][j]);
        }
        printf("\n");
    }
}

void showStackVars(int *valuesRowOne, int *valuesRowTwo) {
    for (int j=0; j<2; j++) {
        for (int i=0; i<3; i++) {
            printf("%d ", valuesRowOne[i]);
        }
        printf("\n");
        for (int i=0; i<3; i++) {
            printf("%d ", valuesRowTwo[i]);
        }
        printf("\n");
    }
}
