#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"define.h"

DEBUG_FUN_DEFINE(LowLevelDebugTest)
{
	int i;
	int char_cnt, char_total;

	char_total = sprintf(vty_str,"argc is %d\n\r", argc);
	for(i = 0; i < argc; i++)
	{
		char_cnt = sprintf(vty_str+char_total,"argv[%d]is %s\n\r",i, argv[i]?argv[i]:"empty":"null");
		char_total += char_cnt;
	}
	return 0;
}
