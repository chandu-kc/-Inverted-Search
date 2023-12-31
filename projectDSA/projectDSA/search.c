/*
Name:Chandan K C
Date:
Description:
sample input:
sample output:
*/
#include "stuct.h"
#include<ctype.h>
int search(word_node *word[])
{
  char word1[10];
 printf("enter searchable word:\n");
  scanf("%s",word1); 
 int index=tolower(word1[0])-'a';
 if(index>25 || index <0)
 {
     index=26;
 }
 word_node *temp=word[index];
 while(temp)
 {
     if(strcmp(temp->wname,word1)==0)
     {
	 printf("%d\t",index);
	 
	 printf("%s\t",temp->wname);
	 printf("%d\t",temp->fc);
	 
	 filenode *temp1=temp->flink;
	 while(temp1)
	 {
	     printf("%s\t",temp1->fname);
	     printf("%d\t",temp1->wc);
	     temp1=temp1->flink;

	 }
	 printf("\n");
	 return SUCCESS;
     }
     temp=temp->wlink;
 }
 return FAILURE;

}
