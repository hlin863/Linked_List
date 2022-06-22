#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insert(struct Node **head, int value);

struct Node *new_node(int value);

void display(struct Node *head);

struct Node* reverse_k_nodes(struct Node *head, int k);

int main(){
    struct Node *graph = new_node(10);
    
    insert(&graph, 20);

    insert(&graph, 5);

    insert(&graph, 30);

    insert(&graph, 40);

    display(graph);

    graph = reverse_k_nodes(graph, 4);

    display(graph);
}

void insert(struct Node **head, int value){

    struct Node *n_node = new_node(value);

    n_node->data = value;

    // adds the new_node at the end of head
    if(*head == NULL){
        *head = n_node;
        return;
    } else {
        struct Node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = n_node;
    }

}

struct Node *new_node(int value){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = value;

    new_node->next = NULL;

    return new_node;
}

void display(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* reverse_k_nodes(struct Node *head, int k){

    int i = 0;

    struct Node *reversed = NULL;

    struct Node *current = head;

    struct Node *next;

    while (i < k && head != NULL){
        // reverses the nodes
        next = current->next;
        current->next = reversed;
        reversed = current;
        current = next;
        i++;
    }

    if (head != NULL){
        head->next = current;
    }

    int count = 0;

    while (count < k - 1 && current != NULL){
        current = current->next;
        count ++;
    }

    if (current != NULL){
        current->next = reverse_k_nodes(current->next, k);
    }

    return reversed;

}