//=========================================================
//CS 433 Assignment 3
//Your names: Jasmine Meyer and Birhane Diarra
//File type: driver.cpp
//Purpose: 
//===========================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "task.h"
#include "list.h"
#include "schedulers.h"
//#include "cpu.h"

#define SIZE    100

//main is the entry point to the program
int main(int argc, char *argv[])
{
    std::cout << "CS 433 Programming Assignment 3" << std::endl;
    std::cout << "Author: Birhane Diarra and Jasmine Meyer" << std::endl;
    std::cout << "Date: 11/5/2021" << std::endl;
    std::cout << "Course: CS433 (Operating Systems)" << std::endl;
    std::cout << "Description : **** " << std::endl;
    std::cout << "=================================" << std::endl;

    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int priority;
    int burst;

    in = fopen(argv[1],"r");

    long RRnumber = 10;
     if(argc == 3){//get RR number from command line
       RRnumber = strtol(argv[2], NULL, 10);
     }
     //runrun = RRnumber;

    
    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));

        // add the task to the scheduler's list of tasks
        add(name,priority,burst);

        free(temp);
    }

    fclose(in);

    // invoke the scheduler
    schedule();
    

    std::cout << "Complete" << std::endl;

    return 0;
}
