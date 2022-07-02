#pragma once
#include "File.h"
#include "Controller.h"

namespace WalkingOnMars {

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
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmaps
		Bitmap^ bmpAstronaut;
		Bitmap^ bmpMeteorite;
		Bitmap^ bmpMap;
	private: System::Windows::Forms::Timer^ timerMeteorites;
	private: System::Windows::Forms::Label^ lblHP;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblMeteoritesLanded;
	private: System::Windows::Forms::Label^ label2;

		//Controller
		Controller* controller;
	private: System::Windows::Forms::Timer^ timerGameTime;
	private: System::Windows::Forms::Label^ lblGameTime;
	private: System::Windows::Forms::Label^ label3;

		//GameTime
		int gameTime;

		//File
		File* file;

	public:
		FrmMain(void)
		{
			srand(time(NULL));
			//File
			file = new File();

			InitializeComponent();

			//GameTime
			gameTime = file->getGameTime();

			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Bitmaps
			bmpAstronaut = gcnew Bitmap("astronauta.png");
			bmpMeteorite = gcnew Bitmap("meteoritos.png");
			bmpMap = gcnew Bitmap("marte.png");
			
			bmpAstronaut->MakeTransparent(bmpAstronaut->GetPixel(0, 0));

			//Controller
			controller = new Controller(bmpAstronaut);

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
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Timer^ timerMain;
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
			this->lblGameTime = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lblMeteoritesLanded = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblHP = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timerMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerMeteorites = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerGameTime = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->lblGameTime);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->lblMeteoritesLanded);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->lblHP);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(2, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1279, 744);
			this->panel1->TabIndex = 0;
			// 
			// lblGameTime
			// 
			this->lblGameTime->AutoSize = true;
			this->lblGameTime->Location = System::Drawing::Point(1158, 16);
			this->lblGameTime->Name = L"lblGameTime";
			this->lblGameTime->Size = System::Drawing::Size(16, 17);
			this->lblGameTime->TabIndex = 5;
			this->lblGameTime->Text = L"0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1071, 16);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(81, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Game Time";
			// 
			// lblMeteoritesLanded
			// 
			this->lblMeteoritesLanded->AutoSize = true;
			this->lblMeteoritesLanded->Location = System::Drawing::Point(347, 16);
			this->lblMeteoritesLanded->Name = L"lblMeteoritesLanded";
			this->lblMeteoritesLanded->Size = System::Drawing::Size(16, 17);
			this->lblMeteoritesLanded->TabIndex = 3;
			this->lblMeteoritesLanded->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(207, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(130, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Meteorites Landed:";
			// 
			// lblHP
			// 
			this->lblHP->AutoSize = true;
			this->lblHP->Location = System::Drawing::Point(124, 16);
			this->lblHP->Name = L"lblHP";
			this->lblHP->Size = System::Drawing::Size(16, 17);
			this->lblHP->TabIndex = 1;
			this->lblHP->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Health Points: ";
			// 
			// timerMain
			// 
			this->timerMain->Enabled = true;
			this->timerMain->Tick += gcnew System::EventHandler(this, &FrmMain::timerMain_Tick);
			// 
			// timerMeteorites
			// 
			this->timerMeteorites->Enabled = true;
			this->timerMeteorites->Interval = file->getMeteoritesSpawn() * 1000;
			this->timerMeteorites->Tick += gcnew System::EventHandler(this, &FrmMain::timerMeteorites_Tick);
			// 
			// timerGameTime
			// 
			this->timerGameTime->Enabled = true;
			this->timerGameTime->Interval = 1000;
			this->timerGameTime->Tick += gcnew System::EventHandler(this, &FrmMain::timerGameTime_Tick);
			// 
			// FrmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1281, 749);
			this->Controls->Add(this->panel1);
			this->Name = L"FrmMain";
			this->Text = L"FrmMain";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMain::FrmMain_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timerMain_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Clear
		buffer->Graphics->Clear(Color::BlueViolet);
		//Collision
		controller->collision();
		//Move
		controller->moveEverything(buffer->Graphics);
		//Draw
		buffer->Graphics->DrawImage(bmpMap, 0, 0, panel1->Width, panel1->Height);
		lblGameTime->Text = Convert::ToString(gameTime);
		lblMeteoritesLanded->Text = Convert::ToString(controller->getMeteoritesLanded());
		lblHP->Text = Convert::ToString(controller->getAstronaut()->getHp());
		controller->drawEverything(buffer->Graphics, bmpAstronaut, bmpMeteorite);

		if (gameTime <= 0) {
			timerMain->Enabled = false;
			timerGameTime->Enabled = false;
			timerMeteorites->Enabled = false;
			MessageBox::Show("YOU WIN");
			this->Close();
		}
		else if (controller->getAstronaut()->getHp() <= 0) {
			timerMain->Enabled = false;
			timerGameTime->Enabled = false;
			timerMeteorites->Enabled = false;
			MessageBox::Show("YOU LOSE");
			this->Close();
		}
		else {
			//Render
			buffer->Render(g);
		}
	}
	private: System::Void FrmMain_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A:
			controller->getAstronaut()->move(buffer->Graphics, 'A'); break;
		case Keys::D:
			controller->getAstronaut()->move(buffer->Graphics, 'D'); break;
		case Keys::W:
			controller->getAstronaut()->move(buffer->Graphics, 'W'); break;
		case Keys::S:
			controller->getAstronaut()->move(buffer->Graphics, 'S'); break;
		}
	}
private: System::Void timerMeteorites_Tick(System::Object^ sender, System::EventArgs^ e) {
	controller->addMeteorite(new Meteorite(bmpMeteorite->Width / 8, bmpMeteorite->Height / 8));
}
private: System::Void timerGameTime_Tick(System::Object^ sender, System::EventArgs^ e) {
	gameTime--;
}
};
}
