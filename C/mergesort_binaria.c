// Programa para ordenar un arreglo por mergesort y buscar un elemento por busqueda binaria

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

// Funcion para mezclar las particiones del arreglo

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

    // Llamada a funcion para el mergesort

    printf("\nOrdenando por mergesort...\n");
    merge_sort(array, 0, n - 1);
    print_array(array, n);

    // Llamada a funcion para la busqueda binaria

    printf("\nIngrese el valor del elemento a buscar: ");
    scanf("%d", &value);

    pos = binary_search(array, n, value);
    printf("\nLa posicion del elemento %d es: %d\n", value, pos);
}