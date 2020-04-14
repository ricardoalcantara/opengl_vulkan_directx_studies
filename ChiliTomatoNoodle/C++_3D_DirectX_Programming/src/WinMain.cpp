#include <Windows.h>
#include <d3d11.h>
#include <chrono>

//#pragma comment(lib,"d3d11.lib")

#ifdef NDEBUG
int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow )
#else
int main()
#endif
{
    HINSTANCE hInst = GetModuleHandle( nullptr );
	const auto pClassName = "hw3dbutts";
	// register window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof( wc );
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = DefWindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInst;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx( &wc );
	// create window instance
	HWND hWnd = CreateWindowEx(
		0,pClassName,
		"Happy Hard Window",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200,200,640,480,
		nullptr,nullptr,hInst,nullptr
	);
	// show the damn window
	ShowWindow( hWnd,SW_SHOW );

	// DX
    ID3D11Device* pDevice = nullptr;
    IDXGISwapChain* pSwap = nullptr;
    ID3D11DeviceContext* pContext = nullptr;
    ID3D11RenderTargetView* pTarget = nullptr;

    DXGI_SWAP_CHAIN_DESC sd = {};
    sd.BufferDesc.Width = 0;
    sd.BufferDesc.Height = 0;
    sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 0;
    sd.BufferDesc.RefreshRate.Denominator = 0;
    sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
    sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.BufferCount = 1;
    sd.OutputWindow = hWnd;
    sd.Windowed = TRUE;
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
    sd.Flags = 0;

    UINT swapCreateFlags = 0u;
#ifndef NDEBUG
    swapCreateFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    // for checking results of d3d functions
    HRESULT hr;

    // create device and front/back buffers, and swap chain and rendering context
    D3D11CreateDeviceAndSwapChain(
            nullptr,
            D3D_DRIVER_TYPE_HARDWARE,
            nullptr,
            swapCreateFlags,
            nullptr,
            0,
            D3D11_SDK_VERSION,
            &sd,
            &pSwap,
            &pDevice,
            nullptr,
            &pContext
    );
    // gain access to texture subresource in swap chain (back buffer)
    ID3D11Resource* pBackBuffer = nullptr;
    pSwap->GetBuffer( 0,__uuidof(ID3D11Resource),reinterpret_cast<void**>(&pBackBuffer) );
    pDevice->CreateRenderTargetView( pBackBuffer,nullptr,&pTarget );
    pBackBuffer->Release();

    bool loop = true;
    std::chrono::steady_clock::time_point last;

    while( loop )
    {
        float tt = std::chrono::duration<float>( std::chrono::steady_clock::now() - last ).count();
        float sin_t = sinf(tt) / 2.0f + 0.5f;
        const float color[] = { sin_t,sin_t,1.0f,1.0f };
        pContext->ClearRenderTargetView( pTarget,color );

        pSwap->Present( 1u,0u );
    }

    if( pTarget != nullptr )
    {
        pTarget->Release();
    }
    if( pContext != nullptr )
    {
        pContext->Release();
    }
    if( pSwap != nullptr )
    {
        pSwap->Release();
    }
    if( pDevice != nullptr )
    {
        pDevice->Release();
    }
	return 0;
}