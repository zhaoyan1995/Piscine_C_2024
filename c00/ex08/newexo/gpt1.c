#include<unistd.h>
#include<string.h>
#include<stdio.h>

int	absolute(int nb)
{
	if(nb < 0)
		nb = -nb;
	return (nb);
}

//与gpt.c几乎一致 唯一区别在于不可以出现 aba acc cbb类似的字符 array里面的元素必须是不一样的
void generate_combination(char array[],int index, int size_of_array,char word[], int size_of_word)
{
	if(index==size_of_array)
	{
		//int counter=0;	
		int x=0;
		int y=0;
		while(x<size_of_array-1) //仅仅加了一个暴力枚举法来过滤掉重复字符，arr0 和arr1 2 3 4 5 ......里的所有元素比较如果有重复的那么counter就+1，然后arr1 在和arr2 3 4 5 ... 比较 一直到倒数第2个和倒数第1个进行比较，while loop完成
		{
			y=x+1;
			while(y<size_of_array)	
			{
				if(array[x]==array[y] || absolute(x - y) == absolute(array[x] - array[y]))
					return;
				y++;
			}
			x++;
		}		
		int i=0;
		while(i<size_of_array)
		{
			char element=array[i];
			write(1,&element,1);
			i++;
		}	
	write(1,"\n",1);
	return;
}
	int INDEX=0;	
	while(INDEX<size_of_word)
	{
		array[index]=word[INDEX];
		generate_combination(array,index+1,size_of_array,word,size_of_word);
		INDEX++;
	}
}


void f(int n, char word[])
{	int size_of_word=strlen(word);	
	char array[n];
	generate_combination(array,0,n,word,size_of_word);	
	printf("\n");
}

int main(void)
{
	char WORD[]="0123456789";
	f(10,WORD);
	//printf("char WORD[]=\"abc\" \n");
	int SIZE=strlen(WORD);
	//printf("SIZE=strlen(WORD)=%d\n",SIZE);
	int Size=sizeof(WORD)/sizeof(WORD[0]);
	//printf("Size=sizeof(WORD)/sizeof(WORD[0])=%d\n",Size);

	return 0;
}
