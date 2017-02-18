#include "merge.h"

int main (int argc, char **argv) {
	//process and validate command-line arguments

	MergeManager manager;

	/*Check if user input correct arguments*/
	if(argc != 4){
		fprintf(stderr, "Usage : main <input filename> <total memory size> <block size>.\n");
		return (-1);
	}

	char *input_file = argv[1];
	int total_mem = atoi(argv[2]);
	int block_size = atoi(argv[3]);



	int num_trunks = phase1(input_file, total_mem, block_size);

	//initialize all fields according to the input and the results of Phase I
	return 0;
}