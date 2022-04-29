# System Design Interviews: A Step By Step Guide

### Step 1: Requirements Clarification
### Step 2: Back-of-the-Envelope Estimation
### Step 3: System Interface
### Step 4: Defining Data Model
### Step 5: High-Level Design
### Step 6: Detailed Design
### Step 7: Identifying and Resolving Bottlenecks

---

## Step 1: Requirements Clarification

It is always a good idea to ask questions about the exact scope of the problem we are solving. Design questions are mostly open-ended, and they don't have one correct answer, that's why clarifying ambiguities early in the interview becomes critical.

Let's expand this with an actual example of designing a Twitter-like service. Here are some questions for designing Twitter that should be answered before moving on to next steps:

- Will users of our service be able to post tweets and follow other people?
- Should we also design to create and display the user's timeline?
- Will tweets contain photos and videos?
- Are we focusing on the backend only or are we developing the frontend too?
- Will users be able to search tweets?
- Will there be any push notifications for new (or important) tweets?

---

## Step 2: Back-of-the-Envelope Estimation

It is always a good idea to estimate the scale of the system we're going to design. This will also help later when we will be focusing on scaling, partitioning, load balancing, and caching.

- What scale is expected from the system (e.g., number of new tweets number of tweet views, number of timeline generations/sec, etc.)
- How much storage will we need? We will have different storage requirements if users can have photos and videos in their tweets.
- What network bandwidth usage are we expecting? This will be crucial in deciding how we will manage traffic and balance load between servers.

---

## Step 3: System Interface Definition

Define what APIs are expected from the system. This will not only establish the exact contract expected from the system, but will also ensure if we haven't gotten any requirements wrong. Some examples of APIs for our Twitter-like service will be:

`postTweet(userId, tweetData, tweetLocation, userLocation, timestamp)`

`generateTimeline(userId, currentTime, userLocation)`

`markTweetFavorite(userId, tweetId, timestamp)`

---

## Step 4: Defining Data Model

Defining the data model in the early part of the interview will clarify how data will flow between different components of the system. Later, it will guide for data partitioning and management. Here are some entities for our Twitter-like service:

**User:** UserID, Name, Email, DoB, CreationData, LastLogin

**Tweet:** TweetID, Content, TweetLocation, NumberOfLikes, Timestamp

**UserFollows:** UserID1, UserID2

**FavoriteTweets:** UserID, TweetID, Timestamp

Which database system should we use? Will NoSQL like Cassandra best fit our needs, or should we use a MySQL-like solution? What kind of block storage should we use to store photos and videos?

---

## Step 5: High-Level Design

Draw a block diagram with 5-6 boxes representing the core components of our system. We should identify enough components that are needed to solve the actual problem from end-to-end.

For Twitter, at a high-level, we will need multiple application servers to serve all the read/write requests with load balancers in front of them for traffic distributions. If we're assuming that we will have a lot more read traffic (as compared to write), we can decide to have separate servers for handling these scenarios. On the backend, we need an efficient database that can store all the tweets and can support a huge number of reads. We will also need a distributed file storage system for storing photos and videos.

![00_a_step_by_step_guide](00_a_step_by_step_guide.png)

---

## Step 6: Detailed Design

Dig deeper into 2 or 3 major components; interviewer's feedback should always guide us to what parts of the system need further discussion. We should be able to present different approaches, their pros and cons, and explain why we will prefer one approach over the other. Remember there is no single answer; the only important thing is to consider tradeoffs between different options while keeping system constraints in mind.

- Since we will be storing a massive amount of data, how should we partition our data to distribute it to multiple databases? Should we try to store all the data of a user on the same database? What issue could it cause?
- How will we handle hot users who tweet a lot or follow lots of people?
- Since users' timeline will contain the most recent (and relevant) tweets, should we try to store our data in such a way that is optimized for scanning the latest tweets?
- How much and at which layer should we introduce caching to speed things up?
- What components need better load balancing?

---

## Step 7: Identifying and Resolving Bottlenecks

Try to discuss as many bottlenecks as possible and different approaches to mitigate them.

- Is there any single point of failure in our system? What are we doing to mitigate it?
- Do we have enough replicas of the data so that if we lose a few servers, we can still serve our users?
- Similarly, do we have enough copies of different services running such that a few failures will not cause total system shutdown?
- How are we monitoring the performance of our service? Do we get alerts whenever critical components fail or their performance degrades?
