#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
int map[10][10];
int init_map[10][10];
struct state{
	int x;
	int y;
};
struct state void_loc[64];
int void_cnt;
struct state virus_loc[12];
int virus_cnt;
int dx[5] = { 1, 0, -1, 0 };
int dy[5] = { 0, 1, 0, -1 };
int result;

void map_initialize(){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			map[i][j] = init_map[i][j];
		}
	}
}
void solve(){
	queue<struct state> que;
	for (int i = 1; i <= virus_cnt; i++){
		que.push({ virus_loc[i].x, virus_loc[i].y });
	}
		
	while (!que.empty()){
		int x = que.front().x;
		int y = que.front().y;
		que.pop();

		for (int j = 0; j < 4; j++){
			int new_x = x + dx[j];
			int new_y = y + dy[j];

			if (new_x < 1 || new_x > n || new_y < 1 || new_y > m) continue;

			if (map[new_x][new_y] == 0){
				map[new_x][new_y] = 2;
				que.push({ new_x, new_y });
			}
		}
	}

	int temp_cnt = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (map[i][j] == 0) temp_cnt++;
		}
	}

	result = max(result, temp_cnt);
}
void make_wall(int cnt, int idx){
	if (cnt == 3){
		solve();
		map_initialize();
		return;
	}

	if(idx < void_cnt){
		int x = void_loc[idx + 1].x;
		int y = void_loc[idx + 1].y;

		map[x][y] = 1; init_map[x][y] = 1;
		make_wall(cnt + 1, idx + 1);
		map[x][y] = 0; init_map[x][y] = 0;

		make_wall(cnt, idx + 1);
	}
	
}

int main(){

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			scanf("%d", &map[i][j]);
			init_map[i][j] = map[i][j];
			if (map[i][j] == 0){
				void_cnt++;
				void_loc[void_cnt].x = i; void_loc[void_cnt].y = j;
			}
			if (map[i][j] == 2){
				virus_cnt++;
				virus_loc[virus_cnt].x = i; virus_loc[virus_cnt].y = j;
			}
		}
	}

	make_wall(0, 0);
	
	printf("%d\n", result);


	return 0;
}