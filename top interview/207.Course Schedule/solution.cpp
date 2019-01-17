class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<bool> visit(numCourses, false);
        
        vector<vector<int>> vecList;
        for(int i = 0 ; i < numCourses ; i ++)
        {
            vector<int> vec;
            vecList.push_back(vec);
        }
        
        for(int i = 0 ; i < prerequisites.size() ; i ++)
        {
            vecList[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        
        for(int i = 0 ; i < numCourses ; i ++)
        {
            bool tmp = search(vecList,visit,i);
            if(!tmp)
                return false;
        }
        
        return true;
    }
    
    bool search(vector<vector<int>>& vecList, vector<bool>& visit, int i){
        if(visit[i])
            return false;
        visit[i] = true;
        for(int j = 0 ; j < vecList[i].size() ; j ++)
        {
            bool tmp = search(vecList,visit,vecList[i][j]);
            if(!tmp)
                return false;
        }
        visit[i] = false;
        vecList[i] = {};
        return true;
    }
};