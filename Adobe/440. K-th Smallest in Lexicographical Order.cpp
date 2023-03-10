class Solution {
public:
    long long get_count(long long prefix, long long n){
        long long upper=prefix+1, cnt=0;
        while(prefix<=n){
            cnt += min(n+1,upper)-prefix;
            prefix*=10;
            upper*=10;
        }
        return cnt;
    }

    int findKthNumber(int n, int k) {
        int prefix=1, cnt=1;
        while(cnt<k){
            int tmpcnt=get_count(prefix,n);
            if(tmpcnt+cnt<=k){
                prefix++;
                cnt+=tmpcnt;
            }else{
                prefix*=10;
                cnt++;
            }
        }
        return prefix;
    }
};
