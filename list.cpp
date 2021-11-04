/**
 * Various list operations
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"
#include "task.h"


// add a new task to the list of tasks
void insert(struct node **head, Task *newTask) {
    // add the new task to the list 
    struct node *newNode = (struct node *) malloc(sizeof(struct node));

    newNode->task = newTask;
    //old code that works, but makes this into a stack. I want a list.
     //newNode->next = *head;
     //*head = newNode;


//maybe the below worked.~~~~~~~~~~~~~~~~~~~~~~~~~ :)
    if(*head == NULL){
        //newNode->next = *head;
      *head = newNode;
      newNode->next = NULL;
    }
    else{ 
      newNode->next = NULL;
      struct node *temp = *head;
      while(temp->next != NULL){//find task with next = null
        temp = temp->next;
    }
    temp->next = newNode;}


}//end insert

// delete the selected task from the list
void remove(struct node **head, Task *task) {
    struct node *temp;
    struct node *prev;

    temp = *head;
    // special case - beginning of list
    if (strcmp(task->name,temp->task->name) == 0) {
        *head = (*head)->next;
    }
    else {
        // interior or last element in the list
        prev = *head;
        temp = temp->next;
        while (strcmp(task->name,temp->task->name) != 0) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
    }
}

// traverse the list
void traverse(struct node *head) {
    struct node *temp;
    temp = head;

    while (temp != NULL) {
        printf("[%s] [%d] [%d]\n",temp->task->name, temp->task->priority, temp->task->burst);
        temp = temp->next;
    }
}
