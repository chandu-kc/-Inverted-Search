/*
Name:Chandan K C
Date:8/11/2023
DSA project:Inverted Search.
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "stuct.h"

int main(int argc,char *argv[])
{
    int op;
    slist *head=NULL;
    if(argc==1)
    {
	printf("pass command line argument\n");
    }



    if(read_and_validate(&head,argv,argc)==SUCCESS)
    {
	printf("\n");
	printf("READ AND VALIDATION SUCCESS\n");
	printf("\n");
    }


    word_node *word[27]={NULL};

    do
    {
	printf("\n");
	printf("1.CREAT DATABASE\n2.DISPLAY DATABASE\n3.SEARCH WORD IN DATABASE\n4.SAVE DATABASE\n5.UPDATE DATABASE\n6.EXIT\nEnter your choice:");
	scanf("%d",&op);
	switch(op)
	{
	    case 1:

		if(creat_database(&head,word)==FAILURE)
		{
		    printf("\n");
		    printf("creation of DATABASE is failed\n");
		}
		break;
	    case 2:
		printf("DATABASE CONTAIN \n");
		printf("\n");
		if(display(word)==FAILURE)
		{
		    printf("display is failed\n");
		}
		break;
		
	    case 3:
	        if(search(word)==FAILURE)
		{
		    printf("YOU ENTERED ELEMENT IS NOT IN DATABASE\n ");
		    printf("\n");
		}
		else
		{
		    printf("\n");
		    printf("Search is Success\n");
		}
               break;
	    case 4:
	       if(save_db(word)==FAILURE)
	       {
		   printf("\n");
		   printf("DATABASE saving is failed\n");
	       }
	       else
	       {
		   printf("\n");
		   printf("DATABASE saved succesfully\n");
	       }
	       break;
	    case 5:
		   printf("\n");
	       
	       printf("ENTER the backup file name of database in (.txt)\n");
                if(update_database(word)==FAILURE)
		{
		   printf("\n");
		    printf("DATABASE update failed\n");
		}
		else
		{
		   printf("\n");
		    printf("DATABASE update success\n");
		}
		break;
	    case 6:
		exit(0);
		break;
	       
                   	     

	    default:
		printf("Enter the correct choice");    
	}

    }while(1);


    return 0;
}
