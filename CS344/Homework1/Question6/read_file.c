// Megan Conley
// conleyme@onid.oregonstate.edu
// CS344-400
// Homework 1

/*

  from:
  http://www.programmingsimplified.com/c-program-read-file

 */

#include "read_file.h"

int main()
{
   char file_name[25];
   char ch;
   FILE *fp;
 
   // Get file name
   printf("Enter the name of file you wish to see: \n");
   scanf("%24s", file_name);

   // Attempt to open file
   fp = fopen(file_name, "rt");

   // If file not found, exit program
   if(!fp) {
	printf("Error opening file. Terminating program.\n");
	exit(EXIT_FAILURE);
   }

   printf("The contents of the %s file are :\n", file_name);

   // Get one character at a time and print to console until end of file is reached
   while(fp) {
       ch = fgetc(fp);
      
       if(ch == EOF) {
           break;
       } else {
	   printf("%c", ch);
       }
   }

   // Close file
   fclose(fp);

   return 0;
}
