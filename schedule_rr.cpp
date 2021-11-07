//=========================================================
//CS 433 Assignment 3
//Your names: Jasmine Meyer and Birhane Diarra
//File type: RR  Scheduling file
//Purpose: RR  Scheduler schedules tasks to be run in order in specified time slices. If task runs and is not completed, then it is placed back into the list to be run again.
//===========================================================
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#include "task.h"
#include "list.h"
#include "cpu.h"


struct node *head = NULL;
struct node *shoulders = NULL;
struct node *tmp;
int count = 1;//counts how many processes have the same priority

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
    newTask->lastRunTime = 0;
    newTask->quantumTime = quantum;

    //insert task into list
    insert(&head, newTask);
}

/**
 *  * Run the RR scheduler
 *   */
void schedule() 
{
	Task *running;
  int timeLine = 0;
  double averageTurnaroundTime = 0;
  double averageWaitingTime = 0;
   
  while (head != NULL) {//while list is not empty
    running = head->task; //set running to head task of list
    int quantumTime = running->quantumTime;
    running->waitingTime = (timeLine - running->lastRunTime) + running->waitingTime;//for fcfs will just be (timeline-0)+0 = timeline. Others will not be.
    

    if (running->burst > quantumTime) { //if task will have to be replaced into list
                timeLine += quantumTime;//move timeline quantumTime units
                run(running, quantumTime);

                running->burst -= quantumTime;
                remove(&head, running);//removes running task from list
                add(running->name, running->priority, running->burst, running->quantumTime);//adds process that is not finished to list to be run again later
            }
            else { //task will finish during this runtime
                timeLine += running->burst;//move timeline burst units
                run(running, running->burst);
            
                running->burst = 0;

                printf("Task %s finished.\n",running->name);        
                remove(&head, running);
                running->turnaroundTime = timeLine;


                //place finished task into list so data can be averaged and printed out
                Task *newTask = (Task *) malloc(sizeof(Task));
                newTask->name = running->name;
                newTask->priority = running->priority;
                newTask->burst = running->burst;
                newTask->turnaroundTime = running->turnaroundTime;
                newTask->waitingTime = running->waitingTime;
                newTask->lastRunTime = 0;

                //insert task into list
                insert(&shoulders, newTask);




            }
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
      temp = temp->next;}

      averageTurnaroundTime = (averageTurnaroundTime/averageCounter);
    averageWaitingTime =  (averageWaitingTime/averageCounter);
    std::cout << "Average turn-around time = " << averageTurnaroundTime << ", Average waiting time = " << averageWaitingTime << std::endl;


}

