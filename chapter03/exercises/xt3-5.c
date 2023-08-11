//用下面的scanf 函数输人数据,使a=3,b=7,x=8.5,y=71. 82,cl=‘A’,c2=‘a’。在键盘上应如何输入?
//整形输入a和b时，必须按照a=3b=7的格式输入，浮点数输入时，%e代表科学记数法输入，字符输入c1和c2时，中间不能有任何空格

#include <stdio.h>

int main()
{
    int a,b;
    float x,y;
    char c1,c2;
    scanf("a=%d b=%d",&a,&b);
    scanf("%f %e",&x,&y);
    scanf("%c%c",&c1,&c2);
    
    printf("a=%d,b=%d,x=%f,y=%f,c1=%c,c2=%c\n",a,b,x,y,c1,c2);
    
    return 0;
}