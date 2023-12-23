#### **puts**函数———输出字符串函数

1. 一般形式：**puts(字符数组)**
2. 作用：将一个字符串（以'\0'结束的字符序列）输出到终端。
   * puts函数输出的字符串中可以包含转义字符。
3. 详细内容：
   * puts()函数用来向标准输出设备（屏幕）输出字符串并换行。具体为：把字符串输出到标准输出设备，将'\0'转换为回车换行
   * 函数原型：`int puts(const char *string)`;
   * 返回值：如果执行成功，该函数返回一个非负值（为字符串长度，包括末尾的'\0'），如果发生错误则返回`EOF`。
   * 用法：puts(字符数组)
   * 注意：在用puts输出时将字符串结束标志'\0'转换为'\n'，即输出完字符后换行
     * '\0'是空操作符，二进制是00000000，ASCII码值为0，
     * '0'是字符0，二进制是00110000，ASCII码值为48。
4. puts()函数无法进行数据类型转换，只能够输出字符串，参数只能是字符指针。输入若为其他类型数据或指针，编译器会报错。

#### **gets**函数———输入字符串函数

1. 一般形式：**gets(字符数组)**
2. 作用：从终端输入一个字符串到字符数组，并得到一个函数值。
3. **注意**：
   * 送给字符数组的字符除输入的字符串外，系统在最后还加上了'\0'；
   * 返回的函数值是字符数组的起始地址；
   * gets函数不大关心函数值。
4. 详细内容：
   1. C库函数gets()函数从stdin流中读取字符串，直至接受到换行符或EOF时停止，并将读取的结果存放在buffer指针所指向的字符数组中。换行符不作为读取串的内容，读取的换行符被转换为‘\0’空字符，并由此来结束字符串。
   2. 函数原型：`char *gets(char *str)`
   3. 返回值：
      * 读入成功，返回与参数buffer相同的指针；
      * 读入过程中遇到EOF(End-of-File)或发生错误，返回NULL指针。（所以在遇到返回值为NULL的情况，要用 ferror 或feof 函数检查是发生是错误还是遇到EOF。）
   4. 用法：**gets(字符数组)**
   5. 和scanf()的区别：
      1. scanf("%s",&str) ：读到空格便停止。
      2. gets(str) ：一直读到敲回车（不管中间是否有空格）。
   6. **注意**：因为gets函数可以无限读取，易发生溢出。
      * 如果溢出，多出来的字符将被写入到堆栈中，这就覆盖了堆栈原先的内容，破坏一个或多个不相关变量的值;
      * 这个事实导致gets函数只适用于玩具程序;
      * 为了避免这种情况，我们可以用fgets(stdin)
        * fgets实际上可以读取标准输入，即大多数情况下的键盘输入。
      * 由于可以无限读取，所以在2011年12月，ANSI采纳了ISO/IEC 9899:2011 标准。标准中删除了 gets()函数，使用一个新的更安全的函数gets_s()替代。
   7. **puts 和 gets 函数只输入输出一个字符串**

#### **strcat**函数———字符串连接函数

1. 一般形式：`strcat(字符数组1，字符数组2)`
2. **说明**：
   * 字符数组1必须足够大，以便容纳连接后的新字符串；
   * 连接时取消字符串1后的'\0'，只在新字符串后保留'\0'。
3. 详细内容：
   * 原型：`extern char *strcat(char *dest, const char *src);`
   * 头文件：
     * 在C中，函数原型存在`<string.h>`头文件中。
     * 在C++中，则存在于`<cstring>`头文件中。
   * 用法：`#include <string.h>`
   * **源代码**：
     1. ibc（Linux下的ANSI C的函数库）

        ```c
        char * strcat(char * dest, const char * src)
        {
            char *tmp = dest;

            while (*dest)
                    dest++;
            while ((*dest++ = *src++) != '\0')
                    ;

            return tmp;
        }
        ```

     2. Windows

        ```c
        char* strcat ( char * dst , const char * src )
        {
            char * cp = dst;
            
            while( *cp )
            
            cp++; /* find end of dst */
            
            while( *cp++ = *src++ ) ; 
            
            return( dst ); 
        }
        ```

     3. GNU C Library

        ```c
        char *  strcat (char *dest, const char *src)  
        {  
            //通过strcpy来实现strcat函数  
            strcpy (dest + strlen (dest), src);

            return dest;
        }
        ```

     4. OpenBSD

        ```c
        char *  strcat(char *s, const char *append)  
        {  
            //将s所指向的字符串的首地址保存下来，以便使用  
                char *save = s;  
        
                //将s所指向的字符串的首指针移至串尾处，s指针指向的字符元素为'\0'  
                for (; *s; ++s);  
            
                //将append所指的字符串的元素复制到s所指向的字符串尾部，直至遇到'\0'  
                while ((*s++ = *append++) != '\0');  
                
                //返回追加后的字符串首地址  
                return(save);  
        }
        ```

     5. 网上实现

        ```c
        #include <assert.h>
        char *strcat (char * dst, const char * src)
        {
            assert(NULL != dst && NULL != src);   // 源码里没有断言检测
            char * cp = dst;
            while( *cp )
                cp++;       /* find end of dst */
            while( *cp++ = *src++ ) ;       /* Copy src to end of dst */
            return( dst );                  /* return dst */
        }
        ```

        或者

        ```c
        char *strcat (char * dst, const char * src)
        {
            assert(NULL != dst && NULL != src);   // 源码里没有断言检测
            char * cp = dst;
            while( '\0' != *cp )
                cp++;       /* find end of dst */
            while( '\0' != (*cp++ = *src++) ) ;       /* Copy src to end of dst */
            return( dst );                  /* return dst */
        }
        ```

   * 功能：把src所指向的字符串（包括'\0'）复制到dest所指向的字符串后面（**删除dest原来末尾的'\0'）。要保证dest足够长，以容纳被复制进来的src。src中原有的字符不变。返回指向dest的指针**。
   * 说明：src和dest所指内存区域不可以重叠且dest必须有足够的空间来容纳src的字符串。

#### `strcpy` 和 `strncpy` 函数———字符串复制函数

1. 一般形式：`strcpy(字符数组1，字符数组2)`
   * **说明**：
     1. 字符数组1必须足够大；
     2. 字符数组1必须写成数组名形式，字符数组2可以是数组名也可以是字符串常量；
     3. 字符数组1未初始化或赋值时，字符数组1中的元素是**无法预知**的，所以将字符数组2中的字符包含'\0'一起复制到字符数组1中，'\0'后的字符不一定是'\0'；
     4. 不能用赋值语句将一个字符串或一个字符数组赋值给另一个字符数组；
2. `strncpy`函数
   * 作用：可以将字符数组2中的前n个字符复制给字符数组1。strncpy(字符数组1，字符数组2，n)
3. `strcpy` 和 `strncpy` 的详细内容：
   1. `strcpy`函数:
      * 定义于头文件 `<string.h>`
      * 函数原型:
        * C99 前：`char *strcpy( char *dest, const char *src );`
        * C99 起：`char *strcpy( char *restrict dest, const char *restrict src );`
        * C11 起：`errno_t strcpy_s(char *restrict dest, rsize_t destsz, const char *restrict src);`
      * 参数:
        * dest - 指向要写入的字符数组的指针
        * src - 指向要复制的空终止字节字符串的指针
        * destsz - 写入的最大字符数，典型地为目标缓冲区的大小
      * 返回值:
        * 返回 dest 的副本,成功时返回零，失败时返回非零。而且失败时向 dest[0] 写入零（除非 dest 是空指针或 destsz 为零或大于 RSIZE_MAX ）。
      * **源代码**
        1. Windows

            ```c
            char * strcpy(char * dst, const char * src)
            {
                char * cp = dst;

                while( *cp++ = *src++ )
                        ;               /* Copy src over dst */

                return( dst );
            }
            ```

      * **说明**：
          * C11前 复制 src 所指向的空终止字节字符串，**包含空终止符**，到首元素为 dest 所指的字符数组。
          * 若 dest 数组长度不足则行为未定义。
          * 若字符串覆盖则行为未定义
          * 若 dest 不是指向字符数组的指针或 src 不是指向空终止字节字符串的指针则行为未定义。
          * 同上，除了它可能因未指定值而破坏目标数组的剩余部分外，还会在运行时检测下列错误，并调用当前安装的制约处理函数：
            1. src 或 dest 为空指
            2. destsz 为零或大于 RSIZE_MAX
            3. destsz 小于或等于 strnlen_s(src, destsz) ；换言之，会发生截断
            4. 源与目标字符串间会发生重叠
          * 若 dest 所指的字符数组大小 <= strnlen_s(src, destsz) < destsz 则行为未定义；换言之， destsz 的错误值不暴露即将发生的缓冲区溢出。
          * 同所有边界检查函数一样， strcpy_s 仅若实现定义了 `__STDC_LIB_EXT1__` ，且用户在包含 `<string.h>` 前定义 `__STDC_WANT_LIB_EXT1__` 为整数常量 1 才保证可用。
          * 注意:
            为提升效率，允许 strcpy_s 破坏至多 destsz 个目标数组上次写入的字符：它可能先复制多字节块再检查空字节。  
            函数 strcpy_s 类似 BSD 函数 strlcpy ，除了
            * strlcpy 截断源字符串以适应目标（这有安全风险）
            * strlcpy 不全部进行 strcpy_s 所进行的运行时检查
            * strlcpy 不会通过设置目标为空字符串或调用处理函数，以令失败显著。

          尽管 strcpy_s 因潜在的安全风险禁止截断，也还可以用使用边界检查的 strncpy_s 替而进行截断字符串。

          * 示例

            ```c
            #define __STDC_WANT_LIB_EXT1__ 1
            #include <string.h>
            #include <stdio.h>
            #include <stdlib.h>
            
            int main(void)
            {
                char *src = "Take the test.";
            //  src[0] = 'M' ; // 这会是未定义行为
                char dst[strlen(src) + 1]; // +1 以适应空终止符
                strcpy(dst, src);
                dst[0] = 'M'; // OK
                printf("src = %s\ndst = %s\n", src, dst);
            
                #ifdef __STDC_LIB_EXT1__
                    set_constraint_handler_s(ignore_handler_s);
                    int r = strcpy_s(dst, sizeof dst, src);
                    printf("dst = \"%s\", r = %d\n", dst, r);
                    r = strcpy_s(dst, sizeof dst, "Take even more tests.");
                    printf("dst = \"%s\", r = %d\n", dst, r);
                #endif
            }
            ```

            可能的输出：

            ```text
            src = Take the test.
            dst = Make the test.
            dst = "Take the test.", r = 0
            dst = "", r = 22
            ```

   2. `strncpy`函数
      * 定义于头文件： `<string.h>`
      * 函数原型：
        * C99前:`char *strncpy( char *dest, const char *src, size_t count );`
        * C99起：`char *strncpy( char *restrict dest, const char *restrict src, size_t count );`
        * C11起：`errno_t strncpy_s(char *restrict dest, rsize_t destsz,const char *restrict src, rsize_t count);`
        * 说明：
          1. C11前：复制 src 所指向的字符数组的至  多 count 个字符（**包含空终止字符，但不包含后随空字符的任何字符**）到 dest 所指向的字符数组。
             * 若在完全复制整个 src 数组前抵达 count ，则结果的字符数组不是空终止的。
             * 若在复制来自 src 的空终止字符后未抵达 count ，则写入额外的空字符到 dest ，直至写入总共 count 个字符。
             * 若字符数组重叠，若 dest 或 src 不是指向字符数组的指针（包含若 dest 或 src 为空指针），若 dest 所指向的数组大小小于 count ，或若 src 所指向的数组大小小于 count 且它不含空字符，则行为未定义。
          2. C11起： 同 (1) ，除了函数不持续写入零到目标数组以填满 count ，它在写入空终止字符后停止（若源中无空字符，则它于 `dest[count]` 写入一个然后停止）。并且在运行时检测下列错误并调用当前安装的制约处理函数：
             * src 或 dest 是空指针
             * destsz 零或大于 RSIZE_MAX
             * count 大于 RSIZE_MAX
             * count 大于或等于 destsz ，但 destsz 小于或等于 strnlen_s(src, count) ，换言之，会出现截断
             * 源和目标字符串间会出现重叠

          若 dest 所指的字符数组大小 < strnlen_s(src, destsz) <= destsz 则行为未定义；换言之，错误的 destsz 值不暴露行将发生的缓冲区溢出。若 src 所指的字符数组大小 < strnlen_s(src, count) < destsz 则行为未定义；换言之，错误的 count 值不暴露行将发生的缓冲区溢出。

          同所有边界检查函数， strncpy_s 仅若实现定义 `__STDC_LIB_EXT1__` 且用户在包含 string.h 前定义 `__STDC_WANT_LIB_EXT1__` 为整数常量 1 才保证可用。
      * 参数：
        * dest - 指向要复制到的字符数组的指针
        * src - 指向复制来源的字符数组的指针
        * count - 要复制的最大字符数
        * destsz - 目标缓冲区的大小
      * 返回值：
        1. 返回 dest 的副本
        2. 成功时返回零，错误时返回非零。而且，在错误时写入零到 `dest[0]` （除非 dest 为空指针，或 destsz 为零或大于 RSIZE_MAX ），而且可能以未指定值破坏目标数组的剩余部分。
      * 注解：
        按 C11 后的 DR 468 更正， strncpy_s 不同于 strcpy_s ，仅若错误发生才被允许破坏目标数组的剩余部分。不同于 strncpy ， strncpy_s 不以零填充目标数组。这是转换既存代码到边界检查版本的常见错误源。尽管适合目标缓冲区的截断是安全风险，从而是 strncpy_s 的运行时制约违规，还是可通过指定 count 等于目标数组大小减一以获取截断行为：它会复制首 count 个字节，并照常添加空终止符： strncpy_s(dst, sizeof dst, src, (sizeof dst)-1);
      * **源代码**

        ```c
        char* strncpy(char* dest, const char* source, size_t count)
        {
            char* start=dest;
            while (count && (*dest++=*source++))
                count--;
            if(count)
                while (--count)
                    *dest++='\0';
            return(start);
        }
        ```

      * 示例

        ```c
        #define __STDC_WANT_LIB_EXT1__ 1
        #include <string.h>
        #include <stdio.h>
        #include <stdlib.h>
        
        int main(void)
        {
            char src[] = "hi";
            char dest[6] = "abcdef"; // 无空字符
            strncpy(dest, src, 5); // 写入五个字符 'h', 'i', '\0', '\0', '\0' 到 dest
            printf("strncpy(dest, src, 5) to a 6-byte dest gives : ");
            for(size_t n = 0; n < sizeof dest; ++n) {
                char c = dest[n];
                c ? printf("'%c' ", c) : printf("'\\0' ");
            }
        
            printf("\nstrncpy(dest2, src, 2) to a 2-byte dst gives : ");
            char dest2[2];
            strncpy(dest2, src, 2); // 截断：写入二个字符 'h', 'i', 到 dest2
            for (size_t n = 0; n < sizeof dest2; ++n) {
                char c = dest2[n];
                c ? printf("'%c' ", c) : printf("'\\0' ");
            }
            printf("\n");
        
        #ifdef __STDC_LIB_EXT1__
            set_constraint_handler_s(ignore_handler_s);
            char dst1[6], src1[100] = "hello";
            int r1 = strncpy_s(dst1, 6, src1, 100);      // 写入 0 到 r1 ， 6 个字符到 dst1
            printf("dst1 = \"%s\", r1 = %d\n", dst1,r1); // 'h','e','l','l','o','\0' 到 dst1
        
            char dst2[5], src2[7] = {'g','o','o','d','b','y','e'};
            int r2 = strncpy_s(dst2, 5, src2, 7);        // 复制溢出目标数组
            printf("dst2 = \"%s\", r2 = %d\n", dst2,r2); // 写入非零到 r2 ， '\0' 到 dst2[0]
        
            char dst3[5];
            int r3 = strncpy_s(dst3, 5, src2, 4);        // 写入 0 到 r3 ， 5 个字符到 dst3
            printf("dst3 = \"%s\", r3 = %d\n", dst3,r3); // 'g', 'o', 'o', 'd', '\0' 到 dst3 
        #endif
        }
        ```

        可能的输出：

        ```text
        strncpy(dest, src, 5) to a 6-byte dst gives : 'h' 'i' '\0' '\0' '\0' 'f'
        strncpy(dest2, src, 2) to a 2-byte dst gives : 'h' 'i'
        dst1 = "hello", r1 = 0
        dst2 = "", r2 = 22
        dst3 = "good", r3 = 0
        ```

#### strcmp函数———字符串比较函数

1. 一般形式：**strcmp(字符串1，字符串2)**
    * 将两个字符串自左向右逐个比较，直到出现不同字符或'\0'为止，字符全部相同则相等。
    * 以第一对不同字符比较结果为准，字母比较中，在英文字典中位置在后面的大，小写字母大于大写字母。
    * 比较结果由函数值带回，字符串1=字符串2，值为0；字符串1>字符串2，值为正整数；字符串1<字符串2，值为负整数。
2. 详细内容：
   1. 定义于头文件： `<string.h>`
   2. 函数原型：`int strcmp( const char *lhs, const char *rhs );`
   3. 功能：以字典序比较二个空终止字节字符串。结果的符号是被比较的字符串中首对不同字符（都转译成 unsigned char ）的值间的差的符号。若 lhs 或 rhs 不是指向空终止字节字符串的指针，则行为未定义。
   4. 参数：lhs, rhs - 指向要比较的空终止字节字符串的指针。
   5. 返回值：
      * 若字典序中 lhs 先出现于 rhs 则为负值。
      * 若 lhs 与 rhs 比较相等则为零。
      * 若字典序中 lhs 后出现于 rhs 则为正值。
   6. 注意:不同于 strcoll 和 strxfrm ，此函数不考虑本地环境。
   7. **源代码**：
      * Windows

      ```c
      int __cdecl strcmp (const char *src, const char *dst)
        {
                int ret = 0 ;
                while(!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst)
                {
                        ++src;
                        ++dst;
                }
                if ( ret < 0 )
                        ret = -1 ;
                else if ( ret > 0 )
                        ret = 1 ;
                return( ret );
        }
      ```

      * Linux

        ```c
        int strcmp( const char *src, const char *dst ) 
        {
            char *p = src;
            char *q = dst;
            while ( *p++ == *q++ ) 
            {
                if ( *p == 0 ) 
                {
                    return 0;
                }
            }
            return *p - *q;
        }
        ```

   8. 示例

        ```c
        #include <string.h>
        #include <stdio.h>
        
        void demo(const char* lhs, const char* rhs)
        {
            int rc = strcmp(lhs, rhs);
            const char *rel = rc < 0 ? "precedes" : rc > 0 ? "follows" : "equals";
            printf("[%s] %s [%s]\n", lhs, rel, rhs);
        }
        int main(void)
        {
            const char* string = "Hello World!";
            demo(string, "Hello!");
            demo(string, "Hello");
            demo(string, "Hello there");
            demo("Hello, everybody!" + 12, "Hello, somebody!" + 11);
        }
        ```

        输出：

        ```text
        [Hello World!] precedes [Hello!]
        [Hello World!] follows [Hello]
        [Hello World!] precedes [Hello there]
        [body!] equals [body!]
        ```

#### strlen函数————测试字符串长度的函数

1. 一般形式：**strlen(字符数组)**，函数的值为字符数组的实际长度（不包含'\0'）。
2. 详细内容：
   * 定义于头文件 `<string.h>`
   * 函数原型：
     * C11前：`size_t strlen( const char *str );`
     * C11起：`size_t strnlen_s( const char *str, size_t strsz );`
        说明：
        1. C11前，返回给定空终止字符串的长度，即首元素为 str 所指，且不包含首个空字符的字符数组中的字符数。若 str 不是指向空终止字节字符串的指针则行为未定义。
        2. C11起，同 (1) ，除了若 str 为空指针则返回零，而若在 str 的首 strsz 个字节找不到空字符则返回 strsz 。若 str 指向缺少空字符的字符数组且该字符数组的大小 < strsz 则行为未定义；换言之， strsz 的错误值不会暴露行将来临的缓冲区溢出。

        同所有边界检查函数， strnlen_s 仅若实现定义了 `__STDC_LIB_EXT1__` ，且用户在包含 `<string.h>` 前定义 `__STDC_WANT_LIB_EXT1__` 为整数常量 1 才保证可用。
   * 参数
     * str - 指向要检测的空终止字符串的指针
     * strsz - 要检测的最大字符数量
   * 返回值
     * 空终止字节字符串 str 的长度。
     * 成功时为空终止字节字符串 str 的长度，若 str 是空指针则为零，若找不到空字符则为 strsz 。
   * 注意
     strnlen_s 与 wcsnlen_s 是仅有的不调用运行时制约处理的边界检查函数。它们是用于提供空终止字符串受限制支持的纯功能函数。
   * **源代码**

     ```c
     size_t strlen_a(const char *str) 
     {  
        size_t length = 0;  
        while (*str++)  
            ++length;  
        return length;  
     }
     ```

   * 示例

     ```c
        #define __STDC_WANT_LIB_EXT1__ 1
        #include <string.h>
        #include <stdio.h>
        
        int main(void)
        {
            const char str[] = "How many characters does this string contain?";
        
            printf("without null character: %zu\n", strlen(str));
            printf("with null character:    %zu\n", sizeof str);
        
        #ifdef __STDC_LIB_EXT1__
            printf("without null character: %zu\n", strnlen_s(str, sizeof str));
        #endif
        }
     ```

     会输出

     ```text
      without null character: 45
      with null character:    46
      without null character: 45
     ```

#### strlwr函数————转换为小写的函数

1. 一般形式：strlwr(字符串)
2. 详细内容：

   * 原型：`extern char *strlwr(char *s)`;
   * 用法：`#include <string.h>`
   * 功能：将字符串s参数转换为小写形式,说明：只转换s参数中出现的大写字母，不改变其它字符。返回指向s参数的指针。
   * 兼容性说明：strlwr和strupr不是标准C库函数，只能在VC中使用。linux gcc环境下需要自行定义这个函数。
   * **源代码**：

     ```c
     extern "C" char * __cdecl _strlwr (char * string)
        {
            if (!__acrt_locale_changed())
            {
                char * cp;

                /* validation section */
                _VALIDATE_RETURN(string != nullptr, EINVAL, nullptr);

                for (cp=string; *cp; ++cp)
                {
                    if ('A' <= *cp && *cp <= 'Z')
                        *cp += 'a' - 'A';
                }

                return(string);
            }
            else
            {
                _strlwr_s_l(string, (size_t)(-1), nullptr);
                return string;
            }
        }
     ```

#### strupr函数————转换为大写的函数

1. 一般形式：strupr(字符串)
2. 详细内容：
   * 原型：`extern char *strupr(char *s);`
   * 用法：`#include <string.h>`
   * 功能：将字符串s转换为大写形式
   * 注意：不能使用常量指针作为参数
   * **源代码**：

     ```c
     extern "C" char * __cdecl _strlwr (
        char * string
        )
        {
            if (!__acrt_locale_changed())
            {
                char * cp;

                /* validation section */
                _VALIDATE_RETURN(string != nullptr, EINVAL, nullptr);

                for (cp=string; *cp; ++cp)
                {
                    if ('a' <= *cp && *cp <= 'z')
                        *cp += 'A' - 'a';
                }

                return(string);
            }
            else
            {
                _strlwr_s_l(string, (size_t)(-1), nullptr);
                return string;
            }
        }
     ```
