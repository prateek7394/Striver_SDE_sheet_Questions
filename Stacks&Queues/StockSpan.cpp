// Design an algorithm that collects daily price quotes for some stock and 
// returns the span of that stock's price for the current day.

// The span of the stock's price in one day is the maximum number of consecutive days (starting from that day 
// and going backward) for which the stock price was less than or equal to the price of that day.

// Implement the StockSpanner class:
// StockSpanner(): Initializes the object of the class.
// int next(int price): Returns the span of the stock's price given that today's price is price.

#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>> st; // {price, count}
    StockSpanner() {}
    
    int next(int price) {
	
        int count = 1;
        while(!st.empty() && st.top().first <= price){
            count+=st.top().second;
            st.pop();    // we add count of popped element
        }
        st.push({price , count}); // stores the element and count of no. of elements<= given element
        return count;
    }
};

int main()
{
    return 0;
}