#define INF 987654321
#include<stdio.h>
#include<algorithm>
using namespace std;

int test;
int n;
int arr[18][18];
int check[18];
int result = INF;

//Ã³À½ cnt´Â 1
void dfs(int all_cnt, int cnt){

	if (all_cnt == n){
		int taste1 = 0, taste2 = 0;
		
		for (int k = 1; k <= n; k++){
			for (int j = k + 1; j <= n; j++){
				if (check[k] == 1 && check[j] == 1){
					taste1 = taste1 + arr[k][j] + arr[j][k];
				}
				else if (check[k] == 0 && check[j] == 0){
					taste2 = taste2 + arr[k][j] + arr[j][k];
				}
			}
		}
			

		result = min(result, abs(taste1 - taste2));
		return;
	}

	if (cnt <= n / 2){
		check[all_cnt] = 1;
		dfs(all_cnt + 1, cnt + 1);
		check[all_cnt] = 0;
	}

	dfs(all_cnt + 1, cnt);
		
}

int main(){
	
	scanf("%d", &test);

	for (int t = 1; t <= test; t++){
		scanf("%d", &n);

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				scanf("%d", &arr[i][j]);
			}
		}

		dfs(0, 0);
		
		printf("#%d %d\n", t, result);

		for (int i = 1; i <= n; i++){
			check[i] = 0;
		}
		result = INF;
		
	}

	return 0;
}