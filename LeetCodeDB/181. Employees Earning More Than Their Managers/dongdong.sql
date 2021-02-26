# Write your MySQL query statement below
# Manager 보다 더 많이 번 사람을 가져와라
SELECT Name AS Employee
FROM Employee AS a
WHERE Salary > (SELECT Salary FROM Employee AS b WHERE a.ManagerId = b.Id);