#include <iostream>

class Node {

public:
    int data;
    Node *next;

};

class NodeOperations{

public:
    void insert(Node **head, int data){
        // Create a new node
        Node *new_node = new Node();
        // Assign data to new node
        new_node->data = data;

        // Assign the linked list to the tail of the new node
        new_node->next = *head;
        
        // Assign the new Node to the head of the linked list
        *head = new_node;
    }

    void print(Node *head){
        while(head != NULL){
            std::cout << head->data << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }

    int getMiddle(Node *head){
        Node *slow = head;
        Node *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }

};

int main(){

    // initialise a linked list
    class Node* head = NULL;

    // initialise the node operations
    class NodeOperations node_operations;

    // insert data into the linked list
    for (int i = 10; i >= 1; i--){
        node_operations.insert(&head, i);
    }

    // print the linked list
    node_operations.print(head);

    std::cout << "Middle element is: " << node_operations.getMiddle(head) << std::endl;

    head = NULL;

    // insert data into the linked list
    for (int i = 9; i >= 1; i--){
        node_operations.insert(&head, i);
    }

    // print the linked list
    node_operations.print(head);

    std::cout << "Middle element is: " << node_operations.getMiddle(head) << std::endl;

}