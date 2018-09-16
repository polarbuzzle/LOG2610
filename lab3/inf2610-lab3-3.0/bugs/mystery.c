/*
 * mystery.c
 *
 *  Created on: 2018-02-16
 *      Author: Loïc Gelle
 */

void bar(void *m) {
    void *secret[1];
    secret[2] = m - 5;
    printf("hohoho %p \n", secret);    
}

void foo() {
    void *mystery[1];
    printf("hihihi %p \n", foo);
    bar(mystery[2]);
}

int main(int argc, char **argv) {
    foo();
    return 0;
}
