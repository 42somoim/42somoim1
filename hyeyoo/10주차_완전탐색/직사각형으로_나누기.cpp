#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string map[100];
long long N, M;

/* 직사각형은 총 6가지 방법으로 나눌 수 있음*/

/* 가로로 3개 */
long long     method1() {
    long long ans = 0;
    for (long long x1 = 0; x1 < M; x1++) {
        for (long long x2 = x1 + 1; x2 < M; x2++) {
            for (long long x3 = x2 + 1; x3 < M; x3++) {
                long long sum1 = 0;
                for (long long i = 0; i <= x1; i++) {
                    for (long long j = 0; j < N; j++) {
                        sum1 += map[j][i] - '0';
                    }
                }

                long long sum2 = 0;
                for (long long i = x2; i < x3; i++) {
                    for (long long j = 0; j < N; j++) {
                        sum2 += map[j][i] - '0';
                    }
                }

                long long sum3 = 0;
                for (long long i = x3; i < M; i++) {
                    for (long long j = 0; j < N; j++) {
                        sum3 += map[j][i] - '0';
                    }
                }
                ans = max(ans, sum1 * sum2 * sum3);
            }
        }
    }
    return ans;
}

/* 세로로 3개 */
long long     method2() {
    long long ans = 0;
    for (long long y1 = 0; y1 < N; y1++) {
        for (long long y2 = y1 + 1; y2 < N; y2++) {
            for (long long y3 = y2 + 1; y3 < N; y3++) {
                long long sum1 = 0;
                for (long long i = 0; i <= y1; i++) {
                    for (long long j = 0; j < M; j++) {
                        sum1 += map[i][j] - '0';
                    }
                }

                long long sum2 = 0;
                for (long long i = y2; i < y3; i++) {
                    for (long long j = 0; j < M; j++) {
                        sum2 += map[i][j] - '0';
                    }
                }

                long long sum3 = 0;
                for (long long i = y3; i < N; i++) {
                    for (long long j = 0; j < M; j++) {
                        sum3 += map[i][j] - '0';
                    }
                }

                ans = max(ans, sum1 * sum2 * sum3);
            }
        }
    }
    return ans;
}

/*
 * 가로로 2개, 왼쪽 가로를 세로로 2개 나눔
 */

long long     method3() {
    long long ans = 0;
    for (long long x1 = 0; x1 < M; x1++) {
        for (long long x2 = x1 + 1; x2 < M; x2++) {
            for (long long y = 1; y < N; y++) {
                long long sum1 = 0;
                for (long long i = 0; i < y; i++) {
                    for (long long j = 0; j <= x1; j++) {
                        sum1 += map[i][j] - '0';
                    }
                }

                long long sum2 = 0;
                for (long long i = y; i < N; i++) {
                    for (long long j = 0; j <= x1; j++) {
                        sum2 += map[i][j] - '0';
                    }
                }

                long long sum3 = 0;
                for (long long i = 0; i < N; i++) {
                    for (long long j = x2; j < M; j++) {
                        sum3 += map[i][j] - '0';
                    }
                }
                
                ans = max(ans, sum1 * sum2 * sum3);
            }
        }
    }
    return ans;
}

/*
 * 가로로 2개, 오른쪽 가로를 세로로 2개 나눔
 */
long long     method4() {
    long long ans = 0;
    for (long long x1 = 0; x1 < M; x1++) {
        for (long long x2 = x1 + 1; x2 < M; x2++) {
            for (long long y = 1; y < N; y++) {
                long long sum3 = 0;
                for (long long i = 0; i < N; i++) {
                    for (long long j = 0; j <= x1; j++) {
                        sum3 += map[i][j] - '0';
                    }
                }

                long long sum1 = 0;
                for (long long i = 0; i < y; i++) {
                    for (long long j = x2; j < M; j++) {
                        sum1 += map[i][j] - '0';
                    }
                }

                long long sum2 = 0;
                for (long long i = y; i < N; i++) {
                    for (long long j = x2; j < M; j++) {
                        sum2 += map[i][j] - '0';
                    }
                }

                ans = max(ans, sum1 * sum2 * sum3);
            }
        }
    }
    return ans;
}

/* 세로로 2개를 나누고, 위쪽을 다시 2개로 나눔 */

long long     method5() {         
    long long ans = 0;
    for (long long y1 = 0; y1 < N; y1++) {
        for (long long y2 = y1 + 1; y2 < N; y2++) {
            for (long long x = 1; x < M; x++) {
                long long sum1 = 0;
                for (long long i = 0; i <= y1; i++) {
                    for (long long j = 0; j < x; j++) {
                        sum1 += map[i][j] - '0';
                    }
                }

                long long sum2 = 0;
                for (long long i = 0; i <= y1; i++) {
                    for (long long j = x; j < M; j++) {
                        sum2 += map[i][j] - '0';
                    }
                }

                long long sum3 = 0;
                for (long long i = y2; i < N; i++) {
                    for (long long j = 0; j < M; j++) {
                        sum3 += map[i][j] - '0';
                    }
                }
                ans = max(ans, sum1 * sum2 * sum3);
            }
        }
    }
    return ans;
}

/* 세로로 2개를 나누고, 아래쪽을 다시 2개로 나눔 */
long long     method6() {
    long long ans = 0;
    for (long long y1 = 0; y1 < N; y1++) {
        for (long long y2 = y1 + 1; y2 < N; y2++) {
            for (long long x = 1; x < M; x++) {
                long long sum3 = 0;
                for (long long i = 0; i <= y1; i++) {
                    for (long long j = 0; j < M; j++) {
                        sum3 += map[i][j] - '0';
                    }
                }

                long long sum1 = 0;
                for (long long i = y2; i < N; i++) {
                    for (long long j = 0; j < x; j++) {
                        sum1 += map[i][j] - '0';
                    }
                }

                long long sum2 = 0;
                for (long long i = y2; i < N; i++) {
                    for (long long j = x; j < M; j++) {
                        sum2 += map[i][j] - '0';
                    }
                }

                ans = max(ans, sum1 * sum2 * sum3);
            }
        }
    }
    return ans;
}

int		main(void) {

	cin >> N >> M;

	for (long long i = 0; i < N; i++)
		cin >> map[i];

    long long ans = 0;
    ans = max(ans, method1());
    ans = max(ans, method2());
    ans = max(ans, method3());
    ans = max(ans, method4());
    ans = max(ans, method5());
    ans = max(ans, method6());
    cout << ans << endl;
	return 0;
}
