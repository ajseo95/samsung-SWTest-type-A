#include<stdio.h>

int n;
int student[1000002];
int all_num, sub_num;
long long int result;

void solve(){
	for (int i = 1; i <= n; i++){
		if (student[i] < 0) continue;
		if (student[i] % sub_num == 0){
			result += student[i]/sub_num;
		}
		else{
			result += (student[i]/sub_num) + 1;
		}
	}
}
int main(){

	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%d", &student[i]);
	}

	scanf("%d %d", &all_num, &sub_num);

	for (int i = 1; i <= n; i++){
		student[i] -= all_num;
		result++;
	}

	solve();

	printf("%lld\n", result);


	return 0;
}