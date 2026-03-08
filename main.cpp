// COMSC-210 | Lab 18 | Johnathan Perez Baltazar

#include <iostream>
using namespace std;

struct Node {
    double rating;
    string comment;
    Node* next;
};

void insertNodeFront(Node *&, double, string);
void insertNodeEnd(Node *&, double, string);
void displayRatings(Node *);


/**
 * @brief Enter review rating and commoent into linked list
*/
int main() {
    bool exit = false;
    Node *head = nullptr;
    
    while (!exit){
        int choice;
        string leave;

        // ask the user to choose how to insert new nodes until they enter a valid choice
        if (!choice == 1 || !choice == 2) {
            cout << "Please enter 1 or 2." << endl;
            cout << "   [1] New nodes are added at the head of the linked list" << endl;
            cout << "   [2] New nodes are added at the tail of the linked list" << endl;
            cout << "   Choice: "; cin >> choice;
        }

        if (choice == 1) {  // insert new nodes at the head of the linked list
            cout << "Enter review rating 0-5: "; int rating; cin >> rating;
            cout << "Enter review comments: "; string comment; 
            cin.ignore();
            getline(cin, comment);

            insertNodeFront(head, rating, comment);
            cout << "Enter another review? Y/N: "; cin >> leave;
        } else if (choice == 2) {   // insert new nodes at the tail of the linked list
            cout << "Enter review rating 0-5: "; int rating; cin >> rating;
            cout << "Enter review comments: "; string comment; 
            cin.ignore();
            getline(cin, comment);

            insertNodeEnd(head, rating, comment);
            cout << "Enter another review? Y/N: "; cin >> leave;
        } else {    // Show error message and ask for input again
            cout << "Invalid choice. ";
            continue; // skip the rest of the loop and ask for input again
        }

        // display all reviews and exit the program
        if (leave == "N" || leave == "n") {
            exit = true;
            displayRatings(head);
            cout << "Exiting program." << endl;
        }
    }
    return 0;
}

/**
 * @brief insert a new node at the end of the linked list
 * @param hd pointer to the head of the linked list
 * @param rating the rating value to be stored in the new node
 * @param comment the comment string to be stored in the new node
*/
void insertNodeEnd(Node *&hd, double rating, string comment){
    // insert a node at the end of the list
    Node * newnode = new Node;
    newnode->rating = rating;
    newnode->comment = comment;
    int count = 1;

    newnode->next = nullptr;

    if (!hd) { // if the list is empty, make the new node the head
        hd = newnode;
    } else { // otherwise, find the end of the list and append the new node
        Node * current = hd;
        while (current->next) {
            current = current->next;
        }
        current->next = newnode;
    }
}

/**
 * @brief insert a new node at the front of the linked list
 * @param hd pointer to the head of the linked list
 * @param rating the rating value to be stored in the new node
 * @param comment the comment string to be stored in the new node
*/
void insertNodeFront(Node *&hd, double rating, string comment){
    // insert a node at the front of the list
    Node * newnode = new Node;
    newnode->rating = rating;
    newnode->comment = comment;

    // insert the new node at the front of the list
    newnode->next = hd;
    hd = newnode;
}

/**
 * @brief Output the linked list of reviews and calculate the average rating
 * @param hd pointer to the head of the linked list
*/
void displayRatings(Node * hd) {
    // output the linked list
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    double totalRating = 0;
    Node * current = hd;
    // traverse the list and output each node's value
    cout << "Outputting all reviews:\n";
    while (current) {
        cout << "   > Review #" << count++ << ": " << current->rating 
            << ": " << current->comment << endl;
        totalRating += current->rating;
        current = current->next;
    }
    cout << "   > Average: " << totalRating/(count - 1) << endl;
}