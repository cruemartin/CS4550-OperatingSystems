#define _CRT_SECURE_NO_WARNINGS // you can remove this line
#include <stdlib.h>   // For _MAX_PATH definition
#include <stdio.h>
#include <malloc.h>
#include "structs.h"
#include "readfile.h"
#include "interactive.h"

void getArrs(zipTowns * arrs, int size) {  // mallocs arrays of size elements
	arrs->zips = malloc(sizeof(int) * size);
	// two more lines
	arrs->cities = malloc(sizeof(city) *size);

	arrs->towns = malloc(sizeof(city) * size);
	// zips[0] is an int
	// towns[0] is a (citie *)
	// city[0] is a citie
}

extern int getArgsInfoOpenFile(int argc, char * argv[], FILE * * infile, int * size); // 0 ok, !0 error

int main(int argc, char * argv[]) {
	zipTowns arrs; // all the arrays in one struct
	int length = 0;		// current count of items in arrays 


	printf("%s/n", argv[1]);

	FILE * infile = NULL;

	int ret=0, size;

	if (getArgsInfoOpenFile(argc, argv, &infile, &size)) {
		printf("error in command line arguments\n");
		ret = -1;
	}

	else {
		getArrs(&arrs, size);
		readFile(arrs, infile, &length);
		fclose(infile);
		doInteractive(arrs, length);
	} // end else no error in command line
	printf("press any key: ");
	getc(stdin);
	
	return ret;
}

int getArgsInfoOpenFile(int argc, char * argv[], FILE ** infile, int * size) // 0 ok else !0 error
{
	int retval = 0;	
	char * fileName;

	printf("\nargv1= %s\n", argv[1]);

	// test for correct arguments number 3: exename, filename, size
	if(argc != 3){
		retval =-1;
	}
	// attempt to open file
	else{

		*size = atoi(argv[2]);
		if((infile = fopen(argv[1], "r") == NULL)){
			retval =-1;
		}
		
		//print(]n)+
		printf("\n\nsize %d\n\n", *size);

	}
	
	// return file and size in parameters or error
	//printf("file %s", *infile);
	printf("\n\nretrival= %d\n\n", retval);
	return retval;
}
