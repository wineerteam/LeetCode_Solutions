typedef long long ll;
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int MAX = 50000;
        vector<ll> freq(MAX+1, 0);
        for(auto x: nums) freq[x]++;
        vector<ll> multiples(MAX+1, 0);
        for(int g=1; g<=MAX; g++) {
            for(int k=g; k<=MAX; k+=g) multiples[g] += freq[k];
        }
        vector<ll> count(MAX+1, 0);
        for(int g=MAX; g>=1; g--){
            if(multiples[g] < 2){
                count[g]=0;
                continue;
            }
            count[g] = multiples[g]*(multiples[g]-1)/2;
            for(int k=2*g; k<=MAX; k+=g){
                count[g] -= count[k];
            }
        }
        int qn = queries.size();
        vector<pair<ll, int>> qs;
        for(int i=0;i<qn;i++) qs.emplace_back(queries[i], i);
        sort(qs.begin(), qs.end());
        vector<int> answer(qn);
        ll total =0;
        int g=1;
        int current =0;
        while(g<=MAX && current < qn){
            total += count[g];
            while(current < qn && qs[current].first < total){
                answer[qs[current].second] = g;
                current++;
            }
            g++;
        }
        return answer;
    }
};