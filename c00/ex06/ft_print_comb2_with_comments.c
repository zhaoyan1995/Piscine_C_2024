#include<unistd.h>
#include<stdio.h>
void ft_print_comb(void)
{
	//Create the buffer1 to stock n1, create the buffer2 to stock n2, the size of buffer1 and buffer2 are 2	
	char buffer1[2]; 
	char buffer2[2];
	int n1=0;
	while(n1<=99)
	{
		 int n2=n1+1; // n2 is always bigger than n1, the smallest n2 =n1+1, IMPORTANT to reset variable n2 to restart inner while loop again when n1++;	
		while(n2<=99)
		{		
			//You muste affect the variable buffer1[0] buffer1[1] buffer2[0] buffer2[1] inside the loop to update the variable frequently!	
			buffer1[0]=n1/10+'0'; //fill in the buffer1[0] by using n1, n1/10 is the 1st digit of n1, dont forget to add '0' to convert it to char if not you can not use the write function properly! if n1=3, n1/10=0, then buffer1[0]=0 
			buffer1[1]=n1%10+'0'; //same thing for buffer1[1] but buffer[1]=n%10, we catch the 2nd digit of n1, ex n1=34, 34%10=4
			buffer2[0]=n2/10+'0';
			buffer2[1]=n2%10+'0';		
			write(1,&buffer1[0],1);
			write(1,&buffer1[1],1);
			write(1," ",1);
			write(1,&buffer2[0],1);
			write(1,&buffer2[1],1);
			if(n1!=98 ||  n2!=99) //if n1 !=98 or n2 !=99 then we can print ", ".
			{	
				write(1,", ",2);	
			}
			n2++;
		}
		n1++;
	}	
}


int main(void) { ft_print_comb();
	return 0;
}
















