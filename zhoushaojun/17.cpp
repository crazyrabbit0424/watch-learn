class Solution {
public:
    vector<string> letterCombinations(string digits) {
       	vector<string> res;
		/* 数字与字母对照表 */
		map<char, string> maps = {{'2',"abc"},
		                       {'3',"def"},
							   {'4',"ghi"},
							   {'5',"jkl"},
							   {'6',"mno"},
							   {'7',"pqrs"},
							   {'8',"tuv"},
							   {'9',"wxyz"}};
		queue<string> que;/* 临时队列 */
	    string s;
		
		/* 先将第一个元素对应的字母入队 */
		for (int j = 0; j < maps[digits[0]].size(); j++)
		{
			string str;
			str.push_back(maps[digits[0]][j]);
			que.push(str);
		}
        
		/* 遍历数字对应的字母表 */
		for (int i = 1; i < digits.size(); i++)
		{
			int length = que.size();
			while (length--)
			{
				/* 出队的与下一个字母表的字符组合起来，再入队 */
				for (int j = 0; j < maps[digits[i]].size(); j++)
				{
					s = que.front();
					s = s + maps[digits[i]][j];
					que.push(s);
				}
				que.pop();
			}
		}
		while (!que.empty())
		{
			res.push_back(que.front());
			que.pop();
		}
		return res; 
    }
};