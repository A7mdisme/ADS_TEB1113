#include <iostream>
#include <string>

using namespace std;

//Sarah
//Michael
//Daniel (delete this)

//Emma (insert Emma here)

//Olivia

// and then last display all

//make class instead of struct

class Node {
public:
    string name;
    Node* next;

    Node(string n) {
        name = n;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertEnd(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void insertAfter(string afterName, string newName) {
        Node* current = head;

        while (current != nullptr && current->name != afterName) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << afterName << " not found." << endl;
            return;
        }

        Node* newNode = new Node(newName);
        newNode->next = current->next;
        current->next = newNode;
    }

    void deleteByName(string name) {
        if (head == nullptr) {
            return;
        }

        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->name == name) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    void display() {
        Node* current = head;
        if (current == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        while (current != nullptr) {
            cout << current->name << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;

    list.insertEnd("Sarah");
    list.insertEnd("Michael");
    list.insertEnd("Daniel");

    cout << "Initial list:" << endl;
    list.display();

    list.insertAfter("Michael", "Emma");

    list.insertEnd("Olivia");

    list.deleteByName("Daniel");

    cout << "\nFinal list:" << endl;
    list.display();
}