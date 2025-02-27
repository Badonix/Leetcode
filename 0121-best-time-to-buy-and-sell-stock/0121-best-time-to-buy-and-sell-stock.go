func maxProfit(prices []int) int {
    left := 0
    maxProfit := 0

    for right := 1; right < len(prices); right++ {
        if prices[right] < prices[left] {
            left = right
        } else {
            currentProfit := prices[right] - prices[left]
            if currentProfit > maxProfit {
                maxProfit = currentProfit
            }
        }
    }

    return maxProfit
}
