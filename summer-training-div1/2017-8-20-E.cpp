#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
char s[125];
int t;
int expr_pre();
void expr();
int expr_pre(){
	if(s[t] == ')' || !s[t]) return 0;
	if(s[t]){
		if(s[t] == '(') {
			t++;
			expr();
			t++;
		}else expr();
	}
	return 1;
}
void expr(){
	string now[4]; // 0 name, 1 id, 2 class, 3 num
	for(int i = 0; i < 4; i++) now[i].clear();
	int cur = 0;
	//int flag = 0;
	while(s[t] && s[t] != ')'){
		if(s[t] == '>'){
			t++;break;
		}
		switch(s[t]){
			case '*': cur = 3; break;
			case '#': cur = 1; break;
			case '.': cur = 2; 
				  if(now[cur].size() != 0) now[cur] += ' ';
				  break;
			default: now[cur] += s[t]; break;
		}
		t++;
	}
	int num = 0;
	if(now[3].size() != 0){
		for(int i = 0; i < now[3].size(); i++) {
			num *= 10;
			num += now[3][i] - '0';
		}
	}else {
		num = 1;
	}
	int tmp = t;
	for(int i = 1; i <= num; i++){
		t = tmp;
		printf("<%s",now[0].c_str());
		if(now[1].size() != 0){
			printf(" id=\"%s\"",now[1].c_str());
		}
		if(now[2].size() != 0){
			printf(" class=\"%s\"",now[2].c_str()); 
		}
		printf(">");
		while(s[t] && expr_pre());
		printf("</%s>",now[0].c_str());
	}
}
int main(){
#ifdef __APPLE__
	freopen("main.in","r",stdin);
#endif
	scanf(" %s", s);
	t = 0;
	expr_pre();
	return 0;
}
