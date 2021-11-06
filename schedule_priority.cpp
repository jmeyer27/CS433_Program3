//=========================================================
//CS 433 Assignment 3
//Your names: Jasmine Meyer and Birhane Diarra
//File type: Priority  Scheduling file
//Purpose: Priority  Scheduler schedules tasks to be run by priority.
//===========================================================
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#include "task.h"
#include "list.h"
#include "cpu.h"

Task *pickNextTask();//chooses task of highest priority to be run next
struct node *shoulders = NULL;
struct node *head = NULL;
// pointer to the struct containing the next task
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
 *  * Run the Priority scheduler
 *   
 */
void schedule()
{
  Task *current;
  int timeLine = 0;
  double averageTurnaroundTime = 0;
  double averageWaitingTime = 0;
    
    tmp = head;

     while (head != NULL) {
        current = pickNextTask();
        current->waitingTime = (timeLine - current->lastRunTime) + current->waitingTime;

          run(current,current->burst);
          timeLine += current->burst;//move timeline
          remove(&head, current);
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

}//while head not null

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






}//schedule ends here


/**
 * Selects and returns the next task with the highest priority to run.
 */
Task *pickNextTask()
{
    struct node *temp;
    Task *highestPriority = head->task;
    temp = head->next;

    count = 1;//how many processes with the same priority
    while (temp != NULL){
        if (temp->task->priority > highestPriority->priority ){
            highestPriority = temp->task;
            count = 1;//not the same priority, and bigger so reset to 1
        }
        else if (temp->task->priority == highestPriority->priority){
            count++;//same priority, increment
        }
        temp = temp->next;
    }

    return highestPriority;

 
}