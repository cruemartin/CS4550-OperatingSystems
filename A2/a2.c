#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "a2.h"


// #define COUNT 48;


int main(int argc, char *agrv[]){

   // printf("hello wolrd");

    printf("\nhere at the very top of main\n");

    int count = 48;
    int i =0;

    
    process *proc = malloc(sizeof(process)*count);

    for(i; i<48; i++){
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

    FILE * file;
          
    file = fopen("testinput", "r");
   
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
    //printf("%d\n", i);



    return 0;
}