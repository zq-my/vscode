import pygame
import random

# Initialize pygame
pygame.init()

# Set up the display
screen_width = 480
screen_height = 700
screen = pygame.display.set_mode((screen_width, screen_height))

# Set up the game clock
clock = pygame.time.Clock()

# Load images
background_image = pygame.image.load("images/background.png").convert()
player_image = pygame.image.load("images/player.png").convert_alpha()
enemy_image = pygame.image.load("images/enemy.png").convert_alpha()
bullet_image = pygame.image.load("images/bullet.png").convert_alpha()

# Set up the player
player_x = screen_width // 2
player_y = screen_height - 100
player_speed = 5
player_rect = player_image.get_rect(center=(player_x, player_y))

# Set up the bullets
bullet_speed = 10
bullet_list = []

# Set up the enemies
enemy_speed = 3
enemy_list = []
for i in range(5):
    enemy_x = random.randint(0, screen_width - enemy_image.get_width())
    enemy_y = random.randint(-500, -50)
    enemy_rect = enemy_image.get_rect(center=(enemy_x, enemy_y))
    enemy_list.append(enemy_rect)

# Set up the score
score = 0
font = pygame.font.Font(None, 36)

# Game loop
running = True
while running:
    # Handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                bullet_x = player_x + player_image.get_width() // 2 - bullet_image.get_width() // 2
                bullet_y = player_y - bullet_image.get_height()
                bullet_rect = bullet_image.get_rect(center=(bullet_x, bullet_y))
                bullet_list.append(bullet_rect)

    # Move the player
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT] and player_x > 0:
        player_x -= player_speed
    elif keys[pygame.K_RIGHT] and player_x < screen_width - player_image.get_width():
        player_x += player_speed
    player_rect = player_image.get_rect(center=(player_x, player_y))

    # Move the bullets
    for bullet_rect in bullet_list:
        bullet_rect.move_ip(0, -bullet_speed)
        if bullet_rect.bottom <= 0:
            bullet_list.remove(bullet_rect)
        for enemy_rect in enemy_list:
            if bullet_rect.colliderect(enemy_rect):
                enemy_list.remove(enemy_rect)
                bullet_list.remove(bullet_rect)
                score += 10


import pygame
import random

# Initialize pygame
pygame.init()

# Set up the display
screen_width = 480
screen_height = 700
screen = pygame.display.set_mode((screen_width, screen_height))

# Set up the game clock
clock = pygame.time.Clock()

# Load images
background_image = pygame.image.load("images/background.png").convert()
player_image = pygame.image.load("images/player.png").convert_alpha()
enemy_image = pygame.image.load("images/enemy.png").convert_alpha()
bullet_image = pygame.image.load("images/bullet.png").convert_alpha()

# Set up the player
player_x = screen_width // 2
player_y = screen_height - 100
player_speed = 5
player_rect = player_image.get_rect(center=(player_x, player_y))

# Set up the bullets
bullet_speed = 10
bullet_list = []

# Set up the enemies
enemy_speed = 3
enemy_list = []
for i in range(5):
    enemy_x = random.randint(0, screen_width - enemy_image.get_width())
    enemy_y = random.randint(-500, -50)
    enemy_rect = enemy_image.get_rect(center=(enemy_x, enemy_y))
    enemy_list.append(enemy_rect)

# Set up the score
score = 0
font = pygame.font.Font(None, 36)

# Game loop
running = True
while running:
    # Handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                bullet_x = player_x + player_image.get_width() // 2 - bullet_image.get_width() // 2
                bullet_y = player_y - bullet_image.get_height()
                bullet_rect = bullet_image.get_rect(center=(bullet_x, bullet_y))
                bullet_list.append(bullet_rect)

    # Move the player
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT] and player_x > 0:
        player_x -= player_speed    
    elif keys[pygame.K_RIGHT] and player_x < screen_width - player_image.get_width():
        player_x += player_speed
    player_rect = player_image.get_rect(center=(player_x, player_y))

    # Move the bullets
    for bullet_rect in bullet_list:
        bullet_rect.move_ip(0, -bullet_speed)
        if bullet_rect.bottom <= 0:
            bullet_list.remove(bullet_rect)
        for enemy_rect in enemy_list:
            if bullet_rect.colliderect(enemy_rect):
                enemy_list.remove(enemy_rect)
                bullet_list.remove(bullet_rect)
                score += 10

    # Move the enemies
    for enemy_rect in enemy_list:
        enemy_rect.move_ip(0, enemy_speed)
        if enemy_rect.top >= screen_height:
            enemy_x = random.randint(0, screen_width - enemy_image.get_width())
            enemy_y = random.randint(-500, -50)
            enemy_rect.center = (enemy_x, enemy_y)
            score -= 5

    # Draw the screen
    screen.blit(background_image, (0, 0))
    screen.blit(player_image, player_rect)
    for bullet_rect in bullet_list:
        screen.blit(bullet_image, bullet_rect)
    for enemy_rect in enemy_list:
        screen.blit(enemy_image, enemy_rect)
    score_text = font.render(f"Score: {score}", True, (255, 255, 255))
    screen.blit(score_text, (10, 10))

    # Update the display
    pygame.display.update()

    # Check for game over
    for enemy_rect in enemy_list:
        if enemy_rect.colliderect(player_rect):
            running = False

    # Tick the clock
    clock.tick(60)

# Quit pygame
pygame.quit()
# Game over screen
game_over_font = pygame.font.Font(None, 48)
game_over_text = game_over_font.render("Game Over", True, (255, 0, 0))
game_over_rect = game_over_text.get_rect(center=(screen_width // 2, screen_height // 2))
screen.blit(game_over_text, game_over_rect)
pygame.display.update()
pygame.time.wait(2000)
import os
os.system("python main.py")
