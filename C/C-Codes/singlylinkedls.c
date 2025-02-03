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
    while(p != NULL){  // Fix the loop condition
        printf("%d -> ", p -> data);
        p = p -> next;
    }
    printf("NULL\n"); // End of list indicator
}

int main(){
    int n = 0;
    node * HEAD = NULL;
    printf("\n How many nodes: ");
    scanf("%d", &n);

    HEAD=createLinkedlist(n);
    displayList(HEAD);
    return 0;
}