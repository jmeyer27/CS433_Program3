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
    newTask->lastRunTime = 0;

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
    running->waitingTime = (timeLine - running->lastRunTime) + running->waitingTime;//for fcfs will just be (timeline-0)+0 = timeline. Others will not be.
    

    if (running->burst > QUANTUM) { //if task will have to be replaced into list
                timeLine += QUANTUM;//move timeline QUANTUM units
                run(running, QUANTUM);

                running->burst -= QUANTUM;
                remove(&head, running);//removes running task from list
                add(running->name, running->priority, running->burst);//adds process that is not finished to list to be run again later
            }
            else { //task will finish during this runtime
                timeLine += running->burst;//move timeline burst units
                run(running, running->burst);
            
                running->burst = 0;

                printf("Task %s finished.\n",running->name);        
                remove(&head, running);
                running->turnaroundTime = timeLine;//potentially wrong

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

