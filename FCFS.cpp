//todo this class
//#include "Scheduler.h"
#include "FCFS.h"
#include "Scheduler.h"
#include <iostream>
using namespace std;


int main(int argc, char** argv) {
  //Print basic information about the program
	cout << "CS 433 Programming assignment 3\n"
	"Author: Birhane Diarra and Jasmine Meyer\n"
	"Date: 10/29/2021\n"
	"Course: CS433 (Operating Systems)\n"
	"Description : \n"
	"=================================" << endl;
  Scheduler scheduler;  


  //todo learn how to make console commands work in cpp
  //supposed to respond to input "./filename textfilename (potential number for rr)"
  string inFile = "";
  int RRnumber = 10; //setting default to 10
  if(argc == 2){//no RRnumber, lazy code is lazy
    inFile = argv[1];
    cout << "Something happened" << endl;
  }

  else{
    cout << "Incorrect format." << endl;
  }}//end main

FCFS::FCFS(){

}