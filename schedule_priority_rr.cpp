#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"


struct node *head = NULL;

// pointer to the struct containing the next task
struct node *tmp;

int cnt = 1;//counts how many processes have the same priority

Task *pickNextTask();

// add a new task to the list of tasks
 void add(char *name, int priority, int burst) 
{
	// add a new task to the list of tasks
void add(char *name, int priority, int burst) {
    // first create the new task
    Task *newTask = (Task *) malloc(sizeof(Task));

    newTask->name = name;
    newTask->priority = priority;
    newTask->burst = burst;

    // insert the new task into the list of tasks 
    insert(&head, newTask);
}
}

/**
 *  * Run the Priority RR scheduler
 */
void schedule() 
{
	
}


