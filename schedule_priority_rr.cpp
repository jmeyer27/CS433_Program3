#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"

struct node *head = NULL;
struct node *shoulders = NULL;
struct node *tmp;
int count = 1;//counts how many processes have the same priority

Task *pickNextTask();



// adds a new task to the list of tasks
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
 *  * Run the Priority RR scheduler
 */
void schedule() 
{
	Task *running;
    tmp = head;
    int timeLine = 0;
    double averageTurnaroundTime = 0;
    double averageWaitingTime = 0;

    while (head != NULL) {
        running = pickNextTask();
        if (count > 1){
            if (running->burst > QUANTUM) {
                
                run(running, QUANTUM);

                running->burst -= QUANTUM;
                remove(&head, running);
               add(running->name, running->priority, running->burst);
            }
            else {
                run(running, running->burst);
            
                running->burst = 0;

                printf("Task %s finished.\n",running->name);        
                remove(&head, running);
            }
        }
        else{
            //no duplicate priorities, run as normal round robin
            run(running, running->burst);
            running->burst = 0;
            printf("Task %s finished.\n",running->name);        
            remove(&head, running);} 
      }

}



/**
 * Returns task with highest priority to be run next
 */
Task *pickNextTask()
{
    struct node *temp;
    Task *highestPriority = head->task;
    temp = head->next;

    count = 1;//how many processes with the same priority
    while (temp != NULL){
        if (temp->task->priority > highestPriority->priority ){
            highestPriority = temp->task;
            count = 1;//not the same priority, and bigger so reset to 1
        }
        else if (temp->task->priority == highestPriority->priority){
            count++;//same priority, increment
        }
        temp = temp->next;
    }

    return highestPriority;

 
}


