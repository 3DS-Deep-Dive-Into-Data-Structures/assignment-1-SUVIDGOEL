class Solution {
public:
    int calculate(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                s.erase(s.begin() + i);
            }
        }
        stack<pair<int, int>> st;
        int ans = 0;
        int sign = 1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='-'){
                if(sign>0) sign = -1 * sign;
            }
            if(s[i]=='+'){
                if(sign<0) sign = -1 * sign;
            }
            if(isdigit(char(s[i]))){
                int num=0;
                while(i<s.size() && isdigit(s[i])){
                    num=num*10 + (s[i]-'0');
                    i++;
                }
                ans = ans + sign*num;
            }
            if(s[i]=='('){
                st.push({ans, sign});
                ans=0;
                sign=1;
            }
            if(s[i]==')'){
                ans = st.top().first + st.top().second*ans;
                sign=1;
                st.pop();
            }
        }
        return ans;
    }
};
