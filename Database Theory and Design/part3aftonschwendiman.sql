-- Part 3 - Afton Schwendiman

CREATE TABLE Branches (
  ID INTEGER,
  Type CHAR(1),
  Phone INTEGER,
  Address VARCHAR(255),
  CONSTRAINT BPK
    PRIMARY KEY(ID),
  CONSTRAINT BRANCHTYPE
    CHECK (Type IN ('F','R'))
);

CREATE TABLE Locations (
  BranchID INTEGER,
  Street VARCHAR(10),
  City VARCHAR(10),
  St CHAR(2),
  Zip INTEGER,
  CONSTRAINT LPK
    PRIMARY KEY(BranchID),
  CONSTRAINT LBIDFK
    FOREIGN KEY (BranchID) REFERENCES Branches(ID)
      ON DELETE SET null
      ON UPDATE CASCADE
);

CREATE TABLE Models (
  ID INTEGER,
  Name VARCHAR(10),
  Sqft INTEGER,
  Beds INTEGER,
  Baths INTEGER,
  MSRP FLOAT,
  CONSTRAINT MPK
    PRIMARY KEY(ID),
  CONSTRAINT MNAME
    UNIQUE(Name)
);

CREATE TABLE Employees (
  ID INTEGER,
  Fname VARCHAR(15) NOT NULL,
  Lname VARCHAR(15) NOT NULL,
  Birth INTEGER,
  Gender CHAR(1) ,
  Phone INTEGER,
  Dept VARCHAR(10) NOT NULL,
  Position VARCHAR(10) NOT NULL,
  BranchID INTEGER,
  Salary FLOAT DEFAULT null,
  Hourly FLOAT DEFAULT null,
  CONSTRAINT EPK
    PRIMARY KEY(ID),
  CONSTRAINT EGENDER
    CHECK (Gender IN ('M', 'F', 'O')),
  CONSTRAINT EBIDFK
    FOREIGN KEY (BranchID) REFERENCES Branches(ID) ON DELETE SET null ON UPDATE CASCADE
);

CREATE TABLE Customers (
  ID INTEGER,
  Fname VARCHAR(15) NOT NULL,
  Lname VARCHAR(15) NOT NULL,
  Birth INTEGER,
  Gender CHAR(1),
  Phone INTEGER NOT NULL,
  Address VARCHAR(30),
  CONSTRAINT CPK
    PRIMARY KEY(ID),
  CONSTRAINT CGENDER
    CHECK (Gender IN ('M', 'F', 'O'))
);

CREATE TABLE Orders (
  Serial INTEGER,
  ModelID INTEGER,
  EmployeeID INTEGER,
  CustomerID INTEGER,
  Mfgdate INTEGER,
  FactoryID INTEGER,
  RetailID INTEGER,
  CONSTRAINT OPK
    PRIMARY KEY(Serial),
  CONSTRAINT OMODELFK
    FOREIGN KEY (ModelID) REFERENCES Models(ID) ON DELETE SET null ON UPDATE CASCADE,
  CONSTRAINT OEMPLOYEEFK
    FOREIGN KEY (EmployeeID) REFERENCES Employees(ID) ON DELETE SET null ON UPDATE CASCADE,
  CONSTRAINT OCUSTOMERFK
    FOREIGN KEY (CustomerID) REFERENCES Customers(ID) ON DELETE SET null ON UPDATE CASCADE,
  CONSTRAINT OFACTORYFK
    FOREIGN KEY (FactoryID) REFERENCES Branches(ID) ON DELETE SET null ON UPDATE CASCADE,
  CONSTRAINT ORETAILFK
    FOREIGN KEY (RetailID) REFERENCES Branches(ID) ON DELETE SET null ON UPDATE CASCADE
);

CREATE TABLE Destinations (
  Serial INTEGER,
  Street VARCHAR(10),
  City VARCHAR(10),
  St CHAR(2),
  Zip INTEGER,
  CONSTRAINT DPK
    PRIMARY KEY(Serial),
  CONSTRAINT DFK
    FOREIGN KEY (Serial) REFERENCES Orders(Serial) ON DELETE SET null ON UPDATE CASCADE
);

INSERT INTO Branches (ID, Type, Phone) VALUES (1, 'F', 5551234);
INSERT INTO Branches (ID, Type, Phone) VALUES (4, 'R', 5555678);
INSERT INTO Branches (ID, Type, Phone) VALUES (2, 'F', 5559999);
INSERT INTO Branches (ID, Type, Phone) VALUES (5, 'R', 5552189);
INSERT INTO Branches (ID, Type, Phone) VALUES (3, 'F', 5552209);

INSERT INTO Orders (Serial, ModelID, EmployeeID, CustomerID, Mfgdate, FactoryID, RetailID) VALUES (1, 1, 2, 1, 10122023, 1, 4);
INSERT INTO Orders (Serial, ModelID, EmployeeID, CustomerID, Mfgdate, FactoryID, RetailID) VALUES (2, 2, 3, 2, 12122022, 1, 5);
INSERT INTO Orders (Serial, ModelID, EmployeeID, CustomerID, Mfgdate, FactoryID, RetailID) VALUES (3, 1, 4, 2, 01102021, 2, 4);
INSERT INTO Orders (Serial, ModelID, EmployeeID, CustomerID, Mfgdate, FactoryID, RetailID) VALUES (4, 2, 4, 3, 03052021, 3, 5);
INSERT INTO Orders (Serial, ModelID, EmployeeID, CustomerID, Mfgdate, FactoryID, RetailID) VALUES (5, 3, 5, 4, 01112022, 2, 4);

INSERT INTO Destinations (Serial, Street, City, St, Zip) VALUES (1, '123 Street', 'San Marcos', 'TX', 12345);
INSERT INTO Destinations (Serial, Street, City, St, Zip) VALUES (2, '1 Forest Drive', 'Austin', 'TX', 78681);
INSERT INTO Destinations (Serial, Street, City, St, Zip) VALUES (3, '321 Elm St', 'Springfield', 'IL', 62701);
INSERT INTO Destinations (Serial, Street, City, St, Zip) VALUES (4, '18 Avenue A', 'Denver', 'CO', 88888);
INSERT INTO Destinations (Serial, Street, City, St, Zip) VALUES (5, '666 Hwy 1', 'Boston', 'MA', 12345);

INSERT INTO Locations (BranchID, Street, City, St, Zip) VALUES (1, '1 Main St', 'Opal', 'TX', 92048);
INSERT INTO Locations (BranchID, Street, City, St, Zip) VALUES (2, '2 First St', 'Newtown', 'CA', 62701);
INSERT INTO Locations (BranchID, Street, City, St, Zip) VALUES (3, '3 Other St', 'Sorrow', 'CO', 62039);
INSERT INTO Locations (BranchID, Street, City, St, Zip) VALUES (4, '4 Another St', 'Tape', 'ID', 81930);
INSERT INTO Locations (BranchID, Street, City, St, Zip) VALUES (5, '5 Main St', 'Color', 'OK', 28339);

INSERT INTO Models (ID, Name, Sqft, Beds, Baths, MSRP) VALUES (1, 'Cozy Cottage', 1000, 2, 1, 150000.00);
INSERT INTO Models (ID, Name, Sqft, Beds, Baths, MSRP) VALUES (2, 'Creepy Cottage', 1100, 3, 2, 500000.00);
INSERT INTO Models (ID, Name, Sqft, Beds, Baths, MSRP) VALUES (3, 'Small Cottage', 1200, 4, 1, 800000.00);
INSERT INTO Models (ID, Name, Sqft, Beds, Baths, MSRP) VALUES (4, 'Cold Cottage', 1300, 4, 2, 200000.00);
INSERT INTO Models (ID, Name, Sqft, Beds, Baths, MSRP) VALUES (5, 'Candy Cottage', 1400, 2, 2, 350000.00);

INSERT INTO Employees (ID, Fname, Lname, Birth, Gender, Phone, Dept, Position, BranchID, Salary, Hourly) VALUES (1, 'Albert', 'Einstein', 1980, 'M', 5551234, 'Sales', 'Associate', 1, 50000.00, NULL);
INSERT INTO Employees (ID, Fname, Lname, Birth, Gender, Phone, Dept, Position, BranchID, Salary, Hourly) VALUES (2, 'Benjamin', 'Franklin', 1940, 'M', 5555678, 'Sales', 'Associate', 2, NULL, 20.00);
INSERT INTO Employees (ID, Fname, Lname, Birth, Gender, Phone, Dept, Position, BranchID, Salary, Hourly) VALUES (3, 'Cindy', 'Hudson', 1981, 'F', 5559999, 'Manufacturing', 'Manager' , 3, 100000.00, NULL);
INSERT INTO Employees (ID, Fname, Lname, Birth, Gender, Phone, Dept, Position, BranchID, Salary, Hourly) VALUES (4, 'Ollie', 'Jones', 1970, 'M', 23490876, 'Manufacturing', 'Associate', 4, NULL, 30.00);
INSERT INTO Employees (ID, Fname, Lname, Birth, Gender, Phone, Dept, Position, BranchID, Salary, Hourly) VALUES (5, 'b12', 'Django', 1965, 'M', 5558769, 'Sales', 'Manager', 5, 70000.00, NULL);

INSERT INTO Customers (ID, Fname, Lname, Birth, Gender, Phone, Address) VALUES (1, 'Jane', 'Smith', 1965, 'F', 5555678, '1 Elm St');
INSERT INTO Customers (ID, Fname, Lname, Birth, Gender, Phone, Address) VALUES (2, 'Jessica', 'Pezzuto', 1970, 'F', 5523478, '2 Elm St');
INSERT INTO Customers (ID, Fname, Lname, Birth, Gender, Phone, Address) VALUES (3, 'Jonathon', 'Arugula', 1985, 'M', 5534578, '3 Elm St');
INSERT INTO Customers (ID, Fname, Lname, Birth, Gender, Phone, Address) VALUES (4, 'Andrew', 'Galipeau', 1980, 'M', 5554568, '4 Elm St');
INSERT INTO Customers (ID, Fname, Lname, Birth, Gender, Phone, Address) VALUES (5, 'Summer', 'Smith', 1990, 'F', 5675678, '5 Elm St');

-- 1) General Queries
-- A) 2 Summary Statistics as per general business aim.
-- The general business aim is to sell houses, make money.  The statistics most relevant to the business aim involve profit (MSRP) on orders and expenses, which at this time the database only considers employee salaries/wages.
-- 1.  Show sum of all order profits (MSRP), sum of all employee salaries, sum of all hourly employees wages for 1 year (2000 hours), sum of all employee expenses (salary and hourly), net profit (sum MSRP - sum employee expenses).
SELECT
  SUM(m.MSRP) AS Total_MSRP,
  SUM(e.Salary) AS Total_Salary,
  SUM(e.Hourly * 2000) AS Total_Hourly,
  SUM(e.Salary) + SUM(e.Hourly * 2000) AS Total_Wages,
  SUM(m.MSRP) - SUM(e.Salary) - SUM(e.Hourly * 2000) AS Net_Profit
FROM
    Orders o, Models m
JOIN
    Employees e ON o.EmployeeID = e.ID;

-- 2. Display models in order of gross profit (assumed total MSRP for all orders for each model) to determine which models are making the business the most money.
SELECT ModelID, SUM(MSRP) AS TotalSales
FROM Orders
JOIN Models ON Orders.ModelID = Models.ID
GROUP BY ModelID
ORDER BY TotalSales DESC;

-- B) 1 Transaction from the business perspective.
-- Suppose an employee leaves the company and a new employee must be assigned to handle their orders.
BEGIN TRANSACTION;
-- Step 1: Update all orders where EmployeeID = 1 to EmployeeID = 2
UPDATE Orders
SET EmployeeID = 2
WHERE EmployeeID = 1;
-- Step 2: Delete Employee with ID = 1 from the Employees table
DELETE FROM Employees
WHERE ID = 1;
COMMIT;

-- C) 1 Data inseriton query where a constraint needs to be preserved.
INSERT INTO Employees (ID, Fname, Lname, Birth, Gender, Phone, Dept, Position, BranchID, Salary, Hourly)
VALUES 
  (6, 'Lady', 'Gaga', 1980, 'F', 1234567890, 'Sales', 'Associate', 1, 70000.00, NULL),
  (7, 'Taylor', 'Swift', 1985, 'F', 9876543210, 'Sales', 'Associate', 2, 60000.00, NULL),
  (8, 'Sam', 'Smith', 1978, 'M', 5555555555, 'Sales', 'Associate', 1, 65000.00, NULL);

-- D) 1 Data deletion query where a constraint needs to be preserved.  This deletion was chosen because there are several foreign key references in the orders table.  It's important that constraints are preserved.
DELETE FROM Orders
WHERE Serial = 2;

-- 2) Specific Queries
-- Considering your specific business scenario, develop 5 queries that would demonstrate average (operational) and specialized (analysis) usage for this database.  Think of it as queries that would reveal the value proposition for this project, given its unique declaration of purpose for a possible manager/client.

-- 1/5. Display employees in order of total sales (MSRP) for associated orders and display in descending order, to determine the top sales associates.
SELECT EmployeeID, SUM(MSRP) AS TotalSales
FROM Orders
JOIN Models ON Orders.ModelID = Models.ID
GROUP BY EmployeeID
ORDER BY TotalSales DESC;

-- 2/5. Display employees in order of total sales (quantity sold) and display in descending order, to determine which employees are closing the most deals.
SELECT EmployeeID, COUNT(*) AS OrderCount
FROM Orders
GROUP BY EmployeeID
ORDER BY OrderCount DESC;

-- 3/5. Display number if orders for each model (descending) to determine which models are most popular.
SELECT ModelID, COUNT(ModelID) AS OrderCount
FROM Orders
GROUP BY ModelID
ORDER BY OrderCount DESC;

-- 4/5 Give a 10% raise to all hourly employees.
UPDATE Employees
SET Hourly = Hourly * 1.10
WHERE Hourly > 0;

-- 5/5 Compare the avg. salary/wage of female employee to that of male employees.
SELECT
    AVG(CASE WHEN Gender = 'M' THEN Salary END) AS AvgMaleSalary,
    AVG(CASE WHEN Gender = 'F' THEN Salary END) AS AvgFemaleSalary,
    AVG(CASE WHEN Gender = 'M' THEN Hourly END) AS AvgMaleHourlyWage,
    AVG(CASE WHEN Gender = 'F' THEN Hourly END) AS AvgFemaleHourlyWage
FROM Employees
WHERE Gender IN ('M', 'F');

