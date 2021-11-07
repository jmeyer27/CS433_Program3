//=========================================================
//CS 433 Assignment 3
//Your names: Jasmine Meyer and Birhane Diarra
//File type: SJF  Scheduling file
//Purpose: SJF  Scheduler schedules tasks so the task with the shortest burst time always runs next.
//===========================================================
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#include "task.h"
#include "list.h"
#include "cpu.h"

struct node *head = NULL;
Task *pickNextTask();
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
    newTask->lastRunTime = 0;//not really needed in sjf but included
    newTask->quantumTime = quantum;

    //insert task into list
    insert(&head, newTask);
}


/**
 *  * Run the SJF scheduler
 *   */
void schedule() 
{
  Task *current;
  int timeLine = 0;
    double averageTurnaroundTime = 0;
    double averageWaitingTime = 0;
    while (head != NULL) {
        current = pickNextTask();//picks task with lowest burst time

         current->waitingTime = (timeLine - current->lastRunTime) + current->waitingTime;//sjf =  (timeline-0)+0 = timeline. 

        run(current,current->burst);//runs task with lowest burst time

         timeLine += current->burst;//move timeline
        remove(&head, current);//removes task when completed
        //current->lastRunTime += timeLine; not needed for sjf
         current->turnaroundTime = timeLine;

      //place finished task into list so data can be averaged and printed out
      Task *newTask = (Task *) malloc(sizeof(Task));
      newTask->name = current->name;
      newTask->priority = current->priority;
      newTask->burst = current->burst;
      newTask->turnaroundTime = current->turnaroundTime;
      newTask->waitingTime = current->waitingTime;
      newTask->lastRunTime = 0;

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
