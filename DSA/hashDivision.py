
def hashfunction(l, key):
    func= key % l
    return func

def div():
    n=int(input("Enter Size of Array: "))
    arr=[None for i in range(0,n)]
    add=int(input("Enter an number to add: "))
    i = hashfunction(n, add)
    arr.insert(i, add)
    print("Value: ", add, "added at: ", i)
    
div()
