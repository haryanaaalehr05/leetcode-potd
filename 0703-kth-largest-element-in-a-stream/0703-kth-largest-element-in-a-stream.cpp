class KthLargest {
public:
     KthLargest(int k, std::vector<int>& nums) : k(k) {
        // Add all elements to the min-heap
        for (int num : nums) {
            minHeap.push(num);
            // If the heap size exceeds k, remove the smallest element
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        // If the heap size exceeds k, remove the smallest element
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        // The root of the heap is the kth largest element
        return minHeap.top();
    }

private:
    int k;  // The kth position
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;  // Min-heap to store k largest elements
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
**/