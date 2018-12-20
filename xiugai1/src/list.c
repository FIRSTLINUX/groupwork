/***********************************************
 * Name: custom_demo  -q  file/directory
 * Copyright: 富士通
 * Author: 徐畅 
 * Date: 13/10/18 15:37
 * Description: 列出对象的属性
 * 				
 ***********************************************/
#include "list.h"

int list_main(char *argv)
{
        
  	 time_t a;
        time(&a);
        struct stat st;
        stat(argv,&st);
        if(access(argv,F_OK) != 0)
        {
                printf("this filename is not found\n");
                return 0;
        }
        if(S_ISDIR(st.st_mode))
        {
                printf("%s 为目录\n",argv);
        }
        if(S_ISREG(st.st_mode))
        {
                printf("%s为文件\n",argv);
        }
        
        printf("文件类型：%o\n",st.st_mode&07777);
        printf("文件操作属性：%d\n",st.st_uid);
        printf("文件大小： %ld\n",st.st_size);
        
	printf("当前访问时间：%s",ctime(&a));
        printf("上次访问时间: %s", ctime(&st.st_atime));
   	printf("文件创建时间: %s", ctime(&st.st_ctime)); 
        printf("\n");

        return 0 ;
}
