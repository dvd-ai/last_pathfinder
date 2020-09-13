#include "findpath.h"
#include "../inc/libmx.h"
#define N 6

static void mx_floyd(t_main **stct);

void Add(long long *sum, int first, int second) {
    long long dodanok1 = first;
    long long dodanok2 = second;
    *sum = dodanok1 + dodanok2;
}

void fp_floyd(t_main **stct) {
    long long sum;
    long long element;
    mx_floyd(stct);

    for (int k = 0; (*stct)->matrix_dist[k] != NULL; k++) {
        for (int i = 0; (*stct)->matrix_dist[i] != NULL; i++) {
            for (int j = 0; (*stct)->matrix_dist[j] != NULL; j++) {
                Add(&sum, (*stct)->matrix_dist[i][k], (*stct)->matrix_dist[k][j]);
                element = (*stct)->matrix_dist[i][j];
                if (element > sum) {
                    (*stct)->matrix_dist[i][j] = (*stct)->matrix_dist[i][k] + (*stct)->matrix_dist[k][j];
                }
            }
        }
    }
}

static void mx_floyd(t_main **stct){

    (*stct)->matrix_floyd = mx_intarrnew((*stct)->count_island);
    for (int i = 0; i < (*stct)->count_island; i++)
        (*stct)->matrix_floyd[i] = mx_intnew((*stct)->count_island);
    (*stct)->count_island = (*stct)->count_island;
    for (int i = 0; i < (*stct)->count_island; i++) {
        for (int j = 0; j < (*stct)->count_island; j++) {
            (*stct)->matrix_floyd[i][j] = (*stct)->matrix_dist[i][j];
        }
    }
}

