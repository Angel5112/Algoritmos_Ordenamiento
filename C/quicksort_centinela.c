// Programa para buscar un elemento con centinela y ordenar el arreglo mediante quicksort

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

    arr[size] = v;

    for (i = 0; arr[i] != v; i++);
    if (i < size)
        return i;
    else
        return -1;
}

// Funcion para la particion del arreglo

int partition(int arr[], int start, int end)
{
    register int j;
    int i, aux, pivote;

    i = start - 1;
    pivote = arr[end];

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

// Funcion para el ordenamiento por quicksort

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

void main()
{
    int n, pos, value;

    printf("\nIngrese la cantidad de elementos del arreglo: ");
    scanf("%d", &n);

    int array[n];

    // Llamada a funcion para llenar el arreglo

    fill_array(array, n);
    print_array(array, n);

    // Llamada a funcion para buscar un elemento por centinela

    printf("\nIngrese el valor del elemento a buscar: \n");
    scanf("%d", &value);
    pos = sentinel_search(array, n, value);
    printf("\nLa posicion del elemento %d es: %d", value, pos);

    // Llamada a funcion para ordenar el arreglo mediante quicksort

    printf("\nOrdenando por quicksort...\n");
    quick_sort(array, 0, n - 1);
    print_array(array, n);
}