#include<stdio.h>
#include<queue>
using namespace std;

int n, m;
char map[12][12];
int check[12][12][12][12];
int start_rx, start_ry, start_bx, start_by;
struct state{
	int rx;
	int ry;
	int bx;
	int by;
	int cnt;
};
int dx[5] = { 1, 0, -1, 0 };
int dy[5] = { 0, 1, 0, -1 };
int result = -1;

void solve(){

	queue<struct state> que;
	que.push({ start_rx, start_ry, start_bx, start_by, 0 });
	check[start_rx][start_ry][start_bx][start_by] = 1;

	while (!que.empty()){
		int rx = que.front().rx;
		int ry = que.front().ry;
		int bx = que.front().bx;
		int by = que.front().by;
		int cnt = que.front().cnt;
		que.pop();

		if (cnt > 10) break;

		if (map[rx][ry] == 'O'){
			result = cnt;
			break;
		}
		
		for (int i = 0; i < 4; i++){

			int nrx = rx, nry = ry, nbx = bx, nby = by;
			
			while (1){
				nrx = nrx + dx[i];
				nry = nry + dy[i];
				
				if (map[nrx][nry] == '#'){
					nrx = nrx - dx[i];
					nry = nry - dy[i];
					break;
				}
				else if (map[nrx][nry] == 'O') break;

			}
			while (1){
				nbx = nbx + dx[i];
				nby = nby + dy[i];

				if (map[nbx][nby] == '#'){
					nbx = nbx - dx[i];
					nby = nby - dy[i];
					break;
				}
				else if (map[nbx][nby] == 'O') break;
			}

			if (map[nbx][nby] == 'O') continue;

			if (nrx == nbx && nry == nby){
				if (i == 0){ //아래
					if (rx < bx) nrx--;
					else nbx--;
				}
				else if (i == 1){ //오른쪽
					if (ry < by) nry--;
					else nby--;
				}
				else if (i == 2){ //위
					if (rx < bx) nbx++;
					else nrx++;
				}
				else if (i == 3){ //왼쪽
					if (ry < by) nby++;
					else nry++;
				}
			}
			
			if (check[nrx][nry][nbx][nby] != 1){
				check[nrx][nry][nbx][nby] = 1;
				que.push({ nrx, nry, nbx, nby, cnt + 1 });
			}
		}
	}

}
int main(){

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'R'){
				start_rx = i;
				start_ry = j;
			}
			else if (map[i][j] == 'B'){
				start_bx = i;
				start_by = j;
			}
		}
	}

	solve();

	printf("%d", result);


	return 0;
}