import pygame

# Initialize Pygame
pygame.init()

# Set the dimensions of the game window
WINDOW_SIZE = (600, 600)

# Set the title of the game window
pygame.display.set_caption("五子棋")

# Create the game window
screen = pygame.display.set_mode(WINDOW_SIZE)

# Set the background color of the game window
background_color = (255, 255, 255)

# Draw the game board
board_color = (0, 0, 0)
board_width = 2
board_margin = 50
board_size = WINDOW_SIZE[0] - 2 * board_margin
board_start = (board_margin, board_margin)
board_end = (board_margin + board_size, board_margin + board_size)
board_line_start = board_start[0] + board_size // 14
board_line_end = board_end[0] - board_size // 14
board_line_interval = board_size // 14
for i in range(15):
    pygame.draw.line(screen, board_color, (board_line_start, board_line_start + i * board_line_interval), (board_line_end, board_line_start + i * board_line_interval), board_width)
    pygame.draw.line(screen, board_color, (board_line_start + i * board_line_interval, board_line_start), (board_line_start + i * board_line_interval, board_line_end), board_width)

# Update the game window
pygame.display.update()

# Game loop
while True:
    # Handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()
        elif event.type == pygame.MOUSEBUTTONDOWN:
            # Get the position of the mouse click
            mouse_position = pygame.mouse.get_pos()
            print(mouse_position)
# Update the game window
pygame.display.update()

# Game loop
while True:
    # Handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()
        elif event.type == pygame.MOUSEBUTTONDOWN:
            # Get the position of the mouse click
            mouse_position = pygame.mouse.get_pos()
            print(mouse_position)

    # Update the game window
    pygame.display.update()
    
    # Continue the game loop
    continue

