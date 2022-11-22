// Programa para ordenar un arreglo por shellsort y buscar por busqueda binaria

#include <stdio.h>

// Funcion para rellenar el arreglo

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

// Funcion para el shellsort

void shell_sort(int arr[], int size)
{
    int gap, i, j, t;

    for (gap = size / 2; gap > 0; gap = gap / 2)
    {
        for (i = gap; i < size; i++)
        {
            t = arr[i];
            for (j = i - gap; j >= 0 && t < arr[j]; j = j - gap)
                arr[j + gap] = arr[j];

            arr[j + gap] = t;
        }
    }
}

// Funcion para la binary search

int binary_search(int arr[], int size, int v)
{
    int start, mid, end;

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
    int n, pos, value;

    printf("\nIngrese la cantidad de elementos del arreglo: ");
    scanf("%d", &n);

    int array[n];

    // Llamada a funcion para rellenar el arreglo

    fill_array(array, n);
    print_array(array, n);

    // Llamada a funcion para ordenar por shellsort

    printf("\nOrdenando por shellsort...\n");
    shell_sort(array, n);
    print_array(array, n);

    // Llamada para busqueda binaria

    printf("\nIngrese el valor del elemento a buscar: ");
    scanf("%d", &value);
    pos = binary_search(array, n, value);
    printf("\nLa posicion del elemento %d es: %d\n", value, pos);
}