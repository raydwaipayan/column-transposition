#include <string.h>
#include <stdlib.h>
#include "conv.h"

char* encrypt_message(char* msg, char* key)
{
	int r,c,i,j,l;
	l=strlen(msg);
	c=strlen(key);
	r=l/c;
	if(l%c)
		r++;
	char mat[r][c];
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(*msg=='\0')
			{
				mat[i][j]='_';//padding character
			}
			else
			{
				mat[i][j]=*msg;
				msg++;
			}
		}
	}
	int *ike=conv(key,c);
	int k=0;
	char* enc=(char*)malloc(r*c*sizeof(char));
	for(i=0;i<c;i++)
	{
		int col=0;
		for(j=0;j<c;j++)
		{
			if(ike[j]==i)
			{
				col=j;
				break;
			}
		}
		for(j=0;j<r;j++)
		{
			enc[k++]=mat[j][col];
		}
	}
	free(ike);
	return enc;
}
