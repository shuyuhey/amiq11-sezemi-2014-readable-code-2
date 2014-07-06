#pragma once
#include <stdlib.h>
#include <stdint.h>
typedef int64_t recipe_id_t;
typedef struct _recipe
{
    recipe_id_t id;
    char *name;
    char *url;
} recipe_t;

typedef struct _recipe_list
{
    recipe_t **list;
    size_t size;
    size_t alloced;
} recipe_list_t;
