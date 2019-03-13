#include<stdio.h>
#include<math.h>

int test;
int k;
int mag[5][10];
int idx[5][10];
int check[5];
int dir[5];
int num, std_dir;
int score;

int main(){

	scanf("%d", &test);

	for (int t = 1; t <= test; t++){
		scanf("%d", &k);

		for (int i = 1; i <= 4; i++){
			for (int j = 1; j <= 8; j++){
				scanf("%d", &mag[i][j]);
				idx[i][j] = j;
			}
		}

		for (int cir = 1; cir <= k; cir++){
			scanf("%d %d", &num, &std_dir);

			//각 자석이 돌아가야 할 방향 저장
			dir[num] = std_dir;
			if (num == 1){
				dir[2] = -std_dir; dir[4] = -std_dir;
				dir[3] = std_dir;
			}
			else if (num == 2){
				dir[1] = -std_dir; dir[3] = -std_dir;
				dir[4] = std_dir;
			}
			else if (num == 3){
				dir[2] = -std_dir; dir[4] = -std_dir;
				dir[1] = std_dir;
			}
			else{
				dir[1] = -std_dir; dir[3] = -std_dir;
				dir[2] = std_dir;
			}

			//같은 극 확인 -> 돌아갈 자석?
			int idx_left = 0, idx_right = 0;
			check[num] = 1;
			for (int i = num; i <= 3; i++){
				for (int j = 1; j <= 8; j++){
					if (idx[i][j] == 3) idx_left = j;
					if (idx[i + 1][j] == 7) idx_right = j;
				}

				if (mag[i][idx_left] != mag[i + 1][idx_right]){
					check[i + 1] = 1;
				}
				else{
					break;
				}
			}

			for(int i = num; i >= 2; i--){
				for (int j = 1; j <= 8; j++){
					if (idx[i][j] == 7) idx_right = j;
					if (idx[i - 1][j] == 3) idx_left = j;
				}

				if (mag[i - 1][idx_left] != mag[i][idx_right]){
					check[i - 1] = 1;
				}
				else{
					break;
				}
			}


			//돌리기
			for (int i = 1; i <= 4; i++){
				for (int j = 1; j <= 8; j++){
					if (dir[i] == -1 && check[i] == 1){
						if (idx[i][j] - 1 > 0) idx[i][j] = idx[i][j] - 1;
						else idx[i][j] = 8;
					}
					else if(dir[i] == 1 && check[i] == 1){
						if (idx[i][j] + 1 <= 8) idx[i][j] = idx[i][j] + 1;
						else idx[i][j] = 1;
					}
				}
			}

			//check 초기화
			//dir 초기화
			for (int i = 0; i <= 4; i++){
				check[i] = 0;
				dir[i] = 0;
			}

		
		}


		//다 돌린 후 점수 계산
		int score_idx = 0;
		for (int i = 1; i <= 4; i++){
			for (int j = 1; j <= 8; j++){
				if (idx[i][j] == 1) score_idx = j;
			}
			if (mag[i][score_idx] == 1){
				if (i == 1){
					score += 1;
				}
				else if(i == 2){
					score += 2;
				}
				else if (i == 3){
					score += 4;
				}
				else if (i == 4){
					score += 8;
				}
			}
		}

		printf("#%d %d\n", t, score);

		score = 0;

	}

	return 0;
}