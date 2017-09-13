cbuffer MatrixBufferType : register(b0)
{
	matrix trans;
};

cbuffer ScreenBufferType : register(b1)
{
	float4 screen;
}

cbuffer TransfBufferType : register(b2)
{
	matrix world;
}

struct Input
{
	float2 position : POSITION;
	float2 tex		: TEXCOORD0;
	//float3 color	: COLOR;
};

struct Output
{
	float4 position : SV_POSITION;
	float2 tex		: TEXCOORD0;
	//float3 color	: COLOR;
};

Output main(Input input)
{
	Output output;

	output.position = mul(float4(input.position, 0, 1), world);
	output.position = mul(output.position, trans);
	output.position.x = output.position.x * 2 / screen.x;
	output.position.y = output.position.y * 2 / screen.y;
	output.tex = input.tex;

	return output;
}