#include <iostream>
#include <string>
using namespace std;

// Node structure for BST
struct Node {
    string key;
    string meaning;
    Node* left;
    Node* right;

    Node(string k, string m) {
        key = k;
        meaning = m;
        left = right = nullptr;
    }
};

// Insert into BST
Node* insert(Node* root, string key, string meaning) {
    if (!root)
        return new Node(key, meaning);

    if (key < root->key)
        root->left = insert(root->left, key, meaning);
    else if (key > root->key)
        root->right = insert(root->right, key, meaning);
    else
        cout << "Word already exists!\n";

    return root;
}

// Search in BST
void search(Node* root, string key) {
    if (!root) {
        cout << "Word not found.\n";
        return;
    }

    if (key == root->key)
        cout << "Meaning of '" << key << "' is: " << root->meaning << "\n";
    else if (key < root->key)
        search(root->left, key);
    else
        search(root->right, key);
}

// Display words in alphabetical order
void display(Node* root) {
    if (!root) return;
    display(root->left);
    cout << root->key << ": " << root->meaning << "\n";
    display(root->right);
}

int main() {
    Node* root = nullptr;
    int choice;
    string word, meaning;

    do {
        cout << "\nDictionary Menu:\n";
        cout << "1. Add Word\n";
        cout << "2. Find Meaning\n";
        cout << "3. Show All Words\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();  // ignore leftover newline

        switch (choice) {
        case 1:
            cout << "Enter word: ";
            getline(cin, word);
            cout << "Enter meaning: ";
            getline(cin, meaning);
            root = insert(root, word, meaning);
            break;
        case 2:
            cout << "Enter word to search: ";
            getline(cin, word);
            search(root, word);
            break;
        case 3:
            cout << "Dictionary contents:\n";
            display(root);
            break;
        case 4:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
