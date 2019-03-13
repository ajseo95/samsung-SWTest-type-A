#include<stdio.h>
#include<algorithm>
using namespace std;

int n;
struct state{
	int term;
	int price;
};
struct state schedule[17];
int check[17];
int result;

void dfs(int day){

	if (day > n){
		int sum = 0;
		for (int i = 1; i <= n; i++){
			if (check[i] == 1){
				sum += schedule[i].price;
			}
		}

		result = max(result, sum);
		return;
	}
	
	for (int i = day; i <= n; i++){
		if (check[i] == 0 && i + schedule[i].term <= n + 1){
			check[i] = 1;
			dfs(i + schedule[i].term);
			check[i] = 0;
		}
		else{
			dfs(i + schedule[i].term);
		}
	}


}
int main(){

	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		scanf("%d %d", &schedule[i].term, &schedule[i].price);
	}

	for (int i = 1; i <= n; i++){
		if (check[i] == 0 && i + schedule[i].term <= n + 1){
			check[i] = 1;
			dfs(i + schedule[i].term);
			check[i] = 0;
		}
	}

	printf("%d\n", result);
	
	return 0;
}