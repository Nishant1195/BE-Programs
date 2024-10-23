#include <iostream>
#include <string>
using namespace std;

// Structure to represent each member of the club
struct Node {
    int PRN;
    string name;
    Node* next;
};

// Class to represent the Pinnacle Club
class PinnacleClub {
private:
    Node* head;  // Pointer to the president (first node)
    Node* tail;  // Pointer to the secretary (last node)

public:
    PinnacleClub() {
        head = nullptr;
        tail = nullptr;
    }

    // Function to add a member (president or secretary or regular member)
    void addMember(int prn, string name, bool isPresident = false, bool isSecretary = false) {
        Node* newNode = new Node{prn, name, nullptr};

        // If adding the president (at the head)
        if (isPresident) {
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) tail = head; // If list was empty, set tail as well
            return;
        }

        // If adding the secretary (at the tail)
        if (isSecretary) {
            if (tail != nullptr) {
                tail->next = newNode;
            }
            tail = newNode;
            if (head == nullptr) head = tail; // If list was empty, set head as well
            return;
        }

        // Otherwise, add as a regular member at the end (before secretary)
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            newNode->next = tail;
            temp->next = newNode;
        }
    }

    // Function to delete a member
    void deleteMember(int prn) {
        if (head == nullptr) {
            cout << "Club is empty, no members to delete." << endl;
            return;
        }

        // If president (head) needs to be deleted
        if (head->PRN == prn) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) tail = nullptr; // If list became empty, set tail as well
            return;
        }

        // Search for the member in the middle or tail
        Node* temp = head;
        while (temp->next != nullptr && temp->next->PRN != prn) {
            temp = temp->next;
        }

        // If member not found
        if (temp->next == nullptr) {
            cout << "Member with PRN " << prn << " not found." << endl;
            return;
        }

        // If secretary (tail) needs to be deleted
        if (temp->next == tail) {
            delete tail;
            tail = temp;
            tail->next = nullptr;
            return;
        }

        // Otherwise, delete regular member
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Function to compute the total number of members
    int countMembers() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Function to display all members
    void displayMembers() {
        if (head == nullptr) {
            cout << "Club has no members." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << "PRN: " << temp->PRN << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

    // Function to concatenate two club member lists
    void concatenate(PinnacleClub& otherClub) {
        if (head == nullptr) {
            head = otherClub.head;
            tail = otherClub.tail;
        } else {
            tail->next = otherClub.head;
            if (otherClub.tail != nullptr) {
                tail = otherClub.tail;
            }
        }
        otherClub.head = otherClub.tail = nullptr; // Empty the other club list after concatenation
    }
};

int main() {
    PinnacleClub club1;
    PinnacleClub club2;

    // Adding members to the first club
    club1.addMember(101, "Alice", true);  // Add president
    club1.addMember(102, "Bob");
    club1.addMember(103, "Charlie");
    club1.addMember(104, "David", false, true);  // Add secretary

    // Display members of club1
    cout << "Members of Club 1:" << endl;
    club1.displayMembers();
    
    // Adding members to the second club
    club2.addMember(201, "Eve", true);  // Add president of second club
    club2.addMember(202, "Frank");
    club2.addMember(203, "Grace", false, true);  // Add secretary of second club

    // Display members of club2
    cout << "\nMembers of Club 2:" << endl;
    club2.displayMembers();

    // Concatenate the two clubs
    club1.concatenate(club2);

    // Display members after concatenation
    cout << "\nMembers after concatenating Club 1 and Club 2:" << endl;
    club1.displayMembers();

    // Delete a member
    club1.deleteMember(102);
    cout << "\nMembers after deleting PRN 102:" << endl;
    club1.displayMembers();

    // Total number of members in the club
    cout << "\nTotal number of members: " << club1.countMembers() << endl;

    return 0;
}
