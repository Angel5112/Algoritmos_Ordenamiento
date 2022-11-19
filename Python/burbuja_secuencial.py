# Programa para buscar un elemento de forma secuencial en una lista y ordenarlo usando el metodo de la burbuja

# Funcion para rellenar una lista

def fill_list(lista):
    length = int(input("\nIngrese la longitud de la lista: "))

    for i in range(0, length):
        element = int(input(f"\nIngresa el valor del elemento {i}: "))
        lista.append(element)

# Funcion para la busqueda secuencial

def linear_search(lista, size, value):

    for i in range(0, size):
        if lista[i] == value:
            return i
    
    return -1

# Funcion para el ordenamiento por intercambio de burbujas

def bubble_sort(lista, size):
    print("\nOrdenando el arreglo por algoritmo de intercambio por burbujas\n")

    for i in range(0, size - 1):
        for j in range(0, size - i - 1):
            if lista[j] > lista[j + 1]:
                aux = lista[j]
                lista[j] = lista[j + 1]
                lista[j + 1] = aux

# PROGRAMA PRINCIPAL

int_list = [];

# Llamada a funcion para rellenar la lista

fill_list(int_list)

# Imprimir la lista

print(f"\nLa lista es: {int_list}")

# Llamada a funcion para implementar la busqueda secuencial

list_length = len(int_list)
v = int(input("\nIngrese el valor del elemento a buscar: "))

pos = linear_search(int_list, list_length, v)
print(f"\nLa posicion del elemento {v} es {pos}")

# Llamada a funcion para implementar el ordenamiento por burbuja

bubble_sort(int_list, list_length)
print(f"La lista ordenada es: {int_list}")
