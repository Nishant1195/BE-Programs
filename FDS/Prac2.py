def average(l1):
    total_sum = 0
    count = 0
    for i in l1:
        if i != -1:  
            total_sum += i
            count += 1
    if count > 0:
        print("Average:", total_sum / count)
    else:
        print("No valid scores to calculate average.")

def high_low(l1):
    valid_scores = [i for i in l1 if i != -1]
    if valid_scores:
        max_score = max(valid_scores)
        min_score = min(valid_scores)
        print("Max:", max_score, "Min:", min_score)
    else:
        print("No valid scores to find max and min.")

def absent(l1):
    count = l1.count(-1)
    print("Total Absent:", count)

def freq(l1):
    frequency = {}
    for i in l1:
        if i != -1: 
            if i in frequency:
                frequency[i] += 1
            else:
                frequency[i] = 1
    
    if frequency:
        max_freq = max(frequency.values())
        most_frequent_scores = [score for score, freq in frequency.items() if freq == max_freq]
        print("Mark(s) with highest frequency:", most_frequent_scores, "with frequency:", max_freq)
    else:
        print("No valid scores to calculate frequency.")

def menu():
    marks = []
    n = int(input("Enter number of students: "))
    for i in range(n):
        mark = int(input(f"Enter marks for student {i+1} (-1 for absent): "))
        marks.append(mark)
    
    print("\nMenu\n1. The average score of class\n2. Highest score and lowest score of class\n3. Count of students who were absent for the test\n4. Display mark with highest frequency")
    
    while True:
        ch = int(input("Enter the choice: "))
        if ch == 1:
            average(marks)
        elif ch == 2:
            high_low(marks)
        elif ch == 3:
            absent(marks)
        elif ch == 4:
            freq(marks)
        else:
            break

menu()