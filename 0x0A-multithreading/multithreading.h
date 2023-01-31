#ifndef _MULTITHREADING_H_
#define _MULTITHREADING_H_

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include "pool_thread.h"
#include "list.h"
#include <sys/sysinfo.h>

/**
 * struct pixel_s - RGB pixel
 *
 * @r: Red component
 * @g: Green component
 * @b: Blue component
 */
typedef struct pixel_s
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
} pixel_t;

/**
 * struct img_s - Image
 *
 * @w:      Image width
 * @h:      Image height
 * @pixels: Array of pixels
 */
typedef struct img_s
{
	size_t w;
	size_t h;
	pixel_t *pixels;
} img_t;

/**
 * struct kernel_s - Convolution kernel
 *
 * @size:   Size of the matrix (both width and height)
 * @matrix: Kernel matrix
 */
typedef struct kernel_s
{
	size_t size;
	float **matrix;
} kernel_t;

/**
 * struct blur_portion_s - Information needed to blur a portion of an image
 *
 * @img:      Source image
 * @img_blur: Destination image
 * @x:        X position of the portion in the image
 * @y:        Y position of the portion in the image
 * @w:        Width of the portion
 * @h:        Height of the portion
 * @kernel:   Convolution kernel to use
 */
typedef struct blur_portion_s
{
	img_t const *img;
	img_t *img_blur;
	size_t x;
	size_t y;
	size_t w;
	size_t h;
	kernel_t const *kernel;
} blur_portion_t;

/************* FUNCTION CALLS ************/
void *thread_entry(void *arg);

int tprintf(char const *format, ...);

pixel_t *conv_sum(blur_portion_t const *portion, size_t i, size_t j,
		pixel_t ***img);
void free_img_utils(blur_portion_t const *portion, pixel_t ***img_c,
	pixel_t ***img);
void blur_portion(blur_portion_t const *portion);

list_t *prime_factors(char const *s);
void primeFactors(unsigned long n, list_t *l);

void *exec_tasks(list_t const *tasks);
void destroy_task(task_t *task);
task_t *create_task(task_entry_t entry, void *param);

void blur_image(img_t *img_blur, img_t const *img, kernel_t const *kernel);
pthread_t *create_list_thr(void);
blur_portion_t *create_list_portion(void);
void *thread_entry_blur(void *arg);


#endif /* _MULTITHREADING_H_ */
