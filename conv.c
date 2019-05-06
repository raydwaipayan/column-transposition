#include <stdlib.h>

void toupr(char *key, int len)
{
	for(int i=0;i<len;i++)
	{
		if(key[i]<='z' && key[i]>='a')
			key[i]+=32;
	}
}
int* conv(char* key, int len)
{		
	toupr(key,len);

	int* ike=(int*)malloc(len*sizeof(int));

	int k=0;
	for(char ch='A';ch<='Z';ch++)
	{
		for(int i=0;i<len;i++)
		{
			if(key[i]==ch)
			{
				ike[i]=k;
				k++;
			}
		}
	}
	return ike;
}

