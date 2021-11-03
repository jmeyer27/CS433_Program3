#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"

Task *pickNextTask();
struct node *head = NULL;
// pointer to the struct containing the next task
struct node *tmp;
int cnt = 1;//counts how many processes have the same priority




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
 *  * Run the Priority scheduler
 *   
 */
void schedule()    //currently has segmentation fault. Something is very wrong.
{
	// TODO: add your implementation here
  Task *current;
    //Task *previous;

    tmp = head;

     while (head != NULL) {
        current = pickNextTask();
        
        //run current. Simple. Is this good enough?
          current = head->task; 

          run(current,current->burst);

          remove(&head, current);



      
}//while head not null
}//schedule ends here


/**
 * Returns the next task selected to run.
 */
Task *pickNextTask()
{

    struct node *temp;
    Task *hp = head->task;
    temp = head->next;

    cnt = 1;//how many processes with the same priority
    while (temp != NULL){
        if (temp->task->priority > hp->priority ){
            hp = temp->task;
            cnt = 1;//not the same priority, and bigger so reset to 1
        }
        else if (temp->task->priority == hp->priority){
            cnt++;//same priority, increment
        }
        temp = temp->next;
    }

    return hp;

 
}