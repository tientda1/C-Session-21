#include<stdio.h>
int main(){
	FILE *fptr;
	fptr = fopen("bt01.txt","w");
	char myString[100];
	fgets(myString,100,fptr);
	fprintf(fptr,"agwagawg");
	fclose(fptr);
	return 0;
}

