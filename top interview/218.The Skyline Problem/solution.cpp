class Solution {
public:
    vector<vector<int>> mergeTwo(vector<int> vec1, vector<int> vec2){
        vector<vector<int>> vec;
        if(vec1[0] != vec2[0])
        {
            vec.push_back({vec1[0], vec2[0], vec1[2]});
        }
        if(vec.size() != 0 && vec1[2] >= vec2[2])
        {
            vec[0][1] = min(vec1[1],vec2[1]);
        }
        else
            vec.push_back({vec2[0],min(vec1[1],vec2[1]),max(vec1[2],vec2[2])});
        return vec;
    }
    vector<vector<int>> merge(vector<vector<int>> leftvec, vector<vector<int>> rightvec){
        vector<vector<int>> vecList;
        int len_left = leftvec.size();
        int len_right = rightvec.size();

        int i = 0 , j = 0;
        while(i < len_left && j < len_right)
        {
            vector<int> left = leftvec[i];
            vector<int> right = rightvec[j];
//            cout << i << " " << j << endl;
            if(left[1] <= right[0])
            {
                vecList.push_back(left);
                i ++;
            }
            else if(right[1] <= left[0])
            {
                vecList.push_back(right);
                j ++;
            }
            else
            {
                vector<vector<int>> tmp;
                if(left[0] <= right[0])
                {
                    tmp = mergeTwo(left,right);
                }
                else
                {
                    tmp = mergeTwo(right,left);
                }
                int k = 0;
                for(; k < tmp.size() ; k ++)
                {
                    vecList.push_back(tmp[k]);
                }
                if(tmp[k-1][1] == left[1])
                {
//                    cout << "i+=1" << endl;
                    i ++;
                }
                else
                {
                    leftvec[i][0] = tmp[k-1][1];
                }

                if(tmp[k-1][1] == right[1])
                {
//                    cout << "j+=1" << endl;
                    j ++;
                }
                else
                {
                    rightvec[j][0] = tmp[k-1][1];
                }
            }
        }

        while(i < len_left)
        {
            if(leftvec[i][2] == vecList.back()[2])
                vecList.back()[1] = leftvec[i][1];
            else
                vecList.push_back(leftvec[i]);
            i++;
        }

        while(j < len_right)
        {
            if(rightvec[j][2] == vecList.back()[2])
                vecList.back()[1] = rightvec[j][1];
            else
                vecList.push_back(rightvec[j]);
            j ++;
        }
        
        for(int k = 1 ; k < vecList.size() ; k ++)
        {
            if(vecList[k][2] == vecList[k-1][2])
            {
                vecList[k-1][1] = vecList[k][1];
                vecList.erase(vecList.begin() + k);
                k --;
            }
        }

        return vecList;
    }
    vector<vector<int>> skyline(vector<vector<int>>& buildings,int left, int right){
        vector<vector<int>> vecList;
        if(left == right)
        {
            vector<int> tmp = buildings[left];
            vecList.push_back(tmp);
            return vecList;
        }

        int mid = (left + right)/2;
        vector<vector<int>> leftVec = skyline(buildings,left,mid);
        vector<vector<int>> rightVec = skyline(buildings,mid+1,right);

        vector<vector<int>> vecReturn = merge(leftVec,rightVec);

        return vecReturn;
    }
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> pairs;
        if(buildings.size() == 0)
            return pairs;
        vector<vector<int>> vecList = skyline(buildings, 0, buildings.size() - 1);
        pairs.push_back(make_pair(vecList[0][0],vecList[0][2]));
        // pair<int,int> before_p = make_pair(vecList[0][0],vecList[0][2]);
        int i = 1;
        for( ; i < vecList.size() ; i ++)
        {
            if(vecList[i][0] != vecList[i-1][1])
            {
                pairs.push_back(make_pair(vecList[i-1][1],0));
            }
            pairs.push_back(make_pair(vecList[i][0],vecList[i][2]));
        }
        pairs.push_back(make_pair(vecList[i-1][1],0));

        return pairs;
    }
};
