#include<stdio.h>
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

struct node{
	int cnt;
	int dir;
	int max_cnt;
};
int test;
int n, m, k; //셀 수,격리시간, 미생물 개수
node map[102][102];
node new_map[102][102];
int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };

int main(){

	scanf("%d", &test);

	for (int t = 1; t <= test; t++){
		scanf("%d %d %d", &n, &m, &k);

		int x, y, num, dir;
		for (int i = 0; i < k; i++){
			scanf("%d %d %d %d", &x, &y, &num, &dir);
			map[x][y].cnt = num;
			map[x][y].dir = dir;
			map[x][y].max_cnt = num;
		}

		while (m > 0){
			m--;
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					if (map[i][j].cnt != 0){
						int new_x = i + dx[map[i][j].dir];
						int new_y = j + dy[map[i][j].dir];
						if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n){
							continue;
						}
						
						if (new_map[new_x][new_y].cnt != 0){
							new_map[new_x][new_y].cnt += map[i][j].cnt;
							if (new_map[new_x][new_y].max_cnt < map[i][j].max_cnt){
								new_map[new_x][new_y].dir = map[i][j].dir;
								new_map[new_x][new_y].max_cnt = map[i][j].max_cnt;
							}
						}
						else{
							new_map[new_x][new_y].cnt = map[i][j].cnt;
							new_map[new_x][new_y].dir = map[i][j].dir;
							new_map[new_x][new_y].max_cnt = map[i][j].max_cnt;
						}

						if (new_x == 0 || new_x == n - 1 || new_y == 0 || new_y == n - 1){
							new_map[new_x][new_y].cnt = map[i][j].cnt / 2;
							new_map[new_x][new_y].max_cnt = new_map[new_x][new_y].cnt;

							if (map[i][j].dir == LEFT){
								new_map[new_x][new_y].dir = RIGHT;
							}
							else if (map[i][j].dir == RIGHT){
								new_map[new_x][new_y].dir = LEFT;
							}
							else if (map[i][j].dir == UP){
								new_map[new_x][new_y].dir = DOWN;
							}
							else if (map[i][j].dir == DOWN){
								new_map[new_x][new_y].dir = UP;
							}
						}

						
					}
				}
			}


			//new_map을 map에 옮기고 new_map초기화
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					map[i][j].cnt = new_map[i][j].cnt;
					map[i][j].dir = new_map[i][j].dir;
					map[i][j].max_cnt = new_map[i][j].cnt;
					new_map[i][j].cnt = 0;
					new_map[i][j].dir = 0;
					new_map[i][j].max_cnt = 0;
				}
			}
		}

		int sum = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				sum += map[i][j].cnt;
			}
		}
		printf("#%d %d\n", t, sum);

		//map, new_map 초기화
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= n; j++){
				map[i][j].cnt = 0;
				map[i][j].dir = 0;
				map[i][j].max_cnt = 0;
				new_map[i][j].cnt = 0;
				new_map[i][j].dir = 0;
				new_map[i][j].max_cnt = 0;
			}
		}
	}

	return 0;
}