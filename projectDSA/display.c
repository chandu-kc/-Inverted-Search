/*
Name:Chandan K C
Date:
Description:
sample input:
sample output:
 */
#include "stuct.h"
int display(word_node *word[])
{
    int i,j;
    for(i=0;i<27;i++)
    {
	word_node *w=word[i];
	while(w)
	{   printf("%d\t",i);
	    printf("%s\t",w->wname);
	    printf("%d\t",w->fc);
	    filenode *f=w->flink;
	    while(f)
	    {
		printf("%s\t",f->fname);
		printf("%d\t",f->wc);
		f=f->flink;

	    }
	    w=w->wlink;
	    printf("\n");

	}
    }
    return SUCCESS;
}



