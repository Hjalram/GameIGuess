#pragma once

#include "raylib/raylib.h"

class SpaceMass
{
public:
    Vector2 position;
    Vector2 velocity;

    float mass;

    Texture2D texture;

    SpaceMass(const char* _imagePath);

    void addVectors(Vector2 &_v, Vector2 &_u, Vector2 &_o);
    void normalizeVector(Vector2 &_u, Vector2 &_o);
    void setMagnitudeVector(float _magnitude, Vector2 &_u, Vector2 &_o);
    void draw();
    void update();
    void noticeGravity(SpaceMass _other);
    void destroy();
};