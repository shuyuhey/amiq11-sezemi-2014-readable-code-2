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
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "recipe.h"

/* params */
const size_t RECIPE_MAX_LEN = 100;
const size_t RECIPE_LIST_DEFAULT_SIZE = 1000;

void print_usage(char *path)
{
    fprintf(stderr, "Usage: %s recipe_path\n", path);
}

inline void *mymalloc(size_t size) {
    void *tmp = malloc(size);
    if (tmp == NULL) { perror("malloc"); exit(EXIT_FAILURE); }
    return tmp;
}

/* generate an unique id */
static recipe_id_t create_new_id()
{
    static recipe_id_t latest_id = 0;
    return latest_id++;
}

/* generate a recipe with unique id */
static recipe_t *create_new_recipe(const char *name)
{
    recipe_t *recipe = (recipe_t *)mymalloc(sizeof(recipe_t));
    /* init variables */
    recipe->name = (char *)mymalloc(sizeof(char) * strlen(name) + 1);
    sscanf(name, "%s", recipe->name);
    recipe->id = create_new_id();
    return recipe;
}

/* create a list object */
static recipe_list_t *create_new_recipe_list()
{
    recipe_list_t *list = mymalloc(sizeof(recipe_list_t));
    list->list = mymalloc(sizeof(recipe_t*) * RECIPE_LIST_DEFAULT_SIZE);
    list->size = 0;
    list->alloced = RECIPE_LIST_DEFAULT_SIZE;
    return list;
}

/* append a recipe as a last element of list */
static bool append_to_recipe_list(recipe_list_t *list, recipe_t *recipe)
{
    if (list->size == list->alloced) {
        size_t new_size = list->alloced * 2;
        recipe_t *new_list = realloc(list->list, sizeof(recipe_t) * new_size);
        if (new_list == NULL) { perror("append_to_recipe_list"); exit(EXIT_FAILURE); }
        list->alloced = new_size;
    }
    list->list[list->size] = recipe;
    list->size ++;
    return true;
}

/* read a whole file and create a list which contains every recipe in the file */
static recipe_list_t *read_recipe_from_file(const char *path)
{
    /* prepare file */
    FILE *fp = fopen(path, "r");
    if (fp == NULL) { perror("fopen"); exit(EXIT_FAILURE); }
    char line[RECIPE_MAX_LEN];
    recipe_list_t *recipe_list = create_new_recipe_list();

    /* get all recipe and create a list of recipes */
    while (fgets(line, RECIPE_MAX_LEN, fp) != NULL) {
        /* printf("%s", recipe); */
        recipe_t *recipe = create_new_recipe(line);
        if (!append_to_recipe_list(recipe_list, recipe)) {
            fclose(fp);
            return NULL;
        }
    }
    fclose(fp);
    return recipe_list;
}

/* print all recipes */
void print_recipes(const recipe_list_t *list)
{
    for (size_t i = 0; i < list->size; i++) {
        recipe_t *r = list->list[i];
        printf("%ld: %s\n", r->id, r->name);
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
    recipe_list_t *recipe_list = read_recipe_from_file(recipe_path);
    print_recipes(recipe_list);
    return 0;
}
