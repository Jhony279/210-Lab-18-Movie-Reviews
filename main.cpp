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

    cout << "which linked list method should we use?" << endl;
    cout << "   [1] New nodes are added at the head of the linked list" << endl;
    cout << "   [2] New nodes are added at the tail of the linked list" << endl;
    cout << "   Choice: "; cin >> choice;

    while (!exit){}
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