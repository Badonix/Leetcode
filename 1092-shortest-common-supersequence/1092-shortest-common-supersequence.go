func reverse(s string) string {
	n := len(s)
	b := []byte(s)
	for i := 0; i < n/2; i++ {
		b[i], b[n-i-1] = b[n-i-1], b[i]
	}
	return string(b)
}

func shortestCommonSupersequence(str1 string, str2 string) string {
	n := len(str1)
	m := len(str2)
	dp := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = make([]int, m+1)
	}

	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if str1[i-1] == str2[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			}
		}
	}

	i := n
	j := m
	var common strings.Builder

	for i > 0 && j > 0 {
		if str1[i-1] == str2[j-1] {
			common.WriteByte(str1[i-1])
			i--
			j--
		} else if dp[i-1][j] >= dp[i][j-1] {
			i--
		} else {
			j--
		}
	}

	commonStr := common.String()
	reversed := reverse(commonStr)

	i = 0
	j = 0
	ans := ""
	for _, c := range reversed {
		for i < n && str1[i] != byte(c) {
			ans += string(str1[i])
			i++
		}
		for j < m && str2[j] != byte(c) {
			ans += string(str2[j])
			j++
		}
		ans += string(c)
		i++
		j++
	}

	for i < n {
		ans += string(str1[i])
		i++
	}

	for j < m {
		ans += string(str2[j])
		j++
	}

	return ans
}