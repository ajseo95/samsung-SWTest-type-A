#define INF 987654321
#include<stdio.h>
#include<algorithm>
using namespace std;

int test;
int n;
int cal_cnt[5]; // +,-,*,/
int num[14];
int maxi = -INF;
int mini = INF;

//대입할 때 cnt = 2부터, result = num[1]
void dfs(int cnt, int result){
	if (cnt == n + 1){
		//연산 최대,최솟값 갱신
		maxi = max(result, maxi);
		mini = min(result, mini);
		return;
	}

	for (int i = 1; i <= 4; i++){
		if (cal_cnt[i] <= 0) continue;
		cal_cnt[i]--;
		if (i == 1){
			dfs(cnt + 1, result + num[cnt]);
		}
		else if (i == 2){
			dfs(cnt + 1, result - num[cnt]);
		}
		else if (i == 3){
			dfs(cnt + 1, result*num[cnt]);
		}
		else if (i == 4){
			dfs(cnt + 1, result/num[cnt]);
		}
		cal_cnt[i]++;
	}
}


int main(){

	scanf("%d", &test);

	for (int t = 1; t <= test; t++){
		scanf("%d", &n);

		for (int i = 1; i <= 4; i++){
			scanf("%d", &cal_cnt[i]);
		}

		for (int i = 1; i <= n; i++){
			scanf("%d", &num[i]);
		}

		dfs(2, num[1]);

		printf("#%d %d\n", t, maxi - mini);

		maxi = -INF;
		mini = INF;
	
	}
	return 0;
}