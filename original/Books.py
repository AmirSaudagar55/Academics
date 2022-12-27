#Assignment 3:
#Write  a  Python  program  for  department  library  which  has  N  books,  
#write  functions  for following: 
#a) Delete the duplicate entries 
#b) Display books in ascending order based on cost of books 
#c) Count number of books with cost more than 500.  
#d) Copy books in a new list which has cost less than 500.

def accept(n):
  for i in range(n):
    a = input("Enter the UNIQUE ID of Book "+str(i+1)+" : ")
    b = input("Enter the Title of Book "+str(i+1)+" : ")
    c = input("Enter the Author of Book "+str(i+1)+" : ")
    d = input("Enter the Cost of Book "+str(i+1)+" : ")
    books.append([a,b,c,int(d)])
    print("\n")

def display(z,y):
  count = 1
  print("\n ",y.center(70,"*"))
  for i in z:
    print("BOOK ",count," --Title : ",i[0]," --Unique Id : ",i[1]," --Author : ",i[2]," --Cost : ",i[3])
    count += 1

def duplicate():
  for book in books:
    list_duplicate = []
    count = 0
    for check in books:
      if (book[0]==0):
        break
      if (book[0]==check[0]):
        list_duplicate.append(count)
      count += 1
    if len(list_duplicate)==1 and books[list_duplicate[0]]!=[0,0,0,0]:
      books2.append(books[list_duplicate[0]])
    elif len(list_duplicate)>1 and books[list_duplicate[0]]!=[0,0,0,0]:
      books2.append(books[list_duplicate[0]])
      for i in range(1,len(list_duplicate)):
        books[list_duplicate[i]]=[0,0,0,0]

def ascending():
  for i in range(len(books2)-1):
    for j in range(len(books2)-i-1):
      if books2[j][3]>books2[j+1][3]:
        temp = books2[j]
        books2[j] = books2[j+1]
        books2[j+1] = temp

def five_hundred():
  count = 0
  for i in books2:
    if (i[3] < 500):
      books500.append(i)
    else:
      count += 1
  return count

books,books2,books500 = [],[],[]
n = int(input("Enter the number of Books : "))
accept(n)
duplicate()
display(books2,"List of non-duplicate books :")
ascending()
display(books2,"List of books in ascending order :")
five_hundred()
display(books500,("Books costing less than 500"))
print("\nCount of books costing > than 500 = "+str(five_hundred()))
