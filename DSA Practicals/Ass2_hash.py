print("DSL Assignment no: 2")    
print("All Functions of Dictionary using hashing")
Keys=['NA','NA','NA','NA','NA']
Values=['NA','NA','NA','NA','NA']
chain=[-1,-1,-1,-1,-1]
tab_size=len(Keys)

def Insert_with():
    k=int(input("Enter the key:"))
    val=k%5    
    for i in range(val,tab_size):
        if Keys[i]=='NA':
            Keys[i]=k
            Values[i]=val
            break
        else:
            if (Keys[val]%tab_size!=val):
                ktemp=Keys[val]
                vtemp=Values[val]
                for j in range(val+1,tab_size):
                    if Keys[j]=='NA':
                        Keys[j]=ktemp
                        Values[j]=vtemp
                        #flag=1
                        break
    print("After Insertion using chaining with replacement:")
    print("Keys are:")
    print(Keys)
    print("Values are:")
    print(Values)

def Insert_without():
    k=int(input("Enter the key:"))
    v=k%tab_size       #Hash Function: Division Method
    for i in range(v,tab_size):
        if Keys[i]=='NA':
            Keys[i]=k
            Values[i]=v
            break
        else:           #Next empty location:Chaining without replacement
            v=v+1
            chain[i]=v
        
    print("After Insertion using chaining without replacement:")
    print("Keys are:")
    print(Keys)
    print("Values are:")
    print(Values)
    print("Chains are:")
    print(chain)

def Find():
    x=int(input("Enter Key to Find:"))
    for i in range(0,tab_size):
        if Keys[i]==x:
            print("Key",x," has Value/location as: ",Values[i])
            break
    

def main_menu():
    print("1. Insert Key using Chaining with replacement in Dictionary")
    print("2. Insert Key using Chaining without replacement in Dictionary")
    print("3. Find the Value of Key")
    print("4. Exit")
    ch=int(input("enter your choice:"))
    if ch==1:
            print("Inserting Key in Dictionary......")
            Insert_with()
            print("-------------------------------------------------------")
            main_menu()
    if ch==2:
            print("Inserting Key in Dictionary......")
            Insert_without()
            print("-------------------------------------------------------")
            main_menu()
    elif ch==3:
            print("Finding Key from Dictionary......")
            Find()
            print("-------------------------------------------------------")
            main_menu()
    elif ch==4:
            exit()
    else:
            print("Enter Valid choice")
            main_menu()
main_menu()
