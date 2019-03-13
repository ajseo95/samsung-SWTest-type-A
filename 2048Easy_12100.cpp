#include<stdio.h>
#include<algorithm>
using namespace std;

int n;
int map[22][22];
int init_map[22][22];
int check[22][22];
int move_dir[6];
int dx[5] = { -1, 1, 0, 0 }; //위, 아래, 오, 왼
int dy[5] = { 0, 0, 1, -1 };
int result;

void move_board(int dir){
	if (dir == 0){//up
		for (int j = 1; j <= n; j++){
			for (int i = 2; i <= n; i++){
				for (int x = i - 1; x >= 1; x--){
					if (map[x][j] == 0) {
						map[x][j] = map[x + 1][j];
						map[x + 1][j] = 0;
						check[x][j] = check[x + 1][j];
						check[x + 1][j] = 0;
					}
					else if(map[x][j] == map[x + 1][j] && check[x][j] == 0 && check[x + 1][j] == 0){
						map[x][j] += map[x][j];
						map[x + 1][j] = 0;
						check[x][j] = 1;
						check[x + 1][j] = 0;
					}
					else break;
				}
			}
		}
	}

	else if (dir == 1){//down
		for (int j = 1; j <= n; j++){
			for (int i = n - 1; i >= 1; i--){
				for (int x = i + 1; x <= n; x++){
					if (map[x][j] == 0) {
						map[x][j] = map[x - 1][j];
						map[x - 1][j] = 0;
						check[x][j] = check[x - 1][j];
						check[x - 1][j] = 0;
					}
					else if (map[x][j] == map[x - 1][j] && check[x][j] == 0 && check[x - 1][j] == 0){
						map[x][j] += map[x][j];
						map[x - 1][j] = 0;
						check[x][j] = 1;
						check[x - 1][j] = 0;
					}
					else break;
				}
			}
		}
	}

	else if (dir == 2){//right
		for (int i = 1; i <= n; i++){
			for (int j = n - 1; j >= 1; j--){
				for (int y = j + 1; y <= n; y++){
					if (map[i][y] == 0) {
						map[i][y] = map[i][y - 1];
						map[i][y - 1] = 0;
						check[i][y] = check[i][y - 1];
						check[i][y - 1] = 0;
					}
					else if (map[i][y] == map[i][y - 1] && check[i][y] == 0 && check[i][y - 1] == 0){
						map[i][y] += map[i][y];
						map[i][y - 1] = 0;
						check[i][y] = 1;
						check[i][y - 1] = 0;
					}
					else break;
				}
			}
		}
	}

	else if (dir == 3){//left
		for (int i = 1; i <= n; i++){
			for (int j = 2; j <= n; j++){
				for (int y = j - 1; y >= 1; y--){
					if (map[i][y] == 0) {
						map[i][y] = map[i][y + 1];
						map[i][y + 1] = 0;
						check[i][y] = check[i][y + 1];
						check[i][y + 1] = 0;
					}
					else if (map[i][y] == map[i][y + 1] && check[i][y] == 0 && check[i][y + 1] == 0){
						map[i][y] += map[i][y];
						map[i][y + 1] = 0;
						check[i][y] = 1;
						check[i][y + 1] = 0;
					}
					else break;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			check[i][j] = 0;
		}
	}


}
void dfs(int cnt, int dir){
	move_dir[cnt] = dir;

	if (cnt == 5){
		//move에 쓰인대로 옮기기
		for (int i = 1; i <= 5; i++){
			move_board(move_dir[i]);
		}
		//최대 찾기
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				result = max(result, map[i][j]);
			}
		}
		//init_map
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				map[i][j] = init_map[i][j];
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++){
		dfs(cnt + 1, i);
	}

}
int main(){

	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			scanf("%d", &map[i][j]);
			init_map[i][j] = map[i][j];
		}
	}

	dfs(0, 0);

	printf("%d\n", result);


	return 0;
}