/*
	Yelo: Open Sauce SDK

	See license\OpenSauce\OpenSauce for specific license information
*/
#pragma once

#include <blamlib/math/real_math.hpp>

namespace Yelo
{
    struct real_matrix3x3
    {
        real_vector3d Forward;
        real_vector3d Left;
        real_vector3d Up;

        friend bool operator==(const real_matrix3x3& lhs, const real_matrix3x3& rhs)
        {
            return lhs.Forward == rhs.Forward
                && lhs.Left == rhs.Left
                && lhs.Up == rhs.Up;
        }

        friend bool operator!=(const real_matrix3x3& lhs, const real_matrix3x3& rhs)
        {
            return !(lhs == rhs);
        }
    };

    ASSERT_SIZE(real_matrix3x3, 0x24);

    struct real_matrix4x3
    {
        real Scale;
        real_vector3d Forward;
        real_vector3d Left;
        real_vector3d Up;
        real_point3d Position;

        friend bool operator==(const real_matrix4x3& lhs, const real_matrix4x3& rhs)
        {
            return lhs.Scale == rhs.Scale
                && lhs.Forward == rhs.Forward
                && lhs.Left == rhs.Left
                && lhs.Up == rhs.Up
                && lhs.Position == rhs.Position;
        }

        friend bool operator!=(const real_matrix4x3& lhs, const real_matrix4x3& rhs)
        {
            return !(lhs == rhs);
        }

#if PLATFORM_TARGET != PLATFORM_TARGET_XBOX
        void ConvertTo4x4(D3DMATRIX& d3dmat) const
        {
            d3dmat._11 = Forward.i;
            d3dmat._12 = Forward.j;
            d3dmat._13 = Forward.k;
            d3dmat._14 = 0.0f;
            d3dmat._21 = Left.i;
            d3dmat._22 = Left.j;
            d3dmat._23 = Left.k;
            d3dmat._24 = 0.0f;
            d3dmat._31 = Up.i;
            d3dmat._32 = Up.j;
            d3dmat._33 = Up.k;
            d3dmat._34 = 0.0f;
            d3dmat._41 = Position.x;
            d3dmat._42 = Position.y;
            d3dmat._43 = Position.z;
            d3dmat._44 = Scale;
        }
#endif
    };

    ASSERT_SIZE(real_matrix4x3, 0x34);

    struct real_matrix3x4
    {
        float m[4][3];
    };

    ASSERT_SIZE(real_matrix3x4, 0x30);

#define pad_real_matrix3x3	PAD_TYPE(real_vector3d) PAD_TYPE(real_vector3d) PAD_TYPE(real_vector3d)
#define pad_real_matrix4x3	PAD32 PAD_TYPE(real_vector3d) PAD_TYPE(real_vector3d) PAD_TYPE(real_vector3d) PAD_TYPE(real_point3d)
#define pad_real_matrix3x4	PAD_TYPE(real_vector3d) PAD_TYPE(real_vector3d) PAD_TYPE(real_vector3d) PAD_TYPE(real_vector3d)
};
