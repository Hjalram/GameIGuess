#include "SpaceMass.hpp"
#include <cmath>
#include <iostream>

// Constuctor
SpaceMass::SpaceMass(const char* _imagePath) 
{
    position = {100, 100};
    velocity = {0, 0};
    texture = LoadTexture(_imagePath);
}

void SpaceMass::addVectors(Vector2 &_v, Vector2 &_u, Vector2 &_o)
{
    _o.x = _v.x + _u.x;
    _o.y = _v.y + _u.y;
}

void SpaceMass::normalizeVector(Vector2 &_u, Vector2 &_o)
{
    float length = sqrtf(_u.x * _u.x + _u.y * _u.y);

    if (length == 0) // Avoid division by zero
    {
        _o = (Vector2){0, 0};
    }  
    else 
    {
        _o = (Vector2){_u.x / length, _u.y / length};
    }
}

void SpaceMass::setMagnitudeVector(float _magnitude, Vector2 &_u, Vector2 &_o)
{
    Vector2 input;
    normalizeVector(_u, input);

    _o.x = input.x * _magnitude;
    _o.y = input.y * _magnitude;
}

void SpaceMass::draw()
{
    Rectangle source = {0, 0, (float)texture.width, (float)texture.height};
    Rectangle dest = {position.x, position.y, (float)texture.width / 3, (float)texture.height / 3};

    DrawTexturePro(texture, source, dest, {dest.width/2, dest.height/2}, 0, WHITE);
}

void SpaceMass::update()
{
    position.x += velocity.x;
    position.y += velocity.y;
}

void SpaceMass::noticeGravity(SpaceMass _other)
{
    int xDistance, yDistance;
    xDistance = _other.position.x - position.x;
    yDistance = _other.position.y - position.y;

    // The total distance between the two points
    float distance = std::sqrt(xDistance*xDistance + yDistance*yDistance);

    // Calculate the gravity vector
    Vector2 gravity;
    gravity.x = _other.position.x - position.x;
    gravity.y = _other.position.y - position.y;

    setMagnitudeVector(1/distance * _other.mass, gravity, gravity);
    
    addVectors(velocity, gravity, velocity);
}

void SpaceMass::destroy()
{
    UnloadTexture(texture);
}