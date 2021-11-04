#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"

Task *pickNextTask();
struct node *head = NULL;
// pointer to the struct containing the next task
struct node *tmp;
int count = 1;//counts how many processes have the same priority


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
 *  * Run the Priority scheduler
 *   
 */
void schedule()
{
	// TODO: add your implementation here
  Task *current;
    

    tmp = head;

     while (head != NULL) {
        current = pickNextTask();

          run(current,current->burst);

          remove(&head, current);

}//while head not null
}//schedule ends here


/**
 * Selects and returns the next task with the highest priority to run.
 */
Task *pickNextTask()
{

    struct node *temp;
    Task *highPriority = head->task;
    temp = head->next;

    count = 1;//how many processes with the same priority
    while (temp != NULL){
        if (temp->task->priority > highPriority->priority ){
            highPriority = temp->task;
            count = 1;//not the same priority, and bigger so reset to 1
        }
        else if (temp->task->priority == highPriority->priority){
            count++;//same priority, increment
        }
        temp = temp->next;
    }

    return highPriority;

 
}