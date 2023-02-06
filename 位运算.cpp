#include"headFile.h"

// �������32λ�����еĽϴ�ֵ��Ҫ��ʹ�ñȽ����� 
class GetMax {
public:
    // n����0����1
    // n��1������0
    // n��0������1
    int flip(int n) {
        return n ^ 1;
    }
    // n�ǷǸ��� ����1
    // n�Ǹ��� ����0
    // ����31λ �õ�����λ���Ǹ���Ϊ0 ����Ϊ1
    int sign(int n) {
        return flip((n >> 31) & 1);
    }
    int getMax1(int a, int b) {
        int c = a - b;
        int scA = sign(c); // a-bΪ�Ǹ���scAΪ1��a-bΪ����scAΪ0
        int scB = flip(scA); // scAΪ1��scBΪ0��scAΪ0��scBΪ1
        return a * scA + b * scB;
    }
    int getMax2(int a, int b) {
        int c = a - b;
        int sa = sign(a);
        int sb = sign(b);
        int sc = sign(c);
        int difSab = sa ^ sb; // a��b������ͬΪ0
        int sameSab = flip(difSab); // a��b������ͬΪ1
        int returnA = difSab * sa + sameSab * sc;
        int returnB = flip(returnA);
        return a * returnA + b * returnB;
    }
};

// �ж�һ��32λ�����ǲ���2���ݡ�4����
// 2���ݣ���������ֻ��һ��λ��1
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

// ��ʹ�����������ʵ���������ļӼ��˳�
class AddMinusMultiDivide {
public:
    int add(int a, int b) { // �޽�λʱ ���ؽ��
        int sum = a;
        while (b != 0) { // 
            sum = a ^ b; // �޽�λ��ӵĽ��
            b = (a & b) << 1; // ��λ��Ϣ
            a = sum;
        }
        return sum;
    }
    int negNum(int n) {
        return add(~n, 1); // ȡ���ټ�1����෴��
    }
    int minus(int a, int b) {
        return add(a, negNum(b)); // a����b���෴��
    }

    int multi(int a, int b) {
        
    }
};