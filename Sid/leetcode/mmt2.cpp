<!-- Airport Connectivity Challenge
There are N airports scattered across a vast territory. The i-th airport is located at coordinates (x_i, y_i) on a coordinate plane. Multiple airports can exist at the same location (co-located airports).
 
Flight Route Construction Rules
You can establish direct flight routes between any two airports at coordinates (a,b) and (c,d). The cost to establish a route is determined by the minimum of the horizontal and vertical distances between the airports, measured in flight credits.
 
Important: The cost calculation uses the minimum of the two distances, not the sum or maximum. This reflects the fact that flight paths can be optimized to follow either the horizontal or vertical direction more efficiently.
 
Objective
Your goal is to establish flight routes so that passengers can travel between any pair of airports by taking connecting flights. What is the minimum total cost in flight credits required to achieve complete airport connectivity?
 
Constraints
- 2 ≤ N ≤ 10^5
- 0 ≤ x_i, y_i ≤ 10^6
- Coordinates can be integers or floating-point numbers (double precision)
- The territory spans multiple time zones and climate regions
 
Input Format
Input is provided via Standard Input in the following format:
```
N
x_1 y_1
x_2 y_2
...
x_N y_N
```
Where:
- N is the number of airports
- (x_i, y_i) are the coordinates of the i-th airport
 
Output
Print the minimum number of flight credits required to establish routes ensuring complete airport connectivity. The result should be rounded to two decimal places.
 
Sample Cases
 
Sample Input 1
```
3
1.25 5.75
3.50 9.25
7.00 8.50
```
 
Sample Output 1
```
3.00
```
 
Explanation: Establish a route between Airports 1 and 2 (cost: min(|1.25-3.50|, |5.75-9.25|) = min(2.25, 3.50) = 2.25 credits), and another between Airports 2 and 3 (cost: min(|3.50-7.00|, |9.25-8.50|) = min(3.50, 0.75) = 0.75 credit). Total cost: 2.25 + 0.75 = 3.00 flight credits.
Sample Input 2
```
6
8.75 3.25
4.50 9.80
12.30 19.45
18.90 1.15
13.60 5.75
7.25 6.90
```
 
Sample Output 2
```
8.00
```
 

Sample input

3
1.25 5.75
3.50 9.25
7.00 8.50
Sample output

3.00 -->