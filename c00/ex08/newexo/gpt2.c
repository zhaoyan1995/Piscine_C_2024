#include<unistd.h>
#include<string.h>
#include<stdio.h>
void generate_combination(char array[],int index, int size_of_array,char word[], int INDEX,int size_of_word)
{
	if(index==size_of_array)
	{
		int i=0;
		while(i<size_of_array)
		{
			char element=array[i];
			write(1,&element,1);
			i++;
		}
		int flag=0;	
		int I=0;
		while(I<size_of_array-1)
		{	
			if(array[0]==word[size_of_word-size_of_array] && array[I]==array[I+1]-1)
			{
				flag++;	
			}
			I++;
		}
	//	printf("flag =%d\n",flag);
		if(flag!=size_of_array-1)
		{		
			write(1,", ",2);
		}
		return;
	}	
	while(INDEX<size_of_word)
	{
		array[index]=word[INDEX];
		generate_combination(array,index+1,size_of_array,word,INDEX+1,size_of_word);
		INDEX++;
	}
}


void f(int n, char word[])
{	
	int size_of_word=strlen(word);	
	char array[n];
	generate_combination(array,0,n,word,0,size_of_word);	
	printf("\n");
}

int main(void)
{
	char WORD[]="abcd";
	f(3,WORD);
	printf("char WORD[]=\"abc\" \n");
	int SIZE=strlen(WORD);
	printf("SIZE=strlen(WORD)=%d\n",SIZE);
	int Size=sizeof(WORD)/sizeof(WORD[0]);
	printf("Size=sizeof(WORD)/sizeof(WORD[0])=%d\n",Size);

	return 0;
}
