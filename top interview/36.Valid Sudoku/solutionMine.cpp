class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool isValid = true;
        vector<map<int , char>> mapVec;
        vector<vector<map<int , char>>> mapVec1;
        
        for(int i = 0 ; i < board.size() ; i ++)
        {
            map<int , char> tmp;
            mapVec.push_back(tmp);
        }
        for(int i = 0 ; i < 3 ; i ++)
        {
            vector<map<int , char>> vec;
            for(int j = 0 ; j < 3 ; j ++)
            {
                map<int , char> tmp;
                vec.push_back(tmp);
            }
            mapVec1.push_back(vec);
        }
        
        for(int i = 0 ; i < board.size() ; i ++)
        {
            vector<char> vec = board[i];
            map<int , char> lineMap;
            for(int j = 0 ; j < vec.size() ; j ++)
            {
                char ch = vec[j];
                if(ch == '.')
                {
                    continue;
                }
                
                int veci = i/3;
                int vecj = j/3;
                cout << "veci: " <<veci<<" vecj: "<<vecj<<endl;
                vector<map<int , char>> line = mapVec1[veci];
                map<int , char> map1= line[vecj];
                if(map1.find(ch - '0') != map1.end())
                {
                    cout << "不符合小正方形";
                    return false;
                }
                else
                {
                    map1.insert(map<int,char>::value_type(ch - '0' , ch));
                    line[vecj] = map1;
                    mapVec1[veci] = line;
                }
                map<int, char>::const_iterator it; 
                cout << "map1:" ;
                for (it = map1.begin(); it != map1.end(); ++it)
                    cout << it->first << " = " << it->second << endl; 
                cout << endl;
                map<int , char> colMap = mapVec[j];
                
                //cout << "i : " << i << " j: " << j << endl;
                //cout << "colMap for "<< j << " :";
                for (it = colMap.begin(); it != colMap.end(); ++it)
                    cout << it->first << " = " << it->second << endl; 
                if(colMap.find(ch - '0') != colMap.end())
                {
                    return false;
                }
                else
                {
                    colMap.insert(map<int,char>::value_type(ch - '0' , ch));
                    mapVec[j] = colMap;
                }
                
                if(lineMap.find(ch - '0') != lineMap.end())
                {
                    return false;
                }
                else
                {
                    lineMap.insert(map<int,char>::value_type(ch - '0' , ch));
                }
                for (it = lineMap.begin(); it != lineMap.end(); ++it)
                    cout << it->first << " = " << it->second << endl; 
            }
        }
        return isValid ;
    }
};