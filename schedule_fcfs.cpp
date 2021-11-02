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

  std::cout << "add fcfs is running" << std::endl;
  // first create the new task
    Task *newTask = (Task *) malloc(sizeof(Task));

    newTask->name = name;
    newTask->priority = priority;
    newTask->burst = burst;

    // insert the new task into the list of tasks 
    insert(&head, newTask);
}
// 	std::cout << "add fcfs" << std::endl;

// if(){}//if first in whatever this is
//  struct node *head = NULL;
  
//   insert(&head, new task);
//   //initialize information in task[0] for new task info
//   //(for sjf make have a var for smallest burt?)


/**
 *  * Run the FCFS scheduler
 *   */
void schedule() //currently writing algorithm
{

  //run(Task task, burst);
	//if list empty
  //put next in front of list
  //do job (run)
  //out time
  std::cout << "Scheduled" << std::endl;


}
