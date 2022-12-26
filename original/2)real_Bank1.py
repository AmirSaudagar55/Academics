
def deposit(amt, balance):
    balance += int(amt)
    print("Deposited to your account Successfully \n")
    print("Total balance : ",balance)
    print("\n")
    return balance

def withdraw(amt, balance):
    if(balance >= amt):
        balance -= amt
        print("Withdrawal to your account Successfully \n")
        print("Total balance : ",balance)
        print("\n")
    else:
        print("Insufficient balance \n")
        print("Total balance : ",balance)
    return balance

def main():
    balance = 0
    terminate = True
    print("Welcome\n")
    while(terminate):
        print("--------------Menu-----------------\n")
        print("1.Display Balance \n")
        print("2.Enter Transaction log \n")
        print("3.Exit\n")
        ch = int(input("Enter choice : "))
        
        if(ch==1):
            print("\nTotal Balance : ",balance)
            print("\n")
            
        elif(ch == 2):
            print("Example : D amount --> for deposit")
            print("          W amount --> for withdraw\n")
            
            log = input("Enter each log at a time : ")
            transact_log = []
            transact_log = log.split()
            
            if(transact_log[0]=='D'):
                balance = deposit(transact_log[1], balance)
                
            elif(transact_log[0]=='W'):
                balance = withdraw(int(transact_log[1]), balance)
            
            else:
                print("Wrong Syntax for entering transaction log\n")
        
        elif(ch == 3):
            print("Thanks for using our services\n")
            terminate = False
            
        else:
            print("! Wrong choice entered")
            
main()