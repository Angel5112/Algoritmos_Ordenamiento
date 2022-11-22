# Programa para ordenar lista por quicksort y buscar un elemento por busqueda binaria

# Funcion para rellenar una lista

def fill_list(lista):
    length = int(input("\nIngrese la longitud de la lista: "))

    for i in range(0, length):
        element = int(input(f"\nIngresa el valor del elemento {i}: "))
        lista.append(element)

# Funcion para particionar una lista

def partition(lista, start, end):

    pivote = lista[end]
    i = start

    for j in range(start, end):
        if lista[j] < pivote:
            aux = lista[i]
            lista[i] = lista[j]
            lista[j] = aux
            i += 1

    aux = lista[i]
    lista[i] = lista[end]
    lista[end] = aux

    return i

# Funcion para ordenar por quicksort

def quick_sort(lista, start, end):

    if start < end:

        pivote = partition(lista, start, end)
        quick_sort(lista, start, pivote - 1)
        quick_sort(lista, pivote + 1, end)

# Funcion para la binary search

def binary_search(lista, size, v):

    start = 0
    end = size - 1
    mid = 0

    while start <= end:

        mid = (start + end) // 2

        if lista[mid] == v:
            return mid
        elif lista[mid] < v:
            start = mid + 1
        else:
            end = mid - 1

    return -1



# Programa main()

int_list = []

# Llamada a funcion para rellenar la lista

fill_list(int_list)
print(f"\nLa lista es: {int_list}")
list_size = len(int_list)

# Llamada a funcion para ordenar por quicksort

print(f"\nOrdenando por quicksort...\n")
quick_sort(int_list, 0, list_size - 1)
print(f"La lista ordenada es: {int_list}")

# Llamada a funcion para la busqueda binaria

value = int(input("Ingrese el valor del elemento a buscar: "))
pos = binary_search(int_list, list_size, value)
print(f"\nLa posicion del elemento {value} es: {pos}")