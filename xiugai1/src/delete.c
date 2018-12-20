
/*********************************************
 * 	FileName:delete.c 
 * 	Version:V1.0 
 * 	Author: zhounana
 * 	Date: 17/12/18 14:50
 * 	Description:delete a dir or file  
 *********************************************/

#include "delete.h"

int remove_dir(const char *dir)
{
	struct stat dir_stat;
	//judge the dir is exist or not
	if(access(dir,F_OK)!=0){
		return 0;
	}
	//get the wrong dir element
	if(stat(dir,&dir_stat)){
	 	 perror("cannot get the right stat...");
	  	return -1;
	}
	//delete the reg file
	if(S_ISREG(dir_stat.st_mode)){
	  remove(dir);
	  printf("delete %s success\n",dir);
	}else if(S_ISDIR(dir_stat.st_mode)){
	  rm_dir(dir);
	  printf("delete %s success\n",dir);
	}
	return 0;
}
int rm_dir(const char *dir)
{
	DIR *dirp;
	struct dirent *dp;
	struct stat dir_stat;

	dirp=opendir(dir);
	chdir(dir);
	while((dp=readdir(dirp))!=NULL){
		stat(dp -> d_name,&dir_stat);
		if(S_ISDIR(dir_stat.st_mode))
		{
		  if((strcmp(dp -> d_name,".")==0) || ( strcmp( dp->d_name,"..") == 0))
		  {
		    continue;
		  }
		   rm_dir(dp -> d_name);
		}
		else
		{
		 remove(dp->d_name);
		}
	}
	chdir("..");
	closedir(dirp);
	rmdir(dir);
	return 0;
}


int del_main(char *argc)
{
	remove_dir(argc);	
	return 0;
}

