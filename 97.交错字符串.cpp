#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    //交错字符串，双指针就行，但是存在一个问题，就是如果s1和s2都匹配怎么办，用递归解决
    //99/101 超时   剪枝还是超时？？？？
    //考虑如何优化时间
    //剪枝，类似于fib优化，减少重复子问题的计算
    bool** valid;
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;
        valid = new bool*[s1.length()+1];
        for (int i = 0; i < s1.length()+1; i++)
        {
            valid[i] = new bool[s2.length()+1];
            for (int j = 0; j < s2.length()+1; j++)
                valid[i][j] = 1;
        }
        return isInterleave(s1, s2, s3, 0, 0, 0);
    }
    bool isInterleave(string s1, string s2, string s3,int length1,int length2,int length3) {
        //要注意边界检查
        if (!valid[length1][length2])
            return false;
        if ((length1 == s1.length()) && (length2 == s2.length()) && (length3 == s3.length()))
            return true;    
        if (length3 == s3.length())
        {
            valid[length1][length2] = false;
            return false;
        }

            
        if (length1 == s1.length())
        {
            //说明s1都已经匹配完成了
            while (length2<s2.length()&& length3 < s3.length() )
            {
                if (s2[length2] == s3[length3])
                {
                    length2++;
                    length3++;
                }
                else
                {
                    break;
                }
            }
            if((length2==s2.length())&&(length3 == s3.length()))
                return true;
            else
            {
                valid[length1][length2] = false;
                return false;

            }

        }
        if (length2 == s2.length())
        {
            //说明s1都已经匹配完成了
            while (length1 < s1.length() && length3 < s3.length())
            {
                if (s1[length1] == s3[length3])
                {
                    length1++;
                    length3++;
                }
                else
                {
                    break;
                }
            }
            if ((length1 == s1.length()) && (length3 == s3.length()))
                return true;
            else
            {
                valid[length1][length2] = false;
                return false;
            }
                

        }
        if ((s1[length1] != s3[length3]) && (s2[length2] != s3[length3]))
        {
            valid[length1][length2] = false;
            return false;
        }
            
        if ((s1[length1] == s3[length3]) && (s2[length2] == s3[length3]))
        {
            bool tmp= false;
            if (valid[length1 + 1][length2])
                tmp|=isInterleave(s1, s2, s3, length1 + 1, length2, length3 + 1);
            if (valid[length1][length2 + 1])
                tmp |= isInterleave(s1, s2, s3, length1, length2 + 1, length3 + 1);
            valid[length1][length2] = tmp;
            return tmp;
        }
        if (s1[length1] == s3[length3])
        {
            return valid[length1][length2]=isInterleave(s1, s2, s3, length1 + 1, length2, length3 + 1);
        }
           
        if (s2[length2] == s3[length3])
        {
            return valid[length1][length2] = isInterleave(s1, s2, s3, length1, length2 + 1, length3 + 1);
        }
            
        return false;
    }
};
/*int main()
{
    Solution s1;
    cout<<s1.isInterleave("aabcc", "dbbca", "aadbbcbcac");
}*/