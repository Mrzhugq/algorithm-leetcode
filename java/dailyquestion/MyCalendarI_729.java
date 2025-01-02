package dailyquestion;

import java.util.ArrayList;
import java.util.List;

/**
 * <a href="https://leetcode.cn/problems/my-calendar-i/description/">我的日程安排表 I</a>
 *
 * @author sutong
 * @date 2025-01-02 14:58
 */
public class MyCalendarI_729 {

    class MyCalendar {
        List<int[]> booked;

        public MyCalendar() {
            booked = new ArrayList<>();
        }

        public boolean book(int startTime, int endTime) {
            for (int[] book : booked) {
                if (book[1] > startTime && endTime > book[0]) {
                    return false;
                }
            }
            booked.add(new int[]{startTime, endTime});
            return true;
        }

    }

}
