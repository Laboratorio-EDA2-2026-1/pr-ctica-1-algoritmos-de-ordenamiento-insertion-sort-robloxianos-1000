#include <stdio.h>
#include <stdlib.h>

/*
 * EJERCICIO:
 * Se quiere definir un programa que, dada una matriz cuadrada con valores enteros,
 * devuelva una permutación de los valores de modo que:
 *
 * 1. Cada renglón esté ordenado de menor a mayor.
 * 2. Todos los elementos del segundo renglón (de arriba hacia abajo)
 *    sean mayores que los del primero, los del tercero mayores que los del segundo, etc.
 *
 * Regla importante:
 * - Cuando se ordenan los elementos de un renglón, por cada elemento de dicho renglón,
 *   se mueven también todos los elementos que se encuentran por debajo en la misma columna.
 *
 * INSTRUCCIONES:
 * - Completa la función sort_matrix() que debe modificar la matriz en su lugar.
 * - Puedes escribir funciones auxiliares si lo deseas.
 * - NO cambies la firma de sort_matrix().
 */
void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];  // Elemento actual a insertar
        j = i - 1;
        
        // Mover elementos mayores que key una posición adelante
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;  // Insertar key en su posición correcta
    }
}

void sort_matrix(int **matrix, int n) {
    int i, j,k,m, key;
    for (m=0; m<3; m++){
    for (i = 1; i < n; i++) {
        key = matrix[m][i];  // Elemento actual a insertar
        j = i - 1;
        
        // Mover elementos mayores que key una posición adelante
        while (j >= 0 && matrix[m][j] > key) {
            matrix[m][j + 1]= matrix[m][j];
            j = j - 1;
        }
        matrix[m][j + 1] = key;  // Insertar key en su posición correcta
    }
    
    }

}

int main() {
    int n = 3;
    // Reserva dinámica de la matriz
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // Ejemplo de entrada
    int ejemplo[3][3] = {
        {4, 7, 2},
        {9, 5, 6},
        {8, 1, 3}
    };

    // Copiar ejemplo a la matriz dinámica
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = ejemplo[i][j];
        }
    }

    printf("Matriz original:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Llamada a la función que deben completar
    sort_matrix(matrix, n);

    printf("\nMatriz ordenada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Liberar memoria
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
