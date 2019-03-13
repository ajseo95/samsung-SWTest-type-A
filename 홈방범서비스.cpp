#include<stdio.h>
#include<algorithm>
using namespace std;

int test, n, m; //도시크기, 하나 집 지불 비용
int map[22][22];
int cost[22];
int cnt;
int result;

void is_range(int x, int dx, int y, int dy){
	int new_x = x + dx;
	int new_y = y + dy;
	if (new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= n){
		if (map[new_x][new_y] == 1){
			cnt++;
		}
	}
}

void check(int k){

	for (int x = 1; x <= n; x++){
		for (int y = 1; y <= n; y++){
			cnt = 0;

			//1사분면
			for (int dx = 0; dx <= k - 1; dx++){
				for (int dy = k - 1 - dx; dy >= 0; dy--){
					is_range(x, dx, y, dy);
				}
			}
			//2사분면
			for (int dx = 1 - k; dx <= 0; dx++){
				if (dx == 0) continue;
				for (int dy = k - 1 + dx; dy >= 0; dy--){
					is_range(x, dx, y, dy);
				}
			}
			//3사분면
			for (int dx = 1 - k; dx <= 0; dx++){
				if (dx == 0) continue;
				for (int dy = -(k - 1) - dx; dy <= 0; dy++){
					if (dy == 0) continue;
					is_range(x, dx, y, dy);
				}
			}
			//4사분면
			for (int dx = 0; dx <= k - 1; dx++){
				for (int dy = -(k - 1) + dx; dy <= 0; dy++){
					if (dy == 0) continue;
					is_range(x, dx, y, dy);
				}
			}

			int temp_cost = m * cnt;
			if (temp_cost >= cost[k]){
				result = max(result, cnt);
			}
		}
	}

	
}

int main(){

	for (int k = 1; k <= 21; k++){
		cost[k] = k*k + (k - 1)*(k - 1);
	}

	scanf("%d", &test);

	for (int t = 1; t <= test; t++){
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				scanf("%d", &map[i][j]);
			}
		}

		for (int k = 1; k <= n + 1; k++){
			check(k);
		}

		printf("#%d %d\n", t, result);

		//초기화
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				map[i][j] = 0;
			}
		}
		result = 0;
	}

	return 0;
}