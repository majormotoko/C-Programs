/* -------------------------------------------------------------------
  
Program file:	chasep4.c
Author:     	A. Chase
Email:			Andrew_Chase@student.uml.edu
Date:       	October 22, 2015
Assignment: 	Programming Assignment #4
Course #:   	90.212.031
Objective: 		This program prompts user to sort information
				about any number of individuals and print a report accordingly.
				(array notation) 
				
------------------------------------------------------------------------ */

#include <stdio.h>
#include <string.h> 

	/* Structure definition */
	/* -------------------- */

 	struct split
 	{
 		char last[10];
 		char first[10];
 	};
 	
 	struct info
  	{
		struct  split name;
		char  	address[20];
		char  	city[15];
		char  	state[3];
		long  	zip;
		int   	age;
		char  	gender;
  	};  /* end struct info */
  	
 		/* Declare Prototype */
 		/* ----------------- */

	void sort_them(struct info [], int, char); 

main()	
{
  	/* Declare variables */
  	/* ----------------- */

  	struct info		people[] =
  	{
  		{"Asimov", "Isaac", "15 Main St", "Worcestor", "MA", 01555, 23, 'M'},
  		{"Smith", "Jane", "17 Make Peace", "Wallham", "ND", 10102, 28, 'F'},
  		{"De Rippa", "Jack", "18 Able Way ", "Boston", "MA", 50503, 74, 'M'},
  		{"Cobb", "Jim", "55 Elm St", "Ware", "MO", 61555, 65, 'M'},
  		{"Kapone", "Al", "15 Morin Ave", "Idunno", "MN", 31333, 34, 'M'},
  		{"Seigel", "Myron", "44 Wing Blvd West", "Sandwich", "WA", 2537, 21, 'M'},
  		{"Thymes", "Mary", "88 Same Place", "Washington", "DC", 90555, 44, 'F'} 
  		
  	};
  	
  	int				i, bad_sort;
	int				num_people = sizeof(people) / sizeof(people[0]); //this will be the count of how many people there are!
	char 			sort_order;
	char 			big_name[22];
		
	struct info *people_ptr = people; 

/*   in Assignment #4 from here down, any references to arrays will be deductions   */ 
			
	printf ("\nWelcome to the People Structure Data Report Program\n");
						
					/* Prompt for sort order and */
					/* validate entry -----------*/
					/* --------------------------*/
	do
	{
			bad_sort = 1;
						
			printf ("\nEnter the sort order for the report: ");
			printf ("\n(N=Name, A=Age, S=State, Z=Zip code ' '=no sort)\n ");
								
			sort_order = getchar();
			
			fflush(stdin);
						
			if(sort_order == '\n' || sort_order == ' ') break; /* blank or return is allowed for no sorting of the data */	
 			
			sort_order = toupper(sort_order);
			
			if ((sort_order == 'N') || (sort_order == 'A') || 
						(sort_order == 'S') || (sort_order == 'Z'))
			  	bad_sort = 0;
			else
			  	printf("\nIncorrect Sort order selected, please re-enter:  ");
			  
	} while (bad_sort == 1); /* end while loop */
	
					/* Pass filtered response to */
					/* switch statement for sort */
					/* options ----------------- */

	switch (sort_order)
	{
		case 'N':
			printf("Sort by Name  %i People.\n", num_people); 
			break;
		case 'A':
			printf("Sort by Age  %i People.\n", num_people); 
			break;
		case 'S':
			printf("Sort by State  %i People.\n", num_people); 
			break;
		case 'Z':
			printf("Sort by Zip  %i People.\n", num_people); 
			break;
		default:
			printf("No Sort selected  %i People.\n", num_people); 
			break;
	}  /* end cases */
	
	if(sort_order != ' ')
		sort_them(people, num_people, sort_order);

 
  						/* Print Report */
  						/* ------------ */

	printf("\n\n                 The People Report\n\n"); /* Title */
	printf ("\n\n%-20s%-20s %-15s %-5s %-6s %-3s %-6s", 
			"Name", "Address","City","State","Zip","Age","Gender"); /* Column Headers */			
	for(i=1; i<=80; i++) printf("%c",196); /* underline the headers */
	
						/* Pointer Version */
						/* Of Print Loop   */
						/* --------------- */
	
	  	for (i = 0; i < num_people; i++)
  	{
			
		strcpy(big_name, people_ptr->name.last);
		strcat(big_name, ", ");
		strcat(big_name, people_ptr->name.first);
				
		printf ("%-20s%-20s %-15s  %-4s%.5d    %-3i  %c\n", 
	    		big_name, people_ptr->address, people_ptr->city, people_ptr->state, 
				people_ptr->zip, people_ptr->age, people_ptr->gender);
				people_ptr++; 		
			            
	} /* end for loop */

	printf("\n\n");

} /* end main */

					/* Function to sort struct */
					/* and return sort to main */
					/* ----------------------- */
					
 void sort_them(struct info them[], int num_people, char sort_by)
{

	struct info *begin_them = them;
	struct info *them; 
	struct info *them2;
	struct info temp;
	struct info *temp_ptr = &temp;
	
	for(them = begin_them; them <
	 begin_them + num_people - 1; ++them)
	
		for(them2 = them + 1; them2 < begin_them + num_people; them2++) 
		{
		 	if( 	(sort_by == 'N' && strcmp(them->name.last, them2->name.last) > 0) 
				|| 	(sort_by == 'A' && them->age > them2->age) 
				|| 	(sort_by == 'S' && strcmp(them->state, them2->state)> 0) 
				|| 	(sort_by == 'Z' && them->zip > them2->zip) )  
		{ 
			*temp_ptr = *them; 
			*them = *them2; 
			*them2 = *temp_ptr;
			}/* end if  */
		 			
	  	} /* end inner for loop  */
};/* end of sort them */
