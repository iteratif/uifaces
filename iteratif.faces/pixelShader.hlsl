Texture2D shaderTex;
SamplerState SampleType;

cbuffer AlphaBufferType {
	float alpha;
};

struct Input {
	float4 position	: SV_POSITION;
	//float3 color	: COLOR;
	float2 tex		: TEXCOORD0;
};

float4 main( Input input ) : SV_TARGET {
	//return float4( input.color.r, input.color.g, input.color.b, 1 );
	float4 textureColor;

	textureColor = shaderTex.Sample(SampleType, input.tex);
	//textureColor.a = alpha;

	return textureColor;
}