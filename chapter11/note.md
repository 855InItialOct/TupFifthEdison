# 第11章  常见错误分析

1. 忘记定义变量。

    ```c
    int main()
    {
        x=3;
        y=6;
        printf("%d\n", x + y);
        return 0;
    }
    ```

2. 输入输出数据的类型与用户指定的输入输出格式声明不一致。

    ```c
    int main()
    {
        int a = 6;
        float b = 4.5f;
        printf("%f,%d", a, b);//0.0000000,0
        return 0;
    }
    ```

3. 未注意数据类型的取值范围。

    ```c
    int main()
    {
        short num;
        num=196607;
        printf("%d", num);
        return 0;
    }
    ```

4. 使用scanf函数时，忘记用变量的地址符&。

    ```c
    int main()
    {
        int a, b;
        scanf("%d%d", a, b);
        return 0;
    }
    ```

5. 输入数据的形式与要求不符。

    ```c
    int main()
    {
        int a, b;
        scanf("%d%d", &a, &b);//输入数据时用空格（或tab键、回车符）来分隔
        return 0;
    }
    ```

6. 在用scanf函数向字符数组输入数据时，在数组名前面多加了&。

    ```c
    int main()
    {
        char a[20];
        scanf("%s", &a);
        return 0;
    }
    ```

7. 在用scanf函数向数值型数组输入数据时，用数值型数组名。

    ```c
    int main()
    {
        int a[20];
        scanf("%d",a);
    }
    ```

8. 语句漏分号。

9. 把预处理指令当作C语句，在行末加了分号。

   `#include "stdio.h";`

10. 在不该加分号的地方加了分号。

    ```c
    if(a<b);
    printf("a is smaller than b.\n");
    ```

11. 对应该有花括号的复合语句，忘记加花括号。

    ```c
    sum=0;
    i=0;
    while(i<=100) 
        sum=sum+i;
    i++;
    ```

12. 括号不配对。

    ```c
    while((c=getchar()!='#') 
        putchar(c);
    ```

13. 在用标识符时，混淆了字母大小写的区别。

    ```c
    int main()
    {
        int A,B,C;
        a=2;
        b=3;
        c=a+b;
        printf("%d", c);
        return 0;
    }
    ```

14. 把"="当作“等于”运算符。

    ```c
    if(score=100)
        n++;
    ```

15. 应用数组元素时用了圆括号。

    `int a(10);`

16. 将定义的“元素个数”认为是“可使用的最大下标值”。

    ```c
    int a[10]={1,2,3,4,5,6,7,8,9,0};
    printf("%d",a[10]);
    ```

17. 对二维或多维数组定义和引用方法不对。

    `int a[5,4]`

18. 误认为数组名代表数组中的全部元素。

    ```c
    int a[4]={1,3,5,7},b[4];
    b=a;
    ```

19. 混淆字符数组与字符指针的区别。

    ```c
    char str[10];
    str="computer and c";//此时str是数组首地址，占内存单元，str是常量，不能赋值。
    ```

20. 在引用指针变量之前没有对它赋确定的值。

    ```c
    char *p;
    scanf("%s",p);
    ```

21. switch语句的各分支漏写break语句。

    ```c
    int main()
    {
        int score;
        scanf("%d", &score);
        switch (score) {
            case 5:
                printf("Very good!\n");
            case 4:
                printf("Good!\n");
            case 3:
                printf("Pass!\n");
            case 2:
                printf("Fail!\n");
            default:
                printf("Data error!\n");
        }
        return 0;
    }
    ```

22. 混淆字符与字符串的表现形式。

    `char sex;sex="M";`

23. 使用自增自减运算符是容易出的错误。

    ```c
    int main()
    {
        int*p, a[5] = {1, 3, 5, 7, 9};
        p=a;
        printf("%d", *p++);
        return 0;
    }
    ```

24. 忘记对所调用的函数进行函数原型声明。

25. 对函数声明与函数定义不匹配。

26. 在需要加头文件是没有用#include 指令。

27. 误认为函数形参值的改变会影响实参的值。

    ```c
    int main() 
    {
        void swap(int, int);
        int a,b;
        a=3;
        b = 4;
        swap(a, b);
        printf("%d,%d", a, b);
        return 0;
    }

    void swap(int x, int y) 
    {
        int t;
        t = x;
        x = y;
        y = t;
    }
    ```

28. 函数实参和形参类型不一致。

    ```c
    # include "stdio.h"

    int main() 
    {
        int fun(int, int);
        float a = 3.5f, b = 4.6f, c;
        c = fun(a, b);
        printf("%f\n", c);
    }

    int fun(int x, int y)
    {
        return x + y;
    }
    ```

29. 不同类型的指针混用。

    ```c
    int main()
    {
        int i = 3, *p1;
        float a = 1.5f,*p2;
        p1 = &i;
        p2 = &a;
        p2 = p1;
        printf("%d,%d\n", *p1,*p2);
        return 0;
    }
    ```

30. 没有注意系统对函数参数的求值顺序的处理方法。

    ```c
    int main()
    {
        int i = 3;
        printf("%d,%d,%d\n", i, ++i, ++i);
        return 0;
    }
    ```

31. 混淆数组名与指针变量的区别。

    ```c
    int main()
    {
        int i, a[5];
        for (i = 0; i < 5; i++) 
        {
            scanf("%s", a++);
        }
    }
    ```

32. 对结构体类型赋值。

    ```c
        struct worker{int num;char name[10]};
        worker.num=187045;
    ```

33. 使用文件是忘记打开，或打开凡是与使用情况不匹配。

    ```c
    int main() 
    {
        FILE *fp;
        char ch;
        if (NULL == (fp = fopen("test", "r"))) 
        {
            printf("Can't open this file.\n");
            exit(0);
        }
        ch = (char)fgetc(fp);
        while ('#' != ch) 
        {
            ch += 4;
            fputc(ch, fp);
            ch =(char)fgetc(fp);
        }
        return 0;
    }
    ```

34. 在打开文件使，指定的文件名找不到。

35. 忘记关闭文件。
