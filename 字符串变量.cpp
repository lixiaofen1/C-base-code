/***********
 * 特性：
 * 1、和char字符的比较
 *      char buf[128] = "hello world";
 *      string buf = "hello world";
 *      字符常量以'\0'作为结束符，但是将字符串常量存放到字符串变量中时，只存放字符串本身而不包括'\0'。因此
 *      字符串buf中只有字符”hello world“而没有尾零
 * 
 * 
 * 2、字符串的输入输出
 *      cin>>string1;
 *      cout<<strinig1;
 *      可以直接用来运算而不用借助其他拷贝函数
 * 
 * 3、字符串变量的运算
 *      可以直接将字符串变量拼接在一起
 *      string string1 = "hello";
 *      string string2 = "world";
 *      string string3 = string1 + string2;
 * 
 * 4、字符串数组
 *      string name[5];
 *      string name[5] = {"zhang","liu","hua","wang","tan"};
 **********/