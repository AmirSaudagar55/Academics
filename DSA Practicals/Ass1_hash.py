print("DSL Assignment no: 1")    
print("telephone Directory using hashing")

clients_name=['NA','NA','NA','NA','NA']
clients_NO=['NA','NA','NA','NA','NA']
tab_size=len(clients_NO)

def insert():
    name=input("Enter the Clients Name:")
    tel_no=int(input("Enter clients telephone no:"))
    index=tel_no%tab_size       #Hash Function: Division Method
    for i in range(index,tab_size):
        if clients_name[i]=='NA':
            clients_name[i]=name
            clients_NO[i]=tel_no
            break
        else:           #Next empty location:linear probing
            index=index+1
    print("clients name are:")
    print(clients_name)
    print("clients telephone no are:")
    print(clients_NO)

def look_up():
    x=input("Enter clients_name for Look-up:")
    for i in range(0,tab_size):
        if clients_name[i]==x:
            print(x,"client has telephone no as:",clients_NO[i])
            break
    
def main_menu():
    print("1. Insert data in Directory")
    print("2. Look-up for Clients telephone no")
    print("3. Exit")
    ch=int(input("enter your choice:"))
    if ch==1:
        print("Inserting data in directory......")
        insert()
        print("-------------------------------------------------------")
        main_menu()
    elif ch==2:
        print("Look-up data from directory......")
        look_up()
        print("-------------------------------------------------------")
        main_menu()
    elif ch==3:
        exit()
    else:
        print("Enter Valid choice")
        main_menu()
        
main_menu()
