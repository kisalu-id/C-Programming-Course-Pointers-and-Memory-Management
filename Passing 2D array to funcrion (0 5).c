/*Change the values in rowOne array using a function and a pointer. The printf output should show zeros insted of ones*/
#include <stdio.h>
#include <stdlib.h>
void change (int **);
void displayResult (int **);

int main () {
    //! showMemory(start=272)
    int rowOne[3] = {1, 1, 1};
    int rowTwo[3] = {5, 5, 5};
    int *rows[4] = {rowOne, rowTwo, rowOne, rowTwo};
    change(rows);
    displayResult (rows);
    return 0;
}

void change (int **a) {
    *(*a) = 0; //1st element of rowOne array
    *((*a) + 1) = 0; //2nd
    //changing 3rd number in a 3rd element in a rows array just for fun
    *(*(a + 2) + 2) = 0;
}

void displayResult (int **rows) {
    for (int i=0; i<4; i++) {
        for (int j=0; j<3; j++) {
            printf("%d", rows[i][j]);
        }
        printf("\n");
    }
}
