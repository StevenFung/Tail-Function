#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lineholder.h"
#define MAX 1000
/** init_lineholder(the n in argc)
    get a value finallines = the n in argc
    void in_line(char *line)
    if (i >= n lines we want to print)
    free the array[i] because there is a memory inside
    find space
    copy string from line to array
    else (i <n)
    just find space and copy string
    void print_lines()
    print the first line we want to print and print to the end of array
    if array[0] is not the first line we want to print
    we print first line to end of array then print first array[0] to the where
    the first line's array 
**/    
static char *lines[MAX];
static int i = 0;;
static int finallines;
void init_lineholder(int nlines)	//try to make the line with less than the length of 1000
{
  if(nlines > MAX)
   nlines = MAX;
   finallines = nlines;            
}
void insert_line(char *line)		//try to put the line in array, the array should be the include the n lines we want to print out 
{
  if (i >= finallines) 			
  {
   free((void*)lines[i% finallines]);  //when using modulo, it will easy to replace the array[i], idea from circular array, free the array if the array[i] already have something inside   
   lines[i%finallines] = (char *)malloc(strlen(line)+1);  
   strcpy(lines[i%finallines], line);
  }
  else 
  {
  lines[i] = (char *)malloc(strlen(line)+1);
   strcpy(lines[i], line);
}
 ++i;
} 
void print_lines()			//print the last n lines
{ 
 int  p = i %finallines;		
  for(i = i %finallines ; i < finallines ; i++)		//find the first lines that should be print, then print all the lines with to the bottom of the array
  {
  if (lines[i] != NULL)
 {  
  printf("%s", lines[i]);
  free(lines[i]);
  }
 }
  for( i = 0 ; i <p ; i++)           // if the first i of array[i] is not equal to array[0], we need to print the lines between array[0] to array[i] 
  {
  if (lines[i] != NULL)
  {
  printf("%s", lines[i]);
  free(lines[i]);
  }
 }
}
