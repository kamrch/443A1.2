#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
#include "merge.h"

/**
* Compares two records a and b
* with respect to the value of the integer field f.
* Returns an integer which indicates relative order:
* positive: record a > record b
* negative: record a < record b
* zero: equal records
*/

//taken from handout
int compare (const void *a, const void *b) {
    int a_f = ((const struct Record*)a)->f;
    int b_f = ((const struct Record*)b)->f;
    return (a_f - b_f);
}


//Sort function that uses qsort, some codes are from handout
void sort(Record* buffer, int total_records){
    /**
 * Arguments:
 * 1 - an array to sort
 * 2 - size of an array
 * 3 - size of each array element
 * 4 - function to compare two elements of the array
 */
    qsort (buffer, total_records, sizeof(Record), compare);
}

// function to print buffer contents to stdout
void print_buffer(Record* buffer, int total_records){
    printf("=====Total records: %d\n=====", total_records);
    for (int i=0; i<total_records; i++){
        printf("uid2 = %d, uid1 = %d\n", buffer[i].UID2, buffer[i].UID1);
    }
}
