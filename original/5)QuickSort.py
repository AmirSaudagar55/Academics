""" Write  a python program to store first year percentage of students in array. Write finction for sorting array of 
floating point number in ascending order using quick sort and display top 5 scores """

def display(marks):
	print(marks)
#	for i in range(len(marks)):
#		print(marks[i])
#		print(" ")

def partition(a, low, high):
	pivot = a[low]
	i = low + 1
	j = high
	while True:
		while (i<=j and a[i]<=pivot):
			i = i+1
		while (i<=j and a[j]>pivot):
			j = j-1
		if (i<=j):
			a[i],a[j]=a[j],a[i]
		else:
			break
	a[low],a[j] = a[j],a[low]
	return j


def quick_sort(marks,s,e):
	if (s < e):
		piv = partition(marks, s, e)
		quick_sort(marks, s, piv-1)
		quick_sort(marks, piv+1, e)


def main():
	terminator = True
	while(terminator):
		print("-------------Menu------------")
		print("\n1. Enter Percentage")
		print("2. Sort Scores")
		print("3. Display top 5 scores")
		print("4. Exit\n")
		ch = int(input("Enter a choice : "))

		if(ch==1):
			total = int(input("Enter Total number of student : "))
			marks = []
			for i in range(total):
				k = float(input("%d score : "%i))
				marks.append(k)

		elif(ch==2):
			if not marks:  #check if list is empty or not
				print("! Enter Percentage First !")
			else:
				print("Before sorting : ")
				display(marks)

				quick_sort(marks,0,len(marks)-1)

				print("After sorting : ")
				display(marks)

		elif(ch == 3):
			temp = 5
			print("\nTop 5 scores are : ")
			for i in range(len(marks)-5,len(marks)):
				print(temp , ") : " , marks[i])
				temp -= 1
		elif(ch == 4):
			print("Program Ended\n")
			terminator = False
		else:
			print("Wrong choice entered\n")
main()