#include <stdlib.h>
#include <string.h>
#include "conv.h"

char* decrypt_message(char* msg, char* key)
{
	int c=strlen(key);
	int l=strlen(msg);
	int r=l/c;
	if(l%c) r++;

	int *ike=conv(key,c);
	
	char mat[r][c];
	int i,j,k;
	k=0;
	for(i=0;i<c;i++)
	{
		int col=0;
		for(j=0;j<c;j++)
		{
			if(ike[j]==i)
				col=j;
		}
		for(j=0;j<r;j++)
		{
			mat[j][col]=msg[k];
			k++;
		}
	}
	char *dec=(char*)malloc(l*sizeof(char));
	k=0;int stp=0;
	for(i=0;i<r;i++)
	{
		if(stp)break;
		for(j=0;j<c;j++)
		{
			if(mat[i][j]=='_')
			{
				stp=1;
				break;
			}
			dec[k++]=mat[i][j];
		}
	}
	dec[k]='\0';
	return dec;
}	
