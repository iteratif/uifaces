#ifndef IMATRIX_H_
#define IMATRIX_H_

class IMatrix {
public:
	IMatrix() {}
	virtual ~IMatrix() {}

	virtual void Identity() = 0;
	virtual void Multiply(IMatrix *_m) = 0;
	virtual void Inverse(IMatrix **_invMatrix) = 0;
	virtual void* Raw() = 0;

	virtual void Scale(float _x, float _y, float _z) = 0;
	virtual void RotationZ(float _angle) = 0;
	virtual void Translate(float _x, float _y, float _z) = 0;
};

#endif // !IMATRIX_H_

