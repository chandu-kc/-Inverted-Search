/*
Name:Chandan K C
Date:
Description:
sample input:
sample output:
 */
#include "stuct.h"
#include<ctype.h>
int creat_database(slist **head,word_node *word[])
{
    if(*head==NULL)
    {
	return FAILURE; 
    }
    slist *temp=*head;
    char word1[10];
    int index, flag, f_flag;
    while(temp!=NULL)
    {
	FILE *fp=fopen(temp->filename,"r");
//	printf("Filename %s\n", temp -> filename);
	if(fp==0)
	{
	    printf("error in opening file");
	    return FAILURE;
	}
	while(fscanf(fp,"%s",word1)!=EOF)
	{
	  //  printf("Word %s\n", word1);
	    index=tolower(word1[0])-'a'; 
	    if(index>25 || index < 0)
	    {
		index=26;
	    }
	  //  printf("index %d\n", index);

	    word_node *new=malloc(sizeof(word_node));
	    if(new==NULL)
	    {
		return FAILURE;
	    }



	    filenode *new1=malloc(sizeof(filenode));
	    if(new1==NULL)
	    {
		return FAILURE;
	    }


	    if(word[index]==NULL)
	    {
		new->fc=1;
		strcpy(new->wname,word1);
		new->wlink=NULL;
		new->flink=new1;

		new1->wc=1;
		strcpy(new1->fname,temp->filename);
		new1->flink=NULL;
		word[index]=new;

	    }
	    else
	    {
		word_node *wp=word[index];
		filenode *fp=word[index]->flink;
		filenode *back;
		word_node *backup;
		flag = 0;
		while(wp)
		{
		    backup=wp;
		    if(strcmp(word1,wp->wname)==0)

		    {
			fp=wp->flink;
		//	printf("WORD SAME           ");
			f_flag = 0;
			while(fp)
			{
			    back=fp;
			    if(strcmp(fp->fname,temp->filename)==0)

			    {
			//	printf("FILE SAME\n");
				(fp->wc)++;
				f_flag = 1;
				flag = 1;
				break;	

			    }

			    fp=fp->flink;
			}

			if( f_flag == 0 && fp==NULL)
			{
			 //   printf("FILE DIFF\n");
			    new1->wc=1;
			    strcpy(new1->fname,temp->filename);
			    new1->flink=NULL;
			    back->flink=new1;

			    (wp->fc)++;
			    flag = 1;
			    break;

			}


		    }


		    wp=wp->wlink;

		}
		if(flag == 0 && wp==NULL)
		{ 
		 //   printf("WORD DIFF\n");
		    new->fc=1;
		    strcpy(new->wname,word1);
		    new->wlink=NULL;
		    new->flink=new1;

		    new1->wc=1;
		    strcpy(new1->fname,temp->filename);
		    new1->flink=NULL;
		    backup->wlink=new;


		}

	    }


	}
	temp=temp->link;
    }


}
