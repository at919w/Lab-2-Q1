#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 24
#define nRows 8
#define nCols 3

// Function to set the value of each array element to its index
void set_array(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        arr[i] = i;
    }
}

// Function to print an array
void print_array(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to remove an element at the specified position
void rem_align(int arr[], int length, int pos) {
    if (pos >= 0 && pos < length) {
        for (int i = pos; i < length - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[length - 1] = arr[length - 2];
    }
}

// Function to insert a value at the specified position
void insert_align(int arr[], int length, int pos, int value) {
    if (pos >= 0 && pos < length) {
        for (int i = length - 1; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = value;
    }
}

// Function to reshape the 1D array into a 2D array
void reshape(int arr[], int length, int arr2d[nRows][nCols]) {
    if (length == nRows * nCols) {
        for (int i = 0; i < length; i++) {
            arr2d[i / nCols][i % nCols] = arr[i];
        }
    } else {
        printf("Error: Array length does not match 2D array dimensions.\n");
    }
}

// Function to print the transposed matrix
void print_trans_matrix(int arr2d[nRows][nCols]) {
    for (int j = 0; j < nCols; j++) {
        for (int i = 0; i < nRows; i++) {
            printf("%d ", arr2d[i][j]);
        }
        printf("\n");
    }
}

// Function to check for duplicate values in the array
bool found_duplicate(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

// Function to flip the array
int* flip_array(int arr[], int length) {
    int* flipped_arr = (int*)malloc(length * sizeof(int));
    if (flipped_arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    for (int i = 0; i < length; i++) {
        flipped_arr[i] = arr[length - i - 1];
    }
    return flipped_arr;
}

int main() {
    int arr[SIZE];
    int arr2d[nRows][nCols];

    set_array(arr, SIZE);

    //printf("Initial array:\n");
    print_array(arr, SIZE);

    rem_align(arr, SIZE, 3);
    //printf("After removing element at position 3:\n");
    printf("\n");
    print_array(arr, SIZE);

    insert_align(arr, SIZE, 2, 80);
    //printf("After inserting 80 at position 2:\n");
    printf("\n");
    print_array(arr, SIZE);

    reshape(arr, SIZE, arr2d);
    printf("\n");
    printf("Reshaped 2D array:\n");
    print_trans_matrix(arr2d);

    printf("\n");
    printf("Transposed matrix:\n");
    print_trans_matrix(arr2d);
    printf("\n");

    if (found_duplicate(arr, SIZE)) {
        printf("Duplicates found in the array.\n");
    } else {
        printf("No duplicates found in the array.\n");
    }

    int* flipped_arr = flip_array(arr, SIZE);
    printf("\n");
    //printf("Flipped array:\n");
    print_array(flipped_arr, SIZE);
    free(flipped_arr);

    return 0;
}