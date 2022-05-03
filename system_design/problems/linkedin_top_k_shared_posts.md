# LinkedIn Top k Shared Posts

Q: LinkedIn users can share posts with each other and externally (outside of LinkedIn). Design a system that tracks the top N shared posts by the following time-intervals; 1 minute, 1 hour, and 1 day.

- Get requirements, assumptions, constraints, etc.
    - What is this system expected to do? Are all of the events generated for us? Are we only building the ingestion engine + DB for queries?
    - What is the number of users/posts/activity?
    - Do we care more about accuracy or speed of metrics?

- High-Level
    - What does the events look like? How do we store it? How do we process it in the DB?
    - Do we want pre-process before into DB? Or let aggregation engine perform the computation during query time?

- Low-Level
    - Talked about all the tables in the DB.
    - Talked about how do we store the events in the DB.
    - Talked about how will the aggregation engine query for these results.
    - Talked about the API calls that will access the DB.
    - Talked about the amount of read/write ratios.
