#include "mainwindow.h"
#include "ui_mainwindow.h"
int chess[3][3]={0};//棋盘
int ai = 1;
int user = -1;
int current=user;
string AI = " X ";
string User = " O ";
int first_or_last;//判断先后手
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));
    if(rand()%2==0)
    {
        current=ai;
    }
    else
    {
        current=user;
    }
    if(gaming==1&&current==ai)
    {
        AI_Input();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::Check_uesr_win(int user)
{
    for (int i = 0; i < 3; i++)
    {
        if (chess[i][0] == user && chess[i][1]==user && chess[i][2] == user)//判断一行
        {
            return true;
        }
        else if (chess[0][i] == user && chess[1][i] == user && chess[2][i] == user)//判断一列
        {
            return true;
        }
    }
    if (chess[0][0] == user && chess[1][1] == user && chess[2][2] == user)//主对角线
    {
        return true;
    }
    if (chess[0][2] == user && chess[1][1] == user && chess[2][0] == user)//斜对角线
    {
        return true;
    }
    return false;
}
void MainWindow::paintEvent(QPaintEvent *e)
{

}
bool MainWindow::Chess_is_Empty()//判断棋盘是否为空
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (chess[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}
int MainWindow::AI_Best_Input(int state , int next_state,int alpha ,int beta)
{
    int now = state;
    if (Check_uesr_win(now))
    {
        if (now == ai)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else if (Chess_is_Empty())
    {
        return 0;//没有判断出胜负同时棋盘已经满了那么平局
    }
    else
    {
        int score;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (chess[i][j] == 0)
                {
                    chess[i][j] = now;
                    score = AI_Best_Input(next_state, state, alpha, beta);
                    chess[i][j] = 0;
                    if (state == ai)
                    {
                        if (score >= alpha)
                        {
                            alpha = score;
                        }
                        if (alpha > beta)
                        {
                            return beta;
                        }
                    }
                    else
                    {
                        if (score <beta)
                        {
                            beta = score;
                        }
                        if (beta<=alpha)
                        {
                            return alpha;
                        }
                    }
                }

            }
        }
        if (state==ai)
        {
            return alpha;
        }
        else
        {
            return beta;
        }
    }

}
void MainWindow::AI_Input()
{
    int best_x = 0;
    int best_y = 0;
    int best_score = -1000;
    int score;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (chess[i][j] == 0)
            {
                chess[i][j] = ai;
                score = AI_Best_Input(user, ai, -1000, 1000);//初始上下界为无穷
                if (score > best_score)
                {
                    best_score = score;
                    best_x = i;
                    best_y = j;
                }
                chess[i][j] = 0;
            }

        }

    }
    chess[best_x][best_y] = ai;
    if(best_x*3+best_y==0)
    {
        ui->pushButton->setText(QString("X"));
    }
    else if(best_x*3+best_y==1)
    {
        ui->pushButton_2->setText(QString("X"));
    }
    else if(best_x*3+best_y==2)
    {
        ui->pushButton_3->setText(QString("X"));
    }
    else if(best_x*3+best_y==3)
    {
        ui->pushButton_4->setText(QString("X"));
    }
    else if(best_x*3+best_y==4)
    {
        ui->pushButton_5->setText(QString("X"));
    }
    else if(best_x*3+best_y==5)
    {
        ui->pushButton_6->setText(QString("X"));
    }
    else if(best_x*3+best_y==6)
    {
        ui->pushButton_7->setText(QString("X"));
    }
    else if(best_x*3+best_y==7)
    {
        ui->pushButton_8->setText(QString("X"));
    }    else if(best_x*3+best_y==8)
    {
        ui->pushButton_9->setText(QString("X"));
    }
    if(Check_uesr_win(ai))
    {
        gaming=0;
        QMessageBox::information(this,"information","Ai Win") ;
    }
    if(Chess_is_Empty())
    {
        gaming=0;
        QMessageBox::information(this,"information","None Win") ;
    }
    current=user;
}
void MainWindow::on_pushButton_clicked()
{
    if(chess[0][0]==0&&current==user&&gaming==1)
    {
        chess[0][0]=user;
        ui->pushButton->setText(QString("O"));
        current=ai;
    }
    if(Check_uesr_win(user))
    {
        gaming=0;
        QMessageBox::information(this,"information","Player Win") ;
    }
    if(Chess_is_Empty())
    {
        gaming=0;
        QMessageBox::information(this,"information","None Win") ;
    }
    if(gaming==1&&current==ai)
    {
        AI_Input();
    }
}
void MainWindow::on_pushButton_2_clicked()
{
    if(chess[0][1]==0&&current==user&&gaming==1)
    {
        chess[0][1]=user;
        ui->pushButton_2->setText(QString("O"));
        current=ai;
    }
    if(Check_uesr_win(user))
    {
        gaming=0;
        QMessageBox::information(this,"information","Player Win") ;
    }
    if(Chess_is_Empty())
    {
        gaming=0;
        QMessageBox::information(this,"information","None Win") ;
    }
    if(gaming==1&&current==ai)
    {
        AI_Input();
    }
}
void MainWindow::on_pushButton_3_clicked()
{
    if(chess[0][2]==0&&current==user&&gaming==1)
    {
        chess[0][2]=user;
        ui->pushButton_3->setText(QString("O"));
        current=ai;
    }
    if(Check_uesr_win(user))
    {
        gaming=0;
        QMessageBox::information(this,"information","Player Win") ;
    }
    if(Chess_is_Empty())
    {
        gaming=0;
        QMessageBox::information(this,"information","None Win") ;
    }
    if(gaming==1&&current==ai)
    {
        AI_Input();
    }
}
void MainWindow::on_pushButton_4_clicked()
{
    if(chess[1][0]==0&&current==user&&gaming==1)
    {
        chess[1][0]=user;
        ui->pushButton_4->setText(QString("O"));
        current=ai;
    }
    if(Check_uesr_win(user))
    {
        gaming=0;
        QMessageBox::information(this,"information","Player Win") ;
    }
    if(Chess_is_Empty())
    {
        gaming=0;
        QMessageBox::information(this,"information","None Win") ;
    }
    if(gaming==1&&current==ai)
    {
        AI_Input();
    }
}
void MainWindow::on_pushButton_5_clicked()
{
    if(chess[1][1]==0&&current==user&&gaming==1)
    {
        chess[1][1]=user;
        ui->pushButton_5->setText(QString("O"));
        current=ai;
    }
    if(Check_uesr_win(user))
    {
        gaming=0;
        QMessageBox::information(this,"information","Player Win") ;
    }
    if(Chess_is_Empty())
    {
        gaming=0;
        QMessageBox::information(this,"information","None Win") ;
    }

    if(gaming==1&&current==ai)
    {
        AI_Input();
    }
}
void MainWindow::on_pushButton_6_clicked()
{
    if(chess[1][2]==0&&current==user&&gaming==1)
    {
        chess[1][2]=user;
        ui->pushButton_6->setText(QString("O"));
        current=ai;
    }
    if(Check_uesr_win(user))
    {
        gaming=0;
        QMessageBox::information(this,"information","Player Win") ;
    }
    if(Chess_is_Empty())
    {
        gaming=0;
        QMessageBox::information(this,"information","None Win") ;
    }

    if(gaming==1&&current==ai)
    {
        AI_Input();
    }
}
void MainWindow::on_pushButton_7_clicked()
{
    if(chess[2][0]==0&&current==user&&gaming==1)
    {
        chess[2][0]=user;
        ui->pushButton_7->setText(QString("O"));
        current=ai;
    }
    if(Check_uesr_win(user))
    {
        gaming=0;
        QMessageBox::information(this,"information","Player Win") ;
    }
    if(Chess_is_Empty())
    {
        gaming=0;
        QMessageBox::information(this,"information","None Win") ;
    }
    if(gaming==1&&current==ai)
    {
        AI_Input();
    }
}
void MainWindow::on_pushButton_8_clicked()
{
    if(chess[2][1]==0&&current==user&&gaming==1)
    {
        chess[2][1]=user;
        ui->pushButton_8->setText(QString("O"));
        current=ai;
    }
    if(Check_uesr_win(user))
    {
        gaming=0;
        QMessageBox::information(this,"information","Player Win") ;
    }
    if(Chess_is_Empty())
    {
        gaming=0;
        QMessageBox::information(this,"information","None Win") ;
    }

    if(gaming==1&&current==ai)
    {
        AI_Input();
    }
}
void MainWindow::on_pushButton_9_clicked()
{
    if(chess[2][2]==0&&current==user&&gaming==1)
    {
        chess[2][2]=user;
        ui->pushButton_9->setText(QString("O"));
        current=ai;
    }
    if(Check_uesr_win(user))
    {
        gaming=0;
        QMessageBox::information(this,"information","Player Win") ;
    }
    if(Chess_is_Empty())
    {
        gaming=0;
        QMessageBox::information(this,"information","None Win") ;
    }

    if(gaming==1&&current==ai)
    {
        AI_Input();
    }
}
