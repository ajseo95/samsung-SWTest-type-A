#include<stdio.h>
#include<algorithm>
using namespace std;

int test;
int n, k;
int map[10][10];
int check[10][10];
struct start_state{
	int x;
	int y;
}start[6];
int result;
int dx[5] = { 1, 0, -1, 0 };
int dy[5] = { 0, 1, 0, -1 };

void solve(int x, int y, int cnt, int break_check){
	result = max(result, cnt);

	for (int i = 0; i < 4; i++){
		int new_x = x + dx[i];
		int new_y = y + dy[i];

		if (new_x<1 || new_x>n || new_y<1 || new_y>n) continue;

		if (map[new_x][new_y] < map[x][y] && check[new_x][new_y] == 0){
			check[new_x][new_y] = 1;
			solve(new_x, new_y, cnt + 1, break_check);
			check[new_x][new_y] = 0;
		}
		else if (map[new_x][new_y] - k < map[x][y] && check[new_x][new_y] == 0 && break_check == 0){
			check[new_x][new_y] = 1;
			int temp_val = map[new_x][new_y];
			map[new_x][new_y] = map[x][y] - 1;
			solve(new_x, new_y, cnt + 1, 1);
			check[new_x][new_y] = 0;
			map[new_x][new_y] = temp_val;
		}
	}
}

int main(){
	
	scanf("%d", &test);

	for (int t = 1; t <= test; t++){
		scanf("%d %d", &n, &k);

		int start_height = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				scanf("%d", &map[i][j]);
				start_height = max(start_height, map[i][j]);
			}
		}

		int start_cnt = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (map[i][j] == start_height){
					start_cnt++;
					start[start_cnt].x = i;
					start[start_cnt].y = j;
				}
			}
		}

		for (int i = 1; i <= start_cnt; i++){
			check[start[i].x][start[i].y] = 1;
			solve(start[i].x, start[i].y, 1, 0);
			check[start[i].x][start[i].y] = 0;
		}
		
		printf("#%d %d\n", t, result);
		//ÃÊ±âÈ­
		result = 0;
	}
	return 0;
}