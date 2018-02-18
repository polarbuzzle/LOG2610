/*
 * remplissage.c
 *
 *  Created on: Aug 26, 2013
 *      Author: Francis Giraldeau <francis.giraldeau@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define READ 0
#define WRITE 1

int main(int argc, char **argv) {
    int fds[2];
    int ret;
    char c = 'x';
    int i = 0;

    /*
     * TODO: Creer un tube, puis le remplir octet par octet a l'infini
     */
    if (pipe(fds) == -1) { printf("fok\n"); }
    // close(fds[READ]);
    while(write(fds[WRITE], &c, sizeof(c)) != 0 ) {
        i++;
        printf("%d\n", i);
    }
    

    return 0;
}
