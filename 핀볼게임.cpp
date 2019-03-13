#include<stdio.h>
#include<algorithm>
using namespace std;

int test;
int n;
int map[102][102];
struct state{
	int x;
	int y;
};
struct state wormhole[11][2];
int dx[5] = { 1, 0, -1, 0 };
int dy[5] = { 0, -1, 0, 1 };
int result;

void solve(){

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			int start_x = i;
			int start_y = j;
			if (map[start_x][start_y] == 0){
				for (int sd = 0; sd < 4; sd++){//출발 진행 방향

					int x = start_x, y = start_y;
					int dir = sd;
					int cnt = 0;

					while (1){
						
						while (1){
							x = x + dx[dir];
							y = y + dy[dir];

							if (map[x][y] != 0) break;
							if (x == start_x && y == start_y) break;
							
							if (x<1 || x>n || y<1 || y>n){
								if (x<1 || x>n) x -= dx[dir];
								if (y<1 || y>n) y -= dy[dir];
								cnt++;
								dir = (dir + 2) % 4;
								break;
							}
						}

						if (map[x][y] == -1) break;
						if (x == start_x && y == start_y) break;
						
						if (map[x][y] == 1){
							cnt++;
							if (dir == 0) dir = 3;
							else if (dir == 1) dir = 2;
							else if (dir == 2 || dir == 3) dir = (dir + 2) % 4;
						}
						else if (map[x][y] == 2){
							cnt++;
							if (dir == 1) dir = 0;
							else if (dir == 2) dir = 3;
							else if (dir == 0 || dir == 3) dir = (dir + 2) % 4;
						}
						else if (map[x][y] == 3){
							cnt++;
							if (dir == 2) dir = 1;
							else if (dir == 3) dir = 0;
							else if (dir == 0 || dir == 1) dir = (dir + 2) % 4;
						}
						else if (map[x][y] == 4){
							cnt++;
							if (dir == 0) dir = 1;
							else if (dir == 3) dir = 2;
							else if (dir == 1 || dir == 2) dir = (dir + 2) % 4;
						}
						else if (map[x][y] == 5){
							cnt++;
							dir = (dir + 2) % 4;
						}
						else if (map[x][y] >= 6 && map[x][y] <= 10){
							int wormnum = map[x][y];
							if (wormhole[wormnum][0].x == x && wormhole[wormnum][0].y == y){
								x = wormhole[wormnum][1].x;
								y = wormhole[wormnum][1].y;
							}
							else{
								x = wormhole[wormnum][0].x;
								y = wormhole[wormnum][0].y;
							}
						}
						
					}

					result = max(result, cnt);

				}
			}
		}
	}
}
int main(){

	scanf("%d", &test);

	for (int t = 1; t <= test; t++){
		scanf("%d", &n);

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				scanf("%d", &map[i][j]);
				if (map[i][j] >= 6 && map[i][j] <= 10){
					if (wormhole[map[i][j]][0].x == 0 && wormhole[map[i][j]][0].y == 0){
						wormhole[map[i][j]][0].x = i;
						wormhole[map[i][j]][0].y = j;
					}
					else{
						wormhole[map[i][j]][1].x = i;
						wormhole[map[i][j]][1].y = j;
					}
				}
				//블랙홀은 -1
			}
		}

		solve();

		printf("#%d %d\n", t, result);

		for (int i = 6; i <= 10; i++){
			wormhole[i][0].x = 0;
			wormhole[i][0].y = 0;
			wormhole[i][1].x = 0;
			wormhole[i][1].y = 0;
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				map[i][j] = 0;
			}
		}

		result = 0;

	}

	return 0;
}