package dailyquestion;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * <a href="https://leetcode.cn/problems/employee-importance/description/">员工的重要性</a>
 *
 * @author sutong
 * @date 2024-08-26 16:33
 */
public class EmployeeImportance_690 {

    private Map<Integer, Employee> map = new HashMap<>();

    public int getImportance(List<Employee> employees, int id) {
        for (Employee employee : employees) {
            map.put(employee.id, employee);
        }
        return dfs(id);
    }

    private int dfs(int id) {
        Employee employee = map.get(id);
        int res = employee.importance;
        for (Integer subordinateId : employee.subordinates) {
            res += dfs(subordinateId);
        }
        return res;
    }


    // employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
    public int getImportance2(List<Employee> employees, int id) {
        int res = 0;
        for (Employee employee : employees) {
            if (employee.id == id) {
                res += employee.importance;
                for (Integer subordinateId : employee.subordinates) {
                    res += getImportance2(employees, subordinateId);
                }
                break;
            }
        }
        return res;
    }

    static class Employee {
        public int id;
        public int importance;
        public List<Integer> subordinates;
    }
}
