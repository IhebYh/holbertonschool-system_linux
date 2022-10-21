#ifndef _HLS_
#define _HLS_

/********* Libraries *********/
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
/*****************************/

/******** FUNCTIONS **********/
int _ls(const char *dir, const char *prog_name, int multi);
/*****************************/
#endif
