#ifndef __CAVE_H__
#define __CAVE_H__

#ifdef __cplusplus
extern "C" {
#endif

int init(int* arr, int length);
int add_number(int x);
int remove_number(int x);
int change_number(int oldx, int newx);

#ifdef __cplusplus
}
#endif

#endif /* __CAVE_H__ */
