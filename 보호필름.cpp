#include<stdio.h>

int test;
int d, w, k;
int film[15][22];
int change[15];
int film_init[15][22];
int pass;

void film_initialize(){
	for (int i = 1; i <= d; i++){
		for (int j = 1; j <= w; j++){
			film[i][j] = film_init[i][j];
		}
	}
}
int check_pass(){
	int pass_available = 1;

	for (int j = 1; j <= w; j++){
		int temp_num = 1;
		int before_film;
		int k_check = 0;
		for (int i = 2; i <= d; i++){
			before_film = film[i - 1][j];
			if (film[i][j] == before_film){
				temp_num++;
			}
			else temp_num = 1;
			if (temp_num >= k){
				k_check = 1;
			}
		}

		if (k_check == 0){
			pass_available = 0;
			break;
		}
	}

	return pass_available;
}
void change_film(int change_num, int cnt, int idx){
	if (pass == 1){
		return;
	}
	if (change_num == cnt){

		for (int i = 1; i <= d; i++){
			if (change[i] == 1){
				for (int j = 1; j <= w; j++){
					film[i][j] = 0;
				}
			}
			else if (change[i] == 2){
				for (int j = 1; j <= w; j++){
					film[i][j] = 1;
				}
			}
		}
		pass = check_pass();

		film_initialize();
		return;
	}
	

	if (idx < d){
		change[idx + 1] = 1; //A·Î¹Ù²Ş
		change_film(change_num, cnt + 1, idx + 1);
		change[idx + 1] = 0;
		change[idx + 1] = 2; //B·Î¹Ù²Ş
		change_film(change_num, cnt + 1, idx + 1);
		change[idx + 1] = 0;
		change_film(change_num, cnt, idx + 1);
	}

}

int main(){

	scanf("%d", &test);

	for (int t = 1; t <= test; t++){

		scanf("%d %d %d", &d, &w, &k);

		for (int i = 1; i <= d; i++){
			for (int j = 1; j <= w; j++){
				scanf("%d", &film[i][j]);
				film_init[i][j] = film[i][j];
			}
		}

		for (int i = 0; i <= d; i++){
			change_film(i, 0, 0);
			if (pass == 1){
				printf("#%d %d\n", t, i);
				break;
			}
		}

		//ÃÊ±âÈ­
		pass = 0;
		for (int i = 1; i <= d; i++){
			change[i] = 0;
		}
	}

	return 0;
}