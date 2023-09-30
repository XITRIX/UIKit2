//
// Created by Даниил Виноградов on 30.09.2023.
//

#include <CATransform3D.hpp>
#include <CoreGraphics/Geometry.hpp>
#define RAD_PER_DEG 0.017453293f

const CATransform3D CATransform3D::identity = CATransform3DIdentity;

CATransform3D::CATransform3D(
        float m11, float m12, float m13, float m14,
        float m21, float m22, float m23, float m24,
        float m31, float m32, float m33, float m34,
        float m41, float m42, float m43, float m44)
        :
        m11(m11), m12(m12), m13(m13), m14(m14),
        m21(m21), m22(m22), m23(m23), m24(m24),
        m31(m31), m32(m32), m33(m33), m34(m34),
        m41(m41), m42(m42), m43(m43), m44(m44)
{ }

CATransform3D::CATransform3D() :
        m11(0), m12(0), m13(0), m14(0),
        m21(0), m22(0), m23(0), m24(0),
        m31(0), m32(0), m33(0), m34(0),
        m41(0), m42(0), m43(0), m44(0)
{ }

CATransform3D::CATransform3D(float* buffer) :
        m11(buffer[0]), m12(buffer[1]), m13(buffer[2]), m14(buffer[3]),
        m21(buffer[4]), m22(buffer[5]), m23(buffer[6]), m24(buffer[7]),
        m31(buffer[8]), m32(buffer[9]), m33(buffer[10]), m34(buffer[11]),
        m41(buffer[12]), m42(buffer[13]), m43(buffer[14]), m44(buffer[15])
{ }


CATransform3D CATransform3D::concat(const CATransform3D& other) const {
    return CATransform3DConcat(*this, other);
}

bool CATransform3D::operator==(const CATransform3D& rhs) const {
    return CATransform3DEqualToTransform(*this, rhs);
}

CATransform3D CATransform3D::operator+(const CATransform3D& b) const {
    CATransform3D a = *this;
    return {
            a.m11 + b.m11, a.m12 + b.m12, a.m13 + b.m13, a.m14 + b.m14,
            a.m21 + b.m21, a.m22 + b.m22, a.m23 + b.m23, a.m24 + b.m24,
            a.m31 + b.m31, a.m32 + b.m32, a.m33 + b.m33, a.m34 + b.m34,
            a.m41 + b.m41, a.m42 + b.m42, a.m43 + b.m43, a.m44 + b.m44
    };
}

CATransform3D CATransform3D::operator-(const CATransform3D& b) const {
    CATransform3D a = *this;
    return {
            a.m11 - b.m11, a.m12 - b.m12, a.m13 - b.m13, a.m14 - b.m14,
            a.m21 - b.m21, a.m22 - b.m22, a.m23 - b.m23, a.m24 - b.m24,
            a.m31 - b.m31, a.m32 - b.m32, a.m33 - b.m33, a.m34 - b.m34,
            a.m41 - b.m41, a.m42 - b.m42, a.m43 - b.m43, a.m44 - b.m44
    };
}

CATransform3D CATransform3D::operator*(const CATransform3D& first) const {
    return (*this).concat(first);
}

CATransform3D CATransform3D::operator*(const float& b) const {
    CATransform3D a = *this;
    return {
            a.m11 * b, a.m12 * b, a.m13 * b, a.m14 * b,
            a.m21 * b, a.m22 * b, a.m23 * b, a.m24 * b,
            a.m31 * b, a.m32 * b, a.m33 * b, a.m34 * b,
            a.m41 * b, a.m42 * b, a.m43 * b, a.m44 * b
    };
}

void getPartsFromMatrix(const CGAffineTransform& matrix, float* angle, CGPoint* translation, CGPoint* scale) {
    auto a = float(matrix.m11);
    auto b = float(matrix.m12);
    auto c = float(matrix.m21);
    auto d = float(matrix.m22);
    auto e = float(matrix.tX);
    auto f = float(matrix.tY);

    auto delta = a * d - b * c;

    *angle = 0;
    *translation = CGPoint(e, f);
    *scale = CGPoint(1, 1);

    // Apply the QR-like decomposition.
    if (a != 0 || b != 0) {
        auto r = sqrtf(a * a + b * b);
        *angle = b > 0 ? acosf(a / r) : -acosf(a / r);
        *scale = CGPoint(r, delta / r);
    } else if (c != 0 || d != 0) {
        auto s = sqrtf(c * c + d * d);
        *angle = M_PI / 2 - (d > 0 ? acosf(-c / s) : -acosf(c / s));
        *scale = CGPoint(delta / s, s);
    } else { }

    *angle = *angle / RAD_PER_DEG;
}

CATransform3D CATransform3D::interpolateTo(const CATransform3D& matrix, const float& progress) const {
    auto currentM = CATransform3DGetAffineTransform(*this);
    auto newM = CATransform3DGetAffineTransform(matrix);

    float angle;
    CGPoint translation, scale;

    float dAngle;
    CGPoint dTranslation, dScale;

    getPartsFromMatrix(currentM, &angle, &translation, &scale);
    getPartsFromMatrix(newM, &dAngle, &dTranslation, &dScale);
//
    angle = angle + (dAngle - angle) * progress;
    scale = scale + (dScale - scale) * progress;// (scale - CGPoint(1, 1)) * progress + CGPoint(1, 1);
    translation = translation + (dTranslation - translation) * progress;

    return CATransform3D::translationBy(translation.x, translation.y, 0) * CATransform3D::scaleBy(scale.x, scale.y, 1) * CATransform3D::rotationBy(angle, 0, 0, 1);
}

Vector3 CATransform3D::transformingVector(float x, float y, float z) const {
    auto newX = m11 * x + m21 * y + m31 * z + m41;
    auto newY = m12 * x + m22 * y + m32 * z + m42;
    auto newZ = m13 * x + m23 * y + m33 * z + m43;
    auto newW = m14 * x + m24 * y + m34 * z + m44;

    return { newX / newW, newY / newW, newZ / newW };
}

bool CATransform3DEqualToTransform(const CATransform3D& a, const CATransform3D& b) {
    return
            a.m11 == b.m11 && a.m12 == b.m12 && a.m13 == b.m13 && a.m14 == b.m14 &&
            a.m21 == b.m21 && a.m22 == b.m22 && a.m23 == b.m23 && a.m24 == b.m24 &&
            a.m31 == b.m31 && a.m32 == b.m32 && a.m33 == b.m33 && a.m34 == b.m34 &&
            a.m41 == b.m41 && a.m42 == b.m42 && a.m43 == b.m43 && a.m44 == b.m44;
}

CATransform3D CATransform3DMakeAffineTransform(CGAffineTransform m) {
    return {
            m.m11, m.m12, 0,    0,
            m.m21, m.m22, 0,    0,
            0,     0,     1,    0,
            m.tX,  m.tY,  0,    1};
}

CATransform3D CATransform3DMakeTranslation(float tx, float ty, float tz) {
    return {
            1,     0,     0,    0,
            0,     1,     0,    0,
            0,     0,     1,    0,
            tx,    ty,    tz,   1};
}

CATransform3D CATransform3DMakeScale(float tx, float ty, float tz) {
    return {
            tx,     0,     0,    0,
            0,    ty,     0,    0,
            0,     0,    tz,    0,
            0,     0,     0,    1};
}

CATransform3D CATransform3DMakeRotation(float angle, float x, float y, float z) {
    float p, radians, c, s, c_, zc_, yc_, xzc_, xyc_, yzc_, xs, ys, zs;

    p = 1/sqrtf(x*x + y*y + z*z);
    x *= p; y *= p; z *= p;
    radians = angle * RAD_PER_DEG;
    c = cosf(radians);
    s = sinf(radians);
    c_ = 1 - c;
    zc_ = z*c_;
    yc_ = y*c_;
    xzc_ = x*zc_;
    xyc_ = x*y*c_;
    yzc_ = y*zc_;
    xs = x*s;
    ys = y*s;
    zs = z*s;

    return {
            x*x*c_ + c, xyc_ + zs, xzc_ - ys, 0,
            xyc_ - zs, y*yc_ + c, yzc_ + xs, 0,
            xzc_ + ys, yzc_ - xs, z*zc_ + c, 0,
            0, 0, 0, 1};
}

CATransform3D CATransform3DConcat(const CATransform3D& a, const CATransform3D& b) {
    if (a == CATransform3DIdentity) { return b; }
    if (b == CATransform3DIdentity) { return a; }

    auto result = CATransform3D();

    result.m11 = a.m11 * b.m11 + a.m21 * b.m12 + a.m31 * b.m13 + a.m41 * b.m14;
    result.m12 = a.m12 * b.m11 + a.m22 * b.m12 + a.m32 * b.m13 + a.m42 * b.m14;
    result.m13 = a.m13 * b.m11 + a.m23 * b.m12 + a.m33 * b.m13 + a.m43 * b.m14;
    result.m14 = a.m14 * b.m11 + a.m24 * b.m12 + a.m34 * b.m13 + a.m44 * b.m14;

    result.m21 = a.m11 * b.m21 + a.m21 * b.m22 + a.m31 * b.m23 + a.m41 * b.m24;
    result.m22 = a.m12 * b.m21 + a.m22 * b.m22 + a.m32 * b.m23 + a.m42 * b.m24;
    result.m23 = a.m13 * b.m21 + a.m23 * b.m22 + a.m33 * b.m23 + a.m43 * b.m24;
    result.m24 = a.m14 * b.m21 + a.m24 * b.m22 + a.m34 * b.m23 + a.m44 * b.m24;

    result.m31 = a.m11 * b.m31 + a.m21 * b.m32 + a.m31 * b.m33 + a.m41 * b.m34;
    result.m32 = a.m12 * b.m31 + a.m22 * b.m32 + a.m32 * b.m33 + a.m42 * b.m34;
    result.m33 = a.m13 * b.m31 + a.m23 * b.m32 + a.m33 * b.m33 + a.m43 * b.m34;
    result.m34 = a.m14 * b.m31 + a.m24 * b.m32 + a.m34 * b.m33 + a.m44 * b.m34;

    result.m41 = a.m11 * b.m41 + a.m21 * b.m42 + a.m31 * b.m43 + a.m41 * b.m44;
    result.m42 = a.m12 * b.m41 + a.m22 * b.m42 + a.m32 * b.m43 + a.m42 * b.m44;
    result.m43 = a.m13 * b.m41 + a.m23 * b.m42 + a.m33 * b.m43 + a.m43 * b.m44;
    result.m44 = a.m14 * b.m41 + a.m24 * b.m42 + a.m34 * b.m43 + a.m44 * b.m44;

    return result;
}

CGAffineTransform CATransform3DGetAffineTransform(CATransform3D t) {
    return {
            t.m11, t.m12,
            t.m21, t.m22,
            t.m41, t.m42};
}

//void CATransform3D::setAsSDLgpuMatrix() const {
//    auto currentMatrix = GPU_GetCurrentMatrix();
//
//    // We could copy currentMatrix to a CATransform3D and save some code here,
//    // but we do this thousands of times a second so it's worth saving ourselves from making a copy:
//    if (
//            currentMatrix[0] == m11 && currentMatrix[1] == m12 && currentMatrix[2] == m13 && currentMatrix[3] == m14 &&
//            currentMatrix[4] == m21 && currentMatrix[5] == m22 && currentMatrix[6] == m23 && currentMatrix[7] == m24 &&
//            currentMatrix[8] == m31 && currentMatrix[9] == m32 && currentMatrix[10] == m33 && currentMatrix[11] == m34 &&
//            currentMatrix[12] == m41 && currentMatrix[13] == m42 && currentMatrix[14] == m43 && currentMatrix[15] == m44)
//    {
//        // The current matrix equals the one we were going to set
//        // Return so we can keep our BlitBuffer intact (saves CPU work)
//        return;
//    }
//
//    // Force anything that hasn't yet been sent to the GPU to be rendered (using the current transform)
//    GPU_FlushBlitBuffer();
//
//    currentMatrix[0] = m11; currentMatrix[1] = m12; currentMatrix[2] = m13; currentMatrix[3] = m14;
//    currentMatrix[4] = m21; currentMatrix[5] = m22; currentMatrix[6] = m23; currentMatrix[7] = m24;
//    currentMatrix[8] = m31; currentMatrix[9] = m32; currentMatrix[10] = m33; currentMatrix[11] = m34;
//    currentMatrix[12] = m41; currentMatrix[13] = m42; currentMatrix[14] = m43; currentMatrix[15] = m44;
//}

CATransform3D CATransform3D::translationBy(float x, float y, float z) {
    return CATransform3DMakeTranslation(x, y, z);
}

CATransform3D CATransform3D::scaleBy(float x, float y, float z) {
    return CATransform3DMakeScale(x, y, z);
}

CATransform3D CATransform3D::scale(float factor) {
    return CATransform3DMakeScale(factor, factor, factor);
}

CATransform3D CATransform3D::rotationBy(float angle, float x, float y, float z) {
    return CATransform3DMakeRotation(angle, x, y, z);
}
