/*Find out the average grade of a student*/

#include <stdio.h>
#include <stdlib.h>

int * allocArr(int);
double count (int *, int);

int main(void) {
    int num;
    double result;
    int *grades;
  
    printf("How much grades do you want to process?\n");
    scanf("%d", &num);
    grades = allocArr(num); //array needs to know it's size in C
  
    printf("Please enter your grades:\n");
    for (int i=0; i<num; i++) {
        scanf("%d", grades + i);
    }
    result = count(grades, num);
  
    printf("The average grade is: %lf.\n", result);
    free(grades); //free the memory in heap from this array
    return 0;
}

int * allocArr(int a) {
    int * arr = (int*) malloc(a * sizeof(int)); //get the beginning of this array space, that was allocated to the memory, as arr. not forget to cast to a pointer to an int
    return arr;
}

double count (int * grades, int n) {
    double result = 0;
    for (int i=0; i<n; i++) {
        result += grades[i];
    }
    result /= n;
    return result;
}
