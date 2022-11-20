# Programa que busca un elemento de forma secuencial y ordena la lista usando selection sort

# Funcion para llenar una lista

def fill_list(lista):
    length = int(input("\nIngrese la cantidad de elementos de la lista: "))

    for i in range(0, length):
        value = int(input(f"Ingrese el elemento numero {i}: "))
        lista.append(value)

# Funcion para buscar un elemento de forma secuencial

def linear_search(lista, size, v):

    for i in range(0, size):
        if lista[i] == v:
            return i
    
    return -1

# Funcion para ordenar la lista usando selection sort

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

# Llamada a funcion para buscar un elemento en la lista

value = int(input("\nIngrese el elemento a buscar: "))
pos = linear_search(int_list, list_size, value)
print(f"\nLa posicion del elemento {value} es: {pos}")

# Llamada a funcion para ordenar la lista usando selection sort

print("\nOrdenando mediante selection sort...")
selection_sort(int_list, list_size)
print(f"\nLa lista ordenada es: {int_list}\n")