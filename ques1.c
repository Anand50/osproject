#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	printf("\n LETS SEE NUMBER OF CHILD PROCESS \n");

	int n=0;
	int number=0;
	
	pid_t pid;

                                 do
		{
			printf("PLEASE ENTER THE POSITIVE NUMBER WHICH IS GREATER THAN 0 \n"); 
  			scanf("%d", &number );	
		}while (number <= 0);

		pid = fork();

		if (pid == 0)
		{
			printf("CHILD IS WORKING\n");
			printf("%d\n",number);
			while (number!=1)
			{
				if (number%2 == 0)
				{
					number= number/2;
				}
				else if (number%2 == 1)
				{
					number = 3 * (number) + 1;
				}	
			
				printf("%d\n",number);
			}
		
			printf("CHILD PROCESS IS DONE.\n");
		}
		else
		{
			printf("PARENTS IS WAITING FOR CHILD PROCESS\n");
			wait();
			printf("PARENT PROCESS IS DONE.\n");
		}
	return 0; 
}
