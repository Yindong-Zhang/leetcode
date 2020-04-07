//
// Created by so_go on 2020/4/5.
//
/*
 * 1114. 按序打印

我们提供了一个类：

public class Foo {
  public void one() { print("one"); }
  public void two() { print("two"); }
  public void three() { print("three"); }
}

三个不同的线程将会共用一个 Foo 实例。

    线程 A 将会调用 one() 方法
    线程 B 将会调用 two() 方法
    线程 C 将会调用 three() 方法

请设计修改程序，以确保 two() 方法在 one() 方法之后被执行，three() 方法在 two() 方法之后被执行。



示例 1:

输入: [1,2,3]
输出: "onetwothree"
解释:
有三个线程会被异步启动。
输入 [1,2,3] 表示线程 A 将会调用 one() 方法，线程 B 将会调用 two() 方法，线程 C 将会调用 three() 方法。
正确的输出是 "onetwothree"。

示例 2:

输入: [1,3,2]
输出: "onetwothree"
解释:
输入 [1,3,2] 表示线程 A 将会调用 one() 方法，线程 B 将会调用 three() 方法，线程 C 将会调用 two() 方法。
正确的输出是 "onetwothree"。



注意:

尽管输入中的数字似乎暗示了顺序，但是我们并不保证线程在操作系统中的调度顺序。

你看到的输入格式主要是为了确保测试的全面性。

 */
#ifndef SRC_PRINTINORDER_1114_H
#define SRC_PRINTINORDER_1114_H
// 应用信号量实现线程同步
#include<semaphore.h>
#include<bits/stdc++.h>
using namespace std;
class Foo {
private:
    sem_t firstJobDone, secondJobDone;
public:
    Foo() {
        sem_init(&firstJobDone, 0, 0);
        sem_init(&secondJobDone, 0, 0);
    }

    void first(function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&firstJobDone);
    }

    void second(function<void()> printSecond) {

        // printSecond() outputs "second". Do not change or remove this line.
        sem_wait(&firstJobDone);
        printSecond();
        sem_post(&secondJobDone);
    }

    void third(function<void()> printThird) {

        // printThird() outputs "third". Do not change or remove this line.
        sem_wait(&secondJobDone);
        printThird();
    }
};

#endif //SRC_PRINTINORDER_1114_H
