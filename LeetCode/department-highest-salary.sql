SELECT Department.Name, Employee.Name, Employee.Salary
FROM Department
JOIN Employee
ON Employee.DepartmentId = Department.Id
WHERE Employee.Salary = (SELECT MAX(Employee.Salary)
                         FROM Employee
                         WHERE Employee.DepartmentId = Department.Id);
