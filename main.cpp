//project is page 327/(260??)
//reading resource is page 272
#include "Scheduler.h"
#include <iostream>
#include <string>
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
  if(argc == 3){
    inFile = argv[1];
    //RRnumber = (int) argv[2]; TODO idk I'll fix this later or something~
  }
  else{
    cout << "Incorrect format." << endl;
  }
  //cin next input on same line = filename-- might not be necessary anymore
  //cin optional input for rr number-- might not be necessary anymore



//switch console commands with one of three options (unless ./filename runs file by default, then this step is not included)

//run appropriate option (unless it runs itself with ./filename?)

//make sure stuff is printed out (probably will be included in each class)







}//end main