#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <errno.h>
#include <errno.h>

#define SYS_matrix_copy 451

int main(int argc,char **argv)
{
    float matrixA[2][3] = {{7.5,9.5,5.5},{2.5,4.5,6.5}};
    float matrixB[2][3];
    long result = syscall(SYS_matrix_copy,matrixA,matrixB);
    printf("syscall returned: %ld \n",result);
    perror("output: ");
    printf("MatrixB (after the we syscall)\n");
    for(int x =0;x<2;x++)
    {
        for(int y = 0;y<3;y++)
        {
            printf("%f ",matrixB[x][y]);
        }
        printf("\n");
    }
    return result;
}