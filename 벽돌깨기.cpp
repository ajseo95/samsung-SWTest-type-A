#include<stdio.h>
#include<algorithm>
#include<vector>
#define MAX 987654321
using namespace std;

int test;
int n, w, h;
int map[17][17];
int init_map[17][17];
int check[17][17];
int check_next[17][17];
int result = MAX;
int dx[5] = { 1, 0, -1, 0 };
int dy[5] = { 0, 1, 0, -1 };

int get_highest(int width_idx){
	for (int i = 1; i <= h; i++){
		if (map[i][width_idx] != 0) return i;
	}

	return 0;
}
void make_init_map(){
	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++){
			map[i][j] = init_map[i][j];
		}
	}
}
void down_ball(){
	vector<int> v;

	for (int j = 1; j <= w; j++){
		for (int i = h; i >= 1; i--){
			if (map[i][j] != 0) v.push_back(map[i][j]);
		}
		int cnt = 0;
		for (int i = h; i >= 1; i--){
			if (cnt < v.size()){
				map[i][j] = v[cnt++];
			}
			else{
				map[i][j] = 0;
			}
		}
		v.clear();
	}

}
int drop_related_ball(){
	int remain = 0;

	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++){
			check[i][j] = check_next[i][j];
			check_next[i][j] = 0;
		}
	}

	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++){
			if (check[i][j] == 1){

				int range = map[i][j];
				map[i][j] = 0;
				if (range > 1){
					for (int l = 0; l < 4; l++){
						for (int r = 1; r < range; r++){
							int x = i + r*dx[l];
							int y = j + r*dy[l];

							if (x<1 || x>h || y<1 || y>w) break;
							if (map[x][y] <= 1) map[x][y] = 0;
							else{
								check_next[x][y] = 1;
								remain = 1;
							}
						}
					}
				}
			}
		}
	}

	return remain;

}
void drop_ball(int width_idx){

	int height_idx = get_highest(width_idx);
	int remain = 0;

	if (height_idx != 0){
		int range = map[height_idx][width_idx];
		map[height_idx][width_idx] = 0;

		if (range > 1){
			for (int i = 0; i < 4; i++){
				for (int r = 1; r < range; r++){
					int x = height_idx + r*dx[i];
					int y = width_idx + r*dy[i];

					if (x<1 || x>h || y<1 || y>w) break;
					if (map[x][y] <= 1) map[x][y] = 0;
					else{
						check_next[x][y] = 1;
						remain = 1;
					}
				}
			}

			while (remain){
				remain = drop_related_ball();
			}
		}

	}

}
void solve(){
	int ball[4];
	for (ball[0] = 1; ball[0] <= w; ball[0]++){
		for (ball[1] = 1; ball[1] <= w; ball[1]++){
			for (ball[2] = 1; ball[2] <= w; ball[2]++){
				for (ball[3] = 1; ball[3] <= w; ball[3]++){
					make_init_map();

					for (int i = 0; i < n; i++){
						drop_ball(ball[i]);
						down_ball();
					}

					int cnt = 0;
					for (int i = 1; i <= h; i++){
						for (int j = 1; j <= w; j++){
							if (map[i][j] != 0)cnt++;
						}
					}

					result = min(result, cnt);

					if (n < 4) break;
				}
				if (n < 3) break;
			}
			if (n < 2) break;
		}
	}
}
int main(){

	scanf("%d", &test);

	for (int t = 1; t <= test; t++){
		scanf("%d %d %d", &n, &w, &h);

		for (int i = 1; i <= h; i++){
			for (int j = 1; j <= w; j++){
				scanf("%d", &map[i][j]);
				init_map[i][j] = map[i][j];
			}
		}

		solve();

		printf("#%d %d\n", t, result);

		result = MAX;
	}

	return 0;
}