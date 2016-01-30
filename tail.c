#include <stdio.h>
#include <string.h>
#include "lineholder.h"
#define MAX 2000
#define MAXLEN 1000
/** Steven Fung
    if( argc only count one)
     the n set as default
    else use the number we give in argc to be the lines that we want to print
    while(we read not line and not end of file)
    ( go to the function of lineholder and use the function)
      use print_ lines in lineholder to print the lines
**/
int getLine (char *line, int Max);
main(int argc, char *argv[])
{
   int n;
   char line[MAX];
   if (argc == 1)       //if we only write tail without -n, we automatically set n = last 10 lines
   {
    n =10;
   }
   else if(argc >1)	//if we giving command with -n after tail, we set the number of lines equal to the n we giving
  {
   n = atoi((++argv)[0]+1);
  }
 init_lineholder(n);   //use the lineholder.c's function
 while (getLine(line, MAXLEN) >0)  //read the lines
 {
   insert_line(line);  //use the lineholder.c's function to put the line in the array with the length we set
 }
   print_lines();     //print out the last n lines we want to print
}
int getLine(char *line, int Max)
{
 int c, i;
 for (i = 0; i < Max-1 && (c = getchar())!= EOF && c !='\n'; ++i)
  line[i] = c;
 if(c == '\n')
{
 line[i] = c;
 ++i;
}
 line[i] = '\0';
 return i;
}
