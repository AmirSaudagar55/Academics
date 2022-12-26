'''
Experiment Number 14: Write a python program to store first year percentage of students in an array.
                      Write function for sorting array of floating point numbers in ascending order using:
                      a) Selection Sort
                      b) Bubble Sort and display top five scores
'''

def selectionSort(marks):
	for i in range(len(marks)):
		minIndex = i
		for j in range(i+1,len(marks)):
			if(marks[j]>marks[minIndex]):
				minIndex=j
		marks[i],marks[minIndex]=marks[minIndex],marks[i]
		
def bubbleSort(marks):
	for i in range(len(marks)-1):
		for j in range(len(marks)-1-i):
			if(marks[j]<marks[j+1]):
				marks[j],marks[j+1]=marks[j+1],marks[j]

def main():
	terminate=True
	while(terminate):
		print("\n1.Enter marks")
		print("2.Selection Sort")
		print("3.Bubble Sort")
		print("4.Display top 5 scores")
		print("5.Exit\n")
		ch = int(input("Enter choice : "))
		
		if(ch == 1):
			marks = []
			total = int(input("Enter total number of students : "))
			print("Enter marks and press Enter : ")
			for i in range(1,total+1):
				k = input()
				marks.append(k)
		
		elif(ch == 2):
			print("Before sorting : ")
			print(marks)
			
			selectionSort(marks)
			
			print("After sorting : ")
			print(marks)
			
		elif(ch==3):
			print("Before sorting : ")
			print(marks)
			
			bubbleSort(marks)
			
			print("After sorting : ")
			print(marks)
			
		elif(ch==4):
			index = -1
			print("Top scores are : ")
			for i in range(1,len(marks)+1):
				print(i,") score = ",marks[index])
				index-=1
		elif(ch==5):
			print("Program Ended\n")
			terminate = False
		else:
			print("!!!Wrong choice entered!!!")
main()
