#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Structure for AVL Tree node
struct Node {
    string word;
    string meaning;
    int height;
    Node* left;
    Node* right;

    Node(string w, string m)
        : word(w), meaning(m), height(1), left(nullptr), right(nullptr) {}
};

// Get height of node
int getHeight(Node* node) {
    return node ? node->height : 0;
}

// Get balance factor of node
int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Update height of node
void updateHeight(Node* node) {
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// Right rotation
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left rotation
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Insert a word into the AVL tree
Node* insert(Node* root, string word, string meaning) {
    if (!root)
        return new Node(word, meaning);

    if (word < root->word)
        root->left = insert(root->left, word, meaning);
    else if (word > root->word)
        root->right = insert(root->right, word, meaning);
    else {
        cout << "Word already exists: " << word << "\n";
        return root;
    }

    updateHeight(root);

    int balance = getBalance(root);

    // Balancing cases
    if (balance > 1 && word < root->left->word) // Left Left
        return rotateRight(root);
    if (balance < -1 && word > root->right->word) // Right Right
        return rotateLeft(root);
    if (balance > 1 && word > root->left->word) { // Left Right
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && word < root->right->word) { // Right Left
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Search for a word
void search(Node* root, const string& word) {
    if (!root) {
        cout << "Word not found: " << word << "\n";
        return;
    }

    if (word == root->word)
        cout << "Meaning of '" << word << "': " << root->meaning << "\n";
    else if (word < root->word)
        search(root->left, word);
    else
        search(root->right, word);
}

// Display all words in alphabetical order
void displayDictionary(Node* root) {
    if (!root) return;
    displayDictionary(root->left);
    cout << root->word << ": " << root->meaning << "\n";
    displayDictionary(root->right);
}

// Main function
int main() {
    Node* root = nullptr;
    int choice;
    string word, meaning;

    do {
        cout << "\n--- Dictionary Menu ---\n";
        cout << "1. Insert Word\n";
        cout << "2. Search Word\n";
        cout << "3. Display All Words\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To handle newline after choice

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
                cout << "\n--- Dictionary Contents ---\n";
                displayDictionary(root);
                break;

            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
