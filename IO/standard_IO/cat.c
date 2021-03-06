/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：cat.c
*   创 建 者：liujing
*   创建日期：2020年06月08日
*   描    述：
*	fputc,fgetc 完成cat指令
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	FILE *src_fp;
	int rd_ret = 0;
	//判断参数
	if(argc < 2)
	{
		printf("please input src file!");
		return -1;
	}
	//打开源文件
	src_fp = fopen(argv[1], "r");
	if(src_fp == NULL)
	{
		printf("open src file %s failure!\n", argv[1]);
		return -2;
	}
	//循环读写
	while(1)
	{
		//读取源文件
		rd_ret = fgetc(src_fp);//fgetc返回-1，表示出错或者读到文件结算
		if(feof(src_fp) != 0)//feof返回值非0，即是读到文件结束
		{
			break;
		}
		//写到标准输出，屏幕上
		fputc(rd_ret,stdout);
	}

	fclose(src_fp);
	return 0;
}
