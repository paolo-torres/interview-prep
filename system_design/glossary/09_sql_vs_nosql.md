# SQL vs. NoSQL

In the world of databases, there are 2 main types of solutions: SQL and NoSQL (or relational databases and non-relational databases). Relational databases are structured and have predefined schemas like phone books that store phone numbers and addresses. Non-relational databases are unstructured, distributed, and have a dynamic schema like file folders that hold everything from a person's address and phone number, to their Facebook 'likes' and online shopping preferences.

___

## SQL

Relational databases store data in rows and columns. Each row contains all the information about one entity and each column contains all the separate data points.

___

## NoSQL

Most common types of NoSQL:

**Key-Value Stores:** Data is stored in an array of key-value pairs. Well-known key-value stores include Redis, Voldemort, and Dynamo.

**Document Databases:** Data is stored in documents (instead of rows and columns in a table) and these documents are grouped together in collections. Document databases include the CouchDB and MongoDB.

**Wide-Column Databases:** Instead of 'tables', in columnar databases we have column families, which are containers for rows. Columnar databases are best suited for analyzing large datasets - big names include Cassandra and HBase.

**Graph Databases:** Data is saved in graph structures with nodes (entities), properties (information about the entities), and lines (connections between the entities). Examples of graph databases include Neo4J and InfiniteGraph.

___

## High Level Differences Between SQL and NoSQL

**Storage:** SQL stores data in tables where each row represents an entity and each column represents a data point about that entity; for example, if we are storing a car entity in a table, different columns could be 'Color', 'Make', 'Model', and so on. NoSQL databases have different data storage models, main ones are key-value, document, graph, and columnar.

**Schema:** In SQL, each record conforms to a fixed schema, meaning the columns must be decided and chosen before data entry and each row must have data for each column. In NoSQL, schemas are dynamic, columns can be added on the fly and each 'row' (or equivalent) doesn't have to contain data for each 'column'.

**Querying:** SQL databases use SQL (structured query language) for defining and manipulating the data, which is very powerful. In a NoSQL database, queries are focused on a collection of documents.

**Scalability:** In most common situations, SQL databases are vertically scalable, i.e., by increasing the horsepower (higher memory, CPU, etc.) of the hardware, which can get very expensive. On the other hand, NoSQL databases are horizontally scalable, meaning we can add more servers easily in our NoSQL database infrastructure to handle a lot of traffic.

**Reliability:** The vast majority of relational databases are data reliable, there is a safe guarantee of performing transactions, SQL databases are the better bet. Most of the NoSQL solutions sacrifice reliability for performance and scalability.

___

## SQL vs. NoSQL - Which One to Use?

When it comes to database technology, there's no one size fits all solution. Even as NoSQL databases are gaining popularity for their speed and scalability, there are still situations where a highly structured SQL database may perform better, depends on use case.

### **Reasons to use SQL database:**

1. We need to ensure reliability. Reliability reduces anomalies and protects the integrity of your database by prescribing exactly how transactions interact with the database. For many e-commerce and financial applications, a reliable database remains preferred.
2. Your data is structured and unchanging. If your business is not experiencing massive growth that would require more servers and if you're only working with data that is consistent, SQL better.

### **Reasons to use NoSQL database:**

When all the other components of our application are fast and seamless,
NoSQL databases prevent data from being the bottleneck. A few popular
examples of NoSQL databases are MongoDB, CouchDB, Cassandra, and HBase.

1. Storing large volumes of data that often have little to no structure. A NoSQL database sets no limits on the types of data we can store together and allows us to add new types as the need changes.
2. Making the most of cloud computing and storage. Using commodity (affordable, smaller) hardware on-site or in the cloud saves you the hassle of additional software and NoSQL databases like Cassandra are designed to be scaled across multiple data centers out of the box.
3. Rapid development. NoSQL is extremely useful for rapid development as it doesn't need to be prepped ahead of time.
