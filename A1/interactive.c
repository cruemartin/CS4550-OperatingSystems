
#include <stdio.h>
#include "structs.h"
#include "interactive.h"

int zipSearch(zipTowns arrs, int left, int right, unsigned int x){

    while( left <= right){
        int mid = left + ((right -left)/2);

        if(arrs.cities[arrs.zips[mid]].zip == x){
            return mid;
        }

        if(arrs.cities[arrs.zips[mid]].zip <x){
            left = mid +1;
        }

        else{
            right = mid - left;
        }
    }

    return -1;

}

//int( ) // add this stuff tomorrow



void doInteractive(zipTowns arrs, int length){

    int input;
    unsigned int zip;
    char city[25];

    int index;


    do{

        printf("1. Quit \n2. Search for Zip\n3. Search for town\n");
        scanf("%d", &input);

        switch(input){
            case 1:
                    break;
            case 2:
                    printf("\nEnter a zip: ");
                    scanf("%u", &zip);
                    //do a zip search

                    index = zipSearch(arrs, 0, length-1, zip);

                    if(index != -1){
                        printf("Found! City: %s Zip: %u\n", arrs.cities[index].town, arrs.cities[index].zip);
                    }
                    else{
                        printf("Sorry not found");
                    }
                    break;
            case 3:
                    printf("\nEnter a city: ");
                    scanf("%s", city);
                    // do a city search
                    break;
            default:
                    break;
        }


    }while(input != 1);

}