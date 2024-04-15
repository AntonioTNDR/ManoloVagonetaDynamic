#include <stdio.h>

const int CAPACITY = 1500; // Maximum lorry capacity

// DYNAMICAL PROGRAMMING ALGORITHM]
// selected[] = Array containing the selected items
// nElements = # of elements
int dynamical(int rows, int elements[], int selected[], int* nElements) {
    // Compute minimum number of columns for the matrix
    int columns = 0;
    for (int i = 0; i < rows; ++i) {
        columns += elements[i];
    }
    columns++; // One more column (to consider 0 total capacity)
    if (columns > CAPACITY) columns = CAPACITY + 1; // Don't accept any more than 15k columns (max lorry capacity)

    rows++; // One more row (to consider 0 items)
    int totalWeight = 0;
    int matrix[rows][columns];

    // Initialize the 1st row to 0
    for (int j = 0; j < columns; j++) {
        matrix[0][j] = 0;
    }

    // Get optimal solution for each size and number of elements
    // Traverse the matrix computing the optimal states
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (elements[i - 1] > j) matrix[i][j] = matrix[i - 1][j];
            else {
                if (matrix[i-1][j] > (matrix[i-1][j-elements[i-1]] + elements[i-1])) matrix[i][j] = matrix[i-1][j];
                else matrix[i][j] = matrix[i-1][j-elements[i-1]] + elements[i-1];
            }
        }
    }
    // printf("columns = %d\n", columns); // Just to check if it's working
    // printf("rows = %d\n", rows);

    // Obtain the selected items
    int n = 0;
    int j = columns - 1;
    *nElements = 0; // Initialize to 0 elements included

    for(int i = rows - 1; i > 0; i--) {
        if(matrix[i][j] != matrix[i-1][j]) { // If the optimal weight changed this iteration
            selected[n] = elements[i-1]; // Include this element
            n++;
            *nElements = *nElements + 1; // Count 1 more element
            totalWeight += elements[i-1]; // Count the weight
            j = j - elements[i-1]; // Move the current pointer weight(i*) to the left to continue checking
        }
    }
    return totalWeight * 6; // Return price
}


int main() {
    int list[20];
    int selected[100];
    int nElements = 0;
    int value;
    int i = 0;

    while(1){
        scanf("%d", &value);
        if(value == -1) break;
        list[i] = value;
        i++;
    }
    int rows = i; // rows = i = # of elements introduced
    int price = dynamical(rows, list, selected, &nElements);

    printf("\nSelected elements:\n");
    for (int x = 0; x < nElements; x++){
        if(x == nElements - 1) printf("%d", selected[x]);
        else printf("%d, ", selected[x]);
    }
    printf("\nTotal price = %d\n", price);

    while(1); // Endless loop to prevent executable program immediately closing after finishing
}
