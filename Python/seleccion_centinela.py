# Programa para buscar un elemento con centinela y ordenarlo usando el algoritmo de selection sort

# Funcion para llenar una lista

def fill_list(lista):
    length = int(input("\nIngrese la cantidad de elementos de la lista: "))

    for i in range(0, length):
        value = int(input(f"Ingrese el elemento numero {i}: "))
        lista.append(value)

# Funcion para la busqueda secuencial con centinela

def sentinel_search(lista, size, v):
    lista.append(v)
    i = 0

    while (lista[i] != v):
        i += 1

    if i < size:
        return i
    else:
        return -1

# Funcion para el selection sort

def selection_sort(lista, size):

    for i in range(0, size - 1):
        min = i
        for j in range(i + 1, size):
            if lista[j] < lista[min]:
                min = j
        
        if min != i:
            aux = lista[i]
            lista[i] = lista[min]
            lista[min] = aux



# Programa main()

int_list = []

# Llamada a funcion para llenar la lista

fill_list(int_list)
list_size = len(int_list)
print(f"\nLa lista es: {int_list}")

# Llamada a funcion para buscar un elemento con centinela

value = int(input("Ingrese el valor del elemento a buscar: "))
pos = sentinel_search(int_list, list_size, value)
print(f"\nLa posicion del elemento {value} es {pos}")
int_list.pop()

# Llamada a funcion para ordenar el arreglo mediante selection sort

print("\nOrdenando mediante selection sort...\n")
selection_sort(int_list, list_size)
print(f"La lista es: {int_list}")