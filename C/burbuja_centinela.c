// Programa para implementar la busqueda por centinela y ordenar el arreglo usando el algoritmo del bubble sort

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

// Funcion para la busqueda por centinela

int sentinel_search(int arr[], int size, int v)
{
    register int i;

    for (i = 0, arr[size] = v; arr[i] != v; i++);

    if (i < size)
        return i;
    else
        return -1;
}

// Funcion para el bubble sort

void bubble_sort(int arr[], int size)
{
    register int i, j;

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

void main()
{
    int length, pos, value, n;
    
    printf("\nIngrese la cantidad de elementos del arreglo: ");
    scanf("%d", &n);

    int array[n];

    length = sizeof(array)/sizeof(array[0]);

    // Llamada a funcion para rellenar el arreglo

    fill_array(array, length);
    print_array(array, length);

    // Llamada a funcion para la busqueda por centinela

    printf("\nIngrese el elemento que desea buscar: ");
    scanf("%d", &value);

    pos = sentinel_search(array, length, value);
    printf("\nLa posicion del elemento %d es %d\n", value, pos);

    // Llamada a funcion para ordenar por bubble sort

    bubble_sort(array, length);
    print_array(array, length);
}