record Pair<T, U>(T first, U second) {}
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        ArrayList<Integer> ans = new ArrayList<>();
        int left = 0;
        int right = 0;
        int n = nums.length;
        // Priority Queue in java are by-default sorted in ascending order or minHeap
               // Fix 4: Use explicit lambda comparator to sort Pairs by 'first' in descending order
        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>(
            (a, b) -> Integer.compare(b.first(), a.first())
        );


        while(right < n){
            pq.add(new Pair<> (nums[right], right));
            if(right - left + 1 < k){
                right++;
                continue;
            }
            
            while(pq.peek().second() < right - k + 1){
                pq.poll();
                left++;
            }
            ans.add(pq.peek().first());
            // ans.push_back(pq.top().first);
            right++;
        }

        int result[] = new int[ans.size()];
        for(int i=0; i<ans.size(); i++){
            result[i] = ans.get(i);
        }
        
        return result;
    }
}