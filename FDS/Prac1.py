def unio(l1,l2):
    unio = []
    for i in l1:
            unio.append(i)
    for i in l2:
        if i not in unio:
            unio.append(i)
    return unio

def intersect(l1,l2):
     inter = []
     for i in l1:
          if i in l2:
               inter.append(i)
     return inter

def differ(l1,l2):
     diff = []
     for i in l1:
          if i not in l2:
               diff.append(i)
     return diff

def symm_differ(l1,l2):
     symm_diff=[]
     for i in l1:
          if i not in l2:
               symm_diff.append(i)
     for i in l2:
          if i not in l1:
               symm_diff.append(i)
     return symm_diff

C = [1,2,3,4,5]
B = [4,5,6,7]
F = [6,7,8,9,10]

print("\n1) List of students who play both cricket and badminton \n2) List of students who play either cricket or badminton but not both \n3) Number of students who play neither cricket nor badminton \n4) Number of students who play cricket and football but not badminton.")
while True:
    inp = int(input("\n\nEnter your choice (By the serial number i.e. 1-4): "))

    if inp == 1:
        print("List of students who play both cricket and badminton:", intersect(C, B))

    elif inp == 2:
        print("List of students who play either cricket or badminton but not both:", symm_differ(C, B))

    elif inp == 3:
        three = unio(C,B)
        print("Number of students who play neither cricket nor badminton:", differ(F,three))

    elif inp == 4:
        four = intersect(C, F)
        print("Number of students who play cricket and football but not badminton:", differ(four, B))
    else :
         print("\n\nError : Invalid Choice/Input")
         break