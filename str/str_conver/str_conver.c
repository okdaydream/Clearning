/*************************************************
*	str convert to number
*	qiuguizhu
*	2017/08/23
*************************************************/
//#include<stdio.h>

int strConvertNum(char * str, int conLen)
{
	int value = 0;
	while(('0' <= *str) && ('9'>= *str) && ( conLen-- > 0))
	{
		value *= 10;
		value += ((*str) - '0');
		++str;
	}

	return value;
}

