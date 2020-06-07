#include <bits/stdc++.h>
using namespace std;

void setup(vector<vector<int> >& vec){
	ifstream fin("triangle.txt");
	vec.resize(100);
	for(int i = 0; i < 100; ++i){
		vec[i].resize(i + 1);
		for(int j = 0; j <= i; ++j){
			int in;
			fin >> in;
			vec[i][j] = in;
		}
	}
	fin.close();
}

int main(int argc, char **argv){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<vector<int> > vec;
	setup(vec);
	
	for(int i = 99; i > 0; --i)
		for(int j = 0; j < i; ++j)
			vec[i - 1][j] += max(vec[i][j], vec[i][j + 1]);
	cout << vec[0][0] << endl;

	return 0;
}

