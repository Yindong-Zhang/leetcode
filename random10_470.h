//
// Created by so_go on 2020/3/12.
//
/*
 * 470. 用 Rand7() 实现 Rand10()

已有方法 rand7 可生成 1 到 7 范围内的均匀随机整数，试写一个方法 rand10 生成 1 到 10 范围内的均匀随机整数。

不要使用系统的 Math.random() 方法。



示例 1:

输入: 1
输出: [7]

示例 2:

输入: 2
输出: [8,4]

示例 3:

输入: 3
输出: [8,1,10]

 */
#ifndef SRC_RANDOM10_470_H
#define SRC_RANDOM10_470_H
// The rand7() API is already defined for you.
 int rand7();
 //@return a random integer in the range 1 to 7

class Rand10 {
public:
    int rand10() {

        int i, j;
        while(true){
            i = rand7() - 1;
            j = rand7();
            int m = i * 7 + j;
            if(m > 40){
                continue;
            }
            else{
                return m % 10 + 1;
            }
        }
    }
};
#endif //SRC_RANDOM10_470_H
