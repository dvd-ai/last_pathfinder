#include "findpath.h"
#include "../inc/libmx.h"

static void init_stack(t_main *stct, t_backpath **path_stack, int i, int j);

void mx_find_all_path(t_main *stct, int first, int last, char **Islands) {
    t_backpath *stack = NULL;

    init_stack(stct, &stack, first, last);
    mx_back_path(stct, stack, Islands);
    free(stack->path);
    free(stack);
}

static void init_stack(t_main *stct, t_backpath **stack, int i, int j) {
    *stack = malloc(sizeof(t_backpath));
    int temp = stct->count_island;

    if ((*stack) == NULL)
        exit(1);
    (*stack)->path = malloc(sizeof(int) * temp + 1);
    (*stack)->size = 1;
    (*stack)->path[1] = i;
    (*stack)->path[0] = j;
    (*stack)->meme = temp;
}
