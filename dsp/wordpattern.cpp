#include<iostream>
#include<unordered_map>
using namespace std;


int check(unordered_map<string ,int>umap,string s){

	for(auto i:umap){
		if(i.first==s){
			return i.second;

		}


	}
	return 0;

}



int main(){
	string s="hello word hello world";
	string pattern="abba";
	int count=0;
	string word="";
	unordered_map<string,char>umap;
	unordered_map<string,int>umap1;

	for(int i=0;i<=s.length();i++){
		if(s[i]!=' ' && i!=s.length()){
			word+=s[i];

		}
		else {
			if(check(umap,word)==0){
				count++;
				umap[word]=count;
			}
			else{
				umap[word]=check(umap,word);

			}
			word="";


		}


	}

	for(int i=0;i<s.length();i++){
		string p(1,s[i]);
		if(check(umap1,p)==0){
			count++;
			umap1[p]=count;

		}
		else{
			umap1[p]=check(umap1,p);

		}


	}

	for(auto i: umap){
		cout<<i.first<<endl;
		cout<<i.second<<endl;
		cout<<""<<endl;

	}












	

	return 0;
}
