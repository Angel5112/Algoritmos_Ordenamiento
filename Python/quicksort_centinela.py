# Programa para buscar un elemento por centinela y ordenar la lista por quicksort

# Funcion para rellenar una lista

def fill_list(lista):
    length = int(input("\nIngrese la longitud de la lista: "))

    for i in range(0, length):
        element = int(input(f"\nIngresa el valor del elemento {i}: "))
        lista.append(element)

# Funcion para la busqueda por centinela

def sentinel_search(lista, size, v):

    lista.append(v)
    i = 0

    while lista[i] != v:
        i += 1

    if i < size:
        return i
    else:
        return -1

# Funcion para particionar la lista

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

# Funcion para el quicksort

def quick_sort(lista, start, end):

    if start < end:
        pivote = partition(lista, start, end)
        quick_sort(lista, start, pivote - 1)
        quick_sort(lista, pivote + 1, end)



# Programa main()

int_list = []

# Llamada a funcion para rellenar la lista

fill_list(int_list)
print(f"\nLa lista es: {int_list}")
list_size = len(int_list)

# Llamada a funcion para la busqueda por centinela

value = int(input("Ingrese el valor del elemento a buscar: "))
pos = sentinel_search(int_list, list_size, value)
print(f"\nLa posicion del elemento {value} es: {pos}")

# Removiendo el centinela de la lista

int_list.pop()

# Llamada a funcion para ordenar por quicksort

print("\nOrdenando por quicksort...")
quick_sort(int_list, 0, list_size - 1)
print(f"\nLa lista ordenada es: {int_list}")