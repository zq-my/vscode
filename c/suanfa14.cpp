#include<iostream>
#include<algorithm>
using namespace std;
double cw;//当前重量
double cp;//当前价值
double bestp;//当前最优价值
int n;//物品数量
double c;//背包容量
const int N = 105;
int x[N];
struct Bag {
	double w, v;
	int id, x;
};
Bag bag[N];
bool cmp(Bag a, Bag b) {
	return (a.v / a.w) > (b.v / b.w);
}
double bound(int i) {
	double cleft = c - cw;
	double bd = cp;
	while (i <= n && bag[i].w <= cleft) {
		cleft -= bag[i].w;
		bd += bag[i].v;
		i++;
	}
	if (i <= n)
		bd += bag[i].v * cleft / bag[i].w;
	return bd;
}
void dfs(int i) {
	if (i > n) {
		bestp = cp;
		for (int i = 1; i <= n; i++) 
				x[bag[i].id] = bag[i].x;
		return;
	}
	if (cw + bag[i].w <= c) {
		cw += bag[i].w;
		cp += bag[i].v;
		bag[i].x = 1;
		dfs(i + 1);
		cw -= bag[i].w;
		cp -= bag[i].v;
		bag[i].x = 0;
	}
	if (bound(i + 1) > bestp)
		dfs(i + 1);
}
int main() {
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
		cin >> bag[i].w;
	for (int i = 1; i <= n; i++)
		cin >> bag[i].v;
	for (int i = 1; i <= n; i++)
		bag[i].id = i;
	
	sort(bag + 1, bag + 1 + n, cmp);
	dfs(1);
	cout << bestp<<endl;
	for (int i = 1; i <= n; i++)
		cout << x[i] << " ";
	return 0;
}

