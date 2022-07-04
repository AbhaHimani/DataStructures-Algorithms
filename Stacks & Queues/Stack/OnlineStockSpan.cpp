class StockSpanner
{
public:
    vector<int> v;
    // nearest greater to left nikalna hai lmao
    stack<pair<int, int>> s;
    int count, ans;
    StockSpanner()
    {

        count = 0;
        ans = 0;
    }

    int next(int price)
    {
        while (!s.empty() && s.top().first <= price)
        {
            s.pop();
        }
        if (!s.empty() && s.top().first > price)
        {
            ans = count - s.top().second;
            s.push({price, count++});
        }
        else if (s.empty())
        {
            s.push({price, count++});
            ans = count;
        }

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */