#pragma once

namespace FormInvaders {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void);

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ newGameToolStripMenuItem;

	private: System::Windows::Forms::PictureBox^ pictureBoxUP;
	private: System::Windows::Forms::PictureBox^ pictureBoxDown;
	private: System::Windows::Forms::PictureBox^ pictureBoxRight;
	private: System::Windows::Forms::PictureBox^ pictureBoxLeft;
	private: System::Windows::Forms::Timer^ timer;

	private: System::ComponentModel::IContainer^ components;





	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBoxUP = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxDown = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxRight = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxLeft = (gcnew System::Windows::Forms::PictureBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxUP))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxRight))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxLeft))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menuToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(909, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->newGameToolStripMenuItem });
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->menuToolStripMenuItem->Text = L"menu";
			// 
			// newGameToolStripMenuItem
			// 
			this->newGameToolStripMenuItem->Name = L"newGameToolStripMenuItem";
			this->newGameToolStripMenuItem->Size = System::Drawing::Size(129, 22);
			this->newGameToolStripMenuItem->Text = L"new game";
			this->newGameToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::newGameToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			this->exitToolStripMenuItem->Text = L"exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// pictureBoxUP
			// 
			this->pictureBoxUP->BackColor = System::Drawing::Color::CornflowerBlue;
			this->pictureBoxUP->Location = System::Drawing::Point(20, 40);
			this->pictureBoxUP->Name = L"pictureBoxUP";
			this->pictureBoxUP->Size = System::Drawing::Size(850, 10);
			this->pictureBoxUP->TabIndex = 1;
			this->pictureBoxUP->TabStop = false;
			// 
			// pictureBoxDown
			// 
			this->pictureBoxDown->BackColor = System::Drawing::Color::CornflowerBlue;
			this->pictureBoxDown->Location = System::Drawing::Point(20, 530);
			this->pictureBoxDown->Name = L"pictureBoxDown";
			this->pictureBoxDown->Size = System::Drawing::Size(850, 10);
			this->pictureBoxDown->TabIndex = 2;
			this->pictureBoxDown->TabStop = false;
			// 
			// pictureBoxRight
			// 
			this->pictureBoxRight->BackColor = System::Drawing::Color::CornflowerBlue;
			this->pictureBoxRight->Location = System::Drawing::Point(870, 40);
			this->pictureBoxRight->Name = L"pictureBoxRight";
			this->pictureBoxRight->Size = System::Drawing::Size(10, 500);
			this->pictureBoxRight->TabIndex = 3;
			this->pictureBoxRight->TabStop = false;
			// 
			// pictureBoxLeft
			// 
			this->pictureBoxLeft->BackColor = System::Drawing::Color::CornflowerBlue;
			this->pictureBoxLeft->Location = System::Drawing::Point(10, 40);
			this->pictureBoxLeft->Name = L"pictureBoxLeft";
			this->pictureBoxLeft->Size = System::Drawing::Size(10, 500);
			this->pictureBoxLeft->TabIndex = 4;
			this->pictureBoxLeft->TabStop = false;
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::GameForm_Update);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(909, 569);
			this->Controls->Add(this->pictureBoxLeft);
			this->Controls->Add(this->pictureBoxRight);
			this->Controls->Add(this->pictureBoxDown);
			this->Controls->Add(this->pictureBoxUP);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::GameDown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxUP))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxRight))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxLeft))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//Данные игры
	private: PictureBox^ player;//игрок
	private: PictureBox^ enemys_1;//враги
	private: PictureBox^ enemys_2;//враги
	private: PictureBox^ enemys_3;//враги
	private: PictureBox^ shoot;//снаряды
	private: bool play;//играть
	private: bool die;//смерть
	private: bool firstLaunch;//первый запуск
	private: int step = 10;//шаг
	private: float updateInterval = 100;//интервал обнавления
	private: int score = 0;//счет 	
	   //-------------
	   //Действия игры
	private: void GeneratePositionEnemy();
	private: void Shooting();
	private: void Movement();
	private: void GameOver();
	private: void NewGame();
	private: void ChackBorders();
	private: System::Void newGameToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void GameDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
	   //Событие по обновлению игры - указывается в timer
	private: void GameForm_Update(Object^ obgect, EventArgs^ e);
};
}
