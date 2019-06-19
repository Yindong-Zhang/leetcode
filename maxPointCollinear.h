//
// Created by so_go on 2019/6/19.
//

#ifndef SRC_MAXPOINTCOLLINEAR_H
#define SRC_MAXPOINTCOLLINEAR_H
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


class maxPointsCollinear {
public:
    vector<int> calculateSlope(vector<int> p1, vector<int> p2){
        int dx, dy, dd;
        dx = p2[0] - p1[0];
        dy = p2[1] - p1[1];
        dd = __gcd(dx, dy);
//        cout << dx << ' ' << dy << ' ' << dd << endl;
        return vector<int>{dx / dd, dy / dd};
    }
    // 用分数保存斜率！！！
    int maxPoints(vector<vector<int>>& points) {
        int nPoints = points.size();
        if(nPoints == 0){
            return 0;
        }
//        cout << "num of Points: " << nPoints << endl;
        vector<vector<float >> m(nPoints, vector<float>(nPoints, 0));
        map<vector<int>, int> count;
        vector<int> slope;
        int max = 0, curMax = 0;
        int duplicate = 0;
        auto ptr = count.end();
        int i = 0, j = 0;
        for(i = 0; i < points.size(); i++){
            count.clear();
            curMax = 0;
            duplicate = 0;
            for(int j = 0; j < nPoints; j++){
                if(points[i] != points[j]){
                    slope = calculateSlope(points[i], points[j]);
//                cout << m[i][j] << ' ';
                    ptr = count.find(slope);
                    if(ptr == count.end()){
                        count.insert({slope, 1});
                    }
                    else{
                        ptr->second++;
                    }

                }
                else{
                    duplicate++;
                }
            }
//            cout << endl;
            for(auto ptr = count.begin(); ptr != count.end(); ptr++){
                if(ptr->second > curMax){
                    curMax = ptr->second;
                }
            }
            curMax += duplicate;
            if(curMax > max){
//                cout << curMax << endl;
                max = curMax;
            }
        }
        return max;
    }
};
#endif //SRC_MAXPOINTCOLLINEAR_H
