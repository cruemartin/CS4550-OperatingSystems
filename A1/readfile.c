#include <stdlib.h>   // For _MAX_PATH definition
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "readfile.h"

void insertZip(unsigned int x, zipTowns arrs, int length){
    int j = length -1;

    while( j >=0 && arrs.cities[j].zip >x){

        arrs.zips[j+1] = j;
        j--;
    }
    arrs.zips[j +1 ] = length;
}   

void insertCity(char *tempCity, zipTowns arrs, int length){

    int j = length -1;

    while( j >=0 && (strcmp(arrs.cities[j].town, tempCity) >0)){

        arrs.towns[j+1] = &arrs.cities[j];
        j--;
    }
    arrs.towns[j+1] = &arrs.cities[length];
}

void readFile(zipTowns arrs, FILE * infile, int * length){
    unsigned int tempZip;
    char tempCity[25];



    while(fscanf(infile, "%u %s", &tempZip, tempCity) !=-1){
        arrs.cities[*length].zip  = tempZip;

        arrs.cities[*length].town = malloc(sizeof(tempCity));

        strncpy(arrs.cities[*length].town, tempCity, sizeof(tempCity));

        insertZip(tempZip, arrs, *length);
        insertCity( tempCity, arrs, *length);

        *length++;
    }
}
