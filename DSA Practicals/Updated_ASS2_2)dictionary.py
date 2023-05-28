class KeyValuePair:
    def __init__(self, key, value):
        self.key = key
        self.value = value

class HashTable:
    def __init__(self, size, replacement=False):
        self.size = size
        self.table = [[] for _ in range(size)]
        self.replacement = replacement

    def hash_function(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self.hash_function(key)
        print(f"{index}\n")

        if self.replacement:
            for pair in self.table[index]:
                if pair.key == key:
                    pair.value = value
                    return

        self.table[index].append(KeyValuePair(key, value))

    def find(self, key):
        index = self.hash_function(key)

        for pair in self.table[index]:
            if pair.key == key:
                return pair.value

        return None

    def delete(self, key):
        index = self.hash_function(key)
        chain = self.table[index]

        for i, pair in enumerate(chain):
            if pair.key == key:
                del chain[i]
                return

    def display(self):
        for i, chain in enumerate(self.table):
            print(f"Chain {i}:")
            for pair in chain:
                print(f"({pair.key}, {pair.value})")
            print()

def main_menu():
    print("Dictionary Operations:")
    print("1. Insert(key, value)")
    print("2. Find(key)")
    print("3. Delete(key)")
    print("4. Display")
    print("5. Exit")

    hash_table_with_chaining = HashTable(10, replacement=False)
    hash_table_with_replacement = HashTable(10, replacement=True)

    while True:
        choice = input("\nEnter your choice: ")

        if choice == "1":
            key = input("Enter the key: ")
            value = input("Enter the value: ")

            hash_table_with_chaining.insert(key, value)
            hash_table_with_replacement.insert(key, value)
        elif choice == "2":
            key = input("Enter the key to find: ")

            value_chaining = hash_table_with_chaining.find(key)
            value_replacement = hash_table_with_replacement.find(key)

            print("\nChaining:")
            if value_chaining is not None:
                print("Value:", value_chaining)
            else:
                print("Key not found.")

            print("\nWith Replacement:")
            if value_replacement is not None:
                print("Value:", value_replacement)
            else:
                print("Key not found.")
        elif choice == "3":
            key = input("Enter the key to delete: ")

            hash_table_with_chaining.delete(key)
            hash_table_with_replacement.delete(key)
        elif choice == "4":
            print("\nChaining Without replacement:")
            hash_table_with_chaining.display()

            print("With Replacement:")
            hash_table_with_replacement.display()
        elif choice == "5":
            break
        else:
            print("Invalid choice. Try again.")

main_menu()
