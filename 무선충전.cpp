#include<stdio.h>
#include<vector>
#include<algorithm>
#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4
using namespace std;

int test;
int m, num;
int way1[102];
int way2[102];
vector<int> map[11][11];
int charge_perf[10];
int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };
int sum_a = 0, sum_b = 0;

void charge_range(int x, int y, int c, int chargenum){

	for (int i = 0; i <= c; i++){
		int new_x = x + i;
		for (int j = i - c; j <= c - i; j++){
			int new_y = y + j;
			if (new_x >= 1 && new_x <= 10 && new_y >= 1 && new_y <= 10){
				map[new_x][new_y].push_back(chargenum);
			}
		}
	}
	for (int i = -c; i < 0; i++){
		int new_x = x + i;
		for (int j = -c - i; j <= c + i; j++){
			int new_y = y + j;
			if (new_x >= 1 && new_x <= 10 && new_y >= 1 && new_y <= 10){
				map[new_x][new_y].push_back(chargenum);
			}
		}
	}
}
void solve(int m){
	//전체 초 돌림
	//각 초마다 몇 번꺼 쓸 건지 선택
	//최댓값
	int ax = 1, ay = 1;
	int bx = 10, by = 10;

	for (int t = 0; t <= m; t++){
		ax = ax + dx[way1[t]];
		ay = ay + dy[way1[t]];
		bx = bx + dx[way2[t]];
		by = by + dy[way2[t]];

		if (map[ax][ay].size() == 0 && map[bx][by].size() != 0){
			int temp_b = 0;
			for (int j = 0; j < map[bx][by].size(); j++){
				int tb = 0;
				tb = charge_perf[map[bx][by][j]];
				temp_b = max(temp_b, tb);
			}
			sum_b += temp_b;
		}

		else if (map[ax][ay].size() != 0 && map[bx][by].size() == 0){
			int temp_a = 0;
			for (int i = 0; i < map[ax][ay].size(); i++){
				int ta = 0;
				ta = charge_perf[map[ax][ay][i]];
				temp_a = max(temp_a, ta);
			}
			sum_a += temp_a;
		}

		else{
			int temp_a = 0, temp_b = 0;

			for (int i = 0; i < map[ax][ay].size(); i++){
				for (int j = 0; j < map[bx][by].size(); j++){
					int ta, tb;
					ta = charge_perf[map[ax][ay][i]];
					tb = charge_perf[map[bx][by][j]];

					if (map[ax][ay][i] == map[bx][by][j]){
						ta /= 2;
						tb /= 2;
					}
					if (ta + tb > temp_a + temp_b){
						temp_a = ta; temp_b = tb;
					}
				}
			}

			sum_a += temp_a; sum_b += temp_b;
		}
		
	}
}
int main(){

	scanf("%d", &test);

	for (int t = 1; t <= test; t++){
		scanf("%d %d", &m, &num);

		for (int i = 1; i <= m; i++){
			scanf("%d", &way1[i]);
		}
		for (int i = 1; i <= m; i++){
			scanf("%d", &way2[i]);
		}

		int x, y, c, p;
		for (int i = 1; i <= num; i++){
			scanf("%d %d %d %d", &y, &x, &c, &p);
			charge_range(x, y, c, i);
			charge_perf[i] = p;
		}

		solve(m);

		printf("#%d %d\n", t, sum_a + sum_b);

		for (int i = 1; i <= 10; i++){
			for (int j = 1; j <= 10; j++){
				if (map[i][j].size() != 0){
					map[i][j].clear();
				}
			}
		}

		for (int i = 1; i <= num; i++){
			charge_perf[i] = 0;
		}
		sum_a = 0; sum_b = 0;
		
	}

	return 0;
}