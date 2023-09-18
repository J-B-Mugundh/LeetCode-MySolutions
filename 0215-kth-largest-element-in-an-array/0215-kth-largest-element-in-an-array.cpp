class Solution {
public:
    // int findKthLargest(vector<int>& nums, int k) {
    //     // Using max-heap
    //     priority_queue<int> heap(nums.begin(), nums.end());
    //     int ans = 0;
    //     while(k--){
    //         ans = heap.top();
    //         heap.pop();
    //     }
    //     return ans;
    // }

    int findKthLargest(vector<int> &nums, int k){
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int num : nums){
            if(pq.size() < k)
                pq.push(num); // Storing the first k largest elements
            else{
                if(pq.top() < num){  // Do it only if top is less than num. If top is greater than num, there is no need to add it into min heap as we already have the current k largest elements
                    pq.pop();
                    pq.push(num);
                }
            }
        }

        return pq.top();
    }
};