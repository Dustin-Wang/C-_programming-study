#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <list>
#include <map>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class person {
public:
    person(){
        cout<<"Person无参构造函数的调用"<<endl;
    }
    person(int a, int b) {
    cout << "Person有参构造函数的调用" << endl;
    mage = a;
    // *mheight = b;
    mheight = b;
    }

    person(const person& p) {
        cout << "拷贝构造函数!" << endl;
        mage = p.mage;
        mheight = p.mage;
    }
    ~person() {//析构函数不可以用参数{
    cout << "Person析构函数的调用" << endl;
}
    int mage;
    // int* mheight;
    int mheight;
};
void test()
{
    person p1(10, 2566);
    person p2 = p1;
    cout << p2.mage << " " << p2.mheight << endl;
}
int main() {
    test();
    // system("pause");
    return 0;
}