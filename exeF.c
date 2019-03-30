#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SECONDS 2
#define MINUTES 1
#define HOURS   0
#define MAX_STRING_LEN 10000

int main()
{
	int inputValue = 0;
		    
	char numberOfTimesPlayed[MAX_STRING_LEN];

	int sumOfSeconds=0;
		    
	while(1){

	  	int flagConter =0;
		    	
	   	sumOfSeconds=0;
		    	
	    char auxInput[MAX_STRING_LEN];

	    //printf("Enter the date:");
		        
	    fgets(auxInput, MAX_STRING_LEN, stdin);
		        
	    if(feof(stdin))
	    {
	      	break;
	    }
	    else{

	       	char *ptr = strtok(auxInput, ":");
		 	
	       	while (ptr != NULL)
			{
				//printf("%s\n", ptr);
	
				switch(flagConter){
	
							case SECONDS:
								sumOfSeconds+=60-atoi(ptr);
								//printf("%d\n",sumOfSeconds);
								flagConter++;
								break;
							case MINUTES:
								sumOfSeconds+=59*60-atoi(ptr)*60;
								//printf("%d\n",sumOfSeconds);
								flagConter++;
								break;
							case HOURS:
								sumOfSeconds+=23*60*60-atoi(ptr)*60*60;
								//printf("%d\n",sumOfSeconds);
								flagConter++;
								break;
	
			}
	
			ptr = strtok(NULL, ":");
	
			}

			printf("%d\n",sumOfSeconds);
		}
	}
}
