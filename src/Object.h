#ifndef OBJECT_H
#define OBJECT_H

#define MAX_X 1024
#define MAX_Y 768

#include <SFML/Graphics.hpp>
#include <ctime>

class Object {
protected:
    sf::Vector2f position;  // Добавлено sf::
    sf::Sprite sprite;
    sf::Texture texture;
    int coins;
    int id;

public:
    Object(sf::Vector2f _position, const std::string& _texture, int _coins, int _id);
    ~Object();

    sf::Sprite getSprite();
    void setPosition(sf::Vector2f _position);
    sf::Vector2f getPosition();
    int getCoins();
    void setCoins(int _coins);
    bool collision(Object* enterObject);
    int getId();
};

#endif