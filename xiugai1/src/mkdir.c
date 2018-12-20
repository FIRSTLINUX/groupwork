/*****************************************************
 * Name: 创建目录 
 * Copyright: 富士通 
 * Author: 徐畅 
 * Date: 12/12/18 16:27
 * Description:custom_demo   -c  directory  mode	
 *
 * ***************************************************/

#include "mkdir.h"

int mkdir_main(char *argv,int argc)
{

  	char ch;
        if(argc == 2)
        {
    		printf("目录重复是否新建? y/n\n");
		if( ( ch=getchar() ) =='y') 
      		{	
          		if(  access(argv,F_OK) == 0  )
            		{
                 		if(remove(argv)==0)
                		  printf("覆盖成功\n");
            			else
                		  perror("remove");
			}
       
		}
 	}

        if( ( mkdir(argv,O_CREAT|0755) ) == -1)
        {
        	perror("mkdir error");
        }
        else
	{
		printf("新建一个%s目录\n",argv);
	}

        return 0;
}

