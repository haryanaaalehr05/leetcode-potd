class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] frequency = new int[1001];
        
        // Count the frequency of each element in arr1
        for (int num : arr1) {
            frequency[num]++;
        }
        
        int[] result = new int[arr1.length];
        int idx = 0;
        
        // Add elements from arr2 in the specified order
        for (int num : arr2) {
            while (frequency[num]-- > 0) {
                result[idx++] = num;
            }
        }
        
        // Add remaining elements in non-decreasing order
        for (int i = 0; i < 1001; i++) {
            while (frequency[i]-- > 0) {
                result[idx++] = i;
            }
        }
        
        return result;
    }
}
