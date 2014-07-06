//! gcc -o recipe.bin recipe.c -W -Wall -O3 -std=gnu99 
/* 
 * 
 * Author:   Makoto Shimazu <makoto.shimaz@gmail.com>
 * URL:      https://amiq11.tumblr.com               
 * License:  MIT License                             
 * Created:  2014-07-06                                  
 *  
 */
#include <stdio.h>

void print_recipe()
{
    printf("オムライス\n");
}

int main(int argc, char *argv[])
{
    print_recipe();
    return 0;
}
