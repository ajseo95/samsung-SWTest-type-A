#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;

int n;
int check[102][102];
vector<int> v;
int dx[5] = { 1, 0, -1, 0 };
int dy[5] = { 0, -1, 0, 1 };

void dragoncurve(int dir, int gen){

	stack<int> s;
	stack<int> temp_s;

	s.push(dir);

	for (int g = 0; g < gen; g++){
		while (!s.empty()){
			int x = s.top();
			v.push_back((x + 1) % 4);
			s.pop();
			temp_s.push(x);
		}
		while (!temp_s.empty()){
			int y = temp_s.top();
			temp_s.pop();
			s.push(y);
		}
		for (int i = 0; i < v.size(); i++){
			s.push(v[i]);
		}
		v.clear();
	}

	while (!s.empty()){
		v.push_back(s.top());
		s.pop();
	}

}
void check_dragon(int x, int y){
	check[x][y] = 1;

	for (int i = v.size() - 1; i >= 0; i--){
		x = x + dx[v[i]];
		y = y + dy[v[i]];
		check[x][y] = 1;
	}
}
int main(){

	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g);
		dragoncurve(d, g);
		check_dragon(x, y);
		v.clear();
	}

	int result = 0;
	for (int i = 0; i <= 100; i++){
		for (int j = 0; j <= 100; j++){
			if (check[i][j] == 1 && check[i+1][j] == 1 && check[i][j+1] == 1 && check[i+1][j+1] == 1){
				result++;
			}
		}
	}

	printf("%d", result);

	return 0;
}