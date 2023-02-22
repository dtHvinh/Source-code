import pygame
import random

# Initialize Pygame
pygame.init()

# Set the window size
WINDOW_SIZE = (800, 600)

# Create the window
screen = pygame.display.set_mode(WINDOW_SIZE)

# Set the title of the window
pygame.display.set_caption("Space Shooter")

# Set the background color
bg_color = (0, 0, 0)

# Load the player image
player_img = pygame.image.load("player.png")

# Get the size of the player image
player_size = player_img.get_size()

# Set the player's starting position
player_pos = [WINDOW_SIZE[0]/2 - player_size[0]/2, WINDOW_SIZE[1] - player_size[1] - 20]

# Set the player's speed
player_speed = 5

# Load the enemy image
enemy_img = pygame.image.load("enemy.png")

# Get the size of the enemy image
enemy_size = enemy_img.get_size()

# Create a list to hold the enemy positions
enemies = []

# Set the enemy speed
enemy_speed = 3

# Set the enemy spawn rate
enemy_spawn_rate = 50

# Set the player score
score = 0

# Load the font for the score
font = pygame.font.Font(None, 30)

# Create a game loop
running = True
while running:

    # Handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Get the keys currently pressed
    keys = pygame.key.get_pressed()

    # Move the player
    if keys[pygame.K_LEFT] and player_pos[0] > 0:
        player_pos[0] -= player_speed
    if keys[pygame.K_RIGHT] and player_pos[0] < WINDOW_SIZE[0] - player_size[0]:
        player_pos[0] += player_speed

    # Spawn enemies
    if random.randint(0, 100) < enemy_spawn_rate:
        enemy_pos = [random.randint(0, WINDOW_SIZE[0] - enemy_size[0]), 0]
        enemies.append(enemy_pos)

    # Move the enemies
    for enemy_pos in enemies:
        enemy_pos[1] += enemy_speed

    # Remove enemies that have gone off the screen
    enemies = [enemy_pos for enemy_pos in enemies if enemy_pos[1] < WINDOW_SIZE[1]]

    # Check for collisions
    for enemy_pos in enemies:
        if pygame.Rect(enemy_pos, enemy_size).colliderect(pygame.Rect(player_pos, player_size)):
            running = False

    # Clear the screen
    screen.fill(bg_color)

    # Draw the player
    screen.blit(player_img, player_pos)

    # Draw the enemies
    for enemy_pos in enemies:
        screen.blit(enemy_img, enemy_pos)

    # Update the score
    score += len(enemies)
    score_text = font.render("Score: " + str(score), True, (255, 255, 255))
    screen.blit(score_text, (10, 10))

    # Update the display
    pygame.display.update()

# Quit Pygame
pygame.quit()
