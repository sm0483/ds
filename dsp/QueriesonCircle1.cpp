class Solution {
	public:
		vector<int>ans;
		vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
			for(int q=0;q<queries.size();q++){
				int count=0;
				for(int p=0;p<points.size();p++){
					if(pow(points[p][0]-queries[q][0],2)+pow(points[p][1]-queries[q][1],2)<=pow(queries[q][2],2)){
						count++;

					}
				}
				ans.push_back(count);
			}
			return ans;
		}
};
