#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"
#include <string.h>
#include <iostream>
#include <stack> //I don't remember if this is needed

struct node *head = NULL;

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
 *  * Run the FCFS scheduler
 *   */
void schedule() //not fcfs, is absolutely lcfs
{

  	//algorithm. move head/stack to new stack. then run and remove.?
    //std::stack<task> stack;    maybe not?

    //other possibility
    //for size of list (class), add run and remove last elements


  //this can be for after stack is organized and ready to run
    Task *current; 
    
     while (head != NULL) {

        current = head->task; 

         run(current,current->burst);

         remove(&head, current);
    }

}//end schedule()
