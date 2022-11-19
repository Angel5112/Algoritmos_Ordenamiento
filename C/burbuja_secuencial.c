// Programa para implementar la busqueda secuencial y el ordenamiento por intercambio burbuja

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

int b_secuencial(int arr[], int size, int v)
{
    register int i;

    for (i = 0; i < size; i++)
    {
        if (arr[i] == v)
            return i;
    }

    return -1;
}

// Funcion para el ordenamiento por intercambio

void bubble_sort(int arr[], int size)
{
    register int i, j;

    printf("\nOrdenando el arreglo con el algoritmo de intercambio por burbujas\n");

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

    // Calculando la longitud del arreglo

    length = sizeof(array)/sizeof(array[0]);

    // Llamada a funcion para llenar un arreglo

    fill_array(array, length);

    // Llamada a funcion para imprimir un arreglo

    print_array(array, length);

    // Llamada a funcion para la busqueda secuencial

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &value);

    pos = b_secuencial(array, length, value);

    printf("\nEl elemento %d se encuentra en la posicion %d\n", value, pos);

    // Llamada a funcion para el ordenamiento por burbuja

    bubble_sort(array, length);

    print_array(array, length);
}