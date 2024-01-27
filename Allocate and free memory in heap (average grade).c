/*Find out the average grade of a student*/

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    //! showMemory(start=272)
    int num;
    double result;
  
    printf("How much grades do you want to process?\n");
    scanf("%d", &num);
    int *grades[num];
  
    printf("Please enter your grades:\n");
    for (int i=0; i<num; i++) {
        scanf("%d", &(grades + i));
    }
  
    printf("The average grade is: %lf.\n", result);
    free(result);
    return 0;
}
