/***********************************************
 * * Name: custom_demo  -q  file/directory
 * * Copyright: 富士通
 * * Author: 徐畅 
 * * Date: 13/10/18 15:37
 * * Description: 列出对象的属性                              ************************************************/
#include "ll.h"

int ll_main(int argc,char * name){
	if(argc==2)
        	do_ls(".");
    	else
        	printf("输入命令,不要带任何参数。\n");
	
	return 0;
}

void do_ls(char dirname[]){
    DIR *dir_ptr;   //路径变量
    struct dirent *direntp;     //存储路径下一个子项信息的结构体
    if((dir_ptr=opendir(dirname))==0)
        fprintf(stderr,"ls:cannot open %s\n",dirname);
    else{
        while((direntp=readdir(dir_ptr))!=0)
            dostat(direntp->d_name);
        closedir(dir_ptr);
    }
}

void dostat(char *filename){
    struct stat info;
    if(lstat(filename,&info)==-1)
        perror("lstat");
    else
        show_file_info(filename,&info);
}

void show_file_info(char *filename,struct stat *info_p){
    char modestr[11];
    mode_to_letters(info_p->st_mode,modestr);
    printf("%-12s",modestr);
    printf("%-4d",(int)info_p->st_nlink);
    printf("%-8s",uid_to_name(info_p->st_uid));
    printf("%-8s",gid_to_name(info_p->st_gid));
    printf("%-8ld",(long)info_p->st_size);
    time_t timelong=info_p->st_mtime;
    struct tm *htime=localtime(&timelong);
    printf("%-4d-%02d-%02d %02d:%02d",htime->tm_year+1990,htime->tm_mon+1,htime->tm_mday,htime->tm_hour,htime->tm_min);
    printf(" %s\n",filename);
}

/*这个函数写得不够全面，首先文件类型不全，其次没有考虑suid,sgid,sticky*/
void mode_to_letters(int mode,char str[]){
    strcpy(str,"----------");
    if(S_ISDIR(mode))   str[0]='d';
    if(S_ISCHR(mode))   str[0]='c';
    if(S_ISBLK(mode))   str[0]='b';

    if(mode & S_IRUSR)  str[1]='r';
    if(mode & S_IWUSR)  str[2]='w';
    if(mode & S_IXUSR)  str[3]='x';

    if(mode & S_IRGRP)  str[4]='r';
    if(mode & S_IWGRP)  str[5]='w';
    if(mode & S_IXGRP)  str[6]='x';

    if(mode & S_IROTH)  str[7]='r';
    if(mode & S_IWOTH)  str[8]='w';
    if(mode & S_IXOTH)  str[9]='x';
}


char * uid_to_name(uid_t uid){
    struct passwd *pw_str;
    static char numstr[10];
    if((pw_str=getpwuid(uid))==NULL){
        sprintf(numstr,"%d",uid);       //如果没有获得用户名，则直接把uid当作用户名
        return numstr;
    }
    else
        return pw_str->pw_name;
}


char * gid_to_name(gid_t gid){
    struct group *grp_ptr;
    static char numstr[10];
    if((grp_ptr=getgrgid(gid))==NULL){
        sprintf(numstr,"%d",gid);
        return numstr;
    }
    else
        return grp_ptr->gr_name;
}
