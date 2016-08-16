/* -------------------------------------------------------------------
  
Program file:	chasep3.c
Author:     	A. Chase
Email:			Andrew_Chase@student.uml.edu
Date:       	October 1, 2015
Assignment: 	Programming Assignment #3
Course #:   	90.212.031
Objective:		Write a C program that prompts the user to enter information 
				about up to ten individuals and stores the information in a 
				structure, then output it.
----------------------------------------------------------------------*/

#include <stdio.h>
#include<string.h>
#include <stdbool.h>

				/* Function Prototypes. */
				/* ------------------- */
				
void safer_gets (char array[], int max_chars);

bool equalStrings (const char  s1[], const char  s2[]);

				/* Declare structs. */
     			/* ------------------ */
	struct info
 		{
   			char 	name[35];
			char	address[50];
			char	city[25];
  			char	state[3];
			long	zip_code;
			int 	age;
			char	gender;
   		};
            
   struct  states
		{
			char   abbr[3];
		}; 
			
int main()
{
     			/* Declare variables. */
     			/* ------------------ */


	int   entries = 51;
	int   test;
	int   x, n;
 	struct info people[10];
  	const struct states members[51] =
		{"AL",    "AK",    "AZ",    "AR",    "CA",    "CO",    "CT",    "DE",    "DC",   
      	"FL",    "GA",    "HI",    "ID",    "IL",    "IN",    "IA",    "KS",    "KY",   
      	"LA",    "ME",    "MD",    "MA",    "MI",    "MN",    "MS",    "MO",    "MT",   
      	"NE",    "NV",    "NH",    "NJ",    "NM",    "NY",    "NC",    "ND",    "OH",   
      	"OK",    "OR",    "PA",    "RI",    "SC",    "SD",    "TN",    "TX",    "UT",   
      	"VT",    "VA",    "WA",    "WV",    "WI",    "WY"};

             /* Prompt for Number of People to be added. */
             
	printf ("****Welcome to the ACME Datatron****");
	printf ("\nPlease enter the following info.\n");
	printf ("Number of persons to be input (1-10)?: ");
			
		do
		{				
			scanf ("%i", &x);
			fflush (stdin);
			if ( x < 1 || x > 10 )
			printf ("Please enter a number between 1 and 10: ");
		}
			while ( x < 1 || x > 10 ); /*end while loop */
      		

		for ( n = 0;  n < x;  n++)
  		{
			printf ("\nEnter name: ");
   			safer_gets( people[n].name, 35);
      		fflush (stdin);                        
        	printf ("Enter street address: ");
         	safer_gets( people[n].address, 50);
          	fflush (stdin);
                        
           	printf ("Enter city: ");
            safer_gets( people[n].city, 25);
            fflush (stdin);
		
		do
		{ 	
			printf ("Enter state: ");
			fflush (stdin);
			scanf ("%2s", &people[n].state, 3);
			fflush (stdin);			
			strupr (people[n].state);
			test = lookup (members, people[n].state, entries);			
			if ( test == -1 )
			printf ("Please enter a two-letter abbreviation for a U.S. State: \n");
		}
			while ( test == -1 ); /*end states loop */
                        
		do
		{
  			printf ("Enter zip code: ");
     		scanf ("%ld", &people[n].zip_code, 5);
			fflush (stdin);
			if 
			(  people[n].zip_code < 00001 || people[n].zip_code > 99999 )
			printf ("Please enter a 5-digit Zip Code:\n");
		}
			while 
			(  people[n].zip_code < 00001 || people[n].zip_code > 99999 ); /*end zip loop */
						
		do
		{
  			printf ("Enter age: ");
     		scanf ("%i", &people[n].age);
       		fflush (stdin);
			if (  people[n].age < 1 || people[n].age > 120 )
			printf ("Please enter an age between 1 and 120:\n");
		}
			while 
			(  people[n].age < 1 || people[n].age > 120 ); /*end age loop */                      
						
		do
		{ 
			printf ("Enter gender(M or F): ");
			fflush (stdin);
  			scanf ("%c", &people[n].gender ) ;
     		fflush (stdin);
			if 
			( toupper (people[n].gender) != 'M' && toupper (people[n].gender) 
			!= 'F' && (people[n].gender) != ' ' )
			printf ("Please enter M, m, F, f, or leave blank:\n");
		}
			while
			( toupper (people[n].gender) != 'M' && toupper (people[n].gender) 
			!= 'F' && (people[n].gender) != ' ' ); /*end gender loop */
			
            } /* end input for loop */

     					/* Now output information. */
     					
	printf ("\nThe information you entered is:\n");
			
	for ( n = 0;  n < x;  n++)
 	{				
 		printf ("%s\n%s\n%s, %s %.5ld\n",
		people[n].name, people[n].address, 
		people[n].city, people[n].state, 
		people[n].zip_code ) ;
		if ( toupper (people[n].gender) == 'M' )
		printf ("He is %i years old.\n\n", people[n].age );
		else if ( toupper (people[n].gender) == 'F' )
		printf ("She is %i years old.\n\n", people[n].age );
		else if ( people[n].gender == ' ')
		printf ("Age is %i years old.\n\n", people[n].age );
				
	} /* end output for loop */

} /* end main */

			/* Function safer_gets */
			/* ******************* */
			
void safer_gets (char array[], int max_chars)
{
  int i;

  /* Read name from input buffer, character by character,   */
  /* up until the maximum number of characters in the array.*/
  /* ------------------------------------------------------ */

  for (i = 0; i < max_chars; i++)
  {
     array[i] = getchar();

     /* If "this" character is the carriage return,      */
     /* replace it with a null terminator and exit loop. */
     /* ------------------------------------------------ */

     if (array[i] == '\n')
     {
            array[i] = '\0';
            break;
     }

   } /* end for */

   /* If we have pulled out the most we can,       */
   /* and, if there are more chars in the buffer,  */
   /* clear out the remaining chars in the buffer. */
   /* This is equivalent to the fflush() function. */
   /* -------------------------------------------- */
   if (i == max_chars - 1 )

     if (array[i-1] != '\0')

       while (getchar() != '\n');

   /* Ensure the last element in the array contains the null terminator. */
   /* ------------------------------------------------------------------ */
   array[max_chars-1] = '\0';

} /* end safer_gets */

      /*-------------------------------------------------------------*/
			/* Function equal strings */
			/* ---------------------- */

bool equalStrings (const char  s1[], const char  s2[])
{
    int  i = 0;
    bool areEqual;

    while ( s1[i] == s2 [i]  &&
    		s1[i] != '\0' &&  s2[i] != '\0' )
        	++i;

    if ( s1[i] == '\0'  &&  s2[i] == '\0' )
       areEqual = true;
    else
       areEqual = false;

    return areEqual;
}
			/* Function to lookup states from an array */
			/* --------------------------------------- */

int  lookup (const struct states  members[], const char  search[],
             const int  entries)
{
    int  i;
    bool equalStrings (const char s1[], const char s2[]);

    for ( i = 0;  i < entries;  ++i )
        if ( equalStrings (search, members[i].abbr) )
            return i;

    return -1;
}
