#include <pthread.h>
#include <time.h>
// 初始化一个互斥锁。
int pthread_mutex_init(pthread_mutex_t *mutex, 
						const pthread_mutexattr_t *attr);

// 对互斥锁上锁，若互斥锁已经上锁，则调用者一直阻塞，
// 直到互斥锁解锁后再上锁。
int pthread_mutex_lock(pthread_mutex_t *mutex);

// 调用该函数时，若互斥锁未加锁，则上锁，返回 0；
// 若互斥锁已加锁，则函数直接返回失败，即 EBUSY。
int pthread_mutex_trylock(pthread_mutex_t *mutex);

// 当线程试图获取一个已加锁的互斥量时，pthread_mutex_timedlock 互斥量
// 原语允许绑定线程阻塞时间。即非阻塞加锁互斥量。
int pthread_mutex_timedlock(pthread_mutex_t *restrict mutex,
const struct timespec *restrict abs_timeout);

// 对指定的互斥锁解锁。
int pthread_mutex_unlock(pthread_mutex_t *mutex);

// 销毁指定的一个互斥锁。互斥锁在使用完毕后，
// 必须要对互斥锁进行销毁，以释放资源。
int pthread_mutex_destroy(pthread_mutex_t *mutex);
