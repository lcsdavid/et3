package com.util.Arrays;

public class Arrays {
    static public int[] arrayFromStrings(String [] strings) {
        if(strings == null)
            return null;
        int[] result = new int[strings.length];
        for (int i = 0; i < result.length; i++) {
            if(strings[i] == null)
                result[i] = 0;
            else
                result[i] = strings[i].hashCode();
        }
        return result;
    }

    static public int indexOf(int[] array, int value) {
        if(array == null || array.length == 0)
            return -1;
        for (int i = 0; i < array.length; i++) {
            if(array[i] == value)
                return i;
        }
        return -1;
    }

    static public int max(int[] array) {
        if(array == null || array.length == 0)
            return Integer.MAX_VALUE;
        int max = array[0];
        for(int i : array) {
            if(max < i)
                max = i;
        }
        return max;
    }

    static public int min(int[] array) {
        if(array == null || array.length == 0)
            return Integer.MIN_VALUE;
        int min = array[0];
        for(int i : array) {
            if(min > i)
                min = i;
        }
        return min;
    }

    static public boolean replaceMinByMax(int[] array, int[] array_bis) {
        if(array == null || array_bis == null || array.length == 0
                || array_bis.length == 0)
            return false;
        int min = min(array);
        int max = max(array_bis);
        if(min == Integer.MIN_VALUE || max == Integer.MAX_VALUE)
            return false;
        int minIndex = indexOf(array, min);
        if(minIndex == -1)
            return false;
        array[minIndex] = max;
        return true;
    }

    static public int sum(int... list) {
        int sum = 0;
        for (int i: list)
            sum += i;
        return sum;
    }
}
