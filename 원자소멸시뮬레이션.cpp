#include<stdio.h>
#include<vector>
using namespace std;

int test;
int n;
int check[4004][4004];
struct atom_info{
	int x; int y;
	int dir;
	int energy;
}atom[1002];
int atom_cnt;
int dx[5] = { 0, 0, -1, 1 };
int dy[5] = { 1, -1, 0, 0 };
int result;

void solve(){
	
	while (1){
		int remove_cnt = 0;
		vector <int> collide;

		for (int i = 1; i <= atom_cnt; i++){
			int x = atom[i].x;
			int y = atom[i].y;
			int dir = atom[i].dir;
			int energy = atom[i].energy;
			if (energy == -1){
				remove_cnt++;
				continue; //이미 충돌되어 없어진 것 -1로
			}

			int new_x = x + dx[dir];
			int new_y = y + dy[dir];

			if (new_x < 0 || new_x > 4000 || new_y < 0 || new_y > 4000){
				atom[i].energy = -1;
				continue;
			}

			if (check[new_x][new_y] == 0){
				check[new_x][new_y] = i;
				atom[i].x = new_x;
				atom[i].y = new_y;
			}
			else{
				//충돌
				if (check[new_x][new_y] != -1){
					collide.push_back(check[new_x][new_y]);
				}
				collide.push_back(i);
				check[new_x][new_y] = -1;
			}
		}

		if (remove_cnt == atom_cnt) break;

		//충돌 제거
		for (int i = 0; i < collide.size(); i++){
			int atom_num = collide[i];
			result += atom[atom_num].energy;
			atom[atom_num].energy = -1;
		}
		collide.clear();
		//check 초기화
		for (int i = 1; i <= atom_cnt; i++){
			check[atom[i].x][atom[i].y] = 0;
		}
	}

	
}
int main(){

	scanf("%d", &test);

	for (int t = 1; t <= test; t++){
		scanf("%d", &n);

		int mid = 2000;
		for (int i = 1; i <= n; i++){
			int x, y, dir, k;
			scanf("%d %d %d %d", &x, &y, &dir, &k);
			atom_cnt++;
			x = mid + 2 * x;
			y = mid + 2 * y;
			atom[atom_cnt] = { x, y, dir, k };
		}

		solve();

		printf("#%d %d\n", t, result);

		//초기화
		atom_cnt = 0;
		result = 0;
	}

	return 0;
}