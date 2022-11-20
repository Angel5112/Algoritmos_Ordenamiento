// Programa para implementar la busqueda con centinela y el ordenamiento por insertion sort

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

// Funcion para buscar un elemento por centinela

int sentinel_search(int arr[], int size, int v)
{
    register int i;

    for (i = 0, arr[size] = v; arr[i] != v; i++);

    if (i < size)
        return i;
    else
        return -1;
}

// Funcion para el insertion sort

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

void main()
{
    int n, value, pos;

    printf("\nIngrese la cantidad de elementos del arreglo: ");
    scanf("%d", &n);

    int array[n];

    // Llamada a funcion para llenar el arreglo

    fill_array(array, n);
    print_array(array, n);

    // Llamada a funcion para buscar un elemento por centinela

    printf("\nIngrese el valor del elemento a buscar: ");
    scanf("%d", &value);

    pos = sentinel_search(array, n, value);
    printf("\nLa posicion del elemento %d es: %d", value, pos);

    // Llamada a funcion para el ordenamiento por insertion sort

    printf("\nOrdenando por insertion sort!");
    insertion_sort(array, n);
    print_array(array, n);
}