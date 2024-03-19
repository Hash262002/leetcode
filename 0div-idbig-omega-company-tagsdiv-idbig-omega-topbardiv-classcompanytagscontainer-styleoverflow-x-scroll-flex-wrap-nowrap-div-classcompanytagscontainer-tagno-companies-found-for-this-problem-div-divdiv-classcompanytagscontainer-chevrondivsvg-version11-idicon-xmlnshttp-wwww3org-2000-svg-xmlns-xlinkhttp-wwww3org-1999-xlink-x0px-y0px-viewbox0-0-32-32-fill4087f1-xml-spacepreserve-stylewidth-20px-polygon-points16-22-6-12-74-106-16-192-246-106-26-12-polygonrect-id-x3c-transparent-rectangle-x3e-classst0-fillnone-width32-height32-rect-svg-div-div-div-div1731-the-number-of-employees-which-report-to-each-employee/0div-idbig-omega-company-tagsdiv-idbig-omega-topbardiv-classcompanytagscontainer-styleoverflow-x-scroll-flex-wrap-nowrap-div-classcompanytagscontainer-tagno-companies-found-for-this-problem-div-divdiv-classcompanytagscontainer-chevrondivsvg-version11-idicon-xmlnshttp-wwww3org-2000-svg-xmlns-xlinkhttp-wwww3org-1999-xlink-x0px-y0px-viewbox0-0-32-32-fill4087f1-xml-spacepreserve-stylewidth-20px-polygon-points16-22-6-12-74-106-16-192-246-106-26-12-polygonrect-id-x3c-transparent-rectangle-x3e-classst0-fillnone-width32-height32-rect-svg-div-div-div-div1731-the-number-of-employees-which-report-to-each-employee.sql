SELECT E1.EMPLOYEE_ID,E1.NAME,E2.REPORTS_COUNT,E2.AVERAGE_AGE FROM EMPLOYEES E1 INNER JOIN (SELECT REPORTS_TO AS EMPLOYEE_ID, COUNT(E.EMPLOYEE_ID) AS REPORTS_COUNT, ROUND(AVG(AGE) ,0) AS AVERAGE_AGE FROM EMPLOYEES E GROUP BY REPORTS_TO) E2 ON E1.EMPLOYEE_ID=E2.EMPLOYEE_ID ORDER BY E1.EMPLOYEE_ID