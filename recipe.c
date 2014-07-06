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
#include <stdlib.h>

/* params */
const size_t RECIPE_MAX_LEN = 100;

void print_usage(char *path)
{
    fprintf(stderr, "Usage: %s recipe_path\n", path);
}

void print_recipe(const char *path)
{
    /* prepare file */
    FILE *fp = fopen(path, "r");
    if (fp == NULL) { perror("fopen"); exit(EXIT_FAILURE); }
    char recipe[RECIPE_MAX_LEN];
    /* print one recipe */
    while (fgets(recipe, RECIPE_MAX_LEN, fp) != NULL) {
        printf("%s", recipe);
    }
}

int main(int argc, char *argv[])
{
    /* check args */
    if (argc < 2) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }
    /* set args to each variants */
    const char *recipe_path = argv[1];
    print_recipe(recipe_path);
    return 0;
}
