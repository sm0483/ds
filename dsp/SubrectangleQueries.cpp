#include<iostream>
#include<vector>
using namespace std;

class SubrectangleQueries {
	public:
		vector<int>base;
		SubrectangleQueries(vector<vector<int>>&rectangle) {
			base=rectangle;

		}

		void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
			for(int row=row1;row<=row2;row++){
				for(int col=co1;col<=col2;col++){
					base[row][col]==newValue;
				}
			}
		}

		int getValue(int row, int col) {
			return base[row][col];

		}
};
int main(){
	sub=SubrectangleQueries([[[1,2,1],[4,3,4],[3,2,1],[1,1,1]]]);




}
