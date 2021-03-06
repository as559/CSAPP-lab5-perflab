/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/* 
 * Please fill in the following team struct 
 */
team_t team = {
    "LAST SUBMISSION",              /* Team name */

    "HaoRan Sun",     /* First member full name */
    "liamdauld@hnu.edu.cn",  /* First member email address */

    "HaoRan Sun",                   /* Second member full name (leave blank if none) */
    "liamdauld@hnu.edu.cn"                    /* Second member email addr (leave blank if none) */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/* 
 * naive_rotate - The naive baseline version of rotate 
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}

/* 
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */

/* version 1 */
char rotate1_descr[] = "rotate1: Current working version";
void rotate1(int dim, pixel *src, pixel *dst) 
{
    int i,j;
	int i1,j1,block;
	block=16;
	for (i1=0;i1<dim;i1+=block)
		for (j1=0;j1<dim;j1+=block)
			for (i=i1;i<i1+block;i++)
				for (j=j1;j<j1+block;j++)
					dst[RIDX(i, j, dim)] = src[RIDX(j, dim-i-1, dim)];
}

/* version 2 */
char rotate2_descr[] = "rotate2: Current working version";
void rotate2(int dim, pixel *src, pixel *dst) 
{
    int i, j;
	int i1;	
	for (i = 0; i < dim; i+=16)
	for (j = 0; j < dim; j++)
	{
		i1=i;
		dst[RIDX(dim-1-j, i1, dim)] = src[RIDX(i1, j, dim)];
		i1++;
		dst[RIDX(dim-1-j, i1, dim)] = src[RIDX(i1, j, dim)];
		i1++;
		dst[RIDX(dim-1-j, i1, dim)] = src[RIDX(i1, j, dim)];
		i1++;
		dst[RIDX(dim-1-j, i1, dim)] = src[RIDX(i1, j, dim)];
		i1++;
		dst[RIDX(dim-1-j, i1, dim)] = src[RIDX(i1, j, dim)];
		i1++;
		dst[RIDX(dim-1-j, i1, dim)] = src[RIDX(i1, j, dim)];
		i1++;
		dst[RIDX(dim-1-j, i1, dim)] = src[RIDX(i1, j, dim)];
		i1++;
		dst[RIDX(dim-1-j, i1, dim)] = src[RIDX(i1, j, dim)];
		i1++;
		dst[RIDX(dim-1-j, i1, dim)] = src[RIDX(i1, j, dim)];
		i1++;
		dst[RIDX(dim-1-j, i1, dim)] = src[RIDX(i1, j, dim)];
		i1++;
		dst[RIDX(dim-1-j, i1, dim)] = src[RIDX(i1, j, dim)];
		i1++;
		dst[RIDX(dim-1-j, i1, dim)] = src[RIDX(i1, j, dim)];
		i1++;
		dst[RIDX(dim-1-j, i1, dim)] = src[RIDX(i1, j, dim)];
		i1++;
		dst[RIDX(dim-1-j, i1, dim)] = src[RIDX(i1, j, dim)];
		i1++;
		dst[RIDX(dim-1-j, i1, dim)] = src[RIDX(i1, j, dim)];
		i1++;
		dst[RIDX(dim-1-j, i1, dim)] = src[RIDX(i1, j, dim)];
	}	    
}

/* version 3 */
char rotate3_descr[] = "rotate3: Current working version";
void rotate3(int dim, pixel *src, pixel *dst) 
{
    int i,j;
    dst+=RIDX(dim-1,0,dim);//???dst?????????src[0]??????????????????
    for(i=0; i< dim; i+=16){//??????????????????2         
        for(j=0;j<dim;j++){
        	*dst=*src;//src??????dst
            dst++;src+=dim;//dst??????????????????????????????src?????????????????????
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;
            *dst=*src;
            dst++;src+=dim;      
            *dst=*src;
            src++;//src?????????????????? ?????????????????????A(???????????????????????????,j==0)
            src-=dim*15;//src????????????????????????
            dst-=dim+15;//dst????????????????????????????????? ?????????????????????B??????????????????????????????,j==0???
        }
        src+=dim*15;//src???????????????????????????????????????????????????A??????
        dst+=dim*dim+16;//dst???????????????????????????????????????????????????B??????
    }        
}

/* native version */
char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}

/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_rotate_functions() 
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);   
    add_rotate_function(&rotate, rotate_descr);
    add_rotate_function(&rotate1, rotate1_descr);   
    add_rotate_function(&rotate2, rotate2_descr);
    add_rotate_function(&rotate3, rotate3_descr);
    /* ... Register additional test functions here */
}


/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* A struct used to compute averaged pixel value */
typedef struct {
    int red;
    int green;
    int blue;
    int num;
} pixel_sum;

/* Compute min and max of two integers, respectively */
static int min(int a, int b) { return (a < b ? a : b); }
static int max(int a, int b) { return (a > b ? a : b); }

/* 
 * initialize_pixel_sum - Initializes all fields of sum to 0 
 */
static void initialize_pixel_sum(pixel_sum *sum) 
{
    sum->red = sum->green = sum->blue = 0;
    sum->num = 0;
    return;
}

/* 
 * accumulate_sum - Accumulates field values of p in corresponding 
 * fields of sum 
 */
static void accumulate_sum(pixel_sum *sum, pixel p) 
{
    sum->red += (int) p.red;
    sum->green += (int) p.green;
    sum->blue += (int) p.blue;
    sum->num++;
    return;
}

/* 
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel 
 */
static void assign_sum_to_pixel(pixel *current_pixel, pixel_sum sum) 
{
    current_pixel->red = (unsigned short) (sum.red/sum.num);
    current_pixel->green = (unsigned short) (sum.green/sum.num);
    current_pixel->blue = (unsigned short) (sum.blue/sum.num);
    return;
}

/* 
 * avg - Returns averaged pixel value at (i,j) 
 */
static pixel avg(int dim, int i, int j, pixel *src) 
{
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;

    initialize_pixel_sum(&sum);
    for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++) 
	for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++) 
	    accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}

/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 * naive_smooth - The naive baseline version of smooth 
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
}

/*
 * smooth - Your current working version of smooth. 
 * IMPORTANT: This is the version you will be graded on
 */

/* version 1 */
char smooth1_descr[] = "smooth1: Current working version";
void smooth1(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	{
    	int ii, jj;
    	pixel_sum sum;
    	pixel current_pixel;

	    sum.red=sum.green=sum.blue=0;
		sum.num=0;
		int ti1=max(i-1, 0);
		int ti2=min(i+1, dim-1);
		int tj1=max(j-1, 0);
		int tj2=min(j+1, dim-1);
	    for(ii = ti1; ii <= ti2; ii++) 
		for(jj = tj1; jj <= tj2; jj++) 
		{
			sum.red+=(int)src[RIDX(ii, jj, dim)].red;
			sum.green+=(int)src[RIDX(ii, jj, dim)].green;
			sum.blue+=(int)src[RIDX(ii, jj, dim)].blue;
			sum.num++;
		}

	    current_pixel.red=(unsigned short)(sum.red/sum.num);
		current_pixel.green=(unsigned short)(sum.green/sum.num);
		current_pixel.blue=(unsigned short)(sum.blue/sum.num);
	    dst[RIDX(i, j, dim)] = current_pixel;	
	}
}

/* version 2 */
char smooth2_descr[] = "smooth2: Current working version";
void smooth2(int dim, pixel *src, pixel *dst) 
{
    int i, j;	
	//?????????????????????????????????
    i = 0;
    j = 0;
    dst[RIDX(0, 0, dim)].red = (unsigned short)(((int)
    					(src[RIDX(0, 0, dim)].red + src[RIDX(0, 1, dim)].red + 
    					src[RIDX(1, 0, dim)].red + src[RIDX(1, 1, dim)].red)) / 4);
    dst[RIDX(0, 0, dim)].green = (unsigned short)(((int)
    					(src[RIDX(0, 0, dim)].green + src[RIDX(0, 1, dim)].green + 
    					src[RIDX(1, 0, dim)].green + src[RIDX(1, 1, dim)].green)) / 4);
    dst[RIDX(0, 0, dim)].blue = (unsigned short)(((int)
    					(src[RIDX(0, 0, dim)].blue + src[RIDX(0, 1, dim)].blue + 
    					src[RIDX(1, 0, dim)].blue + src[RIDX(1, 1, dim)].blue)) / 4);
	//?????????????????????????????????
    i = 0;
    j = dim - 1;
    dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i + 1, j, dim)].red + src[RIDX(i, j - 1, dim)].red + src[RIDX(i + 1, j - 1, dim)].red)) / 4);
    dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i + 1, j, dim)].green + src[RIDX(i, j - 1, dim)].green + src[RIDX(i + 1, j - 1, dim)].green)) / 4);
    dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i + 1, j, dim)].blue + src[RIDX(i, j - 1, dim)].blue + src[RIDX(i + 1, j - 1, dim)].blue)) / 4);
	//?????????????????????????????????
    i = dim - 1;
    j = 0;
    dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i - 1, j, dim)].red + src[RIDX(i, j + 1, dim)].red + src[RIDX(i - 1, j + 1, dim)].red)) / 4);
    dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i - 1, j, dim)].green + src[RIDX(i, j + 1, dim)].green + src[RIDX(i - 1, j + 1, dim)].green)) / 4);
    dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i - 1, j, dim)].blue + src[RIDX(i, j + 1, dim)].blue + src[RIDX(i - 1, j + 1, dim)].blue)) / 4);
	//?????????????????????????????????
    i = dim - 1;
    j = dim - 1;
    dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i - 1, j, dim)].red + src[RIDX(i, j - 1, dim)].red + src[RIDX(i - 1, j - 1, dim)].red)) / 4);
    dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i - 1, j, dim)].green + src[RIDX(i, j - 1, dim)].green + src[RIDX(i - 1, j - 1, dim)].green)) / 4);
    dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i - 1, j, dim)].blue + src[RIDX(i, j - 1, dim)].blue + src[RIDX(i - 1, j - 1, dim)].blue)) / 4);
	//?????????????????????????????????????????????????????????
    j = 0;
    for (i = 1; i < dim - 1; i++)
    {
        dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].red + src[RIDX(i - 1, j + 1, dim)].red +
                                    src[RIDX(i, j, dim)].red + src[RIDX(i, j + 1, dim)].red +
                                    src[RIDX(i + 1, j, dim)].red + src[RIDX(i + 1, j + 1, dim)].red)) / 6);
        dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].green + src[RIDX(i - 1, j + 1, dim)].green +
                                    src[RIDX(i, j, dim)].green + src[RIDX(i, j + 1, dim)].green +
                                    src[RIDX(i + 1, j, dim)].green + src[RIDX(i + 1, j + 1, dim)].green)) / 6);
        dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].blue + src[RIDX(i - 1, j + 1, dim)].blue +
                                    src[RIDX(i, j, dim)].blue + src[RIDX(i, j + 1, dim)].blue +
                                    src[RIDX(i + 1, j, dim)].blue + src[RIDX(i + 1, j + 1, dim)].blue)) / 6);
    }
	//?????????????????????????????????????????????????????????
    i = dim - 1;
    for (j = 1; j < dim - 1; j++)
    {
        dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i - 1, j, dim)].red +
                                    src[RIDX(i, j - 1, dim)].red + src[RIDX(i - 1, j - 1, dim)].red +
                                    src[RIDX(i, j + 1, dim)].red + src[RIDX(i - 1, j + 1, dim)].red)) / 6);
        dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i - 1, j, dim)].green +
                                    src[RIDX(i, j - 1, dim)].green + src[RIDX(i - 1, j - 1, dim)].green +
                                    src[RIDX(i, j + 1, dim)].green + src[RIDX(i - 1, j + 1, dim)].green)) / 6);
        dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i - 1, j, dim)].blue +
                                    src[RIDX(i, j - 1, dim)].blue + src[RIDX(i - 1, j - 1, dim)].blue +
                                    src[RIDX(i, j + 1, dim)].blue + src[RIDX(i - 1, j + 1, dim)].blue)) / 6);
    }
	//?????????????????????????????????????????????????????????
    j = dim - 1;
    for (i = 1; i < dim - 1; i++)
    {
        dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].red + src[RIDX(i - 1, j - 1, dim)].red +
                                    src[RIDX(i, j, dim)].red + src[RIDX(i, j - 1, dim)].red +
                                    src[RIDX(i + 1, j, dim)].red + src[RIDX(i + 1, j - 1, dim)].red)) / 6);
        dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].green + src[RIDX(i - 1, j - 1, dim)].green +
                                    src[RIDX(i, j, dim)].green + src[RIDX(i, j - 1, dim)].green +
                                    src[RIDX(i + 1, j, dim)].green + src[RIDX(i + 1, j - 1, dim)].green)) / 6);
        dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].blue + src[RIDX(i - 1, j - 1, dim)].blue +
                                    src[RIDX(i, j, dim)].blue + src[RIDX(i, j - 1, dim)].blue +
                                    src[RIDX(i + 1, j, dim)].blue + src[RIDX(i + 1, j - 1, dim)].blue)) / 6);
    }
	//?????????????????????????????????????????????????????????
    i = 0;
    for (j = 1; j < dim - 1; j++)
    {
        dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i + 1, j, dim)].red +
                                    src[RIDX(i, j - 1, dim)].red + src[RIDX(i + 1, j - 1, dim)].red +
                                    src[RIDX(i, j + 1, dim)].red + src[RIDX(i + 1, j + 1, dim)].red)) / 6);
        dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i + 1, j, dim)].green +
                                    src[RIDX(i, j - 1, dim)].green + src[RIDX(i + 1, j - 1, dim)].green +
                                    src[RIDX(i, j + 1, dim)].green + src[RIDX(i + 1, j + 1, dim)].green)) / 6);
        dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i + 1, j, dim)].blue +
                                    src[RIDX(i, j - 1, dim)].blue + src[RIDX(i + 1, j - 1, dim)].blue +
                                    src[RIDX(i, j + 1, dim)].blue + src[RIDX(i + 1, j + 1, dim)].blue)) / 6);
    }
	//?????????????????????????????????
    for (i = 1; i < dim - 1; i++)
    {
        for (j = 1; j < dim - 1; j++)
        {
            dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i + 1, j, dim)].red + src[RIDX(i + 1, j - 1, dim)].red +
                                        src[RIDX(i, j, dim)].red + src[RIDX(i - 1, j, dim)].red +
                                        src[RIDX(i, j - 1, dim)].red + src[RIDX(i - 1, j - 1, dim)].red +
                                        src[RIDX(i, j + 1, dim)].red + src[RIDX(i - 1, j + 1, dim)].red +
                                        src[RIDX(i + 1, j + 1, dim)].red)) / 9);
            dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i + 1, j, dim)].green + src[RIDX(i + 1, j - 1, dim)].green +
                                        src[RIDX(i, j, dim)].green + src[RIDX(i - 1, j, dim)].green +
                                        src[RIDX(i, j - 1, dim)].green + src[RIDX(i - 1, j - 1, dim)].green +
                                        src[RIDX(i, j + 1, dim)].green + src[RIDX(i - 1, j + 1, dim)].green +
                                        src[RIDX(i + 1, j + 1, dim)].green)) / 9);
            dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i + 1, j, dim)].blue + src[RIDX(i + 1, j - 1, dim)].blue +
                                        src[RIDX(i, j, dim)].blue + src[RIDX(i - 1, j, dim)].blue +
                                        src[RIDX(i, j - 1, dim)].blue + src[RIDX(i - 1, j - 1, dim)].blue +
                                        src[RIDX(i, j + 1, dim)].blue + src[RIDX(i - 1, j + 1, dim)].blue +
                                        src[RIDX(i + 1, j + 1, dim)].blue)) / 9);
        }
    }
}

/* version 3 */
char smooth3_descr[] = "smooth3: Current working version";
void smooth3(int dim, pixel *src, pixel *dst) 
{
    int i, j;	
	//?????????????????????????????????
    i = 0;
    j = 0;
    dst[RIDX(0, 0, dim)].red = (unsigned short)(((int)
    					(src[RIDX(0, 0, dim)].red + src[RIDX(0, 1, dim)].red + 
    					src[RIDX(1, 0, dim)].red + src[RIDX(1, 1, dim)].red)) / 4);
    dst[RIDX(0, 0, dim)].green = (unsigned short)(((int)
    					(src[RIDX(0, 0, dim)].green + src[RIDX(0, 1, dim)].green + 
    					src[RIDX(1, 0, dim)].green + src[RIDX(1, 1, dim)].green)) / 4);
    dst[RIDX(0, 0, dim)].blue = (unsigned short)(((int)
    					(src[RIDX(0, 0, dim)].blue + src[RIDX(0, 1, dim)].blue + 
    					src[RIDX(1, 0, dim)].blue + src[RIDX(1, 1, dim)].blue)) / 4);
	//?????????????????????????????????
    i = 0;
    j = dim - 1;
    dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i + 1, j, dim)].red + src[RIDX(i, j - 1, dim)].red + src[RIDX(i + 1, j - 1, dim)].red)) / 4);
    dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i + 1, j, dim)].green + src[RIDX(i, j - 1, dim)].green + src[RIDX(i + 1, j - 1, dim)].green)) / 4);
    dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i + 1, j, dim)].blue + src[RIDX(i, j - 1, dim)].blue + src[RIDX(i + 1, j - 1, dim)].blue)) / 4);
	//?????????????????????????????????
    i = dim - 1;
    j = 0;
    dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i - 1, j, dim)].red + src[RIDX(i, j + 1, dim)].red + src[RIDX(i - 1, j + 1, dim)].red)) / 4);
    dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i - 1, j, dim)].green + src[RIDX(i, j + 1, dim)].green + src[RIDX(i - 1, j + 1, dim)].green)) / 4);
    dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i - 1, j, dim)].blue + src[RIDX(i, j + 1, dim)].blue + src[RIDX(i - 1, j + 1, dim)].blue)) / 4);
	//?????????????????????????????????
    i = dim - 1;
    j = dim - 1;
    dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i - 1, j, dim)].red + src[RIDX(i, j - 1, dim)].red + src[RIDX(i - 1, j - 1, dim)].red)) / 4);
    dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i - 1, j, dim)].green + src[RIDX(i, j - 1, dim)].green + src[RIDX(i - 1, j - 1, dim)].green)) / 4);
    dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i - 1, j, dim)].blue + src[RIDX(i, j - 1, dim)].blue + src[RIDX(i - 1, j - 1, dim)].blue)) / 4);
	//?????????????????????????????????????????????????????????
    j = 0;
    for (i = 1; i < dim - 1; i++)
    {
        dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].red + src[RIDX(i - 1, j + 1, dim)].red +
                                    src[RIDX(i, j, dim)].red + src[RIDX(i, j + 1, dim)].red +
                                    src[RIDX(i + 1, j, dim)].red + src[RIDX(i + 1, j + 1, dim)].red)) / 6);
        dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].green + src[RIDX(i - 1, j + 1, dim)].green +
                                    src[RIDX(i, j, dim)].green + src[RIDX(i, j + 1, dim)].green +
                                    src[RIDX(i + 1, j, dim)].green + src[RIDX(i + 1, j + 1, dim)].green)) / 6);
        dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].blue + src[RIDX(i - 1, j + 1, dim)].blue +
                                    src[RIDX(i, j, dim)].blue + src[RIDX(i, j + 1, dim)].blue +
                                    src[RIDX(i + 1, j, dim)].blue + src[RIDX(i + 1, j + 1, dim)].blue)) / 6);
    }
	//?????????????????????????????????????????????????????????
    i = dim - 1;
    for (j = 1; j < dim - 1; j++)
    {
        dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i - 1, j, dim)].red +
                                    src[RIDX(i, j - 1, dim)].red + src[RIDX(i - 1, j - 1, dim)].red +
                                    src[RIDX(i, j + 1, dim)].red + src[RIDX(i - 1, j + 1, dim)].red)) / 6);
        dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i - 1, j, dim)].green +
                                    src[RIDX(i, j - 1, dim)].green + src[RIDX(i - 1, j - 1, dim)].green +
                                    src[RIDX(i, j + 1, dim)].green + src[RIDX(i - 1, j + 1, dim)].green)) / 6);
        dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i - 1, j, dim)].blue +
                                    src[RIDX(i, j - 1, dim)].blue + src[RIDX(i - 1, j - 1, dim)].blue +
                                    src[RIDX(i, j + 1, dim)].blue + src[RIDX(i - 1, j + 1, dim)].blue)) / 6);
    }
	//?????????????????????????????????????????????????????????
    j = dim - 1;
    for (i = 1; i < dim - 1; i++)
    {
        dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].red + src[RIDX(i - 1, j - 1, dim)].red +
                                    src[RIDX(i, j, dim)].red + src[RIDX(i, j - 1, dim)].red +
                                    src[RIDX(i + 1, j, dim)].red + src[RIDX(i + 1, j - 1, dim)].red)) / 6);
        dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].green + src[RIDX(i - 1, j - 1, dim)].green +
                                    src[RIDX(i, j, dim)].green + src[RIDX(i, j - 1, dim)].green +
                                    src[RIDX(i + 1, j, dim)].green + src[RIDX(i + 1, j - 1, dim)].green)) / 6);
        dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i - 1, j, dim)].blue + src[RIDX(i - 1, j - 1, dim)].blue +
                                    src[RIDX(i, j, dim)].blue + src[RIDX(i, j - 1, dim)].blue +
                                    src[RIDX(i + 1, j, dim)].blue + src[RIDX(i + 1, j - 1, dim)].blue)) / 6);
    }
	//?????????????????????????????????????????????????????????
    i = 0;
    for (j = 1; j < dim - 1; j++)
    {
        dst[RIDX(i, j, dim)].red = (unsigned short)(((int)(src[RIDX(i, j, dim)].red + src[RIDX(i + 1, j, dim)].red +
                                    src[RIDX(i, j - 1, dim)].red + src[RIDX(i + 1, j - 1, dim)].red +
                                    src[RIDX(i, j + 1, dim)].red + src[RIDX(i + 1, j + 1, dim)].red)) / 6);
        dst[RIDX(i, j, dim)].green = (unsigned short)(((int)(src[RIDX(i, j, dim)].green + src[RIDX(i + 1, j, dim)].green +
                                    src[RIDX(i, j - 1, dim)].green + src[RIDX(i + 1, j - 1, dim)].green +
                                    src[RIDX(i, j + 1, dim)].green + src[RIDX(i + 1, j + 1, dim)].green)) / 6);
        dst[RIDX(i, j, dim)].blue = (unsigned short)(((int)(src[RIDX(i, j, dim)].blue + src[RIDX(i + 1, j, dim)].blue +
                                    src[RIDX(i, j - 1, dim)].blue + src[RIDX(i + 1, j - 1, dim)].blue +
                                    src[RIDX(i, j + 1, dim)].blue + src[RIDX(i + 1, j + 1, dim)].blue)) / 6);
    }
    //??????????????????????????????
    //????????????????????????????????????????????????????????????????????????????????????
	pixel *pixelA = &src[0]; 
	pixel *pixelB = &src[dim];
	pixel *pixelC = &src[dim+dim];
	pixel *pixelD = &src[dim+dim+dim];
	//?????????sum?????????????????????????????????????????????????????????
	//??????sum0?????????????????????sum3????????????????????????1???4???2???5??????
	int sum0_red, sum0_green, sum0_blue;
	int sum1_red, sum1_green, sum1_blue;
	int sum2_red, sum2_green, sum2_blue;
	int sum3_red, sum3_green, sum3_blue;
	int sum4_red, sum4_green, sum4_blue;
	int sum5_red, sum5_green, sum5_blue; 
	//???????????????????????????????????????????????????
	//index_firstline???????????????index_secondline????????????
	int index_firstline = dim+1;
	int index_secondline = index_firstline+dim;
	//????????????:2???????????????
	for (i = 1; i < dim - 2; i += 2) {
		sum0_red = pixelB->red;
		sum0_blue = pixelB->blue;
		sum0_green = pixelB->green;
		sum0_red += pixelC->red;
		sum0_blue += pixelC->blue;
		sum0_green += pixelC->green;
		sum3_red = sum0_red+pixelD->red;
		sum3_green = sum0_green+pixelD->green;
		sum3_blue = sum0_blue+pixelD->blue;
		sum0_red += pixelA->red;
		sum0_blue += pixelA->blue;
		sum0_green += pixelA->green;
		//??????????????????1???4??????
		pixelA++;
		pixelB++;
		pixelC++;
		pixelD++;

		sum1_red = pixelB->red;
		sum1_blue = pixelB->blue;
		sum1_green = pixelB->green;
		sum1_red += pixelC->red;
		sum1_blue += pixelC->blue;
		sum1_green += pixelC->green;
		sum4_red = sum1_red+pixelD->red;
		sum4_green = sum1_green+pixelD->green;
		sum4_blue = sum1_blue+pixelD->blue;
		sum1_red += pixelA->red;
		sum1_blue += pixelA->blue;
		sum1_green += pixelA->green;
		//????????????2???5??????;
		pixelA++;
		pixelB++;
		pixelC++;
		pixelD++;

		sum2_red = pixelB->red;
		sum2_blue = pixelB->blue;
		sum2_green = pixelB->green;
		sum2_red += pixelC->red;
		sum2_blue += pixelC->blue;
		sum2_green += pixelC->green;
		sum5_red = sum2_red+pixelD->red;
		sum5_green = sum2_green+pixelD->green;
		sum5_blue = sum2_blue+pixelD->blue;
		sum2_red += pixelA->red;
		sum2_blue += pixelA->blue;
		sum2_green += pixelA->green;
		//??????;
		pixelA++;
		pixelB++;
		pixelC++;
		pixelD++;

		dst[index_firstline].red = ((sum0_red+sum1_red+sum2_red)/9);
		dst[index_firstline].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
		dst[index_firstline].green = ((sum0_green+sum1_green+sum2_green)/9);
		index_firstline++;
		dst[index_secondline].red = ((sum3_red+sum4_red+sum5_red)/9);
		dst[index_secondline].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
		dst[index_secondline].green = ((sum3_green+sum4_green+sum5_green)/9);
		index_secondline++;
		//??????
		sum0_red = sum1_red;
		sum1_red = sum2_red;
		sum0_green = sum1_green;
		sum1_green = sum2_green;
		sum0_blue = sum1_blue;
		sum1_blue = sum2_blue;
		sum3_red = sum4_red;
		sum4_red = sum5_red;
		sum3_green = sum4_green;
		sum4_green = sum5_green;
		sum3_blue = sum4_blue;
		sum4_blue = sum5_blue;
		//????????????:4????????????????????????+????????????+??????+??????????????????
		for (j = 2; j < dim-4; j += 4) {
			//?????????
			sum2_red = pixelB->red;
			sum2_blue = pixelB->blue;
			sum2_green = pixelB->green;
			sum2_red += pixelC->red;
			sum2_blue += pixelC->blue;
			sum2_green += pixelC->green;
			sum5_red = sum2_red+pixelD->red;
			sum5_green = sum2_green+pixelD->green;
			sum5_blue = sum2_blue+pixelD->blue;
			sum2_red += pixelA->red;
			sum2_blue += pixelA->blue;
			sum2_green += pixelA->green;
			pixelA++;
			pixelB++;
			pixelC++;
			pixelD++;

			dst[index_firstline].red = ((sum0_red+sum1_red+sum2_red)/9);
			dst[index_firstline].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
			dst[index_firstline].green = ((sum0_green+sum1_green+sum2_green)/9);
			index_firstline++;

			dst[index_secondline].red = ((sum3_red+sum4_red+sum5_red)/9);
			dst[index_secondline].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
			dst[index_secondline].green = ((sum3_green+sum4_green+sum5_green)/9);
			index_secondline++;

			sum0_red = sum1_red;
			sum1_red = sum2_red;
			sum0_green = sum1_green;
			sum1_green = sum2_green;
			sum0_blue = sum1_blue;
			sum1_blue = sum2_blue;
			sum3_red = sum4_red;
			sum4_red = sum5_red;
			sum3_green = sum4_green;
			sum4_green = sum5_green;
			sum3_blue = sum4_blue;
			sum4_blue = sum5_blue;

			//?????????
			sum2_red = pixelB->red;
			sum2_blue = pixelB->blue;
			sum2_green = pixelB->green;
			sum2_red += pixelC->red;
			sum2_blue += pixelC->blue;
			sum2_green += pixelC->green;
			sum5_red = sum2_red+pixelD->red;
			sum5_green = sum2_green+pixelD->green;
			sum5_blue = sum2_blue+pixelD->blue;
			sum2_red += pixelA->red;
			sum2_blue += pixelA->blue;
			sum2_green += pixelA->green;
			pixelA++;
			pixelB++;
			pixelC++;
			pixelD++;

			dst[index_firstline].red = ((sum0_red+sum1_red+sum2_red)/9);
			dst[index_firstline].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
			dst[index_firstline].green = ((sum0_green+sum1_green+sum2_green)/9);
			index_firstline++;

			dst[index_secondline].red = ((sum3_red+sum4_red+sum5_red)/9);
			dst[index_secondline].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
			dst[index_secondline].green = ((sum3_green+sum4_green+sum5_green)/9);
			index_secondline++;

			sum0_red = sum1_red;
			sum1_red = sum2_red;
			sum0_green = sum1_green;
			sum1_green = sum2_green;
			sum0_blue = sum1_blue;
			sum1_blue = sum2_blue;
			sum3_red = sum4_red;
			sum4_red = sum5_red;
			sum3_green = sum4_green;
			sum4_green = sum5_green;
			sum3_blue = sum4_blue;
			sum4_blue = sum5_blue;

			//?????????
			sum2_red = pixelB->red;
			sum2_blue = pixelB->blue;
			sum2_green = pixelB->green;
			sum2_red += pixelC->red;
			sum2_blue += pixelC->blue;
			sum2_green += pixelC->green;
			sum5_red = sum2_red+pixelD->red;
			sum5_green = sum2_green+pixelD->green;
			sum5_blue = sum2_blue+pixelD->blue;
			sum2_red += pixelA->red;
			sum2_blue += pixelA->blue;
			sum2_green += pixelA->green;
			pixelA++;
			pixelB++;
			pixelC++;
			pixelD++;

			dst[index_firstline].red = ((sum0_red+sum1_red+sum2_red)/9);
			dst[index_firstline].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
			dst[index_firstline].green = ((sum0_green+sum1_green+sum2_green)/9);
			index_firstline++;

			dst[index_secondline].red = ((sum3_red+sum4_red+sum5_red)/9);
			dst[index_secondline].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
			dst[index_secondline].green = ((sum3_green+sum4_green+sum5_green)/9);
			index_secondline++;

			sum0_red = sum1_red;
			sum1_red = sum2_red;
			sum0_green = sum1_green;
			sum1_green = sum2_green;
			sum0_blue = sum1_blue;
			sum1_blue = sum2_blue;
			sum3_red = sum4_red;
			sum4_red = sum5_red;
			sum3_green = sum4_green;
			sum4_green = sum5_green;
			sum3_blue = sum4_blue;
			sum4_blue = sum5_blue;

			//?????????
			sum2_red = pixelB->red;
			sum2_blue = pixelB->blue;
			sum2_green = pixelB->green;
			sum2_red += pixelC->red;
			sum2_blue += pixelC->blue;
			sum2_green += pixelC->green;
			sum5_red = sum2_red+pixelD->red;
			sum5_green = sum2_green+pixelD->green;
			sum5_blue = sum2_blue+pixelD->blue;
			sum2_red += pixelA->red;
			sum2_blue += pixelA->blue;
			sum2_green += pixelA->green;
			pixelA++;
			pixelB++;
			pixelC++;
			pixelD++;

			dst[index_firstline].red = ((sum0_red+sum1_red+sum2_red)/9);
			dst[index_firstline].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
			dst[index_firstline].green = ((sum0_green+sum1_green+sum2_green)/9);
			index_firstline++;

			dst[index_secondline].red = ((sum3_red+sum4_red+sum5_red)/9);
			dst[index_secondline].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
			dst[index_secondline].green = ((sum3_green+sum4_green+sum5_green)/9);
			index_secondline++;

			sum0_red = sum1_red;
			sum1_red = sum2_red;
			sum0_green = sum1_green;
			sum1_green = sum2_green;
			sum0_blue = sum1_blue;
			sum1_blue = sum2_blue;
			sum3_red = sum4_red;
			sum4_red = sum5_red;
			sum3_green = sum4_green;
			sum4_green = sum5_green;
			sum3_blue = sum4_blue;
			sum4_blue = sum5_blue;

		}
		//???????????????????????????????????????
		for (; j < dim-1; j++) {
			sum2_red = pixelB->red;
			sum2_blue = pixelB->blue;
			sum2_green = pixelB->green;
			sum2_red += pixelC->red;
			sum2_blue += pixelC->blue;
			sum2_green += pixelC->green;
			sum5_red = sum2_red+pixelD->red;
			sum5_green = sum2_green+pixelD->green;
			sum5_blue = sum2_blue+pixelD->blue;
			sum2_red += pixelA->red;
			sum2_blue += pixelA->blue;
			sum2_green += pixelA->green;
			pixelA++;
			pixelB++;
			pixelC++;
			pixelD++;

			dst[index_firstline].red = ((sum0_red+sum1_red+sum2_red)/9);
			dst[index_firstline].blue = ((sum0_blue+sum1_blue+sum2_blue)/9);
			dst[index_firstline].green = ((sum0_green+sum1_green+sum2_green)/9);
			index_firstline++;

			dst[index_secondline].red = ((sum3_red+sum4_red+sum5_red)/9);
			dst[index_secondline].blue = ((sum3_blue+sum4_blue+sum5_blue)/9);
			dst[index_secondline].green = ((sum3_green+sum4_green+sum5_green)/9);
			index_secondline++;

			sum0_red = sum1_red;
			sum1_red = sum2_red;
			sum0_green = sum1_green;
			sum1_green = sum2_green;
			sum0_blue = sum1_blue;
			sum1_blue = sum2_blue;
			sum3_red = sum4_red;
			sum4_red = sum5_red;
			sum3_green = sum4_green;
			sum4_green = sum5_green;
			sum3_blue = sum4_blue;
			sum4_blue = sum5_blue;
		}

		//??????????????????????????????
		pixelA += dim;
		pixelB += dim;
		pixelC += dim;
		pixelD += dim;
		index_firstline += dim+2;
		index_secondline += dim+2;
	}
}

/* naive version */
char smooth_descr[] = "smooth: Current working version";
void smooth(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
}

/********************************************************************* 
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_smooth_functions() {
    add_smooth_function(&smooth, smooth_descr);
    add_smooth_function(&smooth1, smooth1_descr);
    add_smooth_function(&smooth2, smooth2_descr);
    add_smooth_function(&smooth3, smooth3_descr);
    add_smooth_function(&naive_smooth, naive_smooth_descr);
    /* ... Register additional test functions here */
}

