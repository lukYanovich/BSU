package com.company;

/**
 * Created by Александр on 29.09.2016.
 */
public class Counter {
    private static int counterOfInc = 1, counterOfDec = 1, maxCounterOfInc = 1, maxCounterOfDec = 1;

    public static class Inner {
        public static int getMaxInc() {
            return maxCounterOfInc;
        }

        public static int getMaxDec() {
            return maxCounterOfDec;
        }

        public static void cleanCounter() {
            counterOfInc = counterOfDec = 1;
        }

        private static void checkInc() {
            if (counterOfInc > maxCounterOfInc)
                maxCounterOfInc = counterOfInc;
            counterOfInc = 1;
        }

        private static void checkDec() {
            if (counterOfDec > maxCounterOfDec)
                maxCounterOfDec = counterOfDec;
            counterOfDec = 1;
        }

        public static void check(int a, int b) {
            if (a < b) {
                counterOfInc++;
                checkDec();
            } else if (a > b) {
                counterOfDec++;
                checkInc();
            } else if (a == b) {
                checkDec();
                checkInc();
            }
        }
    }
}
