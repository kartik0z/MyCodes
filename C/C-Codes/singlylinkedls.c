#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}node;

node * createLinkedlist(int n){
    int i = 0;
    node * head = NULL;
    node * temp = NULL;
    node * p = NULL;

    for(i=0; i<n; i++){
        temp = (node*)malloc(sizeof(node));
        printf("Enter the data for node number %d: ", i+1);
        scanf("%d", &(temp->data));

        temp -> next = NULL;

        if(head==NULL){
            head=temp;
        }
        else{
            p=head;
            while(p->next!=NULL){
                p=p->next;
            }
            p -> next = temp;
        }
    }
    return head;
}

void displayList(node * head){
    node * p = head;
    printf("\nLinked List Elements:\n");
    while(p != NULL){
        printf("%d -> ", p -> data);
        p = p -> next;
    }
    printf("NULL\n");
}

void insertAtBeginning(node **head, int value) {
    node *temp = (node*)malloc(sizeof(node));
    temp->data = value;
    temp->next = *head; 
    *head = temp;
}

int main(){
    int value, choice;
    int n = 0;
    node * HEAD = NULL;
    printf("\n How many nodes: ");
    scanf("%d", &n);

    switch(choice){
        case 1: HEAD = createLinkedlist(n);
            break;
        case 2: printf("Enter the value you wish to enter: ");
                scanf("%d", &value);
                insertAtBeginning(&HEAD,value);
            break;
        case 3: displayList(HEAD);
    }
    return 0;
}