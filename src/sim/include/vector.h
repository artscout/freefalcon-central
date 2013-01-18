#ifndef _VEC3D_TEMPLATE_H_
#define _VEC3D_TEMPLATE_H_

template<class RealType>
class Vector_3D
{
private:
    RealType _cmp[3];

public:

    // Constructors.
    Vector_3D();
    Vector_3D
    (
        RealType i,
        RealType j,
        RealType k
    );
    Vector_3D(const Vector_3D<RealType> &copy_me);
    Vector_3D(const Tpoint &p);

    // Destructor.
    ~Vector_3D();

    // Assignment.
    Vector_3D<RealType> &operator=(const Vector_3D<RealType> &v);

    // Indexing operator.
    RealType &operator[](int i);
    const RealType &operator[](int i) const;

    // Negate operator.
    Vector_3D<RealType> operator-();

    // Arithmetic with assignment.
    void operator+=(const Vector_3D<RealType> &v);
    void operator-=(const Vector_3D<RealType> &v);
    void operator*=(RealType n);
    void operator/=(RealType n);

    // Binary arithmetic.
    friend Vector_3D<RealType> operator*(RealType n, const Vector_3D<RealType> &v);
    friend Vector_3D<RealType> operator*(const Vector_3D<RealType> &v, RealType n);

    friend Vector_3D<RealType> operator+(const Vector_3D<RealType> &v1, const Vector_3D<RealType> &v2);
    friend Vector_3D<RealType> operator-(const Vector_3D<RealType> &v1, const Vector_3D<RealType> &v2);

    // Get access.
    RealType I() const;
    RealType J() const;
    RealType K() const;

    // Set access.
    void SetI(RealType i);
    void SetJ(RealType j);
    void SetK(RealType k);

    // Magnitude methods.
    RealType MagnitudeSquared() const;
    RealType Magnitude() const;

    // One over magnitude.  This will return 0 if magnitude is 0.
    // This function is here, because 1/sqrt(x) can be converged upon more quickly than
    // sqrt(x), and one over magnitude is what is commonly desired (for normalization).
    RealType OOMagnitude() const;

    // Methods that act upon this vector.
    void Normalize();
    void Invert();

    // Dot and cross products.
    friend RealType Dot(const Vector_3D<RealType> &v1, const Vector_3D<RealType> &v2);
    void Cross(const Vector_3D<RealType> &v1, const Vector_3D<RealType> &v2);

    // Conversion methods.
    void GetTpoint(Tpoint &p) const;
    void GetTrotation(Trotation &r) const;

    // Unit vector methods.
    // Only use these if you know all vector parameters are unit vectors!
    friend RealType AngleBetweenUnitVectors(const Vector_3D<RealType> &v1, const Vector_3D<RealType> &v2);

    // Get the heading from a direction vector.
    // If singularity, heading will be 0.
    // This is dependent on a right-handed coordinate system,
    // with heading 0 pointing along +x.
    RealType Heading() const;

    // Get the angle
    friend RealType AngleBetween(const Vector_3D<RealType> &v1, const Vector_3D<RealType> &v2);
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// Vector_3D inlines

template<class RealType>
inline Vector_3D<RealType>::Vector_3D()
{
    _cmp[0] = (RealType)0.0;
    _cmp[1] = (RealType)0.0;
    _cmp[2] = (RealType)0.0;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline Vector_3D<RealType>::Vector_3D
(
    RealType i,
    RealType j,
    RealType k
)
{
    _cmp[0] = i;
    _cmp[1] = j;
    _cmp[2] = k;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline Vector_3D<RealType>::Vector_3D(const Vector_3D<RealType> &copy_me)
{
    _cmp[0] = copy_me._cmp[0];
    _cmp[1] = copy_me._cmp[1];
    _cmp[2] = copy_me._cmp[2];
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline Vector_3D<RealType>::Vector_3D(const Tpoint &p)
{
    _cmp[0] = p.x;
    _cmp[1] = p.y;
    _cmp[2] = p.z;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline Vector_3D<RealType>::~Vector_3D()
{
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline Vector_3D<RealType> &Vector_3D<RealType>::operator=(const Vector_3D<RealType> &v)
{
    _cmp[0] = v._cmp[0];
    _cmp[1] = v._cmp[1];
    _cmp[2] = v._cmp[2];

    return *this;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline RealType &Vector_3D<RealType>::operator[](int i)
{
    return _cmp[i];
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline const RealType &Vector_3D<RealType>::operator[](int i) const
{
    return _cmp[i];
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline Vector_3D<RealType> Vector_3D<RealType>::operator-()
{
    return Vector_3D<RealType>
           (
               -_cmp[0],
               -_cmp[1],
               -_cmp[2]
           );
}


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline void Vector_3D<RealType>::operator+=(const Vector_3D<RealType> &v)
{
    _cmp[0] += v._cmp[0];
    _cmp[1] += v._cmp[1];
    _cmp[2] += v._cmp[2];
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline void Vector_3D<RealType>::operator-=(const Vector_3D<RealType> &v)
{
    _cmp[0] -= v._cmp[0];
    _cmp[1] -= v._cmp[1];
    _cmp[2] -= v._cmp[2];
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline void Vector_3D<RealType>::operator*=(RealType n)
{
    _cmp[0] *= n;
    _cmp[1] *= n;
    _cmp[2] *= n;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline void Vector_3D<RealType>::operator/=(RealType n)
{
    F4Assert(n != (RealType)0.0)
    operator*=((RealType)1.0 / n);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline Vector_3D<RealType> operator*(RealType n, const Vector_3D<RealType> &v)
{
    return Vector_3D<RealType>
           (
               v._cmp[0] * n,
               v._cmp[1] * n,
               v._cmp[2] * n
           );
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline Vector_3D<RealType> operator*(const Vector_3D<RealType> &v, RealType n)
{
    return Vector_3D<RealType>
           (
               v._cmp[0] * n,
               v._cmp[1] * n,
               v._cmp[2] * n
           );
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline Vector_3D<RealType> operator+(const Vector_3D<RealType> &v1, const Vector_3D<RealType> &v2)
{
    return Vector_3D<RealType>
           (
               v1._cmp[0] + v2._cmp[0],
               v1._cmp[1] + v2._cmp[1],
               v1._cmp[2] + v2._cmp[2]
           );
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline Vector_3D<RealType> operator-(const Vector_3D<RealType> &v1, const Vector_3D<RealType> &v2)
{
    return Vector_3D<RealType>
           (
               v1._cmp[0] - v2._cmp[0],
               v1._cmp[1] - v2._cmp[1],
               v1._cmp[2] - v2._cmp[2]
           );
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline RealType Vector_3D<RealType>::I() const
{
    return _cmp[0];
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline RealType Vector_3D<RealType>::J() const
{
    return _cmp[1];
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline RealType Vector_3D<RealType>::K() const
{
    return _cmp[2];
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline void Vector_3D<RealType>::SetI(RealType i)
{
    _cmp[0] = i;
}


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline void Vector_3D<RealType>::SetJ(RealType j)
{
    _cmp[1] = j;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline void Vector_3D<RealType>::SetK(RealType k)
{
    _cmp[2] = k;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline RealType Vector_3D<RealType>::MagnitudeSquared() const
{
    return
        (
            _cmp[0] * _cmp[0] +
            _cmp[1] * _cmp[1] +
            _cmp[2] * _cmp[2]
        );
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline RealType Vector_3D<RealType>::Magnitude() const
{
    return((float)sqrt(MagnitudeSquared()));
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// This can be optimized.  1/sqrt(x) can be converged upon very quickly, take a look at
// optimizing this later.
// Actually, I'm not sure this optimization can be made with a template function, but what the
// hell.
template<class RealType>
inline RealType Vector_3D<RealType>::OOMagnitude() const
{
    RealType
    mag;

    mag = Magnitude();
    return(mag == 0.0F ? 0.0F : 1.0F / mag);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline void Vector_3D<RealType>::Normalize()
{
    operator*=(OOMagnitude());
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline void Vector_3D<RealType>::Invert()
{
    _cmp[0] = -_cmp[0];
    _cmp[1] = -_cmp[1];
    _cmp[2] = -_cmp[2];
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline RealType Dot(const Vector_3D<RealType> &v1, const Vector_3D<RealType> &v2)
{
    return
        (
            v1._cmp[0] * v2._cmp[0] +
            v1._cmp[1] * v2._cmp[1] +
            v1._cmp[2] * v2._cmp[2]
        );
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline void Vector_3D<RealType>::Cross(const Vector_3D<RealType> &v1, const Vector_3D<RealType> &v2)
{
    _cmp[0] = v1._cmp[1] * v2._cmp[2] - v1._cmp[2] * v2._cmp[1];
    _cmp[1] = v1._cmp[2] * v2._cmp[0] - v1._cmp[0] * v2._cmp[2];
    _cmp[2] = v1._cmp[0] * v2._cmp[1] - v1._cmp[1] * v2._cmp[0];
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline void Vector_3D<RealType>::GetTpoint(Tpoint &p) const
{
    p.x = (float)_cmp[0];
    p.y = (float)_cmp[1];
    p.z = (float)_cmp[2];
}

/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline void Vector_3D<RealType>::GetTrotation(Trotation &result) const
{
    float
    cr,
    sr,
    cp,
    sp,
    cy,
    sy;

    // Construct Roll matrix.
    cr = (float)cos((float)_cmp[0]);
    sr = (float)sin((float)_cmp[0]);

    // Construct Pitch matrix.
    cp = (float)cos((float)_cmp[1]);
    sp = (float)sin((float)_cmp[1]);

    // Construct Yaw matrix.
    cy = (float)cos((float)_cmp[2]);
    sy = (float)sin((float)_cmp[2]);

    result.M11 = cy * cp;
    result.M21 = sy * cp;
    result.M31 = -sp;

    result.M12 = -sy * cr + cy * sp * sr;
    result.M22 = cy * cr + sy * sp * sr;
    result.M32 = cp * sr;

    result.M13 = sy * sr + cy * sp * cr;
    result.M23 = -cy * sr + sy * sp * cr;
    result.M33 = cp * cr;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline RealType AngleBetweenUnitVectors(const Vector_3D<RealType> &v1, const Vector_3D<RealType> &v2)
{
    return acos(Dot(v1, v2));
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline RealType AngleBetween(const Vector_3D<RealType> &v1, const Vector_3D<RealType> &v2)
{
    return acos(Dot(v1, v2) * v1.OOMagnitude() * v2.OOMagnitude());
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class RealType>
inline RealType Vector_3D<RealType>::Heading() const
{
    Vector_3D<RealType>
    v1;

    if (_cmp[1] == 0.0)
    {
        return 0.0;
    }

    v1 = *this;
    v1._cmp[2] = 0.0;
    v1.Normalize();

    return (float)atan2(v1._cmp[1], v1._cmp[0]);
}

/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#endif // _VEC3D_TEMPLATE_H_