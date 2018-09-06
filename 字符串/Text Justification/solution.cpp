class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> vec;
        int numOfWords = 0;
        int totalSize = 0;
        
        vector<string> wordList;
        
        for(int i = 0 ; i < words.size() ; i ++)
        {
            string tmp = words[i];
            int len = tmp.size();
            if(len + totalSize <= maxWidth)
            {
                totalSize = totalSize + len + 1;
                numOfWords ++;
                wordList.push_back(tmp);
            }
            else
            {
                string s = generateStr(wordList , numOfWords , totalSize , maxWidth);
                vec.push_back(s);
                numOfWords = 1;
                totalSize = len + 1;
                wordList.clear();
                wordList.push_back(tmp);
            }
        }
        
        vec.push_back(generateStr(wordList , maxWidth));
        
        return vec;
    }
    string generateStr(vector<string> vec , int maxWidth){
        string s = "";
        int len = 0;
        for(int i = 0 ; i < vec.size() ; i ++)
        {
            s = s + vec[i];
            len += vec[i].size();
            if(len < maxWidth)
            {
                s = s + ' ';
                len ++;
            }
        }
        for(int i = len ; i < maxWidth ; i ++)
        {
            s = s + ' ';
        }
        return s;
    }
    string generateStr(vector<string> vec , int numOfWords , int totalSize , int maxWidth){
        /*
        for(int i = 0 ; i < vec.size() ; i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
        */
        
        int numSpace = maxWidth - totalSize + numOfWords;
        string s = "";
        
        if(totalSize > maxWidth)
        {
            for(int i = 0 ; i < vec.size() ; i ++)
            {
                s = s + vec[i];
                if(i != vec.size() - 1)
                {
                    s = s + ' ';
                }
            }
            return s;
        }
        
        if(numOfWords == 1)
        {
            s = s + vec[0];
            for(int i = vec[0].size() ; i < maxWidth ; i ++)
            {
                s = s + ' ';
            }
            return s;
        }
        
        int avg = numSpace / (numOfWords - 1);
        int addCount = numSpace % (numOfWords - 1);
        
        for(int i = 0 ; i < vec.size() ; i++)
        {
            s = s + vec[i];
            if(i != vec.size() - 1)
            {
                for(int j = 0 ; j < avg ; j ++)
                {
                    s = s + ' ';
                }
                if(i < addCount)
                {
                    s = s + ' ';
                }
            }
        }
        return s;
    }
};