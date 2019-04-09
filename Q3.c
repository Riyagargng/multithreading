#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
void *display(void *y)
{
	int i,j,fact;
	int *b=(int *)y;
	int n=*b;
	printf("Prime Numbers are: \n");
    for(i=1; i<=n; i++)
    {
        fact=0;
        for(j=1; j<=n; j++)
        {
            if(i%j==0)
                fact++;
        }
        if(fact==2)
            printf("%d " ,i);
    }
}


main()
{
	int n;
printf("\nenter a number \n");
scanf("%d", &n);
	pthread_t th1;
	pthread_create(&th1,NULL,display,&n);
	pthread_join(th1,NULL);
	
}
