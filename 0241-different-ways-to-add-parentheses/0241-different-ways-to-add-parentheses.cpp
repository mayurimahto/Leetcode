class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>ans;
        int n = expression.size();
        
        for(int i=0; i<n; i++){
            char opt = expression[i];
            
            if(opt == '+' || opt == '-' || opt == '*'){
                //Split input string into 2 parts and solve them recursively
                vector<int>ans1 = diffWaysToCompute(expression.substr(0,i));
                vector<int>ans2 = diffWaysToCompute(expression.substr(i+1));
                
                for(auto n1: ans1){
                    for(auto n2: ans2){
                        if(opt == '+'){
                            ans.push_back(n1+n2);
                        }
                        else if(opt == '-'){
                            ans.push_back(n1-n2);
                        }
                        else{
                            ans.push_back(n1*n2);
                        }
                    }
                }
            }
        }
        // if the input string contains only number
        if (ans.empty())
            ans.push_back(atoi(expression.c_str()));
        return ans;
    }
};