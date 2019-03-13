#include<stdio.h>
#include<algorithm>
#define MAX 987654321
using namespace std;

int n, m;
int map[10][10];
int init_map[10][10];
struct cctv{
	int x;
	int y;
	int num;
};
struct cctv tvpos[10];
int cnt; //cctv개수
int dx[6] = { 0, 1, 0, -1, 0 };
int dy[6] = { 0, 0, -1, 0, 1 };
int check_rotate[10];
int result = MAX;

void initialize_map(){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			map[i][j] = init_map[i][j];
		}
	}
}
void solve(){
	initialize_map();

	for (int i = 1; i <= cnt; i++){
		int num = tvpos[i].num;
		int x = tvpos[i].x;
		int y = tvpos[i].y;
		int dir = check_rotate[i];

		if (num == 1){
			while (1){
				x = x + dx[dir];
				y = y + dy[dir];
				if (x<1 || x>n || y<1 || y>m) break;

				if (map[x][y] == 6) break;
				else if (map[x][y] == 0) map[x][y] = -1;
			}
		}
		else if (num == 2){
			for (int d = dir; d <= dir + 2; d+=2){
				int new_x = x, new_y = y;
				while (1){
					if (d >= 5){
						new_x = new_x + dx[d%4];
						new_y = new_y + dy[d%4];
					}
					else{
						new_x = new_x + dx[d];
						new_y = new_y + dy[d];
					}

					if (new_x<1 || new_x>n || new_y<1 || new_y>m) break;
					if (map[new_x][new_y] == 6) break;
					else if (map[new_x][new_y] == 0) map[new_x][new_y] = -1;
				}
			}
		}
		else if (num == 3){
			for (int d = dir; d <= dir + 1; d++){
				int new_x = x, new_y = y;
				while (1){
					if (d >= 5){
						new_x = new_x + dx[d%4];
						new_y = new_y + dy[d%4];
					}
					else{
						new_x = new_x + dx[d];
						new_y = new_y + dy[d];
					}

					if (new_x<1 || new_x>n || new_y<1 || new_y>m) break;
					if (map[new_x][new_y] == 6) break;
					else if (map[new_x][new_y] == 0) map[new_x][new_y] = -1;
				}
			}
		}
		else if (num == 4){
			for (int d = dir + 1; d <= dir + 3; d++){
				int new_x = x, new_y = y;
				while (1){
					if (d >= 5){
						new_x = new_x + dx[d%4];
						new_y = new_y + dy[d%4];
					}
					else{
						new_x = new_x + dx[d];
						new_y = new_y + dy[d];
					}
					if (new_x<1 || new_x>n || new_y<1 || new_y>m) break;
					if (map[new_x][new_y] == 6) break;
					else if (map[new_x][new_y] == 0) map[new_x][new_y] = -1;
				}
			}
		}
		else if (num == 5){
			for (int d = 1; d <= 4; d++){
				int new_x = x, new_y = y;
				while (1){
					new_x = new_x + dx[d];
					new_y = new_y + dy[d];
					if (new_x<1 || new_x>n || new_y<1 || new_y>m) break;
					if (map[new_x][new_y] == 6) break;
					else if (map[new_x][new_y] == 0) map[new_x][new_y] = -1;
				}
			}
		}
	}

	//result 구하기
	int temp = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (map[i][j] == 0) temp++;
		}
	}

	result = min(result, temp);
}
void dfs(int all_cnt, int dir){
	check_rotate[all_cnt] = dir;

	if (all_cnt == cnt){
		solve();
		return;
	}

	for (int i = 1; i <= 4; i++){
		dfs(all_cnt + 1, i);
	}
}
int main(){

	scanf("%d %d", &n, &m);

	cnt = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			scanf("%d", &map[i][j]);
			init_map[i][j] = map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5){
				cnt++;
				tvpos[cnt].num = map[i][j];
				tvpos[cnt].x = i;
				tvpos[cnt].y = j;
			}
		}
	}

	if (cnt > 0){
		for (int i = 1; i <= 4; i++){
			dfs(1, i);
		}
	}
	else{
		int temp = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if (map[i][j] == 0) temp++;
			}
		}
		result = min(result, temp);
	}

	printf("%d\n", result);
	
	return 0;
}