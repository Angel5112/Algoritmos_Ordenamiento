# Programa para buscar un elemento con centinela y ordenar la lista con insertion sort

# Funcion para llenar una lista

def fill_list(lista):
    length = int(input("\nIngrese la cantidad de elementos de la lista: "))

    for i in range(0, length):
        value = int(input(f"Ingrese el elemento numero {i}: "))
        lista.append(value)

# Funcion de busqueda con centinela

def sentinel_search(lista, size, v):
    lista.append(v)
    i = 0

    while (lista[i] != v):
        i += 1
    
    if i < size:
        return i
    else:
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



# Programa main()

int_list = []

# Llamada a funcion para llenar la lista

fill_list(int_list)
print(f"\nLa lista es: {int_list}")
list_size = len(int_list)

# Llamada a funcion para buscar un elemento con centinela

value = int(input("Ingrese el valor del elemento a buscar: "))
pos = sentinel_search(int_list, list_size, value)
print(f"\nLa posicion del elemento {value} es: {pos}")
int_list.pop()

# Llamada a funcion para ordenar la lista mediante insertion sort

print("\nOrdenando por insertion sort...")
insertion_sort(int_list, list_size)
print(f"\nLa lista es: {int_list}")