#include <stdio.h>
#include <iostream>

class Node {
public:
    int data;
    Node *next;
    Node *down;
};

class FlattenedNode {
public:
    int data;
    FlattenedNode *next;
};

class NodeOperations{
    public:
        void insert(Node** head, int data, char direction){
            Node *new_node = new Node();
            new_node->data = data;
            
            if (direction == 'd'){
                new_node->down = *head;
                *head = new_node;
            } else{
                new_node->next = *head;
                *head = new_node;
            }

        }

        void insertFlattened(FlattenedNode **head, int data){
            // Create a new node
            FlattenedNode *new_node = new FlattenedNode();
            // Assign data to new node
            new_node->data = data;

            // Assign the linked list to the tail of the new node
            new_node->next = *head;
            
            // Assign the new Node to the head of the linked list
            *head = new_node;
        }

        FlattenedNode* flatten(Node **head){
            FlattenedNode *result = new FlattenedNode();
            
            while ((*head) != NULL){
                Node *temp = *head;

                std::cout<<"temp->data: "<<temp->data<<std::endl;

                insertFlattened(&result, temp->data);

                while (temp->down != NULL){
                    temp = temp->down;
                    insertFlattened(&result, temp->data);
                }

                *head = (*head)->next;

            }

            return result;

        }

        void display(FlattenedNode *head){
            while (head != NULL){
                std::cout << head->data << " ";
                head = head->next;
            }
            std::cout << std::endl;
        }
};

int main(){

    Node* head = NULL;

    NodeOperations node_operations;

    // insert data into the linked list
    node_operations.insert(&head, 30, 'd');

    node_operations.insert(&head, 8, 'd');

    node_operations.insert(&head, 7, 'd');

    node_operations.insert(&head, 5, 'd');

    node_operations.insert(&head, 10, 'r');

    node_operations.insert(&head, 20, 'd');

    node_operations.insert(&head, 19, 'r');

    node_operations.insert(&head, 22, 'd');

    node_operations.insert(&head, 50, 'd');

    node_operations.display(node_operations.flatten(&head));
}
