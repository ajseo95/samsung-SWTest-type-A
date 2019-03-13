#include<stdio.h>
#include<math.h>
#include<algorithm>
#define MAX 987654321
using namespace std;

int n, m;
int map[52][52];
struct state{
	int x;
	int y;
};
struct state chicken[14];
struct state house[260];
int check[14];
int chic_cnt;
int house_cnt;
int result = MAX;

void dfs(int cnt, int idx){

	if (cnt == m){	
		int temp_result = 0;

		for (int i = 1; i <= house_cnt; i++){
			int shortest = MAX;
			for (int j = 1; j <= chic_cnt; j++){
				if (check[j] == 1){
					int dist = abs(house[i].x - chicken[j].x) + abs(house[i].y - chicken[j].y);
					shortest = min(shortest, dist);
				}
			}
			temp_result += shortest;
		}

		result = min(result, temp_result);
		return;
	}

	if (idx <= chic_cnt){
		if (check[idx] == 0){
			check[idx] = 1;
			dfs(cnt + 1, idx + 1);
			check[idx] = 0;
		}
		dfs(cnt, idx + 1);
	}
}
int main(){

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1){
				house_cnt++;
				house[house_cnt].x = i;
				house[house_cnt].y = j;
			}
			else if (map[i][j] == 2){
				chic_cnt++;
				chicken[chic_cnt].x = i;
				chicken[chic_cnt].y = j;
			}
		}
	}

	dfs(0, 1);

	printf("%d\n", result);

	return 0;
}