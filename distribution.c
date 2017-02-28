#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "merge.h"

int main(int argc, char **argv){
	if (argc != 5){
		printf ("Usage: distribution <file_name> <block_size> <column_id> <max_degree>");
        exit(1);
	}

	char *file_name = argv[1];
    int block_size = atoi(argv[2]);
    char* column_id = argv[3];
    int max_degree = atoi(argv[4]);
    FILE *fp_read;
    int results[max_degree+1];

    /* initialize the result array */
    for (int z=0; z<max_degree+1; z++){
    	results[z] = 0;	
    }

    int records_per_block = block_size / sizeof(Record);
    Record * buffer = calloc(records_per_block, sizeof(Record));

    FILE *fp_read;
    if (!(fp_read = fopen (file_name , "rb" ))){
		perror("Error in distribution.c: fp_read fopen error.\n");
		exit(1);
	}

	FILE *fp_write;
	char output_file_name[] = "merged";
	if (strcmp(column_id, "UID1") == 0){
		// case UID1
		strcat(output_file_name, "1");
	} else if (strcmp(column_id, "UID2") == 0) {
        // case UID2
        strcat(output_file_name, "2");
    }

    strcat(output_file_name, ".txt");
    if (!(fp_write = fopen(output_file_name, "wb"))) {
        printf("Error in distribution.c: fp_write fopen error.  \n");
        exit(1);
    }

    int i = 0;
    int read = 0;


    while ((read = fread(buffer, sizeof(Record), records_per_block, fp_read)) > 0) {
        int pointer = 0;
        records_per_block = block_size / sizeof(Record);

    }

}