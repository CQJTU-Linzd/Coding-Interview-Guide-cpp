#include"headFile.h"

// 求出两个32位整数中的较大值，要求不使用比较运算 
class GetMax {
public:
    // n不是0就是1
    // n是1，返回0
    // n是0，返回1
    int flip(int n) {
        return n ^ 1;
    }
    // n是非负数 返回1
    // n是负数 返回0
    // 右移31位 得到符号位：非负数为0 负数为1
    int sign(int n) {
        return flip((n >> 31) & 1);
    }
    int getMax1(int a, int b) {
        int c = a - b;
        int scA = sign(c); // a-b为非负，scA为1；a-b为负，scA为0
        int scB = flip(scA); // scA为1，scB为0；scA为0，scB为1
        return a * scA + b * scB;
    }
    int getMax2(int a, int b) {
        int c = a - b;
        int sa = sign(a);
        int sb = sign(b);
        int sc = sign(c);
        int difSab = sa ^ sb; // a和b符号相同为0
        int sameSab = flip(difSab); // a和b符号相同为1
        int returnA = difSab * sa + sameSab * sc;
        int returnB = flip(returnA);
        return a * returnA + b * returnB;
    }
};

// 判断一个32位正数是不是2的幂、4的幂
// 2的幂：二进制中只有一个位是1
class Power {
public:
    bool is2Power(int n) {
        return (n & (n - 1)) == 0;
    }
    bool is4Power(int n) {
                                   // ...01010101
        return is2Power(n) && (n & 0x55555555) != 0;
    }
};

// 不使用算术运算符实现两个数的加减乘除
class AddMinusMultiDivide {
public:
    int add(int a, int b) { // 无进位时 返回结果
        int sum = a;
        while (b != 0) { // 
            sum = a ^ b; // 无进位相加的结果
            b = (a & b) << 1; // 进位信息
            a = sum;
        }
        return sum;
    }
    int negNum(int n) {
        return add(~n, 1); // 取反再加1获得相反数
    }
    int minus(int a, int b) {
        return add(a, negNum(b)); // a加上b的相反数
    }

    int multi(int a, int b) {
        
    }
};