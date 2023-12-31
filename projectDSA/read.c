/*
Name:Chandan K C
Date:
Description:
sample input:
sample output:
*/
#include "stuct.h"
#include <string.h>
#include <stdlib.h>
int list(slist **head,char *argv);
int print(slist **head);

int read_and_validate(slist **head,char *argv[],int argc)

{
    
   int i=0;
   for(i=1;i<argc;i++)
   {
       char now[]=".txt";
       char *flag=(char *)strstr(argv[i],now);

	   if(flag==0)
	   {
	       printf("This type file not existed\n");
	       

	   }
	   else
	   {
	       FILE *fp;
	       fp=fopen(argv[i],"r");
	       fseek(fp,0,SEEK_END);
	       int size=ftell(fp);
	       if(size==0)
	       {
		   printf("%s this file is empty\n",argv[i]);
		   printf("\n");
	       }
	       else
	       {
		   if(list(head,argv[i])==FAILURE)
		   {
                       continue;
		   }
		   

	       }
               

	   }
   }
	 //  print(head);

   
   return SUCCESS;


}
int list(slist **head,char argv[])
{
    slist *back;
   // printf("%p\n",argv);
    slist *new=malloc(sizeof(slist));
    strcpy(new->filename,argv);
    new->link=NULL;
    int flag=0;
    int flag1=0;

    if(*head==NULL)
    {
	*head=new;
	return SUCCESS;

    }
    
     {
	slist *temp=*head;
	while(temp)
	{  
	    flag1++;

	    back=temp;
	    if(strcmp(temp->filename,argv)==0)
	    {
		printf("%s this file name is reapted\n",argv);
		
	        flag=1;
	        return FAILURE;

	    }
	    
		temp=temp->link;

	    

		    
	}
	back->link=new;
	

    }
  //  printf("\n");
}


int print(slist **head)
{

    slist *q=*head;
    printf("\nlist\n");
    while(q)
    {
	printf("%s->",q->filename);
	q=q->link;
    }
  
	printf("\n");
}

    

      

    




    
