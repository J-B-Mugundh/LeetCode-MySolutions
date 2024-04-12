class Solution {
public:
    // // Better approach - T.C => O(n) , S.C => O(n)
    // int trap(vector<int>& height) {
    //     int n = height.size();
    //     if (n <= 2) return 0;

    //     vector<int> leftMax(n), rightMax(n);
    //     int maxSoFar = height[0];

    //     // Compute leftMax
    //     for (int i = 1; i < n; i++) {
    //         leftMax[i] = maxSoFar;
    //         maxSoFar = max(maxSoFar, height[i]);
    //     }

    //     maxSoFar = height[n - 1];

    //     // Compute rightMax
    //     for (int i = n - 2; i >= 0; i--) {
    //         rightMax[i] = maxSoFar;
    //         maxSoFar = max(maxSoFar, height[i]);
    //     }

    //     int trappedWater = 0;

    //     // Calculate trapped water for each position
    //     for (int i = 1; i < n - 1; i++) {
    //         int minHeight = min(leftMax[i], rightMax[i]);
    //         if (minHeight > height[i]) {
    //             trappedWater += minHeight - height[i];
    //         }
    //     }

    //     return trappedWater;
    // }

    // Optimal approach => T.C = O(n), S.C = O(1)
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int trappedWater = 0, maxLeft = 0, maxRight = 0;

        while(left <= right){
            if(height[left] <= height[right]) // This condition makes sure that, in right half, there is someone >= height[left]
            {
                if(height[left] >= maxLeft)
                    maxLeft = height[left];
                else 
                    trappedWater += maxLeft - height[left];

                left++;
            }
            else // This condition makes sure that, in left half, there is someone >= height[right]
            {
                if(height[right] >= maxRight)
                    maxRight = height[right];
                else
                    trappedWater += maxRight - height[right];
                
                right--;
            }
        }
        return trappedWater;
    }


};