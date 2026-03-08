// COMSC-210 | Lab 18 | Johnathan Perez Baltazar

#include <iostream>
using namespace std;

struct Node {
    int rating;
    string comment;
    Node* next;
};

void populateNode(Node *&);
void insertNodeFront(Node *&);
void insertNodeEnd(Node *&);
void displayRatings(Node *);


/**
 * @brief - Description of main
 * @return 
*/
int main() {
    int choice;
    bool exit = false;
    Node *head = nullptr;

    while (!exit){
        if (choice == 1 || choice == 2) {
            continue; // valid choice, proceed with the loop
        } else {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
            cout << "   [1] New nodes are added at the head of the linked list" << endl;
            cout << "   [2] New nodes are added at the tail of the linked list" << endl;
            cout << "   Choice: "; cin >> choice;
        }

        if (choice == 1) {
            insertNodeFront(head);
        } else if (choice == 2) {
            insertNodeEnd(head);
        } else {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
            continue; // skip the rest of the loop and ask for input again
        }
    }
    return 0;
}

void insertNodeEnd(Node *&hd){
    // insert a node at the end of the list
    Node * newnode = new Node;
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

void insertNodeFront(Node *&hd){
    // insert a node at the front of the list
    Node * newnode = new Node;

    // insert the new node at the front of the list
    newnode->next = hd;
    hd = newnode;
}