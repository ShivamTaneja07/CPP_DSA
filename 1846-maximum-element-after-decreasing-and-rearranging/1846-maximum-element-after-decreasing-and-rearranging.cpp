class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int result = 1;
        if(arr[0] != 1) {
            arr[0] = 1;
        }

        for(int i=1; i<arr.size();i++) {
            if(abs(arr[i]-arr[i-1]) > 1) {
                arr[i] = arr[i-1] + 1;
            }
            result = arr[i];
        }

        return result;
    }
};