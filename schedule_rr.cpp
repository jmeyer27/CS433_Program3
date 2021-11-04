#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"


struct node *head = NULL;
struct node *tmp;
int count = 1;//counts how many processes have the same priority

void insertTail(struct node **head, Task *task);


// add a new task to the list of tasks
 void add(char *name, int priority, int burst) 
{
	 //make new task and initialize
    Task *newTask = (Task *) malloc(sizeof(Task));
    newTask->name = name;
    newTask->priority = priority;
    newTask->burst = burst;

    //insert task into list
    insert(&head, newTask);
}

/**
 *  * Run the RR scheduler
 *   */
void schedule() 
{
	Task *running;
   
  while (head != NULL) {//while list is not empty
    running = head->task; //set running to head of 

    if (running->burst > QUANTUM) {
                
                run(running, QUANTUM);

                running->burst -= QUANTUM;
                remove(&head, running);
                add(running->name, running->priority, running->burst);
                //insertTail(&head, running);
            }
            else {
                run(running, running->burst);
            
                running->burst = 0;

                printf("Task %s finished.\n",running->name);        
                remove(&head, running);
            }
  }//end while



  
    //run(current, current->burst);
    //current->burst = 0;
    //printf("Task %s finished.\n",current->name);        
    //remove(&head, current);
}


/*
Puts the new node at the end of the list
*/
void insertTail(struct node **head, Task *task){
    struct node* newNode = (struct node *)  malloc(sizeof(struct node));
    newNode->task = task;
    newNode->next = NULL;

    
    if ((*head) == NULL){
        *head = newNode;
        //the head is empty so we place the new node at the end of the list since head is the end
    }
    else{
        //not at the end of the list, keep looking for it by traversing the list
        struct node *tmp = *head;
        while (tmp->next != NULL)
            tmp = tmp->next;
        
        tmp->next = newNode;
    }
}

/**
 * Returns the next task selected to run.
 */