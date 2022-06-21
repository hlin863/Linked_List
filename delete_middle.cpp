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

        // adds the new_node at the end of head
        if(*head == NULL){
            *head = new_node;
            return;
        } else {
            Node *temp = *head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = new_node;
        }
        // // Assign the linked list to the tail of the new node
        // new_node->next = *head;
        
        // // Assign the new Node to the head of the linked list
        // *head = new_node;
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

    Node *deleteMiddle(Node *head){
        Node *slow = head;
        Node *fast = head;
        Node *result = NULL;

        class NodeOperations node_operations;

        while(fast != NULL && fast->next != NULL){
            node_operations.insert(&result, slow->data);
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = slow->next;

        while (slow != NULL){
            node_operations.insert(&result, slow->data);
            slow = slow->next;
        }

        return result;
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

    
    head = node_operations.deleteMiddle(head);

    // print the linked list
    node_operations.print(head);

}