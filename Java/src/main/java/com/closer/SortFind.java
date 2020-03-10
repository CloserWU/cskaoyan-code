package com.closer;


import java.util.*;

/**
 * <p>SortFind</p>
 * <p>description</p>
 *
 * @author closer
 * @version 1.0.0
 * @date 2020-02-19 16:10
 */
public class SortFind {
    void func1() {
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            int n = Integer.parseInt(input.nextLine());
            List<Integer> list = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                list.add(input.nextInt());
            }
            list.sort(new Comparator<Integer>() {
                @Override
                public int compare(Integer o1, Integer o2) {
                    return o1 - o2;
                }
            });
            System.out.println(list.get(list.size() - 1));
            if (n != 1) {
                System.out.print(list.get(0));
                for (int i = 1; i < n - 1; i++) {
                    System.out.print(" " + list.get(i));
                }
                System.out.print("\n");
            } else {
                System.out.println(-1);
            }
        }
    }

    void func2() {
        Scanner input = new Scanner(System.in);
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            list.add(input.nextInt());
        }
        list.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });
        for (Integer aList : list) {
            if (aList % 2 == 1) {
                System.out.print(aList + " ");
            }
        }
        list.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1 - o2;
            }
        });
        for (Integer aList : list) {
            if (aList % 2 == 0) {
                System.out.print(aList + " ");
            }
        }
        System.out.println();
    }

    void func3() {
        class Mouse {
            String color;
            int weight;

            Mouse(int weight, String color) {
                this.color = color;
                this.weight = weight;
            }
        }

        Scanner input = new Scanner(System.in);
        List<Mouse> list = new ArrayList<>();

        while (input.hasNext()) {
            int n = Integer.parseInt(input.nextLine());
            for (int i = 0; i < n; i++) {
                list.add(new Mouse(input.nextInt(), input.next()));
            }
            list.sort(new Comparator<Mouse>() {
                @Override
                public int compare(Mouse o1, Mouse o2) {
                    return o2.weight - o1.weight;
                }
            });
            for (int i = 0; i < n; i++) {
                System.out.println(list.get(i).color);
            }
        }

    }


    class Country {
        private int goldNumber;
        private int modelNumber;
        private int population;
        private double goldRate;
        private double modelRate;
        private int index;

        Country(int goldNumber, int modelNumber, int population, double goldRate, double modelRate, int index) {
            this.goldNumber = goldNumber;
            this.modelNumber = modelNumber;
            this.population = population;
            this.goldRate = goldRate;
            this.modelRate = modelRate;
            this.index = index;
        }

        @Override
        public String toString() {
            return "Country{" +
                    "goldNumber=" + goldNumber +
                    ", modelNumber=" + modelNumber +
                    ", population=" + population +
                    ", goldRate=" + goldRate +
                    ", modelRate=" + modelRate +
                    ", index=" + index +
                    '}';
        }
    }

    ;


    List<Integer> mySort(List<Country> list, int cas) {
        int n = list.size();
        List<Integer> v = new ArrayList<>(Collections.nCopies(n, 0));
        int rate = 0;
        int l = 0;
        switch (cas) {
            case 1:
                list.sort(new Comparator<Country>() {
                    @Override
                    public int compare(Country o1, Country o2) {
                        return o2.goldNumber - o1.goldNumber;
                    }
                });
                v.set(list.get(0).index, ++rate);
                for (int i = 1; i < n; i++) {
                    if (list.get(i).goldNumber == list.get(i - 1).goldNumber) {
                        v.set(list.get(i).index, rate);
                        l++;
                    } else {
                        v.set(list.get(i).index, rate + l + 1);
                        rate = rate + l + 1;
                        l = 0;
                    }
                }
                return v;
            case 2:
                list.sort(new Comparator<Country>() {
                    @Override
                    public int compare(Country o1, Country o2) {
                        return o2.modelNumber - o1.modelNumber;
                    }
                });
                v.set(list.get(0).index, ++rate);
                for (int i = 1; i < n; i++) {
                    if (list.get(i).modelNumber == list.get(i - 1).modelNumber) {
                        v.set(list.get(i).index, rate);
                        l++;
                    } else {
                        v.set(list.get(i).index, rate + l + 1);
                        rate = rate + l + 1;
                        l = 0;
                    }
                }
                return v;
            case 3:
                list.sort(new Comparator<Country>() {
                    @Override
                    public int compare(Country o1, Country o2) {
                        return -Double.compare(o1.goldRate, o2.goldRate);
                    }
                });
                v.set(list.get(0).index, ++rate);
                for (int i = 1; i < n; i++) {
                    if (list.get(i).goldRate == list.get(i - 1).goldRate) {
                        v.set(list.get(i).index, rate);
                        l++;
                    } else {
                        v.set(list.get(i).index, rate + l + 1);
                        rate = rate + l + 1;
                        l = 0;
                    }
                }
                return v;
            case 4:
                list.sort(new Comparator<Country>() {
                    @Override
                    public int compare(Country o1, Country o2) {
                        return -Double.compare(o1.modelRate, o2.modelRate);
                    }
                });
                v.set(list.get(0).index, ++rate);
                for (int i = 1; i < n; i++) {
                    if (list.get(i).modelRate == list.get(i - 1).modelRate) {
                        v.set(list.get(i).index, rate);
                        l++;
                    } else {
                        v.set(list.get(i).index, rate + l + 1);
                        rate = rate + l + 1;
                        l = 0;
                    }
                }
                return v;
            default:
                return v;
        }
    }


    void func4() {


        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();
        List<Country> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int goldNumber = input.nextInt();
            int modelNumber = input.nextInt();
            int population = input.nextInt();
            if (population == 0) {
                population = Integer.MAX_VALUE;
            }
            list.add(new Country(goldNumber, modelNumber, population,
                    (double) goldNumber / population, (double) modelNumber / population, i));
        }
        List<Integer> v = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            v.add(input.nextInt());
        }
        for (int i = 0; i < n; i++) {
            int pos = v.indexOf(i);
            if (pos == -1) {
                list.remove(i);
            }
        }
        for (int i = 0; i < m; i++) {
            Country o = list.get(i);
            o.index = i;
            list.set(i, o);
            System.out.println(o);
        }
        List<Integer> s1 = mySort(list, 1);
        System.out.println(s1);
        List<Integer> s2 = mySort(list, 2);
        System.out.println(s2);
        List<Integer> s3 = mySort(list, 3);
        System.out.println(s3);
        List<Integer> s4 = mySort(list, 4);
        System.out.println(s4);
        for (int i = 0; i < m; i++) {
            List<Integer> tmp = new ArrayList<>();
            tmp.add(s1.get(i));
            tmp.add(s2.get(i));
            tmp.add(s3.get(i));
            tmp.add(s4.get(i));
            int mins = tmp.get(0), index = 0;
            for (int j = 1; j < 4; j++) {
                if (mins > tmp.get(j)) {
                    index = j;
                    mins = tmp.get(j);
                }
            }
            index++;
            System.out.println(mins + ":" + index);
        }
        System.out.println();
    }

    int binarySearch(List<Integer> list, int target) {
        int left = 0;
        int right = list.size() - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (target < list.get(middle)) {
                right = middle - 1;
            } else if (target > list.get(middle)) {
                left = middle + 1;
            } else {
                return middle;
            }
        }
        return -1;
    }

    void func5() {
        class Pair {
            private int x;
            private int y;

            Pair(int x, int y) {
                this.x = x;
                this.y = y;
            }
        }

        Scanner input = new Scanner(System.in);
        int n = Integer.parseInt(input.nextLine());
        List<Pair> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(new Pair(input.nextInt(), input.nextInt()));
        }
        list.sort(new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                if (o1.x != o2.x) {
                    return o1.x - o2.x;
                }
                return o1.y - o2.y;
            }
        });
        System.out.println(list.get(0).x + ":" + list.get(0).y);

    }

    void func6() {
        Scanner input = new Scanner(System.in);
        ;
        while (input.hasNext()) {
            int m = Integer.parseInt(input.nextLine());
            List<Integer> v = new ArrayList<>();
            for (int j = 0; j < m; j++) {
                v.add(input.nextInt());
            }
            for (int j = 0; j < m; j++) {
                if (j != 0 && j != m - 1) {
                    if (v.get(j) > v.get(j - 1) && v.get(j) > v.get(j + 1)) {
                        System.out.print(j + " ");
                    } else if (v.get(j) < v.get(j - 1) && v.get(j) < v.get(j + 1)) {
                        System.out.print(j + " ");
                    }
                } else if (j == 0 && !v.get(j).equals(v.get(j + 1))) {
                    System.out.print(j + " ");
                } else if (j == m - 1 && !v.get(j).equals(v.get(j - 1))) {
                    System.out.print(j + " ");
                }
            }
            System.out.println();
        }
    }

    void func7() {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        Map<Character, List<Integer>> map = new LinkedHashMap<>();
        for (int i = 0; i < str.length(); i++) {
            List<Integer> list;
            if (!map.containsKey(str.charAt(i))) {
                list = new ArrayList<>();
                list.add(i);
                map.put(str.charAt(i), list);
            } else {
                list = map.get(str.charAt(i));
                list.add(i);
            }
        }
        for (Map.Entry<Character, List<Integer>> entry: map.entrySet()) {
            List<Integer> list = entry.getValue();
            if (list != null && list.size() > 1) {
                for (int i = 0; i < list.size(); i++) {
                    System.out.printf("%c:%d", entry.getKey(), list.get(i));
                    if (i != list.size() - 1) {
                        System.out.print(",");
                    }
                }
                System.out.println();
            }
        }
    }

}

