//=========================================================
//CS 433 Assignment 3
//Your names: Jasmine Meyer and Birhane Diarra
//File type: driver.cpp
//Purpose: This program will simulate tasks being run with different scheduling algorithms. It will also calculate the waiting time and turnaround time for each task, and average these numbers for the entire program. 
//===========================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "task.h"
#include "list.h"
#include "schedulers.h"


#define SIZE    100

//main is the entry point to the program
int main(int argc, char *argv[])
{
    std::cout << "CS 433 Programming Assignment 3" << std::endl;
    std::cout << "Author: Birhane Diarra and Jasmine Meyer" << std::endl;
    std::cout << "Date: 11/5/2021" << std::endl;
    std::cout << "Course: CS433 (Operating Systems)" << std::endl;
    std::cout << "Description : This program will simulate tasks being run with different scheduling algorithms. It will also calculate the waiting time and turnaround time for each task, and average these numbers for the entire program. " << std::endl;
    std::cout << "=================================" << std::endl;

    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int priority;
    int burst;

    in = fopen(argv[1],"r");//gets arguments from command line

    int RRnumber = 10;
     if(argc == 3){//get RR number from command line, if argument count = 3
       RRnumber = atoi(argv[2]);
     }
      
    
    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));

        // add the task to the scheduler's list of tasks
        add(name,priority,burst,RRnumber);

        free(temp);
    }

    fclose(in);

    
    // invoke the scheduler for specified scheduler program
    schedule();
    

    std::cout << "Complete" << std::endl;

    return 0;
}
