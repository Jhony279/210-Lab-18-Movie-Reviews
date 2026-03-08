// COMSC-210 | Lab 18 | Johnathan Perez Baltazar

#include <iostream>
using namespace std;

struct Node {
    int rating;
    string comment;
    Node* next;
};

void populateNode(Node *&);
void insertNodeFront(Node *&, int, string);
void insertNodeEnd(Node *&, int, string);
void displayRatings(Node *);


/**
 * @brief - Description of main
 * @return 
*/
int main() {
    bool exit = false;
    Node *head = nullptr;
    
    while (!exit){
        int choice;
        string leave;

        if (choice == 1 || choice == 2) {
            continue; // valid choice, proceed with the loop
        } else {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
            cout << "   [1] New nodes are added at the head of the linked list" << endl;
            cout << "   [2] New nodes are added at the tail of the linked list" << endl;
            cout << "   Choice: "; cin >> choice;
        }

        if (choice == 1) {
            cout << "Enter review rating 0-5: "; int rating; cin >> rating;
            cout << "Enter review comments: "; string comment; cin >> comment;

            insertNodeFront(head, rating, comment);
            continue;
        } else if (choice == 2) {
            cout << "Enter review rating 0-5: "; int rating; cin >> rating;
            cout << "Enter review comments: "; string comment; cin >> comment;

            insertNodeEnd(head, rating, comment);
            continue;
        } else {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
            continue; // skip the rest of the loop and ask for input again
        }
        if (leave == "Y" || leave == "y") { exit = true; }
    }
    return 0;
}

void insertNodeEnd(Node *&hd, int rating, string comment){
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

void insertNodeFront(Node *&hd, int rating, string comment){
    // insert a node at the front of the list
    Node * newnode = new Node;
    newnode->rating = rating;
    newnode->comment = comment;

    // insert the new node at the front of the list
    newnode->next = hd;
    hd = newnode;
}