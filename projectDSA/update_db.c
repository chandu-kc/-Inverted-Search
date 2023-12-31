/*
Name:Chandan K C
Date:
Description:
sample input:
sample output:
*/
#include "stuct.h"
#include "ctype.h"
#include <string.h>

int update_database(word_node *word[])
{
    char filename[20];
    scanf("%s",filename);
    char str[100];
    char word1[10];
    char *arr;
    char *tok;
    char *fname;
    int index;
    int fc,fwc;

    FILE *fp=fopen(filename,"r");
    if(fp==0)
    {
	printf("error opening file for saving database\n");
	return FAILURE;
    }
    fseek(fp,0,SEEK_END);
    int filesize=ftell(fp);
    fseek(fp,0,SEEK_SET);

    if(filesize>0)
    {
	while(fscanf(fp,"%s",str)!=EOF)
	{
	    if(str[0]=='#')
	    {
		index=atoi(strtok(&str[1],";"));
	    }
	    arr=strtok(NULL,";");
	    fc=atoi(strtok(NULL,";"));
	    for(int i=0;i<fc;i++)
	    {
		fname=strtok(NULL,";");
		fwc=atoi(strtok(NULL,";"));

		if(word[index]==NULL)
		{
		    word_node *mainnew=malloc(sizeof(word_node));
		    if(mainnew==NULL)
		    {
			return FAILURE;
		    }
		    filenode *subnew=malloc(sizeof(filenode));
		    if(subnew==NULL)
		    {
			return FAILURE;

		    }
		    word[index]=mainnew;
		    mainnew->fc=fc;
		    strcpy(mainnew->wname,arr);
		    mainnew->wlink=NULL;
		    mainnew->flink=subnew;

		    subnew->wc=fwc;
		    strcpy(subnew->fname,fname);
		    subnew->flink=NULL;
		}
		else
		{
		    word_node *temp1=word[index];
		    while(temp1!=NULL)
		    {
			if(!strcmp(arr,temp1->wname))
			{
			    filenode *temp2=temp1->flink;
			    filenode *prevsubnode=NULL;

			    while(temp2!=NULL)
			    {
				if(!strcmp(temp2->fname,fname))
				{
				    temp2->wc=fc; //increment;
				    break;

				}
				prevsubnode=temp2;
				temp2=temp2->flink;


			    }
			    if(temp2==NULL)
			    {
				filenode *subnew=malloc(sizeof(filenode));
				if(subnew==NULL)
				{
				    return FAILURE;
				}
				subnew->wc=fwc;
				strcpy(subnew->fname,fname);
				subnew->flink=NULL;
				//(temp1->fc)++;

				if(prevsubnode != NULL)
				{
				    prevsubnode->flink=subnew;
				}
				else
				{
				    temp1->flink=subnew;
				}
			    }
			    break;
			}
			if(temp1->wlink==NULL)
			{
			    word_node *mainnew=malloc(sizeof(word_node));
			    filenode *subnew=malloc(sizeof(filenode));

			
			if(mainnew==NULL ||subnew==NULL )
			{
			    free(mainnew);
			    free(subnew);
			    return FAILURE;
			}
			mainnew->fc=fc;
			strcpy(mainnew->wname,arr);
			//
			mainnew->flink=subnew;
			mainnew->wlink=NULL;

			subnew->wc=fwc;
			strcpy(subnew->fname,fname);
			subnew->flink=NULL;

			temp1->wlink=mainnew;
			break;

		    }
		    temp1=temp1->wlink;

		}
	    }
	}
    }
}
else
{
    printf("error no contents in file\n");
    fclose(fp);
    return FAILURE;

}


return SUCCESS;
}
