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

    Node* delete_n_m(Node *head, int m, int n){

        Node *result = NULL;

        class NodeOperations node_operations;

        while (head != NULL){

            for (int i = 0; i < m; i++){

                node_operations.insert(&result, head->data);

                if (head->next == NULL){
                    break;
                }

                head = head->next;
            }

            for (int i = 0; i < n; i++){
                head = head->next;
            }

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

    node_operations.insert(&head, 11);

    node_operations.insert(&head, 12);

    node_operations.insert(&head, 13);

    node_operations.insert(&head, 5);

    node_operations.insert(&head, 14);

    node_operations.print(head);

    head = node_operations.delete_n_m(head, 3, 2);

    // print the linked list
    node_operations.print(head);

}