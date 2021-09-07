#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

void print_list(struct node* NODE){
    struct node * cur = NODE;
    while(cur != NULL){
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

void insert_node(struct node *head, int prevVal, int newVal){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->value = newVal;
    struct node *curNode = head;
    while(curNode->value != prevVal){
        if(curNode->next == NULL){
            printf("Where is no such value, error!\n");
            exit(0);
        }
        curNode = curNode->next;
    }
    if(curNode->next != NULL) newNode->next = curNode->next->next;
    curNode->next = newNode;
}

void delete_node(struct node* head, int delVal){
    struct node *curNode = head;
    while(curNode->next->value != delVal){
        if(curNode->next == NULL){
            printf("Where is no such element, error\n");
            exit(0);
        }
        curNode = curNode->next;
    }
    curNode->next = curNode->next->next;
}

struct node *init() {
    struct node *head = malloc(sizeof(struct node));
    head->next = NULL;
    head->value = 0;
    return head;
}


int main(){
    struct node *list = init();
    printf("initializing empty list with head element = 0\n");
    printf("adding new node with value 15\n");
    insert_node(list, 0, 15);
    printf("linked list now: ");
    print_list(list);
    printf("adding new node with value 22\n");
    insert_node(list, 15, 22);
    printf("linked list now: ");
    print_list(list);
    printf("remove node with value 15\n");
    delete_node(list, 15);
    printf("linked list now: ");
    print_list(list);
}