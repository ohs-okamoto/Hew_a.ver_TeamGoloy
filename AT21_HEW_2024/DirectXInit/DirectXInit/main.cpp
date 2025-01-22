#undef UNICODE  // Unicode�ł͂Ȃ��A�}���`�o�C�g�������g��

#include <Windows.h>
#include "Game.h"
#include "Collision.h"
#include <iostream>
#include <iomanip> // <iomanip>��ǉ�

// �}�N����`
#define CLASS_NAME   "DX21Smpl"// �E�C���h�E�N���X�̖��O
#define WINDOW_NAME  "DirectX������"// �E�B���h�E�̖��O

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// �R���\�[���Ɋւ���֐� �S���C
void SetupConsole() {
	AllocConsole();
	FILE* file;
	freopen_s(&file, "CONOUT$", "w", stdout);
	freopen_s(&file, "CONOUT$", "w", stderr);
	freopen_s(&file, "CONOUT$", "w", stdin);
}

// �R���\�[���̃J�[�\���ʒu��ݒ肷��֐�
void SetConsoleCursorPosition(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}





//--------------------------------------------------------------------------------------
// �G���g���|�C���g����ԍŏ��Ɏ��s�����֐��@�@���쐬�ҁ@���{�䍂
//--------------------------------------------------------------------------------------
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// �R���\�[���E�B���h�E�̏����� �S���C
	SetupConsole();

	// �E�B���h�E�N���X�����܂Ƃ߂�
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_CLASSDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = CLASS_NAME;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	// �E�B���h�E�̏����܂Ƃ߂�
	HWND hWnd;
	hWnd = CreateWindowEx(0,	// �g���E�B���h�E�X�^�C��
		CLASS_NAME,				// �E�B���h�E�N���X�̖��O
		WINDOW_NAME,			// �E�B���h�E�̖��O
		WS_OVERLAPPEDWINDOW,	// �E�B���h�E�X�^�C��
		CW_USEDEFAULT,			// �E�B���h�E�̍���w���W
		CW_USEDEFAULT,			// �E�B���h�E�̍���x���W 
		SCREEN_WIDTH,			// �E�B���h�E�̕�
		SCREEN_HEIGHT,			// �E�B���h�E�̍���
		NULL,					// �e�E�B���h�E�̃n���h��
		NULL,					// ���j���[�n���h���܂��͎q�E�B���h�EID
		hInstance,				// �C���X�^���X�n���h��
		NULL);					// �E�B���h�E�쐬�f�[�^

	//�E�B���h�E�̃T�C�Y��\��
	RECT rc1, rc2;
	GetWindowRect(hWnd, &rc1);
	GetClientRect(hWnd, &rc2);
	int sx = SCREEN_WIDTH;
	int sy = SCREEN_HEIGHT;
	sx += ((rc1.right - rc1.left) - (rc2.right - rc2.left));
	sy += ((rc1.bottom - rc1.top) - (rc2.bottom - rc2.top));
	SetWindowPos(hWnd, NULL, 0, 0, sx, sy, (SWP_NOZORDER | SWP_NOOWNERZORDER | SWP_NOMOVE)); //�E�B���h�E�T�C�Y��ύX

	// �w�肳�ꂽ�E�B���h�E�̕\����Ԃ�ݒ�(�E�B���h�E��\��)
	ShowWindow(hWnd, nCmdShow);
	// �E�B���h�E�̏�Ԃ𒼂��ɔ��f(�E�B���h�E�̃N���C�A���g�̈���X�V)
	UpdateWindow(hWnd);

	//�Q�[��������
	Game game;
	game.Init(hWnd);

	Texture texture;
	// �Q�[�����[�v�ɓ���O��DirectX�̏�����������
	MSG msg;

	// FPS�v���p�ϐ�
	int fpsCounter = 0;
	long long oldTick = GetTickCount64();	//�O��v�����̎���
	long long nowTick = oldTick;			//����v�����̎���

	//FPS�Œ�p�ϐ�
	LARGE_INTEGER liwork;//work�����ϐ��͍�Ɨp�ϐ�
	long long frequency;//�ǂꂭ�炢�ׂ������Ԃ��J�E���g�ł��邩
	QueryPerformanceFrequency(&liwork);
	frequency = liwork.QuadPart;
	//���ԁi�P�ʁF�J�E���g�j�擾
	QueryPerformanceCounter(&liwork);
	long long oldCount = liwork.QuadPart;//�O��v�����̎���
	long long nowCount = oldCount;		 //����̌v������


	// �Q�[�����[�v
	while(1)
	{
		// �V���Ƀ��b�Z�[�W�������
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// �E�B���h�E�v���V�[�W���Ƀ��b�Z�[�W�𑗂�
			DispatchMessage(&msg);

			// �uWM_QUIT�v���b�Z�[�W���󂯎�����烋�[�v�𔲂���
			if (msg.message == WM_QUIT) {
				break;
			}
		}
		{
			QueryPerformanceCounter(&liwork);//���ݎ��Ԃ��擾
			nowCount = liwork.QuadPart;
			//1/60�b���o�߂�����
			if (nowCount >= oldCount + frequency / 60) {
				//�Q�[���������s
				game.Update();


				// �R���\�[����擪�ɖ߂��ĐV��������\�� �S���C

				//texture.Load();�ύX�r��
				// �R���\�[����擪�ɖ߂��ĐV��������\��
				// 

				/*
				SetConsoleCursorPosition(0, 0);
				auto santaPos = game.GetSantaPos();
				std::cout<<"�T���^�̍��W : (" << game.GetSantaPos().x << ", " << game.GetSantaPos().y << ")\n" << std::endl;
				
				
				// �n�ʂ̍��W���o��
				for (int i = 0; i < image; ++i) {
					auto groundPos = game.GetGroundPos(i);
					const auto& groundObj = game.GetGround(i);
					const auto& santaObj = game.GetGround(i);
					Collision collision; // �����蔻��I�u�W�F�N�g

					


					// �n�ʂƃT���^�̓����蔻��`�F�b�N
					bool isColliding = collision.ground_santa(groundObj, santaObj, 50.0f, 50.0f);
					std::cout << "Ground[" << i << "]�̍��W : (" << groundPos.x << "," << groundPos.y << "," << groundPos.z << ") - Collision : " << (collision.isColliding ? "�Z":"�~") << " - Direction: " << collision.collisionDirection<< "\n";
				}
				*/
				game.Draw();

				fpsCounter++;//�Q�[�����������s������{�P����
				oldCount = nowCount;
			}

			nowTick = GetTickCount64();//���ݎ��Ԃ��擾
			//�O��v������P�O�O�O�O�~���b���o�߂������H
			if (nowTick >= oldTick + 1000) {
				//FPS�\��
				char str[32];
				wsprintfA(str, "FPS=%d", fpsCounter);
				SetWindowTextA(hWnd, str);
				//�J�E���^�[���Z�b�g
				fpsCounter = 0;
				oldTick = nowTick;
			}

		}
	}
	game.Uninit();

	UnregisterClass(CLASS_NAME, hInstance);

	return (int)msg.wParam;
}

//--------------------------------------------------------------------------------------
//�E�B���h�E�v���V�[�W���@�@���쐬�ҁ@���{�䍂
//--------------------------------------------------------------------------------------

//�ȉ��̃R�[�h������Ȃ牪�{�܂ŘA��

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static bool isFullscreen = false;
	static bool isMessageBoxShowed = false;
	switch (uMsg)
	{
	case WM_DESTROY:// �E�B���h�E�j���̃��b�Z�[�W
		PostQuitMessage(0);// �uWM_QUIT�v���b�Z�[�W�𑗂�@���@�A�v���I��
		break;

	case WM_CLOSE:  // �ux�v�{�^���������ꂽ��
		{
			int res = MessageBoxA(NULL, "�I�����܂����H", "�m�F", MB_OKCANCEL);
			if (res == IDOK) {
				DestroyWindow(hWnd);  // �uWM_DESTROY�v���b�Z�[�W�𑗂�
			}
		}
		break;

	case WM_KEYDOWN: //�L�[���͂����������b�Z�[�W
		if (LOWORD(wParam) == VK_ESCAPE) { //���͂��ꂽ�L�[��ESCAPE�Ȃ�
			PostMessage(hWnd, WM_CLOSE, wParam, lParam);//�uWM_CLOSE�v�𑗂�
		}
		else if (LOWORD(wParam) == VK_F11) {
			//F11�Ńt���X�N���[���ɐ؂�ւ�
			isFullscreen = !isFullscreen;
			if (isFullscreen) {
				//�^���t���X�N���[�����[�h�ɕύX
				SetWindowLongPtr(hWnd, GWL_STYLE, WS_POPUP | WS_MINIMIZEBOX); //�E�B���h�E��������
				//�f�B�X�v���C�𑜓x���擾
				int screenWidth = GetSystemMetrics(SM_CXSCREEN);
				int screenHeight = GetSystemMetrics(SM_CYSCREEN);
				SetWindowPos(hWnd, HWND_TOP, 0, 0, screenWidth, screenHeight, SWP_FRAMECHANGED | SWP_SHOWWINDOW);

			}
			else {
				//�ʏ�E�B���h�E�ɖ߂�
				SetWindowLongPtr(hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW);//�E�B���h�E����߂�
				SetWindowPos(hWnd, HWND_TOP, 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SWP_FRAMECHANGED | SWP_SHOWWINDOW);

			}
		}
		break;
	case WM_ACTIVATE:
		if (wParam == WA_INACTIVE) {
			if (isFullscreen && !isMessageBoxShowed)//�t���X�N���[���\�������b�Z�[�W�{�b�N�X��\��
			{
				ShowWindow(hWnd, SW_MINIMIZE);//�E�B���h�E���ŏ�������i�^�X�N�؂�ւ����ɔw��Ɏc����΍�j

			}
		}
		return DefWindowProc(hWnd, uMsg, wParam, lParam);//�W�����������s�����邽��
	default:
		// �󂯎�������b�Z�[�W�ɑ΂��ăf�t�H���g�̏��������s
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
		break;
	}

	return 0;
}
