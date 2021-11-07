//=========================================================
//CS 433 Assignment 3
//Your names: Jasmine Meyer and Birhane Diarra
//File type: Priority RR Scheduling file
//Purpose: Priority RR Scheduler schedules tasks to be run by priority. If the priority of more than one task is the same, then the tasks are run in RR scheduling. If there is only one task with the highest priority in the list, then it is schedules FCFS.
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

Task *pickNextTask();



// adds a new task to the list of tasks
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
 *  * Run the Priority RR scheduler
 */
void schedule() 
{
	Task *running;
    tmp = head;
    int timeLine = 0;
    double averageTurnaroundTime = 0;
    double averageWaitingTime = 0;

    while (head != NULL) {
        running = pickNextTask();//picks next task
        running->waitingTime = (timeLine - running->lastRunTime) + running->waitingTime;
        if (count > 1){//if multiple tasks have same priority, is run as round robin
        int quantumTime = running->quantumTime;
            if (running->burst > quantumTime) {
                
                run(running, quantumTime);//run program
                timeLine += quantumTime;//move timeline
                running->burst -= quantumTime;//update remaining burts
                remove(&head, running);//remove from list
                add(running->name, running->priority, running->burst,running->quantumTime);//add to end of list
                running->lastRunTime += timeLine;//update the last run time after it is placed
               
            }
            else {//process
                run(running, running->burst);
                timeLine += running->burst;//move timeline
                running->burst = 0;

                printf("Task %s finished.\n",running->name);        
                remove(&head, running);
                running->lastRunTime += timeLine; 
                running->turnaroundTime = timeLine;

                //place finished task into list so data can be averaged and printed out
                Task *newTask = (Task *) malloc(sizeof(Task));
                newTask->name = running->name;
                newTask->priority = running->priority;
                newTask->burst = running->burst;
                newTask->turnaroundTime = running->turnaroundTime;
                newTask->waitingTime = running->waitingTime;
                newTask->lastRunTime = running->lastRunTime;

                //insert task into list
                insert(&shoulders, newTask);



            }
        }
        else{
            //no duplicate priorities, run as normal round robin
            run(running, running->burst);
            timeLine += running->burst;//move timeline
            running->burst = 0;
            printf("Task %s finished.\n",running->name);        
            remove(&head, running);
            running->lastRunTime += timeLine; 
            running->turnaroundTime = timeLine;
            
            //place finished task into list so data can be averaged and printed out
                Task *newTask = (Task *) malloc(sizeof(Task));
                newTask->name = running->name;
                newTask->priority = running->priority;
                newTask->burst = running->burst;
                newTask->turnaroundTime = running->turnaroundTime;
                newTask->waitingTime = running->waitingTime;
                newTask->lastRunTime = running->lastRunTime;

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
      temp = temp->next;
    }
    
    averageTurnaroundTime = (averageTurnaroundTime/averageCounter);
    averageWaitingTime =  (averageWaitingTime/averageCounter);
    std::cout << "Average turn-around time = " << averageTurnaroundTime << ", Average waiting time = " << averageWaitingTime << std::endl;

}



/**
 * Returns task with highest priority to be run next
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


