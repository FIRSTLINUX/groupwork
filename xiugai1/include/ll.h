#include<stdio.h>
#include<time.h>
#include<sys/types.h>
#include<dirent.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include<pwd.h>
#include<grp.h>

void do_ls(char[]);
void dostat(char *);
void show_file_info(char *,struct stat *);
void mode_to_letters(int,char[]);
char * uid_to_name(uid_t);
char * gid_to_name(gid_t);
int ll_main(int ,char *);
