#include "Dxlib.h"//Dx���C�u�����[���C���N���[�h�i�ǂݍ��݁j

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windows�̃��C���œ�����
{
    //��{�݌v
    ChangeWindowMode(TRUE);//Windows�̉�ʂ��A�N�e�B�u�ɂ���
    DxLib_Init();//DxLib�̏�����
    //SetDrawScreen(DX_SCREEN_BACK);
    //SetGraphMode(800, 600, 32);

    //DxLI���̏��������u
    if (DxLib_Init() == -1)
    {
        //�G���[���N�����璼���ɏI��
        return -1;
    }
    //�~�̏����ʒu
    int circleX = 320;
    int circleY = 240;
    //�Q�[�����[�v
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
        //��ʂ̏�����
        ClearDrawScreen();
        //��ʂɉ~��`�悳����
    DrawCircle(circleX,circleY,30,GetColor(0,0,255),TRUE);
    //�~��X���W�ɓ���������
    circleX += 2;
    circleY += 1;
    if (circleX >= 800)
    {
        circleX = 0;
        circleY = 0;
    }
    //�\��ʂ̓��e��\��ʂɔ��f������
    ScreenFlip();

    //��ʂɓ_��`�悳���ĂˁB�i�w���W�C�x���W�C�_�̐F���w��j
    DrawCircle(320, 240,30,GetColor(0, 0, 255));
    //  ��ʂɉ~��`�悳����
    DrawPixel(320, 240, GetColor(255, 0, 0));
    //�L�[���͑҂�
    WaitKey();
    //Gxlib�g�p�̏I��
    DxLib_End();
    //�\�[�X�̏I��
    return 0;


}