SELECT Department.Name, a.Name, a.Salary
FROM Department
JOIN Employee a
ON a.DepartmentId = Department.Id
WHERE (SELECT COUNT(DISTINCT(b.Salary))
       FROM Employee b
       WHERE a.Salary < b.Salary AND
             a.DepartmentId = b.DepartmentId) < 3;
