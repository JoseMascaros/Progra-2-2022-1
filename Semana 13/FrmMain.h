#pragma once
#include "Controller.h"
#include "File.h"

namespace UsingFiles {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmMain
	/// </summary>
	public ref class FrmMain : public System::Windows::Forms::Form
	{
	private:
		//Time
		int gameTime;

		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmap
		Bitmap^ bmpEnemyA;
		Bitmap^ bmpEnemyB;
		Bitmap^ bmpEnemyC;

		//File
		File* file;

		//Enemies
		Enemy* enemyA;
		Enemy* enemyB;
		Enemy* enemyC;
	private: System::Windows::Forms::Label^ lblTime;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timerGame;
	private: System::Windows::Forms::Timer^ timerSpawn;

		//Controller
		Controller* controller;

	public:
		FrmMain(void)
		{
			InitializeComponent();
			//File
			file = new File();

			gameTime = file->getTime();
			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Bitmap
			bmpEnemyA = gcnew Bitmap("gold.png");
			bmpEnemyB = gcnew Bitmap("proton.png");
			bmpEnemyC = gcnew Bitmap("pikachu.png");
			bmpEnemyC->MakeTransparent(bmpEnemyC->GetPixel(0, 0));

			//Enemies
			enemyA = new Enemy(file->getEAX(), file->getEAY(), bmpEnemyA->Width / 4, bmpEnemyA->Height / 4);
			enemyB = new Enemy(file->getEBX(), file->getEBY(), bmpEnemyB->Width / 4, bmpEnemyB->Height / 4);
			enemyC = new Enemy(file->getECX(), file->getECY(), bmpEnemyC->Width / 4, bmpEnemyC->Height / 4);

			//Controller
			controller = new Controller(enemyA, enemyB, enemyC);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmMain()
		{
			if (components)
			{
				delete components;
			}

			//Buffer
			delete g;
			delete space;
			delete buffer;

			//Bitmap
			delete bmpEnemyA;
			delete bmpEnemyB;
			delete bmpEnemyC;

			//File
			delete file;

			//Enemies
			delete enemyA;
			delete enemyB;
			delete enemyC;

			//Contrtoller
			delete controller;
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lblTime = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerGame = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerSpawn = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->lblTime);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(2, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1351, 754);
			this->panel1->TabIndex = 0;
			// 
			// lblTime
			// 
			this->lblTime->AutoSize = true;
			this->lblTime->Location = System::Drawing::Point(76, 20);
			this->lblTime->Name = L"lblTime";
			this->lblTime->Size = System::Drawing::Size(16, 17);
			this->lblTime->TabIndex = 1;
			this->lblTime->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Time";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmMain::timer1_Tick);
			// 
			// timerGame
			// 
			this->timerGame->Enabled = true;
			this->timerGame->Interval = 1000;
			this->timerGame->Tick += gcnew System::EventHandler(this, &FrmMain::timerGame_Tick);
			// 
			// timerSpawn
			// 
			this->timerSpawn->Enabled = true;
			this->timerSpawn->Interval = 5000;
			this->timerSpawn->Tick += gcnew System::EventHandler(this, &FrmMain::timerSpawn_Tick);
			// 
			// FrmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1354, 759);
			this->Controls->Add(this->panel1);
			this->Name = L"FrmMain";
			this->Text = L"FrmMain";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMain::FrmMain_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//ReSize Buffer Canvas
		panel1->Width = this->Width;
		panel1->Height = this->Height;
		buffer = space->Allocate(g, panel1->ClientRectangle);
		//Clear
		buffer->Graphics->Clear(Color::LightBlue);
		//Move
		controller->moveEverything(buffer->Graphics);
		//Draw
		lblTime->Text = Convert::ToString(gameTime);
		controller->drawEverything(buffer->Graphics, bmpEnemyA, bmpEnemyB, bmpEnemyC);
		//Render
		buffer->Render(g);
	}
private: System::Void timerGame_Tick(System::Object^ sender, System::EventArgs^ e) {
	gameTime--;
}
private: System::Void FrmMain_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	switch (e->KeyCode)
	{
	case Keys::A:
		controller->addEnemyA(new Enemy(rand() % 800, rand() % 400,
			bmpEnemyA->Width / 4, bmpEnemyA->Height / 4));
		break;
	case Keys::B:
		controller->addEnemyB(new Enemy(rand() % 800, rand() % 400,
			bmpEnemyB->Width / 4, bmpEnemyB->Height / 4));
		break;
	case Keys::C:
		controller->addEnemyC(new Enemy(rand() % 800, rand() % 400,
			bmpEnemyC->Width / 4, bmpEnemyC->Height / 4));
		break;
	case Keys::Space:
		controller->makeEnemiesAEmpty(); break;
	}
}
private: System::Void timerSpawn_Tick(System::Object^ sender, System::EventArgs^ e) {
	controller->addEnemyA(new Enemy(rand() % 800, rand() % 400,
		bmpEnemyA->Width / 4, bmpEnemyA->Height / 4));
	controller->addEnemyB(new Enemy(rand() % 800, rand() % 400,
		bmpEnemyB->Width / 4, bmpEnemyB->Height / 4));
	controller->addEnemyC(new Enemy(rand() % 800, rand() % 400,
		bmpEnemyC->Width / 4, bmpEnemyC->Height / 4));
}
};
}
