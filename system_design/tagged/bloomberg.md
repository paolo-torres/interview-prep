# Bloomberg

## Design AWS S3

I explained the consistency model of AWS S3 is eventually consistent and how Bloomberg would want a strictly consistent model. I suggested that when a user queries S3 after inserting data, they should be blocked from retrieving data until the inserted data arrives in all availabilty zones.

The interviewer was suggesting maybe we only need to wait till the data gets replicated to 1 avalability zone and then in the background the data gets replicated to other availability zones.

I also explained that when replicating we want to replicate to the availability zones closest to you.

Note: AWS S3 supports both eventual consistency (for deletion of objects) as well as strong consistency for new objects.

---

## Stock Change Notification System

The start of the interview however mainly focused on the algorithmic approach to the system, which is what this post is focusing on.

The question was to build a stock notification system. The system monitors the stock price of various companies in real time, and a user can subscribe to any of these companies to receive alerts. Specfically, a user would want to receive an alert when the price of a company falls above/below `X%` within `Y` minutes. `X` and `Y` are variables that the user can set, where `X` is the % change and `Y` is the window in which that change can occur.

In terms of the data, you have a constant stream of stock tick data (`stockID`, `price`, `timestamp`). The price of a stock is changing at every millisecond or so. The interviewer was asking questions about algorithmically how you would calculate this change, and wanted to see how you could do it in both a time and space efficient way. A lot of the discussion was focused on how much data would you actually want to log/save. It seems like there should be a way to do this without storing a huge stream of data.

What makes this question a bit more tricky is that you are not just looking at changes between fixed intervals. i.e. Lets say you set an alert for a `X%` change within a 10 minute window. You are not looking whether there is a 10% change at any point between `t = 0` to `t = 9`, then `t = 10` to `t = 19`, etc. Rather you are looking at `t = 0` to `t = 9`, then `t = 1` to `t = 10`, `t = 2` to `t = 11`, etc.

A naive approach to solve this would be to log the data at every millsecond and at every point, iterate backwards for 10 mins to find the minimum and maximum value. Then calculate the % change and see if this change is equal to or bigger than the threshold. This solution would be `O(n * k)` though where `k` is your window size.

I think this can be done better using a min heap and a max heap. At every new datapoint we can do the following:

```
Add KV pair (price, time) to the min heap
Add KV pair (price, time) to the max heap

while the timestamp of the KV pair at the top of our min heap is outside our window 
	poll the min heap 
// (i.e. if our interval is 10, the current time is t = 11 and min heap peek has a time of t = 0, then we would poll this)

// same concept for the max heap
while the timestamp of the KV pair at the top of our max heap is outside our window 
	poll the max heap
	
now peek the min heap and max heap and calculate the % change between them. If it is equal to or above threshold, alert the user.
```

Space complexity of this however would be O(N) worst case (imagine an always increasing stock, the max heap would just keep growing). And I think the time complexity of this would be O(N log K).

Optimal: Sliding Window Maximum

Keep a maximum window of size K, and similarly a minimum window. Need `O(K)` space and `O(N)` time.

```
vector maxSlidingWindow(vector& nums, int y, int x) {
    vector threshold_reached;
    if (y == 0) return result;
    int n = nums.size();

    deque<int> max_q;
    deque<int> min_q;
    
    for (int i = 0; i < n; i++) {
        while (!max_q.empty() && max_q.front() <= i - y) max-q.pop_front();
        while (!min_q.empty() && min_q.front() <= i - y) min_q.pop_front();
        
        while (!max_q.empty() && nums[max_q.back()] <= nums[i]) max_q.pop_back();
        while (!min_q.empty() && nums[min_q.back()] >= nums[i]) min_q.pop_back();
        
        max_q.push_back(i);
        min_q.push_back(i);
        
        if (i >= y - 1){
            int curr_max = nums[max_q.front()];
            int curr_min = nums[min_q.front()];
            bool ans = curr_max - curr_min > x;
            
            threshold_reached.push_back(ans);
        }
    }
    
    return threshold_reached;
}
```

Regarding the systems design part, I guess an important aspect to this is that we would have to stream this data in real time, and we would want to make sure we process each tick in order. So some sort of realtime data processing system would be needed, so things like message queues would maybe come into play here.

There are 1000 companies so we would probably need 1000 sliding window processors (1 for each company).

I feel like this requirement makes this question a bit more tricky:
A user can set whatever % change they like and whatever window size they like (anything up to 1 day).

I guess for a given stock, at every second we calculate the % change (lets say we calculated a 7% change). And then we notify all users who have subscribed for a 7% change alert or below. But how we efficiently deal with varying window sizes I'm not so sure.

I've heard though that they might say the window size can be fixed for everyone. Lets say 10 mins. In which case, I'm thinking maybe batch processing would be a good idea, where the sliding window service will get the stock tick data in maybe 1 hour batches (the batch would have to be larger than the window size, we need to move our 10 minute window across a reasonable timeframe). It can get it from a time series database that we are constantly writing to. However, lets say we just did our sliding window through a batch from t = 0 to t = 60, when we get the t = 60 to t = 120 batch, we would possibly need to iterate from t = 50, depending on the final state of our window in the previous batch. So we shouldn't discard all our data, only data from t = 0 to t = 50.

If we don't do batch processing then we could just do realtime processing in memory, whereby as soon as we get the latest stock data, we would process it into our sliding window service instantly. This would be more consistent and more realtime I guess, but with 1000 stocks we would need 1000 in memory sliding window services running at once.
