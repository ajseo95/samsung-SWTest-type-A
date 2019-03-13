#include<stdio.h>
#include<algorithm>
using namespace std;

int test;
int n, m, k;
struct state{
	int life;
	int birth;
	int active_check;
	int death_check;
};
struct state map[700][700];
int dx[5] = { 1, 0, -1, 0 };
int dy[5] = { 0, 1, 0, -1 };
int result;
int mid = 300;

void solve(){
	for (int t = 1; t <= k; t++){
		for (int i = mid - t; i <= mid + t + 50; i++){
			for (int j = mid - t; j <= mid + t + 50; j++){
				if (map[i][j].life > 0 && map[i][j].death_check == 0){
					if (map[i][j].active_check == 1 && map[i][j].death_check == 0){
						for (int l = 0; l < 4; l++){
							int x = i + dx[l];
							int y = j + dy[l];

							if (x < 0 || x>700 || y < 0 || y>700) continue;

							if (map[x][y].life == 0){
								map[x][y].birth = t;
								map[x][y].life = map[i][j].life;
								map[x][y].active_check = 0;
								map[x][y].death_check = 0;
							}
							else if (map[x][y].life != 0 && map[x][y].birth == t){
								map[x][y].life = max(map[i][j].life, map[x][y].life);
							}
						}
					}

					if ((map[i][j].birth + map[i][j].life) == t){
						map[i][j].active_check = 1;
					}
					else if ((map[i][j].birth + (2 * map[i][j].life)) == t){
						map[i][j].death_check = 1;
					}

				}
			}
		}
	}
}
void find(){
	for (int i = mid - k; i <= mid + k + 50; i++){
		for (int j = mid - k; j <= mid + k + 50; j++){
			if (map[i][j].life > 0 && map[i][j].death_check == 0){
				result++;
			}
		}
	}
}
int main(){

	scanf("%d", &test);

	for (int t = 1; t <= test; t++){
		scanf("%d %d %d", &n, &m, &k);

		for (int i = mid; i < mid + n; i++){
			for (int j = mid; j < mid + m; j++){
				scanf("%d", &map[i][j].life);
				map[i][j].birth = 0;
				map[i][j].death_check = 0;
				map[i][j].active_check = 0;
			}
		}

		solve();
		find();

		printf("#%d %d\n", t, result);

		result = 0;
		for (int i = mid - k; i <= mid + k + 50; i++){
			for (int j = mid - k; j <= mid + k + 50; j++){
				map[i][j].life = 0;
				map[i][j].birth = 0;
				map[i][j].active_check = 0;
				map[i][j].death_check = 0;
			}
		}

	}

	return 0;
}