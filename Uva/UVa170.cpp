#include <bits/stdc++.h>

using namespace std;

typedef pair<int, char> ic;

vector<stack<ic> > board(13);
int contCard;

// A - 1, 2, 3, 4, 5, 6, 7, 8, 9, t - 10, j - 11, Q - 12

int conv(char c) {
	if (c >= '2' && c <= '9')
		return c - '0';
	if (c == 'T')
		return 10;
	if (c == 'J')
		return 11;
	if (c == 'Q')
		return 12;
	if (c == 'A')
		return 1;
	if (c == 'K')
		return 13;
	return 0;
}
char to_char(int i) {
	if (i == 10)
		return 'T';
	if (i == 11)
		return 'J';
	if (i == 12)
		return 'Q';
	if (i == 1)
		return 'A';
	if (i == 13)
		return 'K';
	return '0' + i;
}

void clear() {
	for (int i = 0; i < 13; ++i)
		while(!board[i].empty())
			board[i].pop();
}

int main() {
	string C = "", S;
	
	int i = 0, pos;
	ic card;
	vector<string> s;

	while(cin >> C) {
		if (C == "#") break;
		s.push_back(C);
		for (int j = 0; j < 51; ++j) {
			cin >> C;
			s.push_back(C);
		}
		i = 51;
		for (;i >= 0; --i) {
			S = s[i];
			board[(51 - i) % 13].push(ic(conv(S[0]), S[1]));
		}
	
		contCard = 1;
		card = board[12].top();
		board[12].pop();
		pos = card.first - 1;
		while(true) {	
			if (board[pos].empty())	break;
			card = board[pos].top();
			board[pos].pop();
			pos = card.first - 1;
			contCard++; 
		}
		if (contCard < 10) cout << "0";	
		cout << contCard << "," << to_char(card.first) << card.second <<"\n"; 
		clear();
		s.clear();
	}
		
	return 0;
}


