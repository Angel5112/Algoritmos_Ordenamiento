# Programa para buscar un elemento de forma secuencial y ordenar la lista mediante insertion sort

# Funcion para llenar una lista

def fill_list(lista):
    length = int(input("\nIngrese la cantidad de elementos de la lista: "))

    for i in range(0, length):
        value = int(input(f"Ingrese el elemento numero {i}: "))
        lista.append(value)

# Funcion para la linear search

def linear_search(lista, size, v):

    for i in range(0, size):
        if lista[i] == v:
            return i
    
    return -1

# Funcion para el insertion sort

def insertion_sort(lista, size):

    for i in range(1, size):
        t = lista[i]
        j = i
        while (j > 0) and (t < lista[j - 1]):
            lista[j] = lista[j - 1]
            j -= 1
        
        lista[j] = t



# Funcion main()

int_list = []

# Llamada a funcion para llenar la lista

fill_list(int_list)
print(f"\nLa lista es: {int_list}")
list_size = len(int_list)

# Llamada a funcion para la linear search

value = int(input("Ingrese el valor del elemento a buscar: "))
pos = linear_search(int_list, list_size, value)
print(f"\nLa posicion del elemento {value} es: {pos}")

# Llamada a funcion para el insertion sort

print("\nOrdenando por insertion sort...\n")
insertion_sort(int_list, list_size)
print(f"La lista es: {int_list}\n")

