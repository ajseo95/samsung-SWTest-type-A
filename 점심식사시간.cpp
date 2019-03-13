#include<stdio.h>
#include<queue>
#include<math.h>
#include<algorithm>
#define MAX 987654321
using namespace std;

int test;
int n;
int map[12][12];
struct state{
	int x;
	int y;
};
struct state stair[3];
struct state person[12];
int stair_1[12];
int stair_2[12];
int stair_1_init[12];
int stair_2_init[12];
int stair_1_size;
int stair_2_size;
int result = MAX;

void move_info(){
	for (int i = 1; i <= stair_1_size; i++){
		stair_1[i] = stair_1_init[i];
	}
	for (int i = stair_1_size + 1; i <= 11; i++){
		stair_1[i] = 0;
	}
	for (int j = 1; j <= stair_2_size; j++){
		stair_2[j] = stair_2_init[j];
	}
	for (int j = stair_2_size + 1; j <= 11; j++){
		stair_2[j] = 0;
	}
}
void solve(){
	move_info();
	sort(stair_1, stair_1 + stair_1_size + 1);
	sort(stair_2, stair_2 + stair_2_size + 1);

	queue<int> wait_1, wait_2;
	queue<int> que_1, que_2;
	int time = 0;
	int cnt1 = 1, cnt2 = 1;
	int stair1_time = map[stair[1].x][stair[1].y];
	int stair2_time = map[stair[2].x][stair[2].y];

	while (1){
		time++;
		
		//stair1
		while (stair_1[cnt1] == time){
			wait_1.push(stair_1[cnt1++]);
		}
		if (!que_1.empty()){
			while (1){
				if (que_1.empty()) break;
				int t = que_1.front();

				if (t < time && t + stair1_time <= time){
					que_1.pop();
				}
				else break;
			}
		}
		while (!wait_1.empty() && que_1.size() < 3){
			int t = wait_1.front();
			if (time < t + 1) break;
			wait_1.pop();
			que_1.push(time);
		}

		//stair2
		while (stair_2[cnt2] == time){
			wait_2.push(stair_2[cnt2++]);
		}
		if (!que_2.empty()){
			while (1){
				if (que_2.empty()) break;
				int t = que_2.front();

				if (t < time && t + stair2_time <= time){
					que_2.pop();
				}
				else break;
			}
		}
		while (!wait_2.empty() && que_2.size() < 3){
			int t = wait_2.front();
			if (time < t + 1) break;
			wait_2.pop();
			que_2.push(time);
		}

		if (cnt1 - 1 == stair_1_size && wait_1.empty() && que_1.empty() && cnt2 - 1 == stair_2_size && wait_2.empty() && que_2.empty()) break;
		
	}

	if (time >= 1){
		result = min(result, time);
	}
}
void dfs(int cnt, int person_cnt, int stair_num){

	if (stair_num == 1){
		stair_1_init[stair_1_size] = abs(stair[1].x - person[cnt].x) + abs(stair[1].y - person[cnt].y);
	}
	else if (stair_num == 2){
		stair_2_init[stair_2_size] = abs(stair[2].x - person[cnt].x) + abs(stair[2].y - person[cnt].y);
	}
	
	
	if (cnt == person_cnt){
		solve();
		return;
	}

	stair_1_size++;
	dfs(cnt + 1, person_cnt, 1);
	stair_1_size--;
	stair_2_size++;
	dfs(cnt + 1, person_cnt, 2);
	stair_2_size--;
}

int main(){

	scanf("%d", &test);

	for (int t = 1; t <= test; t++){

		scanf("%d", &n);
		int stair_cnt = 0;
		int person_cnt = 0;

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				scanf("%d", &map[i][j]);

				if (map[i][j] == 1){
					person_cnt++;
					person[person_cnt].x = i;
					person[person_cnt].y = j;
				}
				else if (map[i][j] > 1){
					stair_cnt++;
					stair[stair_cnt].x = i;
					stair[stair_cnt].y = j;
				}
			}
		}

		dfs(0, person_cnt, 0);

		printf("#%d %d\n", t, result);

		//ÃÊ±âÈ­
		result = MAX;
		stair_1_size = 0;
		stair_2_size = 0;

	}

	return 0;
}