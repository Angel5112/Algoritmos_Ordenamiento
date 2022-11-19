// Programar para ordenar un arreglo con bubble sort y buscar un elemento con busqueda binaria

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

// Funcion para el bubble sort

void bubble_sort(int arr[], int size)
{
    register int i, j;
    printf("\nOrdenando el arreglo por bubble sort");

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int aux;
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}

// Funcion para la binary search

int binary_search(int arr[], int size, int v)
{
    int start, middle, end;
    start = 0;
    end = size - 1;

    while (start <= end)
    {
        middle = (start + end) / 2;

        if (arr[middle] == v)
            return middle;
        else if (arr[middle < v])
            start = middle + 1;
        else
            end = middle - 1;
    }

    return -1;
}

void main()
{
    int length, pos, value, n;

    printf("\nIngrese la longitud del arreglo: ");
    scanf("%d", &n);

    int array[n];

    length = sizeof(array)/sizeof(array[0]);

    // Llamada a funcion para rellenar el arreglo

    fill_array(array, length);
    print_array(array, length);

    // Llamada a funcion para el bubble sort

    bubble_sort(array, length);
    print_array(array, length);

    // Llamada a funcion para la busqueda binaria

    printf("\nIngrese el valor del elemento a buscar: ");
    scanf("%d", &value);

    pos = binary_search(array, length, value);
    printf("\nLa posicion del elemento %d es %d\n", value, pos);
}