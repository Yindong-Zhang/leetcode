/*
 * superEggDrop.h
 *
 *  Created on: 2019年4月6日
 *      Author: yindong
 */

#ifndef SUPEREGGDROP_H_
#define SUPEREGGDROP_H_

#include<cmath>
#include<climits>
using namespace std;

class SuperEggDropSolution {
public:
	bool judge(int d, int k, int N)
	{
		double item = 1, sum = 0;
//		cout << '\t' << d << '\t';
		for(int i = 1; i <= k && i <= d; i++){
			item *= (d - i + 1);
			item /= i;
//			cout << item << '\t' ;
			sum += item;
		}
//		cout << sum << endl;
		if(sum >= N)
			return true;
		else
			return false;
	}

	int superEggDrop(int K, int N){
		int up = N, low = 1, med = 0;
		while (low < up){
//			cout << low << '\t' << up << endl;
			med = ( up + low ) / 2;
			if (judge(med, K, N))
				up = med;
			else
				low = med + 1;
		}

		return low;
	}
	/* bad solution...
    int superEggDrop(int K, int N) {
    	N = N + 1;
    	int threshold = floor(log2(N));
    	if ( K >= threshold )
    		return ceil( log2(N) );
    	else
    		return floor( N / exp2( K -1 ) ) + K - 2;
    }
*/

	/*
	 * Solution exceed time limit.

	int superEggDrop(int K, int N){
		int F[10001][101]= {{ -1 }};

		for (int j = 0; j <= K; j ++ )
		{
			F[0][j] = 0;
			F[1][j] = 1;
		}

		for(int i = 0; i <= N ; i ++ )
		{
			F[i][0] = INT_MIN;
			F[i][1] = i;
		}

		for ( int j = 2; j <= K; j++)
			for ( int i = 2; i <= N; i++)
			{
				int min = INT_MAX;
				int a, b, bad_ass;
				for(int k = 1; k <= i ; k++ )
				{
					a = F[k - 1][j - 1], b = F[i - k][j];
					bad_ass = a > b ? a : b;
					if (bad_ass < min)
						min = bad_ass;
				}
				F[i][j] = min + 1;
			}

		for(int j = 0; j <= K; j++)
		{
			for(int i = 0; i <= N; i++)
				cout << F[i][j] << '\t';
			cout << endl;
		}

		return F[N][K];
	}

	int F(int K, int N){
		if ( K == 1 )
			return N;
		int min = -1;
		for( int i = 1 ; i <= N ; i ++ )
		{
			int a = F( i - 1, K - 1);
			int b = F( N - i, K );
			int tmp =  a > b ? a : b;
			if ( tmp < min )
				min = tmp;
		}

		int res = 1 + min;
		return res;
	}
	*/
};



#endif /* SUPEREGGDROP_H_ */
