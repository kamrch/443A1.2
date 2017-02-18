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
    Record r1 = *(Record*) a;
    Record r2 = *(Record*) b;
    int a_f = r1.UID2;
    int b_f = r2.UID2;
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

// function for Phase 1 of 2PMMS
int phase1(char* input_file, int total_mem, int block_size){
    FILE *fp_read, *fp_write;
    char *prefix = "sorted_list";
    int total_records;


    //check if enough memory
    if(block_size > total_mem){
        exit(0);
    }
    int block_num = (total_mem / block_size) / 2;
    if (block_num < 1){
        printf("Error: insufficient memory.\n");
        exit(1);
    }

    int chunks = block_num * block_size / sizeof(Record);

    if (!(fp_read= fopen (input_file , "r" ))) {
        printf ("Error when reading file \"%s\"\n", input_file);
        exit(0);
    }



    /*finding the file size and total number of records*/
    fseek(fp_read, 0, SEEK_END);
    int file_size = ftell(fp_read);
    total_records = file_size / sizeof(Record);
    fseek(fp_read, 0, SEEK_SET);
    int temp_total = total_records;
    int i = 0;

    Record * buffer = (Record *) calloc (chunks, sizeof (Record));

    while (temp_total > 0){
        int read_records = fread(buffer, sizeof(Record), chunks, fp_read);
        if (read_records < 0) {
            printf ("Error when reading file \"%s\" \n", input_file);
            exit(1);
        } else {
            // sort list then write to disk
            sort(buffer, temp_total);
            //save contents of each iteration into different files.
            char output_file[MAX_PATH_LENGTH];
            snprintf(output_file, sizeof(char) * MAX_PATH_LENGTH, "sorted_list%1.dat", i);
            if (!(fp_write = fopen ( output_file , "wb" ))) {
                printf ("Error when writing file sorted_list  \n");
                exit(0);
            }
    	    fwrite (buffer, sizeof(Record), read_records, fp_write);
            fclose(fp_write);

            temp_total -= read_records;
            i++;
        }
    }

    free(buffer);
    fclose(fp_read);

    return i;
}
