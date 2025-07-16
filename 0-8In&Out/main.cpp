#include <stdio.h>

/// printf()
///核心定义与用途
///定义： __builtin_va_list 是一个编译器内置的类型，表示可变参数列表的指针。
/// 在标准库 <stdarg.h> 中， va_list 通常定义为 __builtin_va_list 的别名 [^1]。
///用途：用于声明一个指针，指向函数调用时传入的可变参数列表的起始位置。
/// 例如： void my_printf(const char* format, ...)
/// { __builtin_va_list args; va_start(args, format);初始化args，指向format后的第一个可变参数
///  通过va_arg(args, type)逐个提取参数 va_end(args); // 清理工作 }



int main(void)
{

#if 0 ///字符输入输出    getchar() & putchar() 函数
    ///int getchar(void) 函数从屏幕读取下一个可用的字符，并把它返回为一个整数。
    ///这个函数在同一个时间内只会读取一个单一的字符。可在循环内使用这个方法，从屏幕上读取多个字符。
    ///int putchar(int c) 函数把字符输出到屏幕上，并返回相同的字符。
    /// 这个函数在同一个时间内只会输出一个单一的字符。可在循环内使用这个方法，在屏幕上输出多个字符。



        int c;

        printf( "Enter a value :");
        c = getchar( );  ///从缓冲区拿走一个字符

        printf( "\nYou entered: ");
        putchar( c );
        printf( "\n");

#endif

#if 1 ///字符串输入输出  gets() 和 fgets() 函数
      ///gets() 函数用于从标准输入设备读取一行字符串，但不推荐使用，因为它容易导致缓冲区溢出，推荐使用 fgets() 函数。
      ///char *fgets(char *str, int n, FILE *stream);
        /*
         * str：指向字符数组的指针，用于存储读取的字符串。
         * n：要读取的最大字符数（包括空字符\0）。
         * stream：文件流，通常使用stdin表示标准输入。
         * */

        char str[100];
        printf("Enter a string: ");
        fgets(str, sizeof(str), stdin);
        printf("You entered: %s", str);

        ///puts() 函数
        ///puts() 函数用于将一个字符串输出到标准输出设备，并自动在末尾添加换行符。
        ///int puts(const char *str);
        char str2[] = "Hello, World!";
    char *str3 = "Hello, World!";
        puts(str2);
        fputs(str2, stdout);  // 输出 "Hello, World!"，不换行
        ///fputs() 函数
        ///fputs() 函数用于将字符串输出到指定的流（如标准输出、文件等），但不会自动在字符串末尾添加换行符。
        ///int fputs(const char *str, FILE *stream);
        ///不添加换行符：fputs() 不会在输出字符串后自动添加换行符。
        ///灵活的输出流：fputs() 可以输出到任意流，如标准输出、文件等。
#endif


#if 1  ///文件输入与输出
       ///fopen() 函数
       ///fopen() 函数用于打开一个文件。
       ///FILE *fopen(const char *filename, const char *mode);
        FILE *file;
        file = fopen("example.txt", "w");  // 打开文件用于写入
        if (file != NULL) {
            fprintf(file, "being a hunter\n");  // 写入文件
            fclose(file);  // 关闭文件
        }

        char buffer[100];
        file = fopen("example.txt", "r");  // 打开文件用于读取
        if (file != NULL) {
            fscanf(file, "%s", buffer);  // 读取数据
            printf("Read from file: %s\n", buffer);
            fclose(file);  // 关闭文件
        }

#endif

    return 0;
}
