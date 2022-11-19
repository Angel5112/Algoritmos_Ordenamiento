// Implementacion de busqueda secuencial y ordenamiento por seleccion

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

// Funcion para buscar un elemento de forma secuencial

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

// Funcion para implementar selection sort

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
    int pos, n, value;

    printf("\nIngrese la cantidad de elementos del arreglo: ");
    scanf("%d", &n);

    int array[n];

    // Llamada a funcion para rellenar el arreglo

    fill_array(array, n);
    print_array(array, n);

    // Llamada a funcion para buscar un elemento

    printf("\nIngrese el valor del elemento a buscar: ");
    scanf("%d", &value);

    pos = linear_search(array, n, value);

    printf("\nLa posicion del elemento es: %d\n", pos);

    // Llamada a funcion para ordenar el arreglo por seleccion

    selection_sort(array, n);
    printf("\nOrdenando el arreglo por seleccion...\n");
    print_array(array, n);
}