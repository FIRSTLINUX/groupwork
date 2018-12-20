#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>


int copy_main(char *,char *);

void copy_file(char *,char *);

void copy_folder(char *,char *);

int isdir(char*);

int endwith(char*,char);

char* str_contact(char *,char *);
