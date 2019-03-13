#include<stdio.h>
#include<algorithm>
using namespace std;

#define RightHigh 0
#define RightDown 1
#define HighBack 2
#define DownBack 3

int test;
int n;
int map[22][22];
int dx[4] = { -1, 1, 1, -1 };
int dy[4] = { 1, 1, -1, -1 };
int check[101];
int result;

void solve(int x, int y){
	
	for (int i = 1; i < n - 1; i++){
		for (int j = 1; j < n - 1; j++){

			for (int k = 1; k <= 100; k++){
				check[k] = 0;
			}

			int ax, ay, bx, by, cx, cy, ex, ey;
			for (int a = 1; a <= i; a++){
				ax = x + a*dx[RightHigh];
				ay = y + a*dy[RightHigh];
				if (ax >= 1 && ax <= n && ay >= 1 && ay <= n){
					check[map[ax][ay]] = 1;
				}
				else{
					break;
				}
			}
			for (int b = 1; b <= j; b++){
				bx = ax + b*dx[RightDown];
				by = ay + b*dy[RightDown];
				if (bx >= 1 && bx <= n && by >= 1 && by <= n){
					check[map[bx][by]] = 1;
				}
				else{
					break;
				}
			}
			for (int c = 1; c <= i; c++){
				cx = bx + c*dx[HighBack];
				cy = by + c*dy[HighBack];
				if (cx >= 1 && cx <= n && cy >= 1 && cy <= n){
					check[map[cx][cy]] = 1;
				}
				else{
					break;
				}
			}
			for (int e = 1; e <= j; e++){
				ex = cx + e*dx[DownBack];
				ey = cy + e*dy[DownBack];
				if (ex >= 1 && ex <= n && ey >= 1 && ey <= n){
					check[map[ex][ey]] = 1;
				}
				else{
					break;
				}
			}

			int cnt = 0;
			for (int k = 1; k <= 100; k++){
				if (check[k] == 1) cnt++;
			}
			if (cnt == 2*(i + j)){
				result = max(result, cnt);
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
			}
		}

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				check[map[i][j]] = 1;
				solve(i, j);
			}
		}

		if (result != 0){
			printf("#%d %d\n", t, result);
		}
		else{
			printf("#%d %d\n", t, -1);
		}
		
		result = 0;
	}

	return 0;
}