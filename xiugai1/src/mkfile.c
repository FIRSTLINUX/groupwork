/***************************************************
 * Name: 创建文件 
 * Copyright: 富士通 
 * Author: 徐畅 
 * Date: 12/12/18 16:27
 * Description:demo   -q  file/directory
 **************************************************/

#include "mkfile.h"

int mkfile_main(char *argv,int argc)
{

        char ch;
        if(argc == 2)
        {
        	printf("文件重复是否新建? \ny/n");
        	if( ( ch=getchar() )=='y') 
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

        if( (creat(argv,O_CREAT|0755))  == -1)
        	{
                perror("mkdir error");
        	}
        else
            printf("新建文件\n");
        return 0;
}

