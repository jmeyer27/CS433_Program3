#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"
#include <string.h>
#include <iostream>

struct node *head = NULL;//is this legal?

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
 *  * Run the FCFS scheduler
 *   */
void schedule() //not fcfs, is absolutely lcfs
{

  	//algorithm. move head/stack to new stack. then run and remove.?



  //this can be for after stack is organized and ready to run
    Task *current; 
    
     while (head != NULL) {

        current = head->task; //?????????

         run(current,current->burst);

         remove(&head, current);
    }

}//end schedule()
