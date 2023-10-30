#include <iostream>
#include <cstring>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

typedef long long ll;

string W, S;

// ���ϵ�ī�� ���� w �� ���ڿ� s �� �����Ǵ��� ���θ� ��ȯ�Ѵ�
bool match(const string& w, const string& s) {
	// w[pos] �� s[pos] �� ���糪����
	int pos = 0;
	while(pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos]))
		++pos;
	// �� �̻� ������ �� ������ �� while ���� �������� Ȯ���Ѵ�
	// 1. ���� ���� �����ؼ� ���� ���: ���ڿ��� ������� ��
	if(pos == w.size())
		return pos == s.size();
	// 2. * �� ������ ���� ���: * �� �� ���ڸ� �����ؾ� ���� ���ȣ���ϸ鼭 Ȯ���Ѵ�
	if(w[pos] == '*') {
		for(int skip = 0; pos+skip <= s.size(); ++skip)
			if(match(w.substr(pos+1), s.substr(pos+skip)))
				return true;
		return false;
	}
	// 3. �̿��� ��쿡�� ��� �������� �ʴ´�
	return false;
}

int cache[5001][5001];

// ���ϵ�ī�� ���� W[w..] �� ���ڿ� S[s..] �� �����Ǵ��� ���θ� ��ȯ�Ѵ�
bool matchMemoized(int w, int s) {
	int& ret = cache[w][s];
	if(ret != -1) return ret;
	// W[w] �� S[s] �� ���糪����
	while(s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
		++w;
		++s;
	}
	// �� �̻� ������ �� ������ �� while ���� �������� Ȯ���Ѵ�
	// 1. ���� ���� �����ؼ� ���� ���: ���ڿ��� ������� ��
	if(w == W.size()) return ret = (s == S.size());
	// 2. * �� ������ ���� ���: * �� �� ���ڸ� �����ؾ� ���� ���ȣ���ϸ鼭 Ȯ���Ѵ�
	if(W[w] == '*') {
		for(int skip = 0; skip+s <= S.size(); ++skip)
			if(matchMemoized(w+1, s+skip))
				return ret = 1;
		return ret = 0;
	}
	// 3. �̿��� ��쿡�� ��� �������� �ʴ´�
	return ret = 0;
}
// ���ϵ�ī�� ���� W[w..] �� ���ڿ� S[s..] �� �����Ǵ��� ���θ� ��ȯ�Ѵ�
bool matchMemoized2(int w, int s) {
	int& ret = cache[w][s];
	if(ret != -1) return ret;
	if(w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s]))
		return ret = matchMemoized2(w+1, s+1);
	// �� �̻� ������ �� ������ �� while ���� �������� Ȯ���Ѵ�
	// 1. ���� ���� �����ؼ� ���� ���: ���ڿ��� ������� ��
	if(w == W.size()) return ret = (s == S.size());
	// 2. * �� ������ ���� ���: * �� �� ���ڸ� �����ؾ� ���� ���ȣ���ϸ鼭 Ȯ���Ѵ�
	if(W[w] == '*') {
		if(matchMemoized2(w+1, s) ||
			(s < S.size() && matchMemoized2(w, s+1)))
			return ret = 1;
	}
	// 3. �̿��� ��쿡�� ��� �������� �ʴ´�
	return ret = 0;
}

int main(int argc, char* argv[])
{
	int cases;
	cin >> cases;
	REP(cc,cases)
	{
		cin >> W;
		vector<string> ret;
		int cc2;
		cin >> cc2;
		while(cc2--)
		{
			cin >> S;
			CLEAR(cache,-1);
			if(argc == 1) {
				if(matchMemoized(0, 0)) ret.push_back(S);
			}
            else {
				if(matchMemoized2(0, 0)) ret.push_back(S);
			}
		}
		sort(all(ret));
		REP(i,ret.sz) cout << ret[i] << endl;
	}
}