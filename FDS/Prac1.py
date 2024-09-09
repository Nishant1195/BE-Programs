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
F = [8,9,10]



print(unio(C,B))
print(intersect(C,B))
print(differ(C,B))
print(symm_differ(C,B))