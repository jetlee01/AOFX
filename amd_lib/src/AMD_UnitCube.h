//
// Copyright (c) 2016 Advanced Micro Devices, Inc. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef __AMD_UNIT_CUBE_H__
#define __AMD_UNIT_CUBE_H__

#include <d3d11.h>

namespace AMD
{
  HRESULT CreateUnitCube(ID3D11VertexShader** ppVS, ID3D11Device* pDevice);
  HRESULT CreateUnitCube(ID3D11PixelShader** ppPS, ID3D11Device* pDevice);

  HRESULT CreateClipSpaceCube(ID3D11VertexShader** ppVS, ID3D11Device* pDevice);

  HRESULT RenderUnitCube(ID3D11DeviceContext* pDeviceContext,
    D3D11_VIEWPORT             VP,
    D3D11_RECT*                pSR,   unsigned int uNumSR,
    ID3D11RasterizerState *    pRS,
    ID3D11BlendState *         pBS,   const float bsFactor[],
    ID3D11DepthStencilState*   pDSS,  unsigned int stencilRef,
    ID3D11VertexShader*        pVS,
    ID3D11HullShader*          pHS,
    ID3D11DomainShader*        pDS,
    ID3D11GeometryShader*      pGS,
    ID3D11PixelShader*         pPS,
    ID3D11Buffer**             ppCB,  unsigned int uStartCB,  unsigned int uNumCB,
    ID3D11SamplerState**       ppSS,  unsigned int uStartSS,  unsigned int uNumSS,
    ID3D11ShaderResourceView** ppSRV, unsigned int uStartSRV, unsigned int uNumSRV,
    ID3D11RenderTargetView**   ppRTV, unsigned int uNumRTV,
    ID3D11DepthStencilView*    pDSV);
}

#endif
