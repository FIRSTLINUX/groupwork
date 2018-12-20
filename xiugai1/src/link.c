/**********************************************
 * Name:link.c 
 * Version: V1.0 
 * Author: zhufeiyu
 * Date: 2018-12-**  
 * Description: Generating Soft Links
 * ********************************************/

#include "link.h"

int create_softlink(const char *existingpath, const char *newpath)
{
    if(symlink(existingpath, newpath) != 0)
    {
        fprintf(stderr,
                "create soft link [%s]-> [%s] error[%s]\n",
                existingpath, newpath, strerror(errno));
        return errno;
    }

    return 0;
}

