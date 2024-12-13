#include<unistd.h>
#include<string.h>
//array[]用来存储一个n位数的数组
//index用来控制要改变数组的第几个元素，index在0到n-1之间
//size of array就是n，array是几位数数组 size of array就是多少
//start digit 是起始数字

void generate_digit(int array[],int index, int size_of_array, int digit)
{
	if(index==size_of_array) 			//终止递归条件，当array生成n位数数组后，马上打印出来
	{
		int i=0;
		while(i<size_of_array)              //从第一个数组打印一直打印到size of array-1那一位，将int转换为char
		{
			char number=array[i]+'0';     
			write(1,&number,1);
			i++; //否则如果是最后一组数组的话 那就什么也不用打印
		}
		if(array[0]!=(10-size_of_array))    //如果没有打印到最后一个数组的时候，后面打印", " 否则如果是最后一组数组的话 那就什么也不用打印
		{	
			write(1,", ",2);
		}
		return;
	}
//int next_digit=start_digit;
	while(digit<=9)
	{
		array[index]=digit;  //将数组的当前元素赋值 如果是第一次进入递归 那么就是 array 0 = 0
		generate_digit(array,index+1,size_of_array,digit+1); //调用函数本身，开始递归，从第0位递归到第1位，第一位的数字比第0位大1 
		digit++; //当终止递归条件达到后 上一个数组被全部打印出来后 返回到这一层 digit=digit+1 然后再进入下一轮循环 
	}
}

void ft_print_combn(int n)  //n表示是一个n位数的数组
{
	
	if( n>0 && n<10)  //这个数字n必须大于0小于10才可以	
	{
		int arr[n]; //创造一个可以存储n个元素的数组
		generate_digit(arr,0,n,0);  //将这个arr数组带入到generate digit函数中 从第0位(index)元素开始 该数组的大小是n，从数字0(digit)开始填充数组元素
	}
	else   //否则就打印出错误信息
	{
		char str[]="Error, you need to print a number between 1 and 9."; //错误信息内容 str是一个字符串性质的数组
		int length=strlen(str); //通过strlen计算这个str数组的字符串长度
		write(1,&str,length); //代入str字符串数组和其长度的变量到write函数中
	}
}
	
int main(void)
{
	ft_print_combn(4);
	return 0;
}
