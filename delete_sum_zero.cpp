#include <iostream>
#include <vector>
#include <stack>

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

    int sum(std::stack<int> &stack){
        int sum = 0;

        std::stack<int> temp = stack;
        
        while(!temp.empty()){
            // std::cout << temp.top() << " ";
            sum += temp.top();
            temp.pop();
        }

        return sum;
    }

    void deleteSumZero(Node **head){

        // initialise a stack to track the variables.
        std::stack<int> stack;

        while (*head != NULL){

            stack.push((*head)->data);
            
            std::cout << "size: " << stack.size() << std::endl;

            if (sum(stack) == 0){
                std::cout << std::endl;
                // empties the stack;
                while (!stack.empty()){
                    stack.pop();
                }
            }
            
            *head = (*head)->next;

        }

        // displays the stack contents
        std::cout << "stack contents: ";
        while (!stack.empty()){
            std::cout << stack.top() << " ";
            stack.pop();
        }
        std::cout << std::endl;

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

    node_operations.insert(&head, 6);
    node_operations.insert(&head, -6);
    node_operations.insert(&head, 8);
    node_operations.insert(&head, 4);
    node_operations.insert(&head, -12);
    node_operations.insert(&head, 9);
    node_operations.insert(&head, 8);
    node_operations.insert(&head, -8);

    // print the linked list
    std::cout << "List contents: ";
    node_operations.print(head);
    std::cout << std::endl;

    std::cout << "Deleted elements: ";
    // delete the nodes with sum zero
    node_operations.deleteSumZero(&head);
    std::cout << std::endl;

    // print the linked list
    node_operations.print(head);
}