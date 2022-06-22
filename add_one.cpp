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

    Node* reverse_list(Node *head){
        // reverses the list
        Node *reversed = NULL;

        Node *current = head;

        Node *next;

        while (current != NULL){
            next = current->next;
            current->next = reversed;
            reversed = current;
            current = next;
        }

        return reversed;

    }

    Node* add_one(Node *head){
        Node* result = head;
        Node* temp;

        int carry = 1;
        int sum;

        while (head != NULL){
            sum = head->data + carry;

            carry = (sum >= 10) ? 1 : 0;

            sum = sum % 10;

            head->data = sum;

            temp = head;
            head = head->next;
        }

        if (carry > 0){
            temp->next->data = carry;
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
    for (int i = 9; i >= 1; i--){
        node_operations.insert(&head, i);
    }

    // print the linked list
    node_operations.print(head);

    head = node_operations.reverse_list(head);

    head = node_operations.add_one(head);

    head = node_operations.reverse_list(head);

    node_operations.print(head);


}