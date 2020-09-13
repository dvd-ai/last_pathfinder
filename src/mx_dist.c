#include "../inc/libmx.h"
#include "findpath.h"

void mx_dist(t_main **stct, char **Islands, int **Matrix){
    int len = 0;
    for (int i =0; Islands[i] != NULL; i++, len++);
    *stct = (t_main*)malloc(sizeof(t_main));
    (*stct)->matrix_dist = mx_intarrnew(len);
    for (int i = 0; i < len; i++)
        (*stct)->matrix_dist[i] = mx_intnew(len);
    (*stct)->count_island = len;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            (*stct)->matrix_dist[i][j] = Matrix[i][j];
        }
    }
}

