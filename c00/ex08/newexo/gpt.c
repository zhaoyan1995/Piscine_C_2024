#include<unistd.h>
#include<string.h>
#include<stdio.h> 
// array数组是要生成的组合，index管理数组的第几个元素，size of array是array数组的大小，word数组是已知的字符数组，size of word是word数组大小
void generate_combination(char array[],int index, int size_of_array,char word[], int size_of_word)
{
//     array字符数组生成到size of array的大小，递归停止，开始打印array当中的每一个元素	
	if(index==size_of_array)
	{
		int i=0;
		while(i<size_of_array) //遍历array数组，让array的每一个元素都变成字符类型 方便后续使用write函数
		{
			char element=array[i];
			write(1,&element,1);
			i++;
		}
		int flag=0;	
		int I=0;
		while(I<size_of_array)
		{	
			if(array[I]==word[size_of_word-1]) //如果每一个数组都等于word当中的最后一个元素的话那么flag就需要加1
			{
				flag++;	
			}
			I++;
		}
	//	printf("flag =%d\n",flag);
		if(flag!=size_of_array) //如果flag不等于size of array的话,那么就在每一个array数组后面打印" ，"在否则不打印任何东西出来
		{		
			write(1,", ",2);
		}
		return;
	}
	int INDEX=0; //INDEX指word里面的第几个元素,从word数组里面的第0个元素开始填充array里面的第0个位置	
	while(INDEX<size_of_word)
	{
		array[index]=word[INDEX]; //将array里面第0位填充填上word里面的第0个数组
		generate_combination(array,index+1,size_of_array,word,size_of_word); //开始递归，推进到array的下一位
		INDEX++; //当递归停止 然后开始执行返回层时 INDEX加1，进入下一个循环
	}
}


void f(int n, char word[])
{	
	int size_of_word=strlen(word); //计算word的字符个数	
	char array[n]; //制造一个大小位n的array 数组字符
	generate_combination(array,0,n,word,size_of_word);// 开始调用generate combination函数 带入array数组 从array数组的第0位开始填充，word作为已知数组来填充每一个array数组，size of word 是word数组的大小
	printf("\n");
}

int main(void)
{
	char WORD[]="abc"; //制造一直数组word 里面的元素分别是a，b，c
	f(3,WORD); //调用f(int n, char word)函数，是的array数组每一次都有3个元素在里面
	printf("char WORD[]=\"abc\" \n");
	int SIZE=strlen(WORD);
	printf("SIZE=strlen(WORD)=%d\n",SIZE);
	int Size=sizeof(WORD)/sizeof(WORD[0]);
	printf("Size=sizeof(WORD)/sizeof(WORD[0])=%d\n",Size);

	return 0;
} //遍历array数组，让array的每一个元素都变成字符类型 方便后续使用write函数
