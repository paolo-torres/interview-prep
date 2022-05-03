# Guide

## 1. What/Why

- What are we designing? Why do we need it?

## 2. Requirements and Goals of the System

- List functional and non-functional requirements.
- Functional: Depends on question, actual things the system needs to serve its purpose.
- Non-Functional: Ex. highly available (never down), real-time/min latency (fast), highly reliable, scalable, consistency (different data seen by users), trade-offs between these depending on question.

## 3. Some Design Considerations

- Limitations to stop abuse/stop overload?
- Read or write heavy? Read/write ratio?

## 4. Capacity Estimation and Constraints

- Make assumptions and just throw out some reasonable numbers.
- Traffic estimates: # of users (total, daily), reads, writes.
- Storage estimates: # of objects, how long to store.
- Bandwidth estimates: Usage, requests/queries per second.
- Memory estimates: 80-20 rule, 20% of activity generates 80% of traffic.

## 5. System APIs

- Define endpoints that clients will use to interact with server.
- Write endpoints, list out parameters, and mention return value (JSON common).
- create/post/upload, get/search, delete

## 6. Database Schema

- Write out schema in tables.
- Separate object and metadata.
- Maintain a hash to these tables for quick access.
- SQL: MySQL if need relationships between objects. Scale issues.
- NoSQL: DynamoDB for key-value store, Cassandra for huge data.
- Hadoop, S3: File storage.

## 7. High Level Design/Algorithm

- Draw initial iteration of diagram.
- Clients, servers, services, databases/storages.
- Add APIs between clients and servers.
- Discuss limitations of current design and transition to improvements.

## 8. Detailed Component Design

- Describe each component and iterate on them.
- Load balancers, caches, replicate servers/services/databases/caches, aggregator servers, more servers, more services, synchronization/processing queue, CDN

## 9. Data Partitioning, Sharding, Replication

Data Partitioning:
- Range-Based Partitioning: [a-m][n-z], problem: unbalanced.
- Hash-Based Partitioning: Hash of object to calculate which partition it goes to.

Data Sharding:
- 1st partitioning based on UserID: problem is hot users, non-uniform dist. Can be solved with consistent hashing.
- 2nd partitioning based on objectID: better, more spread out, uniform dist. Hash function to map objectID to server.
- If 2nd, need to query all servers and each returns a set, then a centralized server aggregates. Add aggregation servers to diagram.
- 3rd way based on time, hash on time + ID
- Still, depends on question.

## 10. Caching

- Add cache next to database in diagram.
- Clients/servers should hit cache first before checking database.
- Cache 20% of most prominent thing for each shard (80-20 rule). Or most recent data.
- Cache eviction policy: Least Recently Used (LRU).

## 11. Load Balancing

- 3 places:
    - Clients <-> application servers
    - Application servers <-> database servers
    - Application servers <-> cache servers
- Almost always add between clients and application servers.
- Round Robin approach: simple, no overhead, can take dead servers out. Problem: doesn't take server load into account. To handle this, periodically query backend server about its load and adjust traffic accordingly.

## 12. Reliability, Redundancy, Fault Tolerance

- Duplicate existing servers, databases, storage, load balancers, and caches in the diagram. Duplicate things for failovers.
- ACID: atomicity, consistency, isolation, durability.
- If both primary and secondary servers die, build a reverse index to map objectIDs back to their index, more efficient.

## 13. Ranking, Push/Pull/Hybrid, Long Polling, CDN, etc.

- Ranking: Instead of returning by most recent, return by popularity.

- Push: Servers push data to clients. Problem is hot users.
- Pull: Client pull data from servers. Problems are stale data and empty.
- Hybrid: Hot users pull, normal users push.

- Long Polling: Server holds client request open and waits for response to become available, then sends.

- CDN: For media (video, images, photos), hosts content closer geographically to users.
- Add CDN next to client on diagram.
