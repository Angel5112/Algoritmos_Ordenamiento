# Programa para ordenar la lista por bubble sort y buscar un elemento por busqueda binaria

# Funcion para rellenar una lista

def fill_list(lista):
    length = int(input("\nIngrese la longitud de la lista: "))

    for i in range(0, length):
        element = int(input(f"\nIngresa el valor del elemento {i}: "))
        lista.append(element)

# Funcion para el bubble sort

def bubble_sort(lista, size):
    print("\nOrdenando la lista por bubble sort")

    for i in range(0, size - 1):
        for j in range(0, size - i - 1):
            if lista[j] > lista[j + 1]:
                aux = lista[j]
                lista[j] = lista[j + 1]
                lista[j + 1] = aux


# Funcion para la busqueda binaria

def binary_search(lista, size, v):
    start = 0
    end = size - 1

    while start <= end:

        middle = (start + end) // 2

        if lista[middle] == v:
            return middle
        elif lista[middle] > v:
            end = middle - 1
        else:
            start = middle + 1

    return -1



# MAIN PROGRAM

int_list = []

# Llamada a funcion para rellenar la lista

fill_list(int_list)
print(f"\nLa lista es: {int_list}\n")

# Llamada a funcion para el bubble sort

length = len(int_list)
bubble_sort(int_list, length)
print(f"\nLa lista ordenada es: {int_list}\n")

# Llamada a funcion para la busqueda binaria

value = int(input("Ingrese el valor del elemento a buscar: "))

pos = binary_search(int_list, length, value)
print(f"\nLa posicion del elemento {value} es {pos}")
