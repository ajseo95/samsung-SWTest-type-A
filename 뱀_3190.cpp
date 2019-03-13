#include<stdio.h>

int n, k, l;
int map[102][102];
char time_dir[10002];
int snake[10002][2];
int dx[5] = { 0, 1, 0, -1 };
int dy[5] = { 1, 0, -1, 0 };

int solve(){
	int time = 0;
	int dir = 0;
	int x = 1, y = 1;
	map[1][1] = 1;
	int end = 0, head = 0;
	snake[0][0] = x; snake[0][1] = y;

	while (1){
		time++;
		x = x + dx[dir];
		y = y + dy[dir];

		if (map[x][y] == 1) break;
		if (x < 1 || x > n || y < 1 || y > n) break;

		if (map[x][y] == 2){
			map[x][y] = 1;
			head++;
			snake[head][0] = x;
			snake[head][1] = y;
		}
		else if (map[x][y] == 0){
			map[x][y] = 1;
			head++;
			snake[head][0] = x;
			snake[head][1] = y;
			//²¿¸® ¿Å±â±â
			map[snake[end][0]][snake[end][1]] = 0;
			end++;
		}

		if (time_dir[time] == 'L'){
			if (dir == 0) dir = 3;
			else{
				dir--;
			}
		}
		else if (time_dir[time] == 'D'){
			dir = (dir + 1) % 4;
		}
		
	}

	return time;
}
int main(){

	scanf("%d", &n);

	scanf("%d", &k);
	for (int i = 0; i < k; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		map[x][y] = 2;
	}

	scanf("%d", &l);
	for (int i = 0; i < l; i++){
		int X; char c;
		scanf("%d %c", &X, &c);
		time_dir[X] = c;
	}

	int result = solve();
	printf("%d", result);

	return 0;
}