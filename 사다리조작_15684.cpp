#include<stdio.h>
#include<stdlib.h>

int n, m, h;
int map[32][12];
int return_check;

int check_result(){

	int check = 1;

	for (int i = 1; i <= n; i++){
		//map[1][i]에서 시작
		int state = i;
		for (int j = 1; j <= h; j++){
			if (map[j][state] == 1){
				if (state - 1 > 0){
					state--;
				}
			}
			else if (map[j][state + 1] == 1){
				if (state + 1 <= n){
					state++;
				}
			}
		}

		if (state != i){
			check = 0;
			return check;
		}
	}

	return check;
}
void make_ladder(int ladder_cnt, int cnt, int idx){
	if (cnt == ladder_cnt){
		return_check = check_result();

		if (return_check == 1){
			printf("%d\n", ladder_cnt);
			exit(0);
		}

		return;
	}

	for (int i = idx; i <= h; i++){
		for (int j = 1; j <= n; j++){
			if (map[i][j] == 0){
				if (map[i][j - 1] != 1 && map[i][j + 1] != 1){
					map[i][j] = 1;
					make_ladder(ladder_cnt, cnt + 1, i);
					map[i][j] = 0;
				}
			}
		}
	}
}

int main(){

	scanf("%d %d %d", &n, &m, &h);

	for (int i = 1; i <= m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][b + 1] = 1;
	}

	for (int i = 0; i <= 3; i++){
		make_ladder(i, 0, 1);
	}

	if (return_check == 0){
		printf("%d\n", -1);
	}

	return 0;
}