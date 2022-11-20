// Programa para ordenar un arreglo mediante insertion sort y buscar un elemento mediante binary_search

#include <stdio.h>

// Funcion para llenar un arreglo

void fill_array(int arr[], int size)
{
    register int i;
    int element;

    for (i = 0; i < size; i++)
    {
        printf("\nIngrese el valor del elemento %d ", i);
        scanf("%d", &element);
        arr[i] = element;
    }
    printf("\n");
}

// Funcion para imprimir un arreglo

void print_array(int arr[], int size)
{
    register int i;

    printf("\nLos elementos del arreglo son: [ ");
    
    for (i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
    printf("]\n");
}

void insertion_sort(int arr[], int size)
{
    register int i, j;
    int t;

    for (i = 1; i < size; i++)
    {
        t = arr[i];
        for (j = i; j > 0 && t < arr[j - 1]; j--)
            arr[j] = arr[j - 1];
        
        arr[j] = t;
    }
}

// Funcion para la binary search

int binary_search(int arr[], int size, int v)
{
    int start, end, mid;

    start = 0;
    end = size - 1;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (arr[mid] == v)
            return mid;
        else if (arr[mid] < v)
            start = mid + 1;
        else
            end = mid - 1;
    }
}

void main()
{
    int n, value, pos;

    printf("\nIngrese la cantidad de elementos del arreglo: ");
    scanf("%d", &n);

    int array[n];

    // Llamada a funcion para llenar los elementos del arreglo

    fill_array(array, n);
    print_array(array, n);
    
    // Llamada a funcion para ordenar por insertion sort

    printf("\nOrdenando por insertion sort...");
    insertion_sort(array, n);
    print_array(array, n);

    // Llamada a funcion para buscar un elemento mediante binary search

    printf("\nIngrese el valor del elemento a buscar: ");
    scanf("%d", &value);

    pos = binary_search(array, n, value);
    printf("\nLa posicion del elemento %d es: %d", value, pos);
}