CC = gcc
CFLAGS = -O3 -Wall 
CFLAGS += -D_LARGEFILE_SOURCE
CFLAGS += -fno-exceptions
CFLAGS += -finline-functions
CFLAGS += -funroll-loops
CFLAGS += -D_FILE_OFFSET_BITS=64
 
# Source files
DISK_SORT_SRC=disk_sort.c

MAIN_SRC=main.c


 
# Binaries
all: write_blocks_seq read_blocks_seq

#sequential writing in blocks
disk_sort: $(DISK_SORT_SRC) $(MAIN_SRC)
	$(CC) $(CFLAGS) $^ -o disk_sort

clean:  
	rm write_blocks_seq read_ram_seq output*.dat
