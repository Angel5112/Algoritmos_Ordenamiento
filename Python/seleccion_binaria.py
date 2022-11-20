# Programa para ordenar una lista mediante selection sort y luego buscar un elemento mediante binary search

# Funcion para llenar una lista

def fill_list(lista):
    length = int(input("\nIngrese la cantidad de elementos de la lista: "))

    for i in range(0, length):
        value = int(input(f"Ingrese el elemento numero {i}: "))
        lista.append(value)

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

# Funcion para la binary search

def binary_search(lista, size, v):
    start = 0
    end = size - 1

    while start <= end:
        mid = (start + end) // 2

        if lista[mid] == v:
            return mid
        elif lista[mid] < v:
            start = mid + 1
        else:
            end = mid - 1
    
    return -1


# Funcion main()

int_list = []

# Llamada a funcion para llenar la lista

fill_list(int_list)
list_size = len(int_list)
print(f"\nLa lista es: {int_list}")

# Llamada a funcion para ordenar la lista mediante selection sort

print("\nOrdenando con selection sort...\n")
selection_sort(int_list, list_size)
print(f"La lista es: {int_list}\n")

# Llamada a funcion para la binary search

value = int(input("Ingrese el valor del elemento a buscar: "))
pos = binary_search(int_list, list_size, value)
print(f"\nLa posicion del elemento {value} es: {pos}\n")