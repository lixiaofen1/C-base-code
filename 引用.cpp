/**********************
 * 将变量作为实参
 * 
 * ******************/

#include <iostream>
using namespace std;
void swap1(int a,int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    int i = 3,j = 5;
    swap1(i,j);
    cout<<i<<","<<j<<endl;
    return 0;
}

/***************
 * 传递变量的指针
 * 
 * **************/
#include<iostream>
using namespace std;
void swap2(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    //int *j = 3;*i = 5;指针可以这样赋值吗
    int i = 3,j = 5;
    swap2(&i,&j);
    cout << i <<","<<j<<endl;
    return 0;
}

/****************
 *传递变量别名
 * 
 *  **************/
#include <iostream>
using namespace std;
void swap3(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int i = 3,j = 5;
    swap3(i,j);
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
 *      建立指针变量的引用
 *      int i = 5;
 *      int *p = &i;
 *      int* &pt = p;
 * 
 * 4、使用const对引用加以限定，不允许改变该引用的值
 *      int i = 5;
 *      const int &a = i;
 *      a = 3;(不合法)
 *      i= 3；（合法）
 * 
 * 5、可以用常量或表达式对引用进行初始化，但此时必须用const作声明：
 *      int i = 5;
 *      const &a = i + 3;
 *      此时编译系统这样处理：生成一个临时变量，用来存放该表达式的值，引用是该临时变量的别名，系统
 *      将“const &a = i +3;”转换为：
 *      int temp = i+ 3;
 *      const int &a = temp;
 * 
 *      使用不同的变量初始化引用（要求赋值兼容的类型）
 *      double d = 3.1415926;
 *      const int &a = d;   //使用d初始化a
 *      
 *      编译系统将const int &a = d;转化为
 *      int temp = d;   //先将double类型变量d转换为int型，存放在temp中
 *      const int &a = temp;    //temp和a同类型
 *      此时如果输出引用a的值，将是3而不是3.1415926。因为从根本上说，只能对变量建立引用。
 *      如果上面声明时不同const，则会发生错误。如果不加const，则引用a的值则可以更改，导致临时变量temp的
 *      值同时发生更改，而变量d的值并没有变。会存在二义性。
 * 
 *      加上引用const就像时主从的关系，值的变化只能从主变量向下流，不能从引用向上流。有一个方向
 * *******/