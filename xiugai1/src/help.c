/********************************************
 * Name: help.c
 * Version: v1.1 
 * Author: zhufeiyu
 * Date: 2018-12-** 
 * Description: Display Help Documents 
 *******************************************/

#include "help.h"

int help_main()
{
	int fd ;
	char buf[2048] = {0};
	fd =open ("help.txt",O_RDWR);
	read(fd,buf,sizeof(buf));
	printf("%s \n",buf);
	return 0;
}
