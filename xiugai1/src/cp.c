/**************************************************
 * Name:cp.c 
 * Version: V1.2
 * Author:zhufeiyu
 * Date: 2018-12-12 v1
 * Description:Copy files or directories 
 * ************************************************/

#include "cp.h"

int is_dir(char* path)
{
	struct stat st;
	stat(path,&st);
	if(S_ISDIR(st.st_mode)){
		return 1;
	}
	else{
		return 0;
	}
}
int endwith(char* s,char c){
	if(s[strlen(s)-1]==c){
		return 1;
	}
	else{
		return 0;
	}
}

char* str_contact(char* str1,char* str2){
	char* result;
	result=(char*)malloc(strlen(str1)+strlen(str2)+1);
	if(!result){
		printf("str_contact fail!!!\n");
		exit(1);
	}
	strcat(result,str1);
	strcat(result,str2);
	return result;
}
void copy_file(char* source_path,char *destination_path){
        char buffer[1024];
        FILE *in,*out;
        if((in=fopen(source_path,"r"))==NULL){
                printf("can't open source file!\n");
                exit(1);
        }
        if((out=fopen(destination_path,"w"))==NULL){
                printf("can't create dest file!\n");
                exit(1);
        }
        int len;
        while((len=fread(buffer,sizeof(char),1024,in))>0){
                fwrite(buffer,sizeof(char),len,out);
                printf("source->dest copy finish\n");
        }

        fclose(out);
	fclose(in);
}


void copy_folder(char* source_path,char *destination_path){
        if(!opendir(destination_path))
        {
                mkdir(destination_path,0777);
        }
        char *path;
        path=(char*)malloc(512);
        path=str_contact(path,source_path);
        struct dirent* filename;
        DIR* dp=opendir(path);
        while( ( filename=readdir(dp) ) ){
		//printf("this size is :%ld",sizeof(path));
                memset(path,0,8);
                path=str_contact(path,source_path);
                char *file_source_path;
                file_source_path=(char*)malloc(512);
                if(!endwith(source_path,'/')){
                        file_source_path=str_contact(file_source_path,source_path);
                        file_source_path=str_contact(source_path,"/");
                }
                else{
                        file_source_path=str_contact(file_source_path,source_path);
                }
		char *file_destination_path;
                file_destination_path=(char*)malloc(512);
                if(!endwith(destination_path,'/')){
                        file_destination_path=str_contact(file_destination_path,destination_path);
                        file_destination_path=str_contact(destination_path,"/");
                }
                else{
                        file_destination_path=str_contact(file_destination_path,destination_path);
                }
                file_source_path=str_contact(file_source_path,filename->d_name);
                file_destination_path=str_contact(file_destination_path,filename->d_name);
                if(is_dir(file_source_path)){
                        if(!endwith(file_source_path,'.')){
                                copy_folder(file_source_path,file_destination_path);
                        }
                }
                else{
                        copy_file(file_source_path,file_destination_path);
                        printf("%s->%s copy success!\n",file_source_path,file_destination_path);
                }
        }
}

int copy_main(char *source_path,char *destination_path)
{
//        char* source_path=argv[1];
//        char* destination_path=argv[2];
        DIR* source=opendir(source_path);
//        DIR* destination=opendir(destination_path);
	//if source is file
	if(!source)
	{
		printf("source is file!\n");
        	copy_file(source_path,destination_path);
    	}
	//if source is dir
	if( is_dir(source_path) == 1 )
	{
		printf("source is dir!%s\n",destination_path);
		
                	mkdir(destination_path,0777);
		copy_folder(source_path,destination_path);
	}
	//if source is NULL
	//if destination is NULL

        return 0;
}
