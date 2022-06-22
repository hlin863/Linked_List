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

    void deleteLast(Node **head, int data){
        // deletes the last occurrence of element. 

        // if the head is NULL, then the list is empty
        if (*head == NULL){
            return;
        }

        // if the head is the only element in the list
        if ((*head)->next == NULL){
            if ((*head)->data == data){
                delete *head;
                *head = NULL;
            }
            return;
        }

        // if the head is not the only element in the list
        Node *temp = *head;

        // if the head is the element to be deleted
        if (temp->data == data){
            *head = temp->next;
            delete temp;
            return;
        }

        // if the head is not the element to be deleted
        while (temp->next != NULL){
            if (temp->next->data == data){
                Node *temp2 = temp->next;
                temp->next = temp->next->next;
                delete temp2;
                return;
            }
            temp = temp->next;
        }
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

    node_operations.insert(&head, 11);

    node_operations.insert(&head, 12);

    node_operations.insert(&head, 13);

    node_operations.insert(&head, 5);

    node_operations.insert(&head, 14);

    node_operations.print(head);

    node_operations.deleteLast(&head, 5);

    // print the linked list
    node_operations.print(head);

}