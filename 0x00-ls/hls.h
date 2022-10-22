#ifndef _HLS_
#define _HLS_

/********* Libraries *********/
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
/*****************************/
typedef struct option_s
{
	int files_printed;
	int files_nb;
	int dir_nb;
	int vertically;
	int hidden;
	int multi;
} option_t;
#define LAST_REG ""

/******** FUNCTIONS **********/
int _ls(const char *dir, const char *prog_name, option_t *opt, int *called);
int options_builder(char *opts, option_t *opt_struct);
int options_handler(int argc, char **argv, option_t *opt);
int file_handler(int argc, char **argv, option_t opt);
int is_last_reg(int argc, char **argv, struct stat p);
int IS_REG(const char * f, struct stat p);
/*****************************/
#endif
