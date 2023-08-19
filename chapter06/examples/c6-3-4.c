#include <stdio.h>

int main()
{
    printf("ASCII Code of '\\0': %d\n",'\0');

    char c1[]="Today";
    char c2[]={'T','o','d','a','y'};
    char c3[]={'T','o','d','a','y','\0'};

    printf("%llu\n",sizeof(c1));
    printf("%llu\n",sizeof(c2));
    printf("%llu\n",sizeof(c3));


    return 0;
}