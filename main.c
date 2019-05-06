#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypt.h"

#define MAX 100

int main()
{
	printf("\t\tColumn Transposition cipher\n");
	printf("\tAuthor: Dwaipayan Ray  Dated:7/5/2019 01:20:00\n");
	printf("-------------------------------------------------------------\n\n");
	printf("1. Decrypt\n");
	printf("2. Encrypt\n");
	printf("3. Exit\n\n");
	printf("> ");
	int c;
	char msg[MAX], key[MAX];
	char *res;
	scanf("%d",&c);
	getchar();
	switch(c)
	{
		case 1:
			printf("Enter the message to decrypt: ");
			fgets(msg,MAX,stdin);
			msg[strlen(msg)-1]='\0';
			printf("Enter the key: ");
			fgets(key,MAX,stdin);
			key[strlen(key)-1]='\0';
			res=decrypt_message(msg,key);
			printf("Decrypted Message: %s\n",res);
			break;
		case 2:
			printf("Enter the message to encrypt: ");
			fgets(msg,MAX,stdin);
			msg[strlen(msg)-1]='\0';
			printf("Enter the key: ");
			fgets(key,MAX,stdin);
			key[strlen(key)-1]='\0';
			res=encrypt_message(msg,key);
			printf("Encrypted Message: %s\n",res);
			break;
		default:	
			exit(0);
	}	
	free(res);								
	return 0;
}
