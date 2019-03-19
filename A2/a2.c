
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "a2.h"
#include "printStats.c"

#define COUNT 48

void readFile(process *proc);
void bubbleSort(process *proc, ui *queue, ui queueCount);
void cpuCycle(process *proc, ui *io, ui ioCount, ui cpu, os OS);
void loop(process *proc, ui * queue, ui * io, ui cpu, ui queueCount, ui ioCount, os OS);

int main(int argc, char *agrv[]){


   
    //Varibales and arrays
    process proc[48]; 
    ui queue[48]; 
    ui queueCount = 0;
    ui io[48]; 
    ui ioCount = 0;
    ui cpu;

    os OS;

    OS.quantum = 70;
    OS.wait = 30;

    
	//read in the file
	readFile(proc);

	// do the queue stuff

	for(int i=0; i < COUNT; i++){
		queue[i]=i;
	}
	queueCount = COUNT;

	// sort the queue
	bubbleSort(proc, queue, queueCount);
	//do the loop
	
	loop(proc, queue, io, cpu, queueCount, ioCount, OS);

	//print the stats

	printStats(proc, OS);
    
    

    return 0;
}

void readFile(process *proc){
	int i =0;
	 //File stuff
    char *testFile = "testinput";

    FILE *file;

    file = fopen(testFile, "r");

	if(file == NULL){
		printf("ERROR OPENING FILE\n");
		exit(1);
	}

	for(i; i< COUNT; i++){
		fscanf(file, "%u %u %u %u", &proc[i].priority, &proc[i].cpu, &proc[i].io, &proc[i].runTime);
		proc[i].waitCount =1;
        proc[i].curPrior = proc[i].priority;
	}

	// while(fscanf(file, "%u %u %u %u", &proc[i].priority, &proc[i].cpu, &proc[i].io, &proc[i].runTime) != -1){
    //     proc[i].waitCount =1;
    //     proc[i].curPrior = proc[i].priority;
    // }

}

void bubbleSort(process *proc, ui *queue, ui queueCount){
	ui temp;

	for(int i=0; i< queueCount; i++ ){
		if(proc[i].curPrior > proc[i+1].curPrior){
			temp = queue[i+1];
			queue[i+1]= queue[i];
			queue[i] = temp;
		}
	}
}

void cpuCycle(process *proc, ui *io, ui ioCount, ui cpu, os OS){
	int i =0;

	ui index;

	//io
	while(i < ioCount){
		index = io[i];
		proc[index].curIo++;
		proc[index].waitSum++;
	}

	//queue
	for(i =0; i > COUNT; i++){
		proc[i].wait++;
		proc[i].waitSum++;

		if(proc[i].wait >= OS.wait){
			proc[i].curPrior++;
			proc[i].wait =0;
		}
	}

	//cpu 
	proc[cpu].curCpu++;
	proc[cpu].cpuTotal++;
}

void loop(process *proc, ui * queue, ui * io, ui cpu, ui queueCount, ui ioCount, os OS){

	while((cpu != COUNT) && (ioCount >0) && (queueCount > 0)){

		ui hPriority = queue[queueCount]; // get highes priority in queue

		// load cpu is empty load next ready process

		if((cpu == COUNT) && (queueCount >0)){
			cpu = hPriority;
			queueCount--;

			if(proc[cpu].waitMax < proc[cpu].wait){
				proc[cpu].waitMax = proc[cpu].wait;
			}
			else if(proc[cpu].waitMin > proc[cpu].wait){
				proc[cpu].waitMin = proc[cpu].wait;
			}
		}

		//move process from cpu

		if((proc[cpu].curCpu == proc[cpu].cpu) || (proc[cpu].curCpu == OS.quantum)){

			if(proc[cpu].cpu < OS.quantum){
				io[ioCount] = cpu;
				ioCount++;
			}
			else{ // move out of the cpu
				proc[cpu].wait =0;
				proc[cpu].waitCount++;
				queue[queueCount] = cpu;
				queueCount++;

				bubbleSort(proc, queue, queueCount);
			}

			// set cpu 
			proc[cpu].curCpu =0;
			cpu = COUNT; 
		}

		//update IO

		for(int i =0; i < COUNT; i++){
			ui x = io[i];

			if((x != COUNT) && (proc[x].curIo == proc[x].io)){
				//check runtime
				if(proc[x].runTime <= (proc[x].ioTotal + proc[x].cpuTotal)){
					ioCount--;
				}
				else{
					//put io in the queue
					proc[x].waitCount;
					proc[x].wait =0;
					queueCount++;
					bubbleSort(proc, queue, queueCount);
					ioCount--;
				}
				io[i] = COUNT;
			}
		}

		// do a cycle
		cpuCycle(proc, io, ioCount, cpu, OS);

		//sort the queue
		bubbleSort( proc, queue, queueCount);


	}


}