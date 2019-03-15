#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "a2.h"


#define COUNT 48


void createStructs(process *proc);
// void setupReadyQueue(unsigned int * q);
void enqueue(unsigned int *q, unsigned int *qCount, int process);
unsigned int dequeue(unsigned int *q, unsigned int *qCount);


int main(int argc, char *agrv[]){

	unsigned int *q = malloc(COUNT);
	unsigned int *io = malloc(COUNT);
	unsigned int qCount =0;
	unsigned int ioCount =0;

	//Allocate memory for the pointer to structs
    process *proc = malloc(sizeof(process)*COUNT);

	//Called createStructs to create and fill stucts 
	createStructs(proc);
    
	//set up prority queue

    return 0;
}

void createStructs(process *proc){
	int i =0;

	//Allocate memory for the varibles of each struct
    for(i; i<COUNT; i++){
         proc[i].priority = malloc(sizeof(ui)); // never changes
	     proc[i].cpu = malloc(sizeof(ui));  // time in cpu before I/O
	     proc[i].io = malloc(sizeof(ui)); // time I/O takes
	     proc[i].runTime = malloc(sizeof(ui)); // how long process runs

	     proc[i].curCpu = malloc(sizeof(ui)); // count of current time in CPU
	     proc[i].curIo = malloc(sizeof(ui));  // count of time waiting for I/O
	     proc[i].wait = malloc(sizeof(ui)); // current count of time in ready queue
	     proc[i].curPrior = malloc(sizeof(ui)); // adjusted for starvation
	     proc[i].cpuTotal = malloc(sizeof(ui)); // sum of time in cpu
	     proc[i].ioTotal = malloc(sizeof(ui)); // sum of time doing io
				// statistics
	     proc[i].waitSum = malloc(sizeof(ui)); // total time in ready queue
	     proc[i].waitCount = malloc(sizeof(ui)); // how many times in ready queue (for average)
	     proc[i].waitMin = malloc(sizeof(ui)); // smallest time in ready queue
	     proc[i].waitMax = malloc(sizeof(ui)); // longet time in ready queu
    }

	i =0;

	// open file

    FILE * file;
          
    file = fopen("testinput", "r");

	//read in the information from the file and intialize the stuct variables 
    while(fscanf(file, "%u %u %u %u", &proc[i].priority, &proc[i].cpu, &proc[i].io, &proc[i].runTime) != -1){

        //fprintf(stdout,"%d\n", i);

        proc[i].curCpu =0; // count of current time in CPU
	    proc[i].curIo =0;  // count of time waiting for I/O
	    proc[i].wait =0; // current count of time in ready queue
	    proc[i].curPrior =0; // adjusted for starvation
	    proc[i].cpuTotal =0; // sum of time in cpu
	    proc[i].ioTotal =0; // sum of time doing io
				// statistics
	    proc[i].waitSum =0; // total time in ready queue
	    proc[i].waitCount =0; // how many times in ready queue (for average)
	    proc[i].waitMin =0; // smallest time in ready queue
	    proc[i].waitMax =0; // longet time in ready queu

        i++;

    }

    fclose(file);
}

// void setupReadyQueue(unsigned int * q){
// 	for(int i=0; i<COUNT; i++){
// 		q[i]=i;
// 	}
// }

void enqueue(unsigned int *q, unsigned int *qCount, int process){
	q[(unsigned int)*qCount] = process;
}

unsigned int dequeue(unsigned int *q, unsigned int *qCount){
	unsigned int oldFront = q[0];

	for(int i=0; i<*qCount; i++){

		q[i] = q[i+1];
	}

	*qCount = *qCount-1;

	return oldFront;
}
