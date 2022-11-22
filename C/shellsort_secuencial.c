// Programa para buscar un elemento de forma secuencial y ordenarlo por shellsort

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

// Funcion para la busqueda lineal

int linear_search(int arr[], int size, int v)
{
    register int i;

    for (i = 0; i < size; i++)
    {
        if (arr[i] == v)
            return i;
    }

    return -1;
}

// Funcion para el shellsort

void shell_sort(int arr[], int size)
{
    int gap, i, j, t;

    for (gap = size / 2; gap > 0; gap = gap / 2)
    {
        // Comienza la insercion

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

    printf("\nIngrese la cantidad de elementos del arreglo: ");
    scanf("%d", &n);

    int array[n];

    // Llamada a funcion para rellenar e imprimir el arreglo

    fill_array(array, n);
    print_array(array, n);

    // Llamada a funcion para buscar un elemento de forma secuencial

    printf("\nIngrese el valor del elemento a buscar: ");
    scanf("%d", &value);

    pos = linear_search(array, n, value);
    printf("\nLa posicion del elemento %d es: %d", value, pos);

    // Llamada a funcion para ordenar por shellsort

    printf("\nOrdenando por shellsort...\n");
    shell_sort(array, n);
    print_array(array, n);
}