// Programa para buscar un elemento de forma secuencial y ordenar el arreglo mediante mergesort

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

// Funcion para la busqueda secuencial

int linear_search(int array[], int size, int v)
{
    register int i;

    for (i = 0; i < size; i++)
    {
        if (array[i] == v)
            return i;
    }

    return -1;
}

// Funcion para mezclar particiones de arreglos

void merge(int array[], int start, int mid, int end)
{   
    int i = start;
    int j = mid + 1;
    int k = 0;
    int temp[end - start];

    while (i <= mid && j <= end)
        temp[k++] = (array[i] < array[j] ? array[i++] : array[j++]);
    while (i <= mid)
        temp[k++] = array[i++];
    while (j <= end)
        temp[k++] = array[j++];
    for (i = start, k = 0; i <= end; i++, k++)
        array[i] = temp[k];
}

// Funcion para el mergesort

void merge_sort(int array[], int start, int end)
{
    int mid;

    if (start >= end)
        return;
    
    mid = (start + end) / 2;
    merge_sort(array, start, mid);
    merge_sort(array, mid + 1, end);
    merge(array, start, mid, end);
}

void main()
{
    int n, pos, value;

    printf("\nIngrese la cantidad de elementos del arreglo: ");
    scanf("%d", &n);

    int arr[n];

    // Llamada a funcion para llenar el arreglo e imprimirlo

    fill_array(arr, n);
    print_array(arr, n);

    // Llamada a funcion para buscar un elemento de forma secuencial

    printf("\nIngrese el valor del elemento a buscar: ");
    scanf("%d", &value);

    pos = linear_search(arr, n, value);
    printf("\nLa posicion del elemento %d es: %d", value, pos);

    // Llamada a funcion para el mergesort

    printf("\nOrdenando por mergesort...\n");
    merge_sort(arr, 0, n - 1);
    print_array(arr, n);
}