/*************************************************************
 *  FileName:content.c 
 *  Version:V1.0 
 *  Author: zhounana
 *  Date: 13/12/10 14:50
 *  Description:show the content/infomation of a dir or file  
*************************************************************/

#include "content.h"

off_t lseek(int fd,off_t offset,int whence);//set position function

int content_main(int argc,char *o,char *l, char *name)
{
	int offset=0,size=0;//define the length and the offset size;
	struct stat st;
	int fd =0;//the description of the file
	char buf[4096] = {0} ;
	stat (name,&st);
	if(access(name,F_OK)!=0)
	{
		printf("Can't found the file! \n");
		return 0 ;
	}
	if(S_ISDIR(st.st_mode))
	{
		printf("This is a dir!Can not support the paramter! \n");
	}
	if(S_ISREG(st.st_mode))
	{
		printf("this file is ok! \n");
		if(fd==-1){
		  return -1; 
		}else{
		  printf("the contents are as follow:\n");
		  fd = open(name,O_RDWR);
		  if(argc>0 && argc<3)
		  {
		   lseek(fd,offset,SEEK_SET);
		   read(fd,buf,sizeof(buf));
		   printf("%s \n",buf);
		  }else{
		    offset = atoi(o);//get the paratmer dynamically
		    size = atoi(l);
		    lseek(fd,offset,SEEK_SET);//set the offset and length
		    read(fd,buf,size); //read the content by setting
                    printf("%s \n",buf);
		 }
		}
		return 0 ;
	}
	return 0 ;
}
