#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int test;
int n, k;
int arr[30];
int length;
int result[30];
int cnt;

int is_exist(int num, int cnt){
	for (int i = 0; i <= cnt; i++){
		if (result[i] == num) return 1;
	}
	return 0;
}
void make_number(){
	
	int num;

	for (int i = 1; i <= length; i++){ //경우의 수 출발점
		for (int j = i; j <= n; j += length){//출발점
			num = 0;
			for (int k = 0; k < length; k++){	
				int digit = length - 1 - k;
				int digit_num = 1;
				for (int a = 1; a <= digit; a++){
					digit_num *= 16;
				}
				if (j + k > n){
					num += digit_num * arr[(j + k) % n];
				}
				else{
					num += digit_num * arr[(j + k)];
				}
				
			}
			if (!is_exist(num, cnt)){
				result[cnt++] = num;
			}
		}
	}
}
int main(){

	scanf("%d", &test);

	for (int t = 1; t <= test; t++){
		scanf("%d %d", &n, &k);

		for (int i = 1; i <= n; i++){
			char x;
			scanf(" %c", &x);
			if (!isdigit(x)){
				x = x - '0' - 7;
				arr[i] = x;
			}
			else{
				arr[i] = x - '0';
			}
		}

		length = n / 4;

		make_number();
		sort(result, result + cnt);

		//k번째 큰수 찾기
		int k_result = 0;
		int k_cnt = 0;
		for (int i = cnt - 1; i >= 0; i--){
			k_cnt++;
			if (k_cnt == k){
				k_result = result[i];
				break;
			}
		}

		printf("#%d %d\n", t, k_result);

		for (int i = 0; i < n; i++){
			result[i] = 0;
		}
		cnt = 0;

	}

	return 0;
}