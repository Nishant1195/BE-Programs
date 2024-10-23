def longest_word(string):
    words = string.split()
    longest = max(words, key=len)
    return longest

def char_frequency(string, char):
    return string.count(char)

def is_palindrome(string):
    string = string.replace(" ", "").lower()
    return string == string[::-1]

def first_index_of_substring(string, substring):
    return string.find(substring)

def word_count(string):
    words = string.split()
    word_freq = {}
    for word in words:
        word_freq[word] = word_freq.get(word, 0) + 1
    return word_freq

def menu():
    while True:
        print("\nMenu:")
        print("a) Display word with the longest length")
        print("b) Determine the frequency of a particular character in the string")
        print("c) Check whether the given string is palindrome or not")
        print("d) Display index of the first appearance of the substring")
        print("e) Count occurrences of each word in the string")
        print("f) Exit")
        
        choice = input("Enter your choice (a/b/c/d/e/f): ")
        if choice == 'f':
            print("Exiting the program.")
            break
        
        string = input("Enter the string: ")
        
        if choice == 'a':
            print("Longest word:", longest_word(string))
        elif choice == 'b':
            char = input("Enter the character to check frequency: ")
            print(f"Frequency of '{char}':", char_frequency(string, char))
        elif choice == 'c':
            if is_palindrome(string):
                print("The string is a palindrome.")
            else:
                print("The string is not a palindrome.")
        elif choice == 'd':
            substring = input("Enter the substring: ")
            index = first_index_of_substring(string, substring)
            if index != -1:
                print(f"First appearance of '{substring}' is at index {index}")
            else:
                print(f"'{substring}' not found in the string.")
        elif choice == 'e':
            word_counts = word_count(string)
            print("Word occurrences:", word_counts)
        else:
            print("Invalid choice. Please try again.")

# Run the menu
menu()
