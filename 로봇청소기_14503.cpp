#include<stdio.h>
#define North 0
#define East 1
#define South 2
#define West 3

int n, m;
int start_x, start_y, start_dir;
int map[52][52];
int check[52][52];
int dx[5] = { -1,0,1,0 };
int dy[5] = { 0,1,0,-1 };
int result;


void solve(int x, int y, int dir) {
	if (map[x][y] == 0) {
		check[x][y] = 1;
		result++;
	}

	int new_x, new_y, new_dir;
	int now_x = x, now_y = y, now_dir = dir;
	int cnt = 0, no_way_check = 0;
	while (1) {
		new_dir = now_dir;
		cnt = 0; no_way_check = 0;
		do {
			new_dir = (new_dir + 3) % 4;
			new_x = now_x + dx[new_dir];
			new_y = now_y + dy[new_dir];
			cnt++;

			if (cnt == 5) {
				no_way_check = 1;
				break;
			}
			if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) {
				continue;
			}
		} while (check[new_x][new_y] != 0 || map[new_x][new_y] != 0);

		if (no_way_check == 0) {
			check[new_x][new_y] = 1;
			result++;
		}
		else {
			int opp_dir;
			opp_dir = (now_dir + 2) % 4;
			new_x = now_x + dx[opp_dir];
			new_y = now_y + dy[opp_dir];
			if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) {
				break;
			}
			if (map[new_x][new_y] == 1) {
				break;
			}
			if (check[new_x][new_y] == 0 && map[new_x][new_y] == 0) {
				check[new_x][new_y] = 1;
				result++;
			}
			new_dir = now_dir;
		}
		now_x = new_x; now_y = new_y; now_dir = new_dir;
	}
	

}

int main() {

	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &start_x, &start_y, &start_dir);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	solve(start_x, start_y, start_dir);

	printf("%d\n", result);
	
	return 0;
}