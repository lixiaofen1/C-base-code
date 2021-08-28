/**********************
 * 将变量作为实参
 * 
 * ******************/

#include <iostream>
using namespace std;
void swap(int a,int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    int i = 3,j = 5;
    swap(i,j);
    cout<<i<<","<<j<<endl;
    return 0;
}

/***************
 * 传递变量的指针
 * 
 * **************/
#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    //int *j = 3;*i = 5;指针可以这样赋值吗
    int i = 3,j = 5;
    swap(&i,&j);
    cout << i <<","<<j<<endl;
    return 0;
}

/****************
 *传递变量别名
 * 
 *  **************/
#include <iostream>
using namespace std;
swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int i = 3,j = 5;
    swap(i,j);
    return 0;
}

/****************
 * *int 指针的初始化与赋值
int类型的指针使用需要初始化，不然会段错误。字符串常量传递的是它的首地址。
int *num;
*num = 10;
这样的写法是错误的，因为指针num没有地址，是导致段错误。
需要int *num;
int a = 10;
num = &a;
num =20;
这样才ok.对于字符串，在C语言里面，没有总体处理一个字符串的机制
字符串传递的是字符串的首地址，
char *str;
str = "hello world!";
这样；
但是*str = "hello world!"是错误的写法

但是可以这样
int text(int *p)
{
  *p = 10;
}
* ********************/

/**********
 * 关于引用的细节
 * 1、不能建立void类型
 * void &b = a;
 * 因为任何实际存在的变量都是属于非void类型，void的含义时无类型或空类型
 * 
 * 2、不能建立引用的数组
 * char c[6] = "hello";
 * char &rc[6] = c;
 * 数组名c只是代表数组首地址元素的地址，本身并不是一个占有存储空间的变量
 * 
 * 3、引用就相当于变量本身
 *      int &b = a;(b此时相当于a)
 *      int *p  =&b;（相当于 int *p = &a;）
 * 
 *      
 * *******/