class PhoneDirectory:
    def __init__(self):
        self.MAX = 10
        self.arrSeperate = [[] for i in range(self.MAX)]
        self.arrLinear = [None for i in range(self.MAX)]
    
    def get_hash(self, key):
        hash = 0
        for char in key:
            hash += ord(char)
        return hash % self.MAX


    #--------------------------------------------Separate Chaining--------------------------------------------------------------    
    def setSeparate(self, key, value):
        h = self.get_hash(key)
        found = False
        
        for index,element in enumerate(self.arrSeperate):
            if(len(element)==2 and element[0] == key):
                self.arrSeperate[h][index] = (key,value)
                found = True
                break
            
        if not found:
            self.arrSeperate[h].append((key,value))
    
    def lookSeparate(self, key):
        comparison = 0
        h = self.get_hash(key)
        for element in self.arrSeperate[h]:
            comparison += 1
            if(element[0] == key):
                print("Comparison Required : ",comparison)
                return element[1]
            

    #--------------------------------LINEAR PROBING--------------------------------------------------------------
    def setLinear(self, key, value):
        index = self.get_hash(key)
        # Linear probing to find the next available slot
        while self.arrLinear[index] is not None:
            # If the key already exists, update the value
            if self.arrLinear[index][0] == key:
                self.arrLinear[index] = (key, value)
                return
            index = (index + 1) % self.MAX
        
        # Insert the key-value pair at the available slot
        self.arrLinear[index] = (key, value)
    
    def lookLinear(self, key):
        comparison = 0
        index = self.get_hash(key)
        
        while self.arrLinear[index] is not None:
            comparison += 1
            if self.arrLinear[index][0] == key:
                print("Comparison required : ",comparison)
                return self.arrLinear[index][1]
            index = (index + 1) % self.MAX
        
        # Key not found
        return None
    
def main():
    d1 = PhoneDirectory()
    
    while(True):
        print("\n1.Add Contact using Separate Chainging")
        print("\n2.Add Contact using Linear Probing")
        print("\n3.Display Contact using Separate Chaining")
        print("\n4.Display Contact using Linear Probing")
        print("\n5.Exit")
        choice = int(input("Enter the choice : "))
        
        if(choice == 1):
            print("\nInserting using Separate Chaining")
            name = input("Enter name : ")
            number = int(input("Enter Phone Number : "))
            d1.setSeparate(name, number)
            print("\n")
            print(d1.arrSeperate)
            print("\n--------------------------------------------------------------------------\n")
            
        elif (choice == 2):
            print("\nInserting using Linear Chaining")
            name = input("Enter name : ")
            number = int(input("Enter Phone Number : "))
            d1.setLinear(name, number)
            print("\n")
            print(d1.arrLinear)
            print("\n--------------------------------------------------------------------------\n")
            
        elif(choice == 3):
            name = input("Enter name : ")
            print(f"Phone number of {name} is ",d1.lookSeparate(name))
            print("\n--------------------------------------------------------------------------\n")
        
        elif(choice == 4):
            name = input("Enter name : ")
            print(f"Phone number of {name} is ",d1.lookLinear(name))
            print("\n--------------------------------------------------------------------------\n")
        
        elif (choice == 5):
            break
        else:
             print("!! Wrong choice entered !!")

main()
