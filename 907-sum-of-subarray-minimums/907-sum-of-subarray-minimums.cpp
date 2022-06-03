class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> sl(n);
        vector<int> sr(n);
        stack<int> st;
        
        for(int i=0; i<n; ++i){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                sl[i]=i+1;
            }
            else sl[i]=i-st.top();
            
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; --i){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                sr[i]=n-i;
            }
            else sr[i]=st.top()-i;
            
            st.push(i);
        }
        
        long long ans = 0;
        int mod = 1e9+7;
        for(int i=0; i<n; ++i){
            ans = (ans + arr[i] * (long long)sl[i] * sr[i]) % mod;
        }
        
        return ans;
    }
};