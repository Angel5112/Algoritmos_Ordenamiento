// Programa para buscar un elemento por centinela y ordenar el arreglo mediante mergesort

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

// Funcion para la busqueda con centinela

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

// Funcion para el merge de particiones

void merge(int arr[], int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = 0;
    int temp[end - start];

    while (i <= mid && j <= end)
        temp[k++] = (arr[i] < arr[j] ? arr[i++] : arr[j++]);
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= end)
        temp[k++] = arr[j++];
    for (i = start, k = 0; i <= end; i++, k++)
        arr[i] = temp[k];
}

// Funcion para el mergesort

void merge_sort(int arr[], int start, int end)
{
    int mid;

    if (start >= end)
        return;
    
    mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
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

    // Llamada a funcion para buscar un elemento por centinela

    printf("\nIngrese el valor del elemento a buscar: ");
    scanf("%d", &value);

    pos = sentinel_search(array, n, value);
    printf("\nLa posicion del elemento %d es: %d", value, pos);

    // Llamada a funcion para el mergesort

    printf("\nOrdenando por mergesort...\n");
    merge_sort(array, 0, n - 1);
    print_array(array, n);
}