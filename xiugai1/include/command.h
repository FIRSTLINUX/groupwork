#include "cp.h"
#include "help.h"
#include "list.h"
#include "mkdir.h"
#include "content.h"
#include "delete.h"
#include "link.h"
#include "ll.h"
#include "mkfile.h"

#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

#define EXIT_SUCESS             0           
#define EXIT_FAILURE            1           
#define MAX_LINE_BUF_SIZE       1024       

static char    *program_name = NULL;
static int     exit_status = EXIT_FAILURE;


