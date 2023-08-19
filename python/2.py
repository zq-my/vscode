# 五子棋游戏
import numpy as np

# 定义棋盘大小
BOARD_SIZE = 15

# 定义棋子类型
EMPTY = 0
BLACK = 1
WHITE = 2

# 定义赢法数组
wins = np.zeros((BOARD_SIZE, BOARD_SIZE, 572), dtype=np.int)

# 定义赢法统计数组
black_win = np.zeros(572, dtype=np.int)
white_win = np.zeros(572, dtype=np.int)

# 定义棋盘
board = np.zeros((BOARD_SIZE, BOARD_SIZE), dtype=np.int)

# 定义当前下棋方
current_player = BLACK

# 初始化赢法数组
count = 0
for i in range(BOARD_SIZE):
    for j in range(BOARD_SIZE - 4):
        for k in range(5):
            wins[i, j + k, count] = 1
        count += 1

for i in range(BOARD_SIZE - 4):
    for j in range(BOARD_SIZE):
        for k in range(5):
            wins[i + k, j, count] = 1
        count += 1

for i in range(BOARD_SIZE - 4):
    for j in range(BOARD_SIZE - 4):
        for k in range(5):
            wins[i + k, j + k, count] = 1
        count += 1

for i in range(BOARD_SIZE - 4):
    for j in range(4, BOARD_SIZE):
        for k in range(5):
            wins[i + k, j - k, count] = 1
        count += 1

# 定义胜负判断函数
def check_win(player):
    global wins, black_win, white_win
    if player == BLACK:
        my_win = black_win
        enemy_win = white_win
    else:
        my_win = white_win
        enemy_win = black_win
    for i in range(count):
        if wins[:, :, i][board == player].sum() == 5:
            my_win[i] = 1
            enemy_win[i] = -1
            return True
    return False

# 定义绘制棋盘函数
def draw_board():
    # 绘制棋盘边框
    print("+" + "+".join(["-" for _ in range(BOARD_SIZE)]) + "+")
    # 绘制棋盘内容
    for i in range(BOARD_SIZE):
        print("|" + "|".join([" " if board[i][j] == EMPTY else "●" if board[i][j] == BLACK else "○" for j in range(BOARD_SIZE)]) + "|")
    # 绘制棋盘边框
    print("+" + "+".join(["-" for _ in range(BOARD_SIZE)]) + "+")
    # 绘制当前下棋方
    print("当前下棋方：", "黑棋" if current_player == BLACK else "白棋")
while True:
    # 绘制棋盘
    draw_board()
    # 等待用户输入落子位置
    row, col = map(int, input("请输入落子位置，以逗号分隔：").split(","))
    # 判断落子位置是否合法
    if row < 0 or row >= BOARD_SIZE or col < 0 or col >= BOARD_SIZE or board[row][col] != EMPTY:
        print("落子位置不合法，请重新输入！")
        continue
    # 在落子位置落子
    board[row][col] = current_player
    # 判断当前下棋方是否获胜
    if check_win(current_player):
        print("恭喜，", "黑棋" if current_player == BLACK else "白棋", "获胜！")
        break
    # 判断是否平局
    if (board == EMPTY).sum() == 0:
        print("平局！")
        break
    # 切换下棋方
    current_player = BLACK if current_player == WHITE else WHITE
print("游戏结束！")
