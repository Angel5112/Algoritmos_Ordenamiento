// Pograma para ordenar un arreglo mediante el algoritmo de QuickSort y buscar un elemento mediante Binary Search

#include <stdio.h>

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
        printf("%d ", arr[i]);
    }
    
    printf("]\n");
}

// Funcion para particionar el arreglo

int partition(int arr[], int start, int end)
{
    register int j;
    int pivote, i, aux;
    pivote = arr[end];
    i = start - 1;

    for (j = start; j <= end - 1; j++)
    {
        if (arr[j] < pivote)
        {
            i++;
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }
    }
    i++;
    aux = arr[i];
    arr[i] = arr[end];
    arr[end] = aux;

    return i;
}

// Funcion para el ordenamiento por QuickSort

void quick_sort(int arr[], int start, int end)
{
    int pivote;

    if (start < end)
    {
        pivote = partition(arr, start, end);
        quick_sort(arr, start, pivote - 1);
        quick_sort(arr, pivote + 1, end);
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

    return -1;
}

void main()
{
    int n, value, pos;

    printf("\nIngrese la cantidad de elementos del arreglo: ");
    scanf("%d", &n);

    int array[n];

    // Llamada a funcion para rellenar el arreglo

    fill_array(array, n);
    print_array(array, n);

    // Llamada a funcion para ordenar el arreglo mediante QuickSort

    printf("\nOrdenando mediante Quicksort...\n");
    quick_sort(array, 0, n - 1);
    print_array(array, n);

    // Busqueda de un elemento por binary search

    printf("Ingrese el valor del elemento a buscar: ");
    scanf("%d", &value);

    pos = binary_search(array, n, value);
    printf("\nLa posicion del elemento %d es: %d\n", value, pos);
}