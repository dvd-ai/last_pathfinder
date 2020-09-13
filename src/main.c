#include "findpath.h"
#include "../inc/libmx.h"

int main(int argc, const char **argv) {
    fp_validation(argc, argv);
    t_main *stct = NULL;
    int b;
    char **Islands = NULL;
    int **Matrix = NULL;
    int **WayMatrix = NULL;
    
    fp_store_data(&Islands, &Matrix, argv[ARGC_NUMBER], &WayMatrix, &stct);

    b = stct->count_island;
    fp_floyd(&stct);

    for (int i = 0; i < b; i++) {
        for (int j = 0; j < b; j++) {
            if (i < j)
                mx_find_all_path(stct, i, j, Islands);
        }
    }

    mx_delintarr(&stct->matrix_dist);
    mx_delintarr(&stct->matrix_floyd);
    free(stct);
    stct = NULL;
    mx_del_strarr(&Islands);
    mx_delintarr(&Matrix);
    mx_delintarr(&WayMatrix);
    return 0;
}
//gcc -Wall -Werror -Wpedantic -Wextra -o o -I libmx/inc -I inc src/*.c libmx/src/*.c

