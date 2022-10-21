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
typedef struct option_s 
{
    int pos;
    int vertically;
    int multi;
} option_t;
/******** FUNCTIONS **********/
int _ls(const char *dir, const char *prog_name, option_t opt);
int options_builder(char *opts, option_t *opt_struct);
int options_handler(int argc, char **argv, option_t *opt);
/*****************************/
#endif
