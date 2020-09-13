#include "../inc/libmx.h"
#include "findpath.h"

void fp_store_data(char ***Islands, int ***Matrix, const char *filename, int ***WayMatrix, t_main **stct) {
    IslandArray(Islands, filename);
    FillTheMatrix(Matrix, *Islands, filename);
    FillTheWayMatrix(WayMatrix, Matrix);
    mx_dist(stct, *Islands, *Matrix);
}
