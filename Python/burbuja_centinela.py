# Programa para buscar un elemento mediante centinela en una lista y ordenarla usando ordenamiento por intercambio burbujas

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

    while (lista[i] != v):
        i += 1;

    if i < size:
        return i
    else:
        return -1

# Funcion para el bubble sort

def bubble_sort(lista, size):
    print("\nOrdenando por bubble sort")

    for i in range(0, size - 1):
        for j in range(0, size - i - 1):
            if lista[j] > lista[j + 1]:
                aux = lista[j]
                lista[j] = lista[j + 1]
                lista[j + 1] = aux



# MAIN PROGRAM

int_list = [];

# Llamada a funcion para rellenar la lista

fill_list(int_list)
print(f"\nLa lista es: {int_list}")

# Llamada a funcion para la busqueda por centinela

length = len(int_list)
value = int(input("\nIngrese el valor del elemento a buscar: "))
pos = sentinel_search(int_list, length, value)
print(f"\nLa posicion del elemento {value} es {pos}")

# Eliminando el centinela de la lista

int_list.pop()

# Llamada a funcion para el bubble sort

bubble_sort(int_list, length)
print(f"\nLa lista ordenada es: {int_list}")
