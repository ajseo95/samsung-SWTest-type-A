#include<stdio.h>
#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4

int n, m, k;
int start_x, start_y;
int move[1002];
int map[22][22];
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };
int dice[7], temp_dice[7];

void move_dice(int dir){
	if (dir == EAST){
		temp_dice[1] = dice[4];
		temp_dice[2] = dice[2];
		temp_dice[3] = dice[1];
		temp_dice[4] = dice[6];
		temp_dice[5] = dice[5];
		temp_dice[6] = dice[3];
	}
	else if (dir == WEST){
		temp_dice[1] = dice[3];
		temp_dice[2] = dice[2];
		temp_dice[3] = dice[6];
		temp_dice[4] = dice[1];
		temp_dice[5] = dice[5];
		temp_dice[6] = dice[4];
	}
	else if (dir == SOUTH){
		temp_dice[1] = dice[2];
		temp_dice[2] = dice[6];
		temp_dice[3] = dice[3];
		temp_dice[4] = dice[4];
		temp_dice[5] = dice[1];
		temp_dice[6] = dice[5];
	}
	else if (dir == NORTH){
		temp_dice[1] = dice[5];
		temp_dice[2] = dice[1];
		temp_dice[3] = dice[3];
		temp_dice[4] = dice[4];
		temp_dice[5] = dice[6];
		temp_dice[6] = dice[2];
	}

	for (int i = 1; i <= 6; i++){
		dice[i] = temp_dice[i];
	}
}
void solve(){
	int x = start_x, y = start_y;
	for (int i = 0; i < k; i++){
		int dir = move[i];

		x = x + dx[dir];
		y = y + dy[dir];
		if (x<0 || x>=n || y<0 || y>=m){
			x -= dx[dir];
			y -= dy[dir];
			continue;
		}

		move_dice(dir);

		if (map[x][y] == 0){
			map[x][y] = dice[6];
		}
		else{
			dice[6] = map[x][y];
			map[x][y] = 0;
		}

		printf("%d\n", dice[1]);
	}
}
int main(){

	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &start_x, &start_y, &k);

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < k; i++){
		scanf("%d", &move[i]);
	}

	solve();

	return 0;
}