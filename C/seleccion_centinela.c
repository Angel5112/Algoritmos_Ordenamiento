// Programa donde se busca un elemento por centinela y se ordena usando el algoritmo de selection sort

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

// Funcion de busqueda por centinela

int sentinel_search(int arr[], int size, int v)
{
    register int i;

    for (i = 0, arr[size] = v; arr[i] != v; i++);

    if (i < size)
        return i;
    else
        return -1;
}

// Funcion para ordenar por selection sort

void selection_sort(int arr[], int size)
{
    register int i, j;
    int min;

    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i)
        {
            int aux;
            aux = arr[i];
            arr[i] = arr[min];
            arr[min] = aux;
        }
    }
}

void main()
{
    int n, pos, value;

    printf("\nIngrese la cantidad de elementos del arreglo: ");
    scanf("%d", &n);

    int array[n];

    // Llamada a funcion para rellenar el arreglo

    fill_array(array, n);

    // Llamada a funcion para imprimir el arreglo

    print_array(array, n);

    // Llamada a funcion para buscar un elemento por centinela

    printf("\nIngrese el elemento a buscar en el arreglo: ");
    scanf("%d", &value);

    pos = sentinel_search(array, n, value);
    printf("\nLa posicion del elemento es: %d", pos);

    // Llamada a funcion para ordenar el arreglo por selection sort

    selection_sort(array, n);
    printf("\nOrdenando por seleccion...\n");
    print_array(array, n);
}