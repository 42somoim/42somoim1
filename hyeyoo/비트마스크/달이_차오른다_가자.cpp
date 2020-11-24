#include <iostream>
#include <string>
#include <queue>

using namespace std;

// y, x, key
bool visited[51][51][1000];
string map[51];
int N, M;

// c = a, b, c, d, e, f
int  addKey(int oldKey, char c) {
  return oldKey | (1 << (c - 'a'));
}

// c = A, B, C, D, E, F
bool  hasKey(int key, char c) {
  return key & (1 << (c - 'A'));
}

int   bfs(int sx, int sy) {
  queue<int> qx, qy, qkey, qmove;
  qx.push(sx); qy.push(sy); qkey.push(0); qmove.push(0);

  int dx[] = {0, 0, 1, -1};
  int dy[] = {-1, 1, 0, 0};

  while (!qx.empty()) {
    int x, y, key, move;
    x = qx.front(); qx.pop();
    y = qy.front();  qy.pop();
    key = qkey.front(); qkey.pop();
    move = qmove.front(); qmove.pop();

    if (map[y][x] == '1')
      return move;
    
    char c;
    for (int i = 0; i < 4; i++) {
      int nx = dx[i] + x;
      int ny = dy[i] + y;
      if (0 <= nx && nx < M && 0 <= ny && ny < N &&
          (c = map[ny][nx]) != '#' && !visited[ny][nx][key]) {
        if ('a' <= c && c <= 'f') {
          qx.push(nx);
          qy.push(ny);
          qkey.push(addKey(key, c));
          visited[ny][nx][addKey(key, c)] = true;
        } else if ('A' <= c && c <= 'F') {
          if (!hasKey(key, c))
            continue;
          qx.push(nx);
          qy.push(ny);
          qkey.push(key);
          visited[ny][nx][key] = true;
        } else {
          qx.push(nx);
          qy.push(ny);
          qkey.push(key);
          visited[ny][nx][key] = true;
        }
        qmove.push(move + 1);
      }
    }
  }
  return -1;
}

int   main(void)
{
  cin >> N >> M;
  int start_x, start_y;

  for (int i = 0; i < N; i++) {
    cin >> map[i];
    for (int j = 0; j < M; j++) {
      if (map[i][j] == '0') {
        start_y = i;
        start_x = j;
      }
    }
  }

  cout << bfs(start_x, start_y) << endl;
  return 0;
}
