#include "findpath.h"
#include "../inc/libmx.h"


static void print_distance(t_main *stct, t_backpath *stack);

void mx_output(t_main *stct, t_backpath *stack, char **Islands) {
    int j = stack->path[1];
    int i = stack->path[0];
    int n = stack->size;

    mx_printstr("========================================");
    mx_printstr("\n");
    mx_printstr("Path: ");
    mx_printstr(Islands[j]);
    mx_printstr(" -> ");
    mx_printstr(Islands[i]);
    mx_printstr("\nRoute: ");
    for (int i = 1; i <= n; i++) {
        mx_printstr(Islands[stack->path[i]]);
        (i < n) ? mx_printstr(" -> ") : mx_printstr("");
    }
    print_distance(stct, stack);
    mx_printstr("\n");
    mx_printstr("========================================\n");
}

static void print_distance(t_main *stct, t_backpath *stack) {
    int sum = 0;
    int n = stack->size;

    mx_printstr("\nDistance: ");
    if (n == 2)
        mx_printint(stct->matrix_dist[stack->path[n]][stack->path[n - 1]]);
    else {
        for (int i = 1; i < n; i++) {
            mx_printint(stct->matrix_dist[stack->path[i]][stack->path[i + 1]]);
            sum += stct->matrix_dist[stack->path[i]][stack->path[i + 1]];
            (i + 1 < n) ? mx_printstr(" + ") : mx_printstr("");
        }
        mx_printstr(" = ");
        mx_printint(sum);
    }

}
