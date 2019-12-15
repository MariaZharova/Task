#define SIZE 100
#include "common.h"
#include <string.h>
#include "Task_1.10.h"


int main(void)
{
	  char c;
	  char command[SIZE];
	  char name[SIZE];
	  unsigned long long number;
 	  while ((c = getchar()) != '\n')  //На одной строке можно ввести несколько команд
	  {
		    if (c != ',')
		    {
			      ungetc(c, stdin);
		    }

		    scanf("%s %s", command, name);
		    if (strcmp(command, "INSERT") == 0)
		    {
			      scanf("%llu", &number);
			      INSERT(name, number);
		    }
		    if (strcmp(command, "FIND") == 0)
		    {
			      FIND(name);
		    }
	      return 0;
    }
}
