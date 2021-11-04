#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"

struct node *head = NULL;
Task *pickNextTask();


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
 *  * Run the SJF scheduler
 *   */
void schedule() 
{
  Task *current;
    while (head != NULL) {
        current = pickNextTask();//picks task with lowest burst time

        run(current,current->burst);//runs task with lowest burst time

        remove(&head, current);//removes task when completed
    }
}

/**
 * This function will find the task with the shortest burst time and returns it to be scheduled to be run
 */
Task *pickNextTask() 
{
struct node *temp;//used to loop through list and compare burst times
Task *lowestBurstTime = head->task; 
temp = head->next;

    while (temp != NULL) {
        if (temp->task->burst < lowestBurstTime->burst)
            lowestBurstTime = temp->task;

        temp = temp->next;//gets next task to compare
    }

    return lowestBurstTime;
}
