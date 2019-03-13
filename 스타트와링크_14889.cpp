#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int n;
int arr[22][22];
int team[22];
int result = 987654321;

void dfs(int cnt,int idx){
	
	if (cnt == n / 2){
		int start_score = 0, link_score = 0;
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				if (team[i] == 0 && team[j] == 0){
					start_score += (arr[i][j] + arr[j][i]);
				}
				else if (team[i] == 1 && team[j] == 1){
					link_score += (arr[i][j] + arr[j][i]);
				}
			}
		}

		result = min(result, abs(start_score - link_score));
		return;
	}

	if (idx <= n){
		team[idx + 1] = 1;
		dfs(cnt + 1, idx + 1);
		team[idx + 1] = 0;
		dfs(cnt, idx + 1);
	}
	
}
int main(){

	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			scanf("%d", &arr[i][j]);
		}
	}

	dfs(0, 0);

	printf("%d", result);

	return 0;
}