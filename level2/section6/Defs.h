#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
#define PRINT1(x) (printf("%d\n",x))
#define PRINT2(x1,x2) (printf("%d %d\n",x1,x2))

#define MAX2(x,y) ((x > y)? x : y)
#define MAX3(x,y,z) (MAX2(MAX2(x,y),z))

#endif
