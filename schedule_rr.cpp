#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"



struct node *head = NULL;

// pointer to the struct containing the next task
struct node *tmp;

int cnt = 1;//counts how many processes have the same priority

//Task *pickNextTask();
void insert_tail(struct node **head, Task *task);//

// add a new task to the list of tasks
 void add(char *name, int priority, int burst) 
{
	 // first create the new task
    Task *newTask = (Task *) malloc(sizeof(Task));

    newTask->name = name;
    newTask->priority = priority;
    newTask->burst = burst;

    // insert the new task into the list of tasks 
    insert(&head, newTask);
}

/**
 *  * Run the RR scheduler
 *   */
void schedule() 
{
	Task *current;
   
  while (head != NULL) {
    current = head->task; 

    //tmp = head;


    if (current->burst > QUANTUM) {
                
                run(current, QUANTUM);

                current->burst -= QUANTUM;
                remove(&head, current);
                insert_tail(&head, current);
            }
            else {
                run(current, current->burst);
            
                current->burst = 0;

                printf("Task %s finished.\n",current->name);        
                remove(&head, current);
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
void insert_tail(struct node **head, Task *task){
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