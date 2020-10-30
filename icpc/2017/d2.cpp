#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <memory>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cfloat>
#include <cassert>
#include <random>
#include <bitset>

int bit_count(int n) {
	return n == 0 ? 0 : (n & 1) + bit_count(n >> 1);
}
int main() {
	while (true) {
		int n, m; std::cin >> n >> m; if (n == 0) break;
		std::vector<std::string> state(n); for (auto& line : state) std::cin >> line;
		if (n < m) {
			int max = 0;
			std::vector<bool> is_rest(m);
			for (auto i = 1; i < (1 << n); ++i) {
				const int bit = bit_count(i);
				if (bit > max) {
					std::fill(is_rest.begin(), is_rest.end(), false);
					for (auto j = 0; j < n; ++j) if ((i & (1 << j)) != 0) {
						for (auto k = 0; k < m; ++k) if (state[j][k] == '1') {
							is_rest[k] = !is_rest[k];
						}
					}
					if (std::all_of(is_rest.begin(), is_rest.end(), [](bool b) {return !b; })) {
						max = bit;
					}
				}
			}
			std::cout << max << std::endl;
		}
		else {
			std::vector<std::vector<short>> max(n + 1, std::vector<short>(1 << m, -1));
			max[0][0] = 0;
			for (auto i = 0; i < n; ++i) {
				int bit = 0;
				for (auto j = 0; j < m; ++j) {
					bit = (bit << 1) + state[i][j] - '0';
				}
				for (auto j = 0; j < (1 << m); ++j) if (max[i][j] >= 0) {
					max[i + 1][j] = std::max(max[i + 1][j], max[i][j]);
					max[i + 1][j ^ bit] = std::max(max[i + 1][j ^ bit], static_cast<short>(max[i][j] + 1));
				}
			}
			std::cout << max.back().front() << std::endl;
		}
	}
}