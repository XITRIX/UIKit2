//
// Created by Даниил Виноградов on 30.09.2023.
//

#pragma once

#include <CoreGraphics/CGAffineTransform.hpp>
#include <libretro-common/retro_math.h>

struct Vector3 {
    float x, y, z;
};

struct CATransform3D {
public:
    float m11; float m12; float m13; float m14;
    float m21; float m22; float m23; float m24;
    float m31; float m32; float m33; float m34;
    float m41; float m42; float m43; float m44;

    CATransform3D(float m11, float m12, float m13, float m14,
                  float m21, float m22, float m23, float m24,
                  float m31, float m32, float m33, float m34,
                  float m41, float m42, float m43, float m44);
    CATransform3D();
    explicit CATransform3D(float* unsafePointer);

    static CATransform3D translationBy(float x, float y, float z);
    static CATransform3D scaleBy(float x, float y, float z);
    static CATransform3D scale(float factor);
    static CATransform3D rotationBy(float angle, float x, float y, float z);

    [[nodiscard]] CATransform3D concat(const CATransform3D& other) const;
    bool operator==(const CATransform3D& rhs) const;
    CATransform3D operator+(const CATransform3D& rhs) const;
    CATransform3D operator-(const CATransform3D& rhs) const;
    CATransform3D operator*(const CATransform3D& first) const;
    CATransform3D operator*(const float& first) const;
    [[nodiscard]] CATransform3D interpolateTo(const CATransform3D& matrix, const float& progress) const;

    [[nodiscard]] Vector3 transformingVector(float x, float y, float z) const;

    static const CATransform3D identity;

};

const CATransform3D CATransform3DIdentity = CATransform3D(1, 0, 0, 0,
                                                          0, 1, 0, 0,
                                                          0, 0, 1, 0,
                                                          0, 0, 0, 1);

bool CATransform3DEqualToTransform(const CATransform3D& a, const CATransform3D& b);

CATransform3D CATransform3DMakeAffineTransform(CGAffineTransform transform);
CATransform3D CATransform3DMakeTranslation(float tx, float ty, float tz);
CATransform3D CATransform3DMakeScale(float sx, float sy, float sz);
CATransform3D CATransform3DMakeRotation(float angle, float x, float y, float z);
CATransform3D CATransform3DConcat(const CATransform3D& a, const CATransform3D& b);
CGAffineTransform CATransform3DGetAffineTransform(CATransform3D t);

