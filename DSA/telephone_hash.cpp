#include <iostream>
#include <vector>
using namespace std;

// Class to store client details
class Client {
public:
    string name;
    long long phone;

    Client() {
        name = "----";
        phone = 0;
    }

    Client(string n, long long p) {
        name = n;
        phone = p;
    }

    bool isEmpty() {
        return phone == 0;
    }

    void printDetails() {
        cout << name << "\t" << phone << endl;
    }
};

// Class for Hash Table
class HashTable {
private:
    int size;
    vector<Client> table;

    // Hash function: simple sum of ASCII values % table size
    int hashFunction(string name) {
        int sum = 0;
        for (char ch : name) {
            sum += int(ch);
        }
        return sum % size;
    }

public:
    HashTable(int s) {
        size = s;
        table.resize(size);
    }

    // Insert without replacement
    void insertWithoutReplacement(Client c) {
        int index = hashFunction(c.name);

        // If empty, place directly
        if (table[index].isEmpty()) {
            table[index] = c;
        } else {
            // Linear probing to find next empty spot
            int start = index;
            do {
                index = (index + 1) % size;
            } while (!table[index].isEmpty() && index != start);

            if (table[index].isEmpty()) {
                table[index] = c;
            } else {
                cout << "Hash table is full, cannot insert " << c.name << endl;
            }
        }
    }

    // Insert with replacement
    void insertWithReplacement(Client c) {
        int index = hashFunction(c.name);

        if (table[index].isEmpty()) {
            table[index] = c;
        } else {
            int existingIndex = hashFunction(table[index].name);
            if (existingIndex == index) {
                // Existing client is in correct spot, do linear probe for new
                int newIndex = index;
                do {
                    newIndex = (newIndex + 1) % size;
                } while (!table[newIndex].isEmpty() && newIndex != index);

                if (table[newIndex].isEmpty()) {
                    table[newIndex] = c;
                } else {
                    cout << "Hash table is full, cannot insert " << c.name << endl;
                }
            } else {
                // Replace and reinsert existing client
                Client temp = table[index];
                table[index] = c;

                int newIndex = index;
                do {
                    newIndex = (newIndex + 1) % size;
                } while (!table[newIndex].isEmpty() && newIndex != index);

                if (table[newIndex].isEmpty()) {
                    table[newIndex] = temp;
                } else {
                    cout << "Hash table is full, cannot reinsert " << temp.name << endl;
                }
            }
        }
    }

    // Search for a client
    void search(string name) {
        int index = hashFunction(name);
        int comparisons = 0;

        int start = index;
        do {
            comparisons++;
            if (table[index].name == name) {
                cout << "Found " << name << " in " << comparisons << " comparisons.\n";
                return;
            }
            index = (index + 1) % size;
        } while (index != start);

        cout << name << " not found after " << comparisons << " comparisons.\n";
    }

    // Display the hash table
    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            table[i].printDetails();
        }
    }
};

// Main program
int main() {
    HashTable ht1(10);
    HashTable ht2(10);

    // Sample data
    vector<Client> clients = {
        {"abcd", 1001}, {"zdfg", 1002}, {"asdf", 1003}, {"dbca", 1004},
        {"qwer", 1005}, {"rtyu", 1006}, {"ergh", 1007}, {"fghj", 1008},
        {"zasd", 1009}, {"dfgh", 1010}
    };

    cout << "\nInserting clients WITHOUT replacement:\n";
    for (Client c : clients)
        ht1.insertWithoutReplacement(c);

    ht1.display();

    cout << "\nInserting clients WITH replacement:\n";
    for (Client c : clients)
        ht2.insertWithReplacement(c);

    ht2.display();

    // Search test
    cout << "\nSearching in table without replacement:\n";
    ht1.search("abcd");
    ht1.search("dfgh");
    ht1.search("unknown");

    cout << "\nSearching in table with replacement:\n";
    ht2.search("abcd");
    ht2.search("dfgh");
    ht2.search("unknown");

    return 0;
}
