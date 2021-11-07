//=========================================================
//CS 433 Assignment 3
//Your names: Jasmine Meyer and Birhane Diarra
//File type: FCFS Scheduling file
//Purpose: FCFS Scheduler schedules tasks to be run in order added until completed.
//===========================================================
#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"
#include <string.h>
#include <iostream>

struct node *head = NULL;
struct node *shoulders = NULL;


//Add a new task to the list of tasks
//Parameters: char *name is the name of the task
//int priority = priority of task
//int burst = length of burst that task still has left to run
//int quantum = the quantum time allowed for each burst (used in RR schedulers)
 void add(char *name, int priority, int burst, int quantum) 
{
  //make new task and initialize
    Task *newTask = (Task *) malloc(sizeof(Task));
    newTask->name = name;
    newTask->priority = priority;
    newTask->burst = burst;
    newTask->turnaroundTime = 0;
    newTask->waitingTime = 0;
    newTask->lastRunTime = 0;//not really needed in fcfs but included
    newTask->quantumTime = quantum;

    //insert task into list
    insert(&head, newTask);
}



/**
 *  * Run the FCFS scheduler
 *   */
void schedule()
{
     Task *current; 
     int timeLine = 0;
     double averageTurnaroundTime = 0;
     double averageWaitingTime = 0;

    
     while (head != NULL) {

        current = head->task;
        current->waitingTime = (timeLine - current->lastRunTime) + current->waitingTime;//for fcfs will just be (timeline-0)+0 = timeline. Others will not be.
         run(current,current->burst);
         timeLine += current->burst;//move timeline
         remove(&head, current);
         //current->lastRunTime += timeLine; not needed for fcfs
         current->turnaroundTime = timeLine;//fcfs turnaroundtime is time passed until finished.


      //place finished task into list so data can be averaged and printed out
      Task *newTask = (Task *) malloc(sizeof(Task));
      newTask->name = current->name;
      newTask->priority = current->priority;
      newTask->burst = current->burst;
      newTask->turnaroundTime = current->turnaroundTime;
      newTask->waitingTime = current->waitingTime;
      newTask->lastRunTime = 0;//not really needed in fcfs but included

    //insert task into list
    insert(&shoulders, newTask);

    }//end while

    struct node *temp;
    temp = shoulders;
    int averageCounter = 0;

    while(temp != NULL){
      averageTurnaroundTime += temp->task->turnaroundTime;
      averageWaitingTime += temp->task->waitingTime;
      averageCounter++;
      std::cout <<temp->task->name << " turn-around time = " << temp->task->turnaroundTime << ", waiting time = " << temp->task->waitingTime<< std::endl;
      remove(&shoulders, temp->task);
      temp = temp->next;
    }
    
    averageTurnaroundTime = (averageTurnaroundTime/averageCounter);
    averageWaitingTime =  (averageWaitingTime/averageCounter);
    std::cout << "Average turn-around time = " << averageTurnaroundTime << ", Average waiting time = " << averageWaitingTime << std::endl;

}//end schedule()
