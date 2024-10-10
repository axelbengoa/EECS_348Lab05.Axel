#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // Define the size of the matrices

// Function to add two matrices
void addMatrices(int firstMatrix[SIZE][SIZE], int secondMatrix[SIZE][SIZE], int resultMatrix[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            resultMatrix[row][col] = firstMatrix[row][col] + secondMatrix[row][col];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int firstMatrix[SIZE][SIZE], int secondMatrix[SIZE][SIZE], int resultMatrix[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            resultMatrix[row][col] = 0; // Initialize the result 
            for (int k = 0; k < SIZE; k++) {
                resultMatrix[row][col] += firstMatrix[row][k] * secondMatrix[k][col];
            }
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int inputMatrix[SIZE][SIZE], int transposedMatrix[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            transposedMatrix[col][row] = inputMatrix[row][col];
        }
    }
}

// Function to print a matrix
void printMatrix(int matrixToPrint[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%4d ", matrixToPrint[row][col]); 
        }
        printf("\n"); // Newline 
    }
}

int main() {
    // Two matrices with the sample input
    int matrixA[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int matrixB[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int matrixSum[SIZE][SIZE], matrixProduct[SIZE][SIZE], matrixTranspose[SIZE][SIZE];

    // Matrix addition
    addMatrices(matrixA, matrixB, matrixSum);
    printf("Sum of Matrix A and Matrix B:\n");
    printMatrix(matrixSum);

    // Matrix multiplication
    multiplyMatrices(matrixA, matrixB, matrixProduct);
    printf("\nProduct of Matrix A and Matrix B:\n");
    printMatrix(matrixProduct);

    // Transpose of Matrix A
    transposeMatrix(matrixA, matrixTranspose);
    printf("\nTranspose of Matrix A:\n");
    printMatrix(matrixTranspose);

    return 0;
}
