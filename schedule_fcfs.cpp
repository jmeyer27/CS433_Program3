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
    newTask->turnaroundTime = 0;
    newTask->waitingTime = 0;

    //insert task into list
    insert(&head, newTask);
}



/**
 *  * Run the FCFS scheduler
 *   */
void schedule()
{
     Task *current; 
    // int timeLine = 0;
    // double averageTurnaroundTime = 0;
    // double averageWaitingTime = 0;

    
     while (head != NULL) {

        current = head->task; 
         run(current,current->burst);
         //int timeLine =+ current->burst;//move timeline
         remove(&head, current);

    }

    //print each turnaround and waiting time
    //average turnaroundtime & average waiting time

}//end schedule()
