#ifndef void_list_h
#define void_list_h

#include <stdbool.h>

typedef void *(*t_v2vfunc)(void *);

typedef void *(*t_vv2vfunc)(void *, void *);

typedef bool (*t_v2bfunc)(void *);

typedef bool (*t_vv2bfunc)(void *, void *);

#endif
