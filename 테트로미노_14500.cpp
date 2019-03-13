#include<stdio.h>
#include<algorithm>
using namespace std;

int n, m;
int map[502][502];
int dx[5] = { 0, 1, 0, -1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };
pair<int,int> check[4];
int result;
int dir_exception[4][4] = { { 1, 2, 3 }, { 1, 2, 4 }, { 1, 3, 4 }, { 2, 3, 4 } };

int alreadyExist(int x, int y, int cnt){
	for (int i = 1; i <= cnt; i++){
		if (check[i].first == x && check[i].second == y){
			return 1;
		}
	}

	return 0;
}
void dfs(int cnt, int x, int y){

	if (cnt == 4){
		int sum = 0;
		for (int i = 1; i <= 4; i++){
			sum += map[check[i].first][check[i].second];
		}

		result = max(result, sum);

		return;
	}

	for (int i = 1; i <= 4; i++){

		int new_x = x + dx[i];
		int new_y = y + dy[i];

		if (new_x<1 || new_x>n || new_y<1 || new_y>m) continue;
		if (alreadyExist(new_x, new_y, cnt) == 1) continue;

		check[cnt + 1].first = new_x; check[cnt + 1].second = new_y;
		dfs(cnt + 1, new_x, new_y);
		check[cnt + 1].first = 0; check[cnt + 1].second = 0;
		
	}
	
}
void exception_case(int x, int y){
	for (int i = 0; i < 4; i++){
		int sum = map[x][y];
		for (int j = 0; j < 3; j++){
			int new_x = x + dx[dir_exception[i][j]];
			int new_y = y + dy[dir_exception[i][j]];

			if (new_x<1 || new_x>n || new_y<1 || new_y>m) break;

			sum += map[new_x][new_y];
		}

		result = max(result, sum);
	}
	
}
int main(){

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			scanf("%d", &map[i][j]);
		}
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			check[1].first = i; check[1].second = j;
			dfs(1, i, j);
			exception_case(i, j);
		}
	}

	printf("%d\n", result);
	
	return 0;
}