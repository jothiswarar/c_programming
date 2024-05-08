#include <stdio.h>

#define MAX_SIZE 100

int subset[MAX_SIZE]; // To store the current subset
int n;                // Size of the input array
int targetSum;        // Target sum

// Function to print the subset that sums up to the target sum
void printSubset(int size)
{
    printf("Subset that sums up to %d is: ", targetSum);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

void subsetSum(int set[], int sum, int index, int size)
{
    if (sum == targetSum)
    {
        printSubset(size);
        return;
    }
    if (index >= n || sum > targetSum)
    {
        return;
    }

    subset[size] = set[index];
    subsetSum(set, sum + set[index], index + 1, size + 1);

    subsetSum(set, sum, index + 1, size);
}

int main()
{
    int set[] = {1, 3, 5, 7, 9};
    n = sizeof(set) / sizeof(set[0]);
    targetSum = 12;

    printf("Set: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", set[i]);
    }
    printf("\nTarget Sum: %d\n", targetSum);

    subsetSum(set, 0, 0, 0); // Start from index 0, with current sum 0, and empty subset

    return 0;
}
