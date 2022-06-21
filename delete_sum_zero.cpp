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

    std::vector<int> sum(std::stack<int> &stack){
        int sum = 0;

        std::stack<int> temp = stack;
        
        int index = 0;

        while(!temp.empty()){
            // std::cout << temp.top() << " ";
            sum += temp.top();
            temp.pop();
            if (sum == 0){
                break;
            }
            index++;
        }

        std::vector<int> result;

        result.push_back(sum);
        result.push_back(index);

        return result;
    }

    Node* deleteSumZero(Node **head){

        // initialise a stack to track the variables.
        std::stack<int> stack;

        while (*head != NULL){

            stack.push((*head)->data);
            
            // std::cout << "size: " << stack.size() << std::endl;

            std::vector<int> result = sum(stack);

            if (result[0] == 0){

                /* 
                    TO-DO:
                    If there is a list with elements [a, b, c, d, e]
                    and c + d + e = 0
                    then we need to delete the elements [c, d, e]
                    and the remaining elements will be [a, b]
                */
                // std::cout << std::endl;

                int i = result[1];
                // empties the stack;
                while (i >= 0){
                    stack.pop();
                    i--;
                }
            }
            
            *head = (*head)->next;

        }

        Node *result_node = NULL;
        class NodeOperations node_operations;

        // displays the stack contents
        // std::cout << "stack contents: ";
        while (!stack.empty()){
            // std::cout << stack.top() << " ";
            node_operations.insert(&result_node, stack.top());
            stack.pop();
        }
        // std::cout << std::endl;

        return result_node;

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

    // std::cout << "Deleted elements: ";
    // delete the nodes with sum zero
    class Node* result = node_operations.deleteSumZero(&head);
    // std::cout << std::endl;

    std::cout << "List contents after deleting elements that sum to zero: ";
    // print the linked list
    node_operations.print(result);
    std::cout << std::endl;
}