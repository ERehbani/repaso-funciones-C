#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIMENSION 20


int cargarNumeros(int arr[], int dimension);

void mostrarArray(int arr[], int validos);

void ordenarSeleccion(int arr[], int validos);

int encontrarMenor(int i, int validos, int arr[]);

void ordenarInsercion(int arr[], int validos);

void encontrarMenorIns(int pos, int aux, int arr[]);

int cargarStrings(char strings[][DIMENSION]);

void mostrarStrings(char strings[][DIMENSION], int validos);

int encontrarPosMenorString(int pos, int validos, char arr[][DIMENSION]);

void ordenarSeleccionStrings(char arr[][DIMENSION], int validos);

int main(void) {
    char seguir = 's';
    int ejercicio;
    int arr[DIMENSION];
    int validos;
    char strings[DIMENSION][DIMENSION];
    int validosString;

    while (seguir == 's' || seguir == 'S') {
        printf("Seleccione que ejercicio ejecutar: ");
        scanf("%i", &ejercicio);
        switch (ejercicio) {
            case 1:
                validos = cargarNumeros(arr, DIMENSION);
                mostrarArray(arr, validos);
                break;
            case 2:
                ordenarSeleccion(arr, validos);
                mostrarArray(arr, validos);
                break;
            case 3:
                ordenarInsercion(arr, validos);
                mostrarArray(arr, validos);
                break;
            case 4:
                validosString = cargarStrings(strings);
                mostrarStrings(strings, validosString);
                break;
            case 5:
                ordenarSeleccionStrings(strings, validosString);
                mostrarStrings(strings, validosString);
                break;
        };

        printf("\n Deseas ejecutar otro ejercicio? (s/n): ");
        fflush(stdin);
        scanf(" %c", &seguir);
    };
    return 0;
}


int cargarNumeros(int arr[], int dimension) {
    int i = 0;
    char seguir = 's';

    while (seguir == 's' && i < dimension) {
        printf("Ingrese un valor: ");
        scanf(" %i", &arr[i]);

        printf("Deseas continuar?: (s/n)");
        fflush(stdin);
        scanf(" %c", &seguir);
        i++;
    }
    return i;
}

void mostrarArray(int arr[], int validos) {
    for (int i = 0; i < validos; i++) {
        printf(" %i -", arr[i]);
    }
}

int encontrarMenor(int i, int validos, int arr[]) {
    int posMenor = i;
    int menor = arr[i];

    for (int j = i; j < validos; j++) {
        if (arr[j] < menor) {
            posMenor = j;
            menor = arr[j];
        }
    }
    return posMenor;
}

void ordenarSeleccion(int arr[], int validos) {
    int i = 0;
    int posMenor;
    int aux;

    while (i < validos) {
        posMenor = encontrarMenor(i, validos, arr);
        aux = arr[i];
        arr[i] = arr[posMenor];
        arr[posMenor] = aux;
        i++;
    }
}


void encontrarMenorIns(int pos, int aux, int arr[]) {
    while (pos >= 0 && arr[pos] > aux) {
        arr[pos + 1] = arr[pos];
        pos--;
    }
    arr[pos + 1] = aux;
}

void ordenarInsercion(int arr[], int validos) {
    int i = 0;
    int aux;
    while (i < validos - 1) {
        aux = arr[i + 1];
        encontrarMenorIns(i, aux, arr);
        i++;
    }
}

int cargarStrings(char strings[][DIMENSION]) {
    int i = 0;
    char seguir = 's';
    while ((seguir == 's' || seguir == 'S') && i < DIMENSION) {
        printf("Ingrese un string: ");
        scanf(" %s", strings[i]);
        if (i < DIMENSION) {
            printf("Desea continuar?: (s/n)");
            scanf(" %c", &seguir);
        }
        i++;
    }
    return i;
}

void mostrarStrings(char strings[][DIMENSION], int validos) {
    for (int i = 0; i < validos; i++) {
        printf("\n %s", strings[i]);
    }
}

int encontrarPosMenorString(int pos, int validos, char arr[][DIMENSION]) {
    int posMenor = pos;
    char menor[DIMENSION];
    strcpy(menor, arr[posMenor]);

    for (int i = 0; i < validos; i++) {
        if (strcmp(menor, arr[i]) < 0) {
            posMenor = i;
            strcpy(menor, arr[i]);
        }
    }

    return posMenor;
}


void ordenarSeleccionStrings(char arr[][DIMENSION], int validos) {
    int i = 0;
    int posMenor;
    char aux[DIMENSION];

    while (i < validos - 1) {
        posMenor = encontrarMenor(i, validos, arr);
        strcpy(aux, arr[i]);
        strcpy(arr[i], arr[posMenor]);
        strcpy(arr[posMenor], aux);

        i++;
    }
}
