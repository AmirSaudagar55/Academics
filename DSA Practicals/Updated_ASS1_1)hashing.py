clients = [None] * 10  # Directory to store client information
tab_size = len(clients)  # Size of the directory

def hash_function(x):
    return sum(ord(char) for char in x) % tab_size  # Simple hash function based on character ASCII values

def insert_linear_probing(name, number):
    global clients, tab_size
    index = hash_function(name)  # Hash Function

    while clients[index] is not None:
        index = (index + 1) % tab_size  # Linear Probing

    clients[index] = (name, number)
    print("Data inserted successfully using Linear Probing.")

def insert_quadratic_probing(name, number):
    global clients, tab_size
    index = hash_function(name)  # Hash Function
    offset = 1

    while clients[index] is not None:
        index = (index + offset**2) % tab_size  # Quadratic Probing
        offset += 1

    clients[index] = (name, number)
    print("Data inserted successfully using Quadratic Probing.")

def look_up_linear_probing(x):
    global clients, tab_size
    index = hash_function(x)  # Hash Function
    comparisons = 0

    while clients[index] is not None:
        comparisons += 1
        if clients[index][0] == x:
            print(f"{x} client has telephone number as: {clients[index][1]}")
            break
        index = (index + 1) % tab_size

    if clients[index] is None:
        print("Client not found.")

    return comparisons

def look_up_quadratic_probing(x):
    global clients, tab_size
    index = hash_function(x)  # Hash Function
    offset = 1
    comparisons = 0

    while clients[index] is not None:
        comparisons += 1
        if clients[index][0] == x:
            print(f"{x} client has telephone number as: {clients[index][1]}")
            break
        index = (index + offset**2) % tab_size  # Quadratic Probing
        offset += 1

    if clients[index] is None:
        print("Client not found.")

    return comparisons

def main_menu():
    print("1. Insert data in Directory using Linear Probing")
    print("2. Insert data in Directory using Quadratic Probing")
    print("3. Look-up for Clients telephone no using Linear Probing")
    print("4. Look-up for Clients telephone no using Quadratic Probing")
    print("5. Exit")
    ch = int(input("Enter your choice: "))

    if ch == 1:
        print("Inserting data in directory using Linear Probing......")
        name = input("Enter the name: ")
        number = int(input("Enter the number: "))
        insert_linear_probing(name, number)
        print("-------------------------------------------------------")
        main_menu()
    elif ch == 2:
        print("Inserting data in directory using Quadratic Probing......")
        name = input("Enter the name: ")
        number = int(input("Enter the number: "))
        insert_quadratic_probing(name, number)
        print("-------------------------------------------------------")
        main_menu()
    elif ch == 3:
        print("Look-up data from directory using Linear Probing......")
        x = input("Enter the client name for look-up: ")
        comparisons = look_up_linear_probing(x)
        print(f"Total comparisons: {comparisons}")
        print("-------------------------------------------------------")
        main_menu()
    elif ch == 4:
        print("Look-up data from directory using Quadratic Probing......")
        x = input("Enter the client name for look-up: ")
        comparisons = look_up_quadratic_probing(x)
        print(f"Total comparisons: {comparisons}")
        print("-------------------------------------------------------")
        main_menu()
    elif ch == 5:
        exit()
    else:
        print("Enter a valid choice.")
        main_menu()

print("DSL Assignment no: 1")
print("Telephone Directory using Hashing")
main_menu()
