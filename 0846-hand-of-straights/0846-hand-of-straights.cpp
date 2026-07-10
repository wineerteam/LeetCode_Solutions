class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // size of hand
        int n = hand.size();

        // if grouPsize se not divide len it means not possible grouping 
        if( n % groupSize != 0) 
         return false;

         //use order map to stred freeq in order
         map<int, int> mp;
         
         // stored freq 
         for( int &num : hand)
          mp[num]++;

        // main logic 
        while( !mp.empty()){
            int curr = mp.begin()-> first;

            // next number ka freq nhi h ,so grouping not possible
            for( int i=0; i<groupSize; i++){
            if( mp[curr + i] == 0) 
                return false;

            mp[curr+i]--;
               // remove bq freq khatam ho gya 
            if( mp[curr+i] < 1)   
            mp.erase(curr+i);
        }
        }
        return true;
    }
};

// time complexity Tc 