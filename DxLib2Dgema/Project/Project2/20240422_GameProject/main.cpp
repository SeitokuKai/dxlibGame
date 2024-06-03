#include"DxLib.h"//Dx���C�u�����[���C���N���[�h�i�ǂݍ��݁j

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windows�̃��C���œ�����
{
    //��{�݌v
    ChangeWindowMode(TRUE);//Windows�̉�ʂ��A�N�e�B�u�ɂ���
    DxLib_Init();//DxLib�̏�����
    SetDrawScreen(DX_SCREEN_BACK);//��ʂ̔w�i�͍�
    SetGraphMode(800, 600, 32);//��ʂ̑傫��

    //DxLib�̏���������
    if (DxLib_Init() == -1)
    {
        //�G���[���N�����璼���ɏI��
        return -1;
    }
    //�~�̏����ʒu
    int circleX = 150;
    int circleY = 200;
    //�����̈ʒu
    int stringX = 10;
    int stringY = 15;
    int stringX1 = 10;
    int stringY1 = 40;
    //�}�E�X�̍��W
    int mouseX = 0;
    int mouseY = 0;
    //�~�̐F�w��
    int circleColor = GetColor(0, 0, 255);
    //�����̐F�w��
    int StringColor = GetColor(255, 255, 255);
    int StringColor2 = GetColor(255, 0,0);
    //�Q�[�����[�v
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //��ʂ̏�����
        ClearDrawScreen();
        //��ʂɉ~��`�悳����
        DrawCircle(circleX, circleY, 30, circleColor ,TRUE);
        //�}�E�X�̍��W���擾
        GetMousePoint(&mouseX, &mouseY);
        //�}�E�X���N���b�N���ꂽ��
        if ((GetMouseInput() & MOUSE_INPUT_LEFT))
        {
            SetFontSize(30);
            DrawString(stringX1, stringY1, "Hit", StringColor2);
        }
        if (CheckHitKey(KEY_INPUT_UP))
        {
            //�~��Y���W��40��菬�����Ȃ�����
            if (circleY <= 40)
            {
                circleY += 6;
            }
            else
            {
                circleY -= 6;
            }
        }
        //�e���L�[�̉����������牺�ɓ���
        if (CheckHitKey(KEY_INPUT_DOWN))
        {
            if (circleY >= 560)
            {
                circleY -= 6;
            }
            else
            {
                circleY += 6;
            }
           
        }
        //�e���L�[�̉E����������E�ɓ���
        if (CheckHitKey(KEY_INPUT_RIGHT))
        {
            if (circleX >= 750)
            {
                circleX -= 6;
            }
            else
            {
                circleX += 6;
            }
        }
        //�e���L�[�̍����������獶�ɓ���
        if (CheckHitKey(KEY_INPUT_LEFT))
        {
            if (circleX <= 50)
            {
                circleX += 6;
            }
            else
            {
                circleX -= 6;
            }
            
            
        }
        

            //�~��X���W�ɓ���������
        //circleX += 4;
        //circleY += 2;
        //if (circleX >= 800)
        //{
            //circleX = 0;
           // circleY = 0;
        //}
        //  //�����̑傫���̎w��
        SetFontSize(32);
        //��ʂɕ����\��
        // DrawString(10,15,"HelloWould",StringColor);
        DrawFormatString(stringX, stringY, StringColor, "Mouse X:%d Y:%d", mouseX,mouseY);
            //����ʂ̓��e��\��ʂɔ��f������
        ScreenFlip();

    }
    
    //�\�[�X�̏I��
    return 0;
}