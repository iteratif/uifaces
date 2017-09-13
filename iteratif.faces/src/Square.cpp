#include "Square.h"

Square::Square( float _x, float _y, float _w, float _h ) : VisualElement(),
	m_d3dSquareSRV( NULL )
{
	setX(_x);
	setY(_y);
	setWidth(_w);
	setHeight(_h);
}

Square::~Square()
{
	if (m_d3dSquareSRV != NULL)
	{
		m_d3dSquareSRV->Release();
		m_d3dSquareSRV = NULL;
	}
}

void Square::draw(D3DRenderer & renderer)
{
}

/*void Square::CreateSquareTexture(float *color)
{
	float *texArray = (float *)malloc(4 * 20 * 20 * sizeof(float));

	for (int i = 0; i < 20 * 20 * 4; i++)
		texArray[i] = 1.0f;

	ID3D11Texture2D *boxTex = 0;

	D3D11_TEXTURE2D_DESC boxTexDesc;
	ZeroMemory(&boxTexDesc, sizeof(D3D11_TEXTURE2D_DESC));
	boxTexDesc.ArraySize = 1;
	boxTexDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	boxTexDesc.CPUAccessFlags = 0;
	boxTexDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	boxTexDesc.Height = 20;
	boxTexDesc.MipLevels = 1;
	boxTexDesc.MiscFlags = 0;
	boxTexDesc.SampleDesc.Count = 4;
	boxTexDesc.SampleDesc.Quality = m_4xMsaaQuality - 1;
	boxTexDesc.Usage = D3D11_USAGE_DEFAULT;
	boxTexDesc.Width = 20;

	D3D11_SUBRESOURCE_DATA boxTexInitData;
	ZeroMemory(&boxTexInitData, sizeof(D3D11_SUBRESOURCE_DATA));
	boxTexInitData.pSysMem = texArray;

	m_d3dDevice->CreateTexture2D(&boxTexDesc, &boxTexInitData, &boxTex);
	m_d3dDevice->CreateShaderResourceView(boxTex, NULL, &m_d3dSquareSRV);
}

***********************************************************
*********** SHADER ****************************************
***********************************************************

Texture2D squareMap : register(t0);
SamplerState samLinear : register(s0);

struct PixelIn
{
float4 Pos : SV_POSITION;
float2 Tex : TEXCOORD;
};

float4 main(PixelIn pin) : SV_TARGET
{
float4 texColor = squareMap.Sample(samLinear, pin.Tex);

return texColor;
}

DXGI_FORMAT_R8G8B8A8_UNORM A four-component, 32-bit unsigned-normalized-integer format that supports 8 bits per channel including alpha.

*/
