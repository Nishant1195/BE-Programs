s1 = {7, 8, 9, 10}
s = set()

def menu():
    ch = 0
    while ch != -1:
        print("\n1. Insert")
        print("2. Delete")
        print("3. Contains")
        print("4. Display/Iterator")
        print("5. Intersection")
        print("6. Union")
        print("7. Difference")
        print("8. Subsets")
        print("9. Size")
        print("-1. Exit")
        ch = int(input("\nEnter your choice: "))

        if ch == 1:
            a = int(input("Enter value to be inserted: "))
            s.add(a)
            print(f"{a} added to the set.")
        elif ch == 2:
            r = int(input("Enter value to be deleted: "))
            if r in s:
                s.remove(r)
                print(f"{r} removed from the set.")
            else:
                print(f"{r} not found in the set.")
        elif ch == 3:
            search = int(input("Enter value to be searched: "))
            if search in s:
                print(f"Found element: {search}")
            else:
                print(f"Element {search} not found.")
        elif ch == 4:
            print("Elements in the set:")
            for i in s:
                print(i, end=" ")
            print()
        elif ch == 5:
            inter = s & s1
            print("Intersection:", inter)
        elif ch == 6:
            unio = s.union(s1)
            print("Union:", unio)
        elif ch == 7:
            diff = s - s1
            print("Difference:", diff)
        elif ch == 8:
            print(f"Is {s} a subset of {s1}? {s.issubset(s1)}")
            print(f"Is {s1} a subset of {s}? {s1.issubset(s)}")
        elif ch == 9:
            count = len(s)
            print(f"Size of set: {count}")
        elif ch == -1:
            print("Exiting menu. Goodbye!")
        else:
            print("Invalid choice. Please try again.")

menu()
