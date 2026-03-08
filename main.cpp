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
    bool exit = false;

    cout << "which linked list method should we use?" << endl;
    cout << "   [1] New nodes are added at the head of the linked list" << endl;
    cout << "   [2] New nodes are added at the tail of the linked list" << endl;

    while (!exit){}
    return 0;
}