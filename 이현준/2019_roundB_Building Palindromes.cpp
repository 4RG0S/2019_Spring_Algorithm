#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>

#include <map>

using namespace std;


bool isavailable(string a) {

	map<char, int> map;
	if (1==a.length()) {
		return true;
	}
	
	int length = a.length();
	
	for (int i = 0; i < length; i++) {
		if (map[a.at(i)]==0) {
			map[a.at(i)] = 1;
		}
		else {
			int value = map[a.at(i)];
			map[a.at(i)] = value + 1;
		}
	}
	int chance = 1;
	int j = 0;
	while (!map.empty()) {
		//printf("%c : %d  ", a.at(j), map[a.at(j)]);
		if (map[a.at(j)] % 2 == 0) {
			map.erase(a.at(j));
			j++;
			continue;
		}
		else {
			chance--;
			if (chance < 0) {
				//printf("false\n");
				return false;
			}
			map.erase(a.at(j));
			j++;
			continue;
		}
		
	}
	
	//printf("true\n");
	return true;


}
int main() {
	
	int n;
	cin >> n; //test
	int rule = 1;
	while (n != 0) {
		int N; int Q;
		int correct = 0;
		cin >> N >> Q;
		string a;
		cin >> a;
		while (Q != 0) {
			
			int firstnum; int secondnum;
			cin >> firstnum >> secondnum;
			
			string substr;
			substr = a.substr(firstnum-1, secondnum-firstnum+1);
			
			if (substr == string(substr.rbegin(), substr.rend())) {
		          correct++;
				  Q--;
			}
			else {
				if (isavailable(substr) == true) {
					correct++;
					Q--;
				}
				else {
					Q--;
				}
			}
			
		}
		cout << "Case #" << rule << ": " << correct<<endl;
		rule++;
		n--;

	}
	system("pause");
	return 0;
}
