#include <SFML/Graphics.hpp>

#include <vector>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const float PLAYER_SPEED = 200.f;

class Player {
public:
    sf::RectangleShape sprite;
    sf::Vector2f velocity;

    Player() {
        sprite.setSize(sf::Vector2f(50.f, 50.f));
        sprite.setFillColor(sf::Color::Red);
        sprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 100);
    }

    void update(sf::Time delta) {
        sprite.move(velocity * delta.asSeconds());
        if (sprite.getPosition().x < 0) {
            sprite.setPosition(0, sprite.getPosition().y);
        }
        if (sprite.getPosition().x + sprite.getSize().x > WINDOW_WIDTH) {
            sprite.setPosition(WINDOW_WIDTH - sprite.getSize().x, sprite.getPosition().y);
        }
    }
};

class Bullet {
public:
    sf::CircleShape shape;
    sf::Vector2f velocity;

    Bullet(sf::Vector2f position, sf::Vector2f direction) {
        shape.setRadius(5.f);
        shape.setFillColor(sf::Color::Yellow);
        shape.setPosition(position);
        velocity = direction * 500.f;
    }

    void update(sf::Time delta) {
        shape.move(velocity * delta.asSeconds());
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Shooter");
    window.setFramerateLimit(60);

    Player player;
    std::vector<Bullet> bullets;

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time delta = clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.velocity.x = -PLAYER_SPEED;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.velocity.x = PLAYER_SPEED;
        }
        else {
            player.velocity.x = 0;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            bullets.emplace_back(player.sprite.getPosition(), sf::Vector2f(0, -1));
        }

        player.update(delta);
        for (auto& bullet : bullets) {
            bullet.update(delta);
        }

        window.clear(sf::Color::Black);
        window.draw(player.sprite);
        for (auto& bullet : bullets) {
            window.draw(bullet.shape);
        }
        window.display();
    }

    return 0;
}
