# cse_4110

서강대학교 컴퓨터공학과 Database System 2023년 1학기


## Package Delivery System
Goal: The goal of this project is to provide a realistic experience in the conceptual design, logical design, physical design, query processing implementation and maintenance of a small relational database.

> The application is a package delivery company (e. FedEx, UPS, DHL, CJ
Logistics The company needs to keep track of packages shipped and their
customers. To find out more about this application, think about any experiences
you may have had shipping packages and receiving packages, and browse
shippers’ websites.
In our hypothetical company, the manager assigned to solicit database
design proposals is not very computer literate and is unable to provide a very
detailed specification.


#### Project1
1. E-R Model
   Construct an E-R diagram representing the conceptual design of the database.
2. Relational Schema Diagram
   After creating an E-R model, reduce it into Schema diagram. Create the schema diagram in ERwin Data Modeler.


#### Project2
1. BCNF Decomposition
   Check the logical schema from project1 and decompose your logical Schema to BCNF form if they are not.
2. Physical Schema Diagram
   Create the physical schema diagram using Erwin.
3. Queries
> Type1 Assume truck X is destroyed in a crash  
> [User input for query: truck number]
>> Type1-1) Find all customers who had a package on the truck at the time of the crash  
>> Type1-2) Find all recipients who had a package on that truck at the time of the crash  
>> Type1-3) Find the last successful delivery by that truck prior to the crash.

> Type2 Find the customer who has shipped the most packages in the past year.  
> [User input for query: year]  

    
> Type3 Find the customer who has spent the most money on shipping in the past year.  
> [User input for query: year]

> Type4 Find the packages that were not delivered within the promised time.

> Type5 Generate the bill for each customer for the past month.
> [User input for query: year, month]

Execute these queries within MySQL DBMS  
Use ODBC with C language API to implement your Database model.
