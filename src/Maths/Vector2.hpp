//
// Created by nevemlaci on 13/08/2024.
//

#pragma once
#include <ccmath/ccmath.hpp>
#include <iostream>
#include "../export.hpp"

namespace EngiNL::Math{
    struct NLExport Vector2 {
        float x;
        float y;

        explicit constexpr Vector2(float x = 0.0f, float y = 0.0f) : x{ x }, y{ y } {}

        Vector2(const Vector2&) = default;
        Vector2(Vector2&&) noexcept = default;
        Vector2& operator=(const Vector2& other) = default;
        Vector2& operator=(Vector2&&) = default;

        constexpr ~Vector2() = default;

        constexpr bool operator==(const Vector2& other) const {
            return (x == other.x && y == other.y);
        }

        constexpr Vector2 operator+(const Vector2& other) const {
            return Vector2{ x + other.x, y + other.y };
        }

        constexpr Vector2 operator-(const Vector2& other) const {
            return Vector2{ x - other.x, y - other.y };
        }

        constexpr float operator* (const Vector2& other) const {
            return ((x * other.x) + (y * other.y));
        }

        [[nodiscard]]
        constexpr float length() const {
            return ccm::sqrtf(ccm::fabs(x * x + y * y));
        }

        [[nodiscard]]
        constexpr Vector2 normalized() const {
            if (length() != 0.0f) {
                return Vector2{ x / length(), y / length() };
            }
            return Vector2{ 0.0f, 0.0f };
        }


    };

    inline std::istream& operator>>(std::istream& is, Vector2& vec) {
        char c;
        is >> c;
        if(c!='(') {
            throw std::runtime_error("Parse error in Vector2 operator>> | '(' expected.");
        }
        float n;
        is>>n;
        vec.x = n;
        is>>c;
        if(c!=';') {
            throw std::runtime_error("Parse error in Vector2 operator>> | ';' expected.");
        }
        is>>n;
        vec.y = n;
        is>>c;
        if(c!=')') {
            throw std::runtime_error("Parse error in Vector2 operator>> | ')' expected.");
        }
        return is;
    }

    inline std::ostream& operator<<(std::ostream& os, const Vector2& vec) {
        os << "(" << vec.x << ";" << vec.y << ")";
        return os;
    }

    constexpr Vector2 operator* (float a, const Vector2& vec) {
        return Vector2(a * vec.x, a * vec.y);
    }
    constexpr Vector2 operator* (const Vector2& vec, float a) {
        return Vector2(a * vec.x, a * vec.y);
    }
}