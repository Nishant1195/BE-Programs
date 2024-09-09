def unio(l1,l2):
    unio = []
    for i in l1:
        unio.append(i)
        if i not in l2:
            unio.append(i)
    for i in l2:
        unio.append(i)
        if i not in l1:
            unio.append(i)