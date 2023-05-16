#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

struct Node {
    string data;
    Node* next;
};
void Query()  { 
            
    ifstream file("userinformation.csv");
    string line;
    Node* head = nullptr;
    Node* tail = nullptr;

    while (getline(file, line)) {
        Node* newNode = new Node;
        newNode->data = line;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* current = head;
    while (current != nullptr) {
        cout << current->data << endl;
        current = current->next;
    }

    current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}
int main(){
    Query();
    return 0;
}
