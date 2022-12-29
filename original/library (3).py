"""Write a Python program for department library which has N books, write functions for
following:
a) Delete the duplicate entries
b) Display books in ascending order based on cost of books
c) Count number of books with cost more than 500.
d) Copy books in a new list which has cost less than 500."""


book = []
price = []
def Input():
    bk = input("\tEnter the name of the book : ")
    book.append(bk)
    pr = int (input("\tEnter the price of the book : "))
    price.append(pr)
    return

def display():
    print("\t Following are the given books with price \n\n")
    for element in range(len(book)):
        print(" Book : " , book[element])
        print(" price : ", price[element])
    return

def deletedup():
    i = []
    j = []
    for element in range(len(book)):
            if book[element] not in i:
                 i.append(book[element])
                 j.append(price[element])
    book.clear()
    book.extend(i)
    price.clear()
    price.extend(j)
    return

def assending():
    for element in range(len(price)):
          for element1 in range(len(price)):
            # if element1 > len(price)-1:
            #      break
            if price[element] < price[element1]:
                    price[element],price[element1] = price[element1],price[element]
                    book[element],book[element1] = book[element1],book[element]
    return

def countmore500():
    count = 0
    for element in range(len(book)):
         if price[element] > 500:
              count+=1
    return count

def countless500():
    count = 0
    for element in range(len(book)):
         if price[element] <= 500:
              count+=1
    return count

def main():
    print("""\t---------------------menu-----------------------
         \n\t1. Accept\n\t2. Display \n\t3. Delete the duplicate \n\t4. Make it assending \n\t5. Count more than 500 \n\t6. Count less than 500 \n\t7. Exit\n\n""")
    ch = input("Enter your choise : ")
    while True:
        ch = int(input("Enter your choise : "))
        if ch == 1:
              Input()
        elif ch == 2:
             display()
        elif ch == 3:
             deletedup()
        elif ch == 4:
             assending()
        elif ch == 5:
             print(countmore500())
        elif ch == 6:
             print(countless500())
        elif ch == 7:
             exit()
        else:
             print("Invalid Choise")
    return

main()
