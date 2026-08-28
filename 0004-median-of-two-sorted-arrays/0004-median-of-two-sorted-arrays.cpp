class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans=0;
        int n=nums1.size();
        int m=nums2.size();

        vector<int>a(n+m);

        int i=0,j=0,k=0;
        while(i<n && j<m){
            
            if(nums1[i] <= nums2[j]){
                a[k++]=nums1[i++];
            }
            else
                a[k++]=nums2[j++];
             
        }
        while(i<n){
            a[k++]=nums1[i++];
        }
        while(j<m){
            a[k++]=nums2[j++];
        }

        n=a.size();

       
        ans=(n%2==1)?(a[n/2]):(a[n/2]+a[(n/2)-1])/2.0;

        return ans;
    }
};