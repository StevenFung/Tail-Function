#include <stdio.h>
#include <string.h>

void init_lineholder(int nlines);
// read the nlines we want to print

void insert_line(char *line);
//insert a line to array, but the array should have 10 elements if we didn't giving special command, or the
// n lines we set because the tail only take the last ten lines of sentences or the last n lines we want, 
//then we need to free the array if we want to replace the lines to the array
//then we need to use malloc to find a place to put the memory


void print_lines();

//print out the last ten lines or the last n lines we all.
