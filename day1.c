#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int *num1 = NULL, *num2 = NULL; // Pointers for dynamic arrays
    int n = 0, capacity = 10; // Initial capacity
    int diff = 0;

    // Allocate initial memory for both arrays
    num1 = (int *)malloc(capacity * sizeof(int));
    num2 = (int *)malloc(capacity * sizeof(int));
    if (num1 == NULL || num2 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Read input dynamically
    while (scanf("%d %d", &num1[n], &num2[n]) != EOF) {
        n++;
        if (n >= capacity) {
            // Double the capacity if needed
            capacity *= 2;
            num1 = (int *)realloc(num1, capacity * sizeof(int));
            num2 = (int *)realloc(num2, capacity * sizeof(int));
            if (num1 == NULL || num2 == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                free(num1);
                free(num2);
                return 1;
            }
        }
    }

    // Sort both arrays
    qsort(num1, n, sizeof(int), compare);
    qsort(num2, n, sizeof(int), compare);
// part 1
    // Pair smallest with smallest, second-smallest with second-smallest, etc.
    for (int i = 0; i < n; i++) {
        diff += abs(num1[i] - num2[i]);
    }
// part 2
    int j = 0;
    int score = 0;
    for(int i = 0; i<n ; i++){
        while(num2[i] > num1[j] &&  j<n){
            j++;
        }
        if(num2[i] == num1[j]){
            score += num2[i];
        }
    }    

    // Output the result
    printf("The sum of absolute differences is: %d\n The similarity score is: %d\n", diff, score);

    // Free allocated memory
    free(num1);
    free(num2);

    return 0;
}

