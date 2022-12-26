#program to check whether the student is member of club or not.

def accept_array(A):
       n=int(input("Enter the total no of students:"))
       print("INPUT ROLL NUMBERS IN SORTED ORDER")
       for i in range(n):
             x=int(input("Enter roll no of students %d:" %(i+1)))
             A.append(x)
       print("student info accepted successfully\n\n")
       return n
       
def display_array(A,n):
       if(n==0):
             print("\nNo records in the database")
       else :
             print("Students Array:")
             for i in range(n):
                     print("%d "%A[i],)
             print("\n")
             
def ternary_search(A , l , r ,key):
       if(r>=l):
             mid1=l+int((r-l)/3)
             mid2=r-int((r-l)/3)
             if (A[mid1] == key):
                 return mid1
             if (A[mid2] == key):
                 return mid2                          
             if (key<A[mid1]) :
                  return ternary_search(A,l,mid1-1,key)  #key lies between 1 to mid1 
             elif (key>A[mid2]) :
                   return ternary_search(A,mid2+1,r.key)  #key liies between mid2 to r
             else:
                   return ternary_search(A,mid1+1,mid2-1,key)  #$key lies between mid1 to mid2
             return -1   # key not found
             
def main():
      A=[]
      while True :
              print("\t1 : Accept and Display students info ")
              print("\t2: Ternary search")
              print("\t3: Exit")
              ch=int(input("Enter your choice:"))
              if(ch==3):
                   print("end of program")
                   quit()
              elif (ch==1):
                    A=[ ]
                    n=accept_array(A)
                    display_array(A,n)     
              elif (ch==2):
                    x=int(input("Enter the roll no to be searched :"))
                    flag= ternary_search(A, 0 , n-1 ,x)
                    if(flag ==-1):
                            print("\t%d Roll no is not a member of the club\n"%x)
                    else:
                            print("\t%d Roll no is a member of the club stored at location %d"%(x,flag+1))
              else:
                    print("Wrong choice entered !! TRY AGAIN") 
main()                                          
                                                     
