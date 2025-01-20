def MidSquare( key, capacity):
	length = capacity-1
	newLen = 0
	while length != 0:
		  length=length//10
		  newLen+=1
	key = pow(key,2)
	newStr=str(key)
	mid=len(newStr)//2
	
	return int(newStr[mid-newLen+1:mid+1])
	
def menu():
	n=int(input("Enter the size of the array: "))
	arr=[None for i in range(0,n)]
	print("###############Menu################")
	while True:
			print("\n1.Add \n2.Search \n3.Exit")
			ch=int(input("\n\nEnter your choice: "))
			if ch==1:
				value=int(input("Enter value to be added: "))
				index=MidSquare(value, len(arr))
				print(index)
				arr[index] = value
			if ch==2:
				search=int(input("Enter value to be searched"))
				index=MidSquare(search, len(arr))
				if arr[index]==search:
					print("Found value: ", search," at ", index)
			if ch==3:
				break
menu()
