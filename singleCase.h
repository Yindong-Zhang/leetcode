//
// Created by so_go on 2020/4/21.
//

#ifndef SRC_SINGLECASE_H
#define SRC_SINGLECASE_H
#include<bits/stdc++.h>
using namespace std;
class Singleton{
private:
    Singleton(); // 构造函数私有
    Singleton(const Singleton &t); // 复制构造函数私有化，
    Singleton& operator=(const Singleton &t); // 私有赋值运算, 重载幅值运算符，返回自身
    static Singleton *ptr;
public:
    static Singleton * getInstance(){
        if(ptr == NULL){
            return new Singleton();
        }
        return ptr;
    }
};

Singleton * Singleton::ptr = NULL;
Singleton::Singleton() {

};
Singleton::Singleton(const Singleton &t) {};
Singleton& Singleton::operator=(const Singleton &t){};

#endif //SRC_SINGLECASE_H
