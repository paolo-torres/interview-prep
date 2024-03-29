# Data Partitioning

Data partitioning is a technique to break up a big database (DB) into many smaller parts. It is the process of splitting up a DB/table across multiple machines to improve the manageability, performance,availability, and load balancing of an application.

___

## 1. Partitioning Methods

There are many different schemes one could use to decide how to break up an application database into multiple smaller DBs.

**a. Horizontal Partitioning:** Put different rows into different tables.
For example, if we are storing different places in a table, we can decide that locations with ZIP codes less than 10,000 are stores in one table, and places with ZIP codes greater than 10,000 are stored in a separate table. This is also known as data sharding.

**b. Vertical Partitioning:** Divide data to store tables related to a specific feature in their own server. For example, if we are building an Instagram-like application - where we need to store data related to users, photos they upload, and people they follow - we can decide to place user profile information on one DB server, friends list on another, and photos on a 3rd server.

**c. Directory Based Partitioning:** Create a lookup service which knows your current partitioning scheme and abstracts it away from the DB access code. So, to find out where a particular data entry resides, we query the directory server that holds the mapping between each tuple key to its DB server.

___

## 2. Partitioning Criteria

**a. Key or Hash-Based Partitioning:** Apply a hash function to some key attributes of the entity we are storing; that yields the partition number.

**b. List Partitioning:** Each partition is assigned a list of values, so whenever we want to insert a new record, we will see which partition contains our key and then store it there.

**c. Round-Robin Partitioning:** There is a very simple strategy that ensures uniform data distribution. With 'n' partitions, the 'i' tuple is assigned to partition (i mod n).

**d. Composite Partitioning:** Combine any of the above partitioning schemes to devise a new scheme. Consistent hashing could be considered a composite of hash and list partitioning where the hash reduces the key space to a size that can be listed.

___

## 3. Common Problems of Data Partitioning

Some constraints/additional complexities introduced by partitioning:

**a. Joins and Denormalization:** Performing joins on a database which is running on one server is straightforward, but once a database is partitioned and spread across multiple machines, it is often not feasible to perform joins that span database partitions.

**b. Referential Integrity:** Trying to enforce data integrity constraints such as foreign keys in a partitioned database can be difficult. Most of RDBMS do not support foreign key constraints across databases on different database servers, applications have to run regular SQL jobs to clean up dangling references.

**c. Rebalancing:** There could be many reasons to change our scheme:
1. The data distribution is not uniform.
2. There is a lot of load on a partition.

Have to rebalance existing partitions, which means the partitioning scheme changed and all existing data moved to new locations.
