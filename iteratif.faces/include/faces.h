/*#include <Windows.h>

#ifdef _GL_
#include <gl\GL.h>
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>

using namespace glm;
#else
#include <D3D11.h>
#include <DDSTextureLoader.h>
#include <DirectXMath.h>
#include <D3Dcompiler.h>

using namespace DirectX;
#endif // !_GL_

#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <tchar.h>

#include "tinyxml2.h"

using namespace std;

#include "faces_types.h"

typedef struct Vertex Vertex;

#include "itMatrix.h"
#include "D3DMatrix.h"
#include "itFile.h"
#include "itObject.h"
#include "itWindow.h"
#include "itString.h"
#include "TypeInfo.h"
#include "FacesException.h"
#include "IRenderer.h"
#include "IVertexBuffer.h"
#include "IIndexBuffer.h"
#include "IBuffer.h"
#include "AlphaBuffer.h"
#include "Array.h"
#include "ILayout.h"
#include "VisualElement.h"
#include "HorizontalLayout.h"
#include "VerticalLayout.h"
#include "Image.h"
#include "itFileManager.h"
#include "Square.h"
#include "ResourceManager.h"
#include "FacesEngine.h"

#include "HashMap.h"
#include "ClassFactory.h"
#include "itFaceParser.h"
#include "itGame.h"


#include "Container.h"
#include "View.h"
#include "D3DRenderer.h"


#include "D3DVertexBuffer.h"
#include "D3DIndexBuffer.h"*/

#ifndef FACES
#define FACES

template<typename T>
inline void Release(T& ptr)
{
	if (ptr != NULL)
	{
		ptr->Release();
		ptr = NULL;
	}
}

#endif // !FACES
