#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	//Ѕазовые настройки дл€ запуска формы
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//«апускаем указанную форму
	FormInvaders::MyForm form;
	Application::Run(% form);
}

struct Vector2 {
	int X, Y;
};
Vector2 direction;//направление
Vector2 positionEnemy_1;//позици€ противника 1
Vector2 positionEnemy_2;//позици€ противника 2
Vector2 positionEnemy_3;//позици€ противника 3
Vector2 gameArea;//игрова€ зона

FormInvaders::MyForm::MyForm(void)
{
	InitializeComponent();

	//«адаем размеры игровой зоны
	gameArea.X = 850;
	gameArea.Y = 470;

	firstLaunch = true;//первый запуск
	NewGame();//нова€ игра
}

void FormInvaders::MyForm::GeneratePositionEnemy()
{
		enemys_1 = gcnew PictureBox();
		enemys_1->Location = Point(40, 60);
		enemys_1->BackColor = Color::Red;
		enemys_1->Width = 30;
		enemys_1->Height = 10;
	this->Controls->Add(enemys_1);
	//-----------------
	enemys_2 = gcnew PictureBox();
	enemys_2->Location = Point(200, 60);
	enemys_2->BackColor = Color::Red;
	enemys_2->Width = 30;
	enemys_2->Height = 10;
	this->Controls->Add(enemys_2);
	//---------------------
	enemys_3 = gcnew PictureBox();
	enemys_3->Location = Point(400, 60);
	enemys_3->BackColor = Color::Red;
	enemys_3->Width = 30;
	enemys_3->Height = 10;
	this->Controls->Add(enemys_3);
}

void FormInvaders::MyForm::Shooting()
{
	throw gcnew System::NotImplementedException();
}

void FormInvaders::MyForm::Movement()
{
	player->Location = Point(player->Location.X + direction.X * step, player->Location.Y + direction.Y * step);
	enemys_1->Location = Point(enemys_1->Location.X, enemys_1->Location.Y + 1);
	enemys_2->Location = Point(enemys_2->Location.X, enemys_2->Location.Y + 1);
	enemys_3->Location = Point(enemys_3->Location.X, enemys_3->Location.Y + 1);
	shoot->Location = Point(shoot->Location.X, shoot->Location.Y - 10);
}

void FormInvaders::MyForm::GameOver()
{
	play = true;
	die = true;

}

void FormInvaders::MyForm::NewGame()
{

	if (!firstLaunch) {
		this->Controls->Remove(player);
		this->Controls->Remove(shoot);
		this->Controls->Remove(enemys_3);
		this->Controls->Remove(enemys_2);
		this->Controls->Remove(enemys_1);
	}
	else
		firstLaunch = false;

	//«адаем интревал обнавлени€ и запускаем таймер дл€ обнавлени€
	timer->Interval = updateInterval;
	timer->Start();


	//ћожно играть
	play = true;
	die = false;
	//инициализаци€ игрока
	player = gcnew PictureBox();
	player->Location = Point(450, 500);
	player->BackColor = Color::Green;
	player->Width = 50;
	player->Height = 10;

	this->Controls->Add(player);
	
	//«адаем направление на запуске
	direction.X = 0;
	direction.Y = 0;
	//инициализаци€ противников
	GeneratePositionEnemy();
	//выстрел
	shoot = gcnew PictureBox();
	shoot->Location = Point(player->Location.X+20, player->Location.Y);
	shoot->BackColor = Color::Blue;
	shoot->Width = 10;
	shoot->Height = 10;
	this->Controls->Add(shoot);
}

void FormInvaders::MyForm::ChackBorders()
{
	if (player->Location.X >= pictureBoxRight->Location.X-50 || player->Location.X <= pictureBoxLeft->Location.X) {
		direction.X *= -1;//развернуть в обратном направлении
	}

	if (player->Location.Y <= pictureBoxUP->Location.Y || player->Location.Y >= pictureBoxDown->Location.Y) {
		direction.Y *= -1;//развернуть в обратном направлении
	}
	if (shoot->Location.Y <= pictureBoxUP->Location.Y) {
		shoot->Location = Point(player->Location.X + 20, player->Location.Y);
	}
	if (shoot->Location.Y >= enemys_1->Location.Y && shoot->Location.Y <= enemys_1->Location.Y+10 && shoot->Location.X >= enemys_1->Location.X && shoot->Location.X <= enemys_1->Location.X + 30) {
		shoot->Location = Point(player->Location.X + 20, player->Location.Y);
		enemys_1->Location = Point(0,0);
		delete enemys_1;
		//this->Controls->Remove(enemys_1);
	}
	if (shoot->Location.Y >= enemys_2->Location.Y && shoot->Location.Y <= enemys_2->Location.Y + 10 && shoot->Location.X >= enemys_2->Location.X && shoot->Location.X <= enemys_2->Location.X + 30) {
		shoot->Location = Point(player->Location.X + 20, player->Location.Y);
		enemys_2->Location = Point(0, 0);
		delete enemys_2;
		//this->Controls->Remove(enemys_2);
	}
	if (shoot->Location.Y >= enemys_3->Location.Y && shoot->Location.Y <= enemys_3->Location.Y + 10 && shoot->Location.X >= enemys_3->Location.X && shoot->Location.X <= enemys_3->Location.X + 30) {
		shoot->Location = Point(player->Location.X + 20, player->Location.Y);
		enemys_3->Location = Point(0, 0);
		delete enemys_3;
		//this->Controls->Remove(enemys_3);
	}
	return System::Void();
}

System::Void FormInvaders::MyForm::newGameToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	NewGame();

	return System::Void();
}


System::Void FormInvaders::MyForm::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
	return System::Void();
}
System::Void FormInvaders::MyForm::GameDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	//—читываем нажатую клавишу
	if (e->KeyCode.ToString() == "Right") {
		direction.X = 1;
		direction.Y = 0;
	}
	else if (e->KeyCode.ToString() == "Left") {
		direction.X = -1;
		direction.Y = 0;
	}
	else if (e->KeyCode.ToString() == "Up") {
		direction.Y = -1;
		direction.X = 0;
	}
	else if (e->KeyCode.ToString() == "Down") {
		direction.Y = 1;
		direction.X = 0;
	}

	return System::Void();
}
void FormInvaders::MyForm::GameForm_Update(Object^ obgect, EventArgs^ e)
{
	if (!die && play) {
		//«адает движение 
		Movement();

		ChackBorders();//проверка на столкновение с стеной
	}
	else if (die && play) {
		timer->Stop();
		MessageBox::Show("»гра окончена!", "¬нимание!");
	}
}


