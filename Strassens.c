
#include<stdio.h>
void readMatrix(int matrix[2][2]){
    int i,j;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("Enter Element %d%d",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
    }
}
int main(){
    int x[2][2],y[2][2],z[2][2];
    int m1,m2,m3,m4,m5,m6,m7;
    printf("Enter Matrix X: \n");
    readMatrix(x);
    printf("Enter Matrix Y: \n");
    readMatrix(y);
    m1=(x[0][0]+x[1][1])*(y[0][0]+y[1][1]);
    m2=y[0][0]*(x[1][0]+x[1][1]);
    m3=x[0][0]*(y[0][1]-y[1][1]);
    m4=x[1][1]*(y[1][0]-y[0][0]);
    m5=y[1][1]*(x[0][0]+x[0][1]);
    m6=(x[1][0]-x[0][0])*(y[0][0]+y[0][1]);
    m7=(y[1][0]+y[1][1])*(x[0][1]-x[1][1]);
    z[0][0]=m1+m4-m5+m7;
    z[0][1]=m3+m5;
    z[1][0]=m2+m4;
    z[1][1]=m1+m3-m2+m6;
    printf("\n Product Achieved: \n" );
    for(int i=0;i<2;i++){
        printf("\n");
        for(int j=0;j<2;j++){
            printf("%d\t",z[i][j]);
        }
    }
    return 0;
}
