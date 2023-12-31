/*
Name:Chandan K C
Date:
Description:
sample input:
sample output:
*/
#include "stuct.h"
#include<string.h>
int save_db(word_node *word[])
{
    printf("Enter the file name to save the data (name.txt) : ");
    char filename[20];
    char now[]=".txt";
    scanf("%s",filename);
    char *flag=strstr(filename,now);
    
    if(flag==NULL)
    {
	printf("Enter validable file\n");
	return FAILURE;
    }
    else
    
    {
    FILE *fp=fopen(filename,"a");
    if(fp==NULL)
    {
	printf("error in opening file\n");
	return FAILURE;
    }
    for(int i=0;i<27;i++)
    {
	word_node *temp=word[i];
	while(temp)
	{
	    fprintf(fp,"#%d;%s;%d;",i,temp->wname,temp->fc);
	    filenode *temp1=temp->flink;
	    while(temp1)
	    {
		fprintf(fp,"%s;%d;",temp1->fname,temp1->wc);
		temp1=temp1->flink;
	    }
	    fprintf(fp,"#\n");
	    temp=temp->wlink;
	}
    }
    fclose(fp);
    return SUCCESS;
    }

}
