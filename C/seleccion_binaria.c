// Programa para ordenar mediante selection sort y buscar mediante busqueda binaria

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

// Funcion del selection sort

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

// Funcion para busqueda binaria

int binary_search(int arr[], int size, int v)
{
    int start, end, mid;
    start = 0;
    end = size - 1;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (arr[mid] == v)
            return mid;
        else if (arr[mid] > v)
            end = mid - 1;
        else
            start = mid + 1;
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

    // Llamada a funcion para ordenar mediante selection sort

    printf("\nOrdenando mediante selection sort...\n");
    selection_sort(array, n);
    print_array(array, n);

    // Llamada a funcion para la busqueda binaria

    printf("\nIngrese el valor del elemento a buscar: ");
    scanf("%d", &value);

    pos = binary_search(array, n, value);
    printf("\nLa posicion del elemento es: %d\n", pos);

}