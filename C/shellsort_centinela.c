// Programa para buscar un elemento con centinela y ordenar el arreglo mediante shellsort

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

// Funcion para buscar por centinela

int sentinel_search(int arr[], int size, int v)
{
    register int i;

    arr[size] = v;

    for (i = 0; arr[i] != v; i++);

    if (i < size)
        return i;
    else
        return -1;
}

// Funcion para el shellsort

void shell_sort(int arr[], int size)
{
    int gap, i, j, t;

    for (gap = size / 2; gap > 0; gap = gap / 2)
    {
        // Insertion sort

        for (i = gap; i < size; i++)
        {
            t = arr[i];
            for (j = i - gap; j >= 0 && t < arr[j]; j = j - gap)
                arr[j + gap] = arr[j];
            
            arr[j + gap] = t;
        }
    }
}

void main()
{
    int n, pos, value;

    printf("\nIngrese la cantidad de elementos del arreglo");
    scanf("%d", &n);

    int array[n];

    // Llamada a funcion para rellenar el arreglo

    fill_array(array, n);
    print_array(array, n);

    // Llamada a funcion para la busqueda por centinela

    printf("\nIngrese el valor del elemento a buscar: ");
    scanf("%d", &value);

    pos = sentinel_search(array, n, value);
    printf("\nLa posicion del elemento %d es: %d", value, pos);

    // Llamada a funcion para el mergesort

    printf("\nOrdenando por shellsort...\n");
    shell_sort(array, n);
    print_array(array, n);
}