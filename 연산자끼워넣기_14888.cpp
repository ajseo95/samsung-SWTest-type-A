#include<stdio.h>
#include<algorithm>
#define MAX 987654321
using namespace std;

int n;
int num[13];
int operate_num[5];//+,-,*,/
int check[13];
int maxi = -MAX, mini = MAX;

void dfs(int cnt, int operate, int plus, int minus, int multi, int divide){
	check[cnt] = operate;

	if (cnt == n - 1){
		int temp_result = num[1];
		for (int i = 1; i <= n - 1; i++){
			if (check[i] == 1) temp_result += num[i + 1];
			else if (check[i] == 2) temp_result -= num[i + 1];
			else if (check[i] == 3) temp_result *= num[i + 1];
			else if (check[i] == 4) temp_result /= num[i + 1];
		}

		maxi = max(maxi, temp_result);
		mini = min(mini, temp_result);
		return;
	}

	for (int i = 1; i <= 4; i++){
		if (i == 1 && plus + 1 <= operate_num[1]) dfs(cnt + 1, i, plus + 1, minus, multi, divide);
		else if (i == 2 && minus + 1 <= operate_num[2]) dfs(cnt + 1, i, plus, minus + 1, multi, divide);
		else if (i == 3 && multi + 1 <= operate_num[3]) dfs(cnt + 1, i, plus, minus, multi + 1, divide);
		else if (i == 4 && divide + 1 <= operate_num[4]) dfs(cnt + 1, i, plus, minus, multi, divide + 1);
	}

}
int main(){

	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%d", &num[i]);
	}
	for (int i = 1; i <= 4; i++){
		scanf("%d", &operate_num[i]);
	}

	dfs(0, 0, 0, 0, 0, 0);

	printf("%d\n%d", maxi, mini);

	return 0;
}