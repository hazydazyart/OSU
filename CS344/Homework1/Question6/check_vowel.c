// Megan Conley
// conleyme@onid.oregonstate.edu
// CS344-400
// Homework 

/*

  from:
  http://www.programmingsimplified.com/c/source-code/c-program-check-vowel

 */


#include <stdio.h>
 
int main()
{
  char ch[1];
 
  fflush(stdin);
  printf("Input a character: \n");
  scanf("%c", ch);
 
  switch(*ch)
  {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
      printf("%c is a vowel.\n", *ch);
      break;
    default:
      printf("%c is not a vowel.\n", *ch);
  }              
 
  return 0;
}
