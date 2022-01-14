
#include "GameObject.h"

#include <iostream>

using std::cout;
using std::endl;

GameObject::GameObject(const const sf::Vector2f position, const int numOfAnim,
                    const int numOfFrames,const float animTime, float scale, string imagePath)
                       :m_imagePath(imagePath)

{

    m_sprite.setTexture(texture);
    m_animation =new Animation(&m_texture,sf::Vector2u(numOfFrames,numOfAnim),animTime);

    m_sprite.setOrigin(m_sprite.getGlobalBounds().width/(numOfFrames) /2.f,m_sprite.getGlobalBounds().height / (numOfAnim) /2.f);

    m_sprite.setPosition(position);

    m_sprite.scale(scale, scale);// need to make func

    //cout << "scale x: " << m_sprite.getScale().x << " y: " << m_sprite.getScale().y << endl;

    //cout << "origin x: " << m_sprite.getOrigin().x << " y: " << m_sprite.getOrigin().y << endl;
}



bool GameObject::checkCollision(const GameObject& gameObject)
{
    if (&gameObject == this)
        return false;

    return this->getSprite().getGlobalBounds().intersects(gameObject.getSprite().getGlobalBounds());
}

sf::Sprite GameObject::getSprite() const
{
    return m_sprite;
}

void GameObject:: updateAndDraw(const int row,float deltaTime,sf::RenderWindow& window)
{
    m_animation->update(row,deltaTime);
    m_sprite.setTextureRect(m_animation->getRect());
    window.draw(m_sprite);
    
}

void GameObject::setLocation(const sf::Vector2f position)
{
    m_sprite.setPosition(position);
}

sf::Vector2<float> GameObject::getLocation( ) const
{
    return m_sprite.getPosition();
}