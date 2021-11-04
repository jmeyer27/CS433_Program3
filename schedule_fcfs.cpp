#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"
#include <string.h>
#include <iostream>
#include <stack> //I don't think this is needed

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
    Task *current; 
    
     while (head != NULL) {

        current = head->task; 

         run(current,current->burst);

         remove(&head, current);
    }

}//end schedule()
