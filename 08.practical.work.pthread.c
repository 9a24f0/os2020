#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX 1000000

void *fibo(void *args) {
    int n, fast, slow;
    fast = slow = 1;
    while (fast + slow <= MAX) {
        n = fast + slow;
        slow = fast;
        fast = n;
        printf ("fibo sequence: %d\n", n);
    }
}

bool check (int n) {
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    if (n % 3 == 0) return false;
    for (int i = 6; i * i < n; i += 6) {
        if (n % (i - 1) == 0) return false;
        if (n % (i + 1) == 0) return false;
    }
    return true;
}

void *prime_num(void *args) {
    int n = 2;
    while (n <= MAX) {
        if (check(n) == true) {
            printf ("prime number: %d\n", n);
        }
        n++;
    }

}

int main() {
	pthread_t tid1, tid2;
	pthread_create(&tid1, NULL, fibo, NULL);
    pthread_create(&tid2, NULL, prime_num, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    return 0;
}



