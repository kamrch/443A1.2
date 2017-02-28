CC = gcc
CFLAGS = -O3 -Wall 
CFLAGS += -D_LARGEFILE_SOURCE
CFLAGS += -fno-exceptions
CFLAGS += -finline-functions
CFLAGS += -funroll-loops
CFLAGS += -D_FILE_OFFSET_BITS=64
 
# Source files
DISK_SORT_SRC=disk_sort.c merge_external.c

MERGE_EXTERNAL=merge_external.c

MAIN_SRC=main.c


 
all: write_blocks_seq read_blocks_seq


disk_sort: $(DISK_SORT_SRC) $(MAIN_SRC)
	$(CC) $(CFLAGS) $^ -o disk_sort

merge_external: $(MERGE_EXTERNAL) $(MAIN_SRC)
	$(CC) $(CFLAGS) $^ -o merge_external

clean:  
	rm disk_sort merge_external output*.dat
